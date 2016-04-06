(function ($) {

/**
 * Create google map.
 *
 * @param object map
 *   Object of map options.
 * @return object
 *   On success returns gmap object.
 */
function gmap3ToolsCreateMap(map) {
  if (map.mapId == null) {
    alert(Drupal.t('gmap3_tools error: Map id element is not defined.'));
    return null;
  }

  // Create map.
  var mapOptions = map.mapOptions;
  mapOptions.center = new google.maps.LatLng(map.mapOptions.centerX, map.mapOptions.centerY);
  var gmap = new google.maps.Map(document.getElementById(map.mapId), mapOptions);

  // Stores current opened infoWindow.
  var currentInfoWindow = null;

  // Array for storing all markers that are on this map.
  var gmapMarkers = [];

  // Create markers for this map.
  var markersNum = 0;
  $.each(map.markers, function (i, markerData) {
    
    var marker = new google.maps.Marker({
      position: new google.maps.LatLng(markerData.lat, markerData.lng),
      map: gmap
    });
    if (typeof map.markerOptions.icon != 'undefined') {
      marker.setIcon(map.markerOptions.icon);
    }
    if (typeof markerData.title != 'undefined') {
      marker.setTitle(markerData.title);
    }
    if (typeof markerData.content != 'undefined') {
      google.maps.event.addListener(marker, 'click', function(e) {
        if (map.gmap3ToolsOptions.closeCurrentInfoWindow &&  currentInfoWindow != null) {
          currentInfoWindow.close();
        }
        var infoWindowOptions = map.infoWindowOptions;
        infoWindowOptions.position = marker.getPosition();
        infoWindowOptions.content = markerData.content;
        infoWindowOptions.map = gmap;
        currentInfoWindow = new google.maps.InfoWindow(infoWindowOptions);
      });
    }

    ++markersNum;
    gmapMarkers.push(marker);
  });


  if (markersNum) {
    // If we are centering markers on map we should move map center near makers.
    // We are doing this so first map center (on first display) will be near
    // map center when all markers are displayed - we will avoid map move
    // when map displays markers.
    // @todo - this can be more smarter - first get exact center from markers
    // and then apply it.
    if (map.gmap3ToolsOptions.defaultMarkersPosition != 'default') {
      mapOptions.center = new google.maps.LatLng(map.markers[0].lat, map.markers[0].lng);
    }

    // Default markers position on map.
    if (map.gmap3ToolsOptions.defaultMarkersPosition == 'center') {
      gmap3ToolsCenterMarkers(gmap, map.markers, markersNum);
    }
    else if (map.gmap3ToolsOptions.defaultMarkersPosition == 'center zoom') {
      var bounds = new google.maps.LatLngBounds();
      for (var i = 0; i < markersNum; i++) {
        var marker = map.markers[i];
        bounds.extend(new google.maps.LatLng(marker.lat, marker.lng));
      }
      gmap.fitBounds(bounds);
    }
  }

  // Store map object and map markers in map element so it can be accessed
  // later from js if needed.
  $('#' + map.mapId).data('gmap', gmap);
  $('#' + map.mapId).data('gmapMarkers', gmapMarkers);

  return gmap;
}

/**
 * Center markers on map.
 */
function gmap3ToolsCenterMarkers(map, markers, markersNum) {
  var centerLat = 0;
  var centerLng = 0;
  $.each(markers, function (i, markerData) {
    centerLat += parseFloat(markerData.lat);
    centerLng += parseFloat(markerData.lng);
  });
  centerLat /= markersNum;
  centerLng /= markersNum;
  map.setCenter(new google.maps.LatLng(centerLat, centerLng));
}

$(document).ready(function () {
  // Create all google maps.
  $.each(Drupal.settings.gmap3_tools.maps, function(i, map) {
    var gmap = gmap3ToolsCreateMap(map);
  });
});

})(jQuery);
