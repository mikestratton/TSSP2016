/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Javascript Drupal Theming function for inside of Popouts
 *
 * To override
 *
 * @param feature
 *  OpenLayers feature object.
 * @return
 *  Formatted HTML.
 */
Drupal.theme.prototype.openlayersPopout = function(feature) {
  var output = '';
  function escapeHtml(text){
    return jQuery("<div>").text(text).html();
  }

  if (feature.attributes.name) {
    output += '<div class="openlayers-popout openlayers-tooltip-name">' + escapeHtml(feature.attributes.name) + '</div>';
  }
  if (feature.attributes.description) {
    // No escaping here because contents are HTML.
    output += '<div class="openlayers-popout openlayers-tooltip-description">' + feature.attributes.description + '</div>';
  }

  return output;
};

// Make sure the namespace exists
Drupal.openlayers.popout = Drupal.openlayers.popout || {};

/**
 * OpenLayers Popout Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_popout', function (data, options) {
  var map = data.openlayers;
  var layers = [];

  // For backwards compatiability, if layers is not
  // defined, then include all vector layers
  if (typeof options.layers == 'undefined' || options.layers.length == 0) {
    layers = map.getLayersByClass('OpenLayers.Layer.Vector');
  }
  else {
    for (var i in options.layers) {
      var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
      if (typeof selectedLayer[0] != 'undefined') {
        layers.push(selectedLayer[0]);
      }
    }
  }
  
  // if only 1 layer exists, do not add as an array.  Kind of a
  // hack, see https://drupal.org/node/1393460
  if (layers.length == 1) {
    layers = layers[0];
  }

  var popoutSelect = new OpenLayers.Control.SelectFeature(layers,
    {
      onSelect: function(feature) {
        // Create FramedCloud popup.
        var html = Drupal.theme('openlayersPopout', feature);
        jQuery('#'+options.container_id).html(html);
        
        Drupal.attachBehaviors();
        Drupal.openlayers.popout.selectedFeature = feature;
      },
      onUnselect: function(feature) {
        jQuery('#'+options.container_id).html('');
      }
    }
  );

  map.addControl(popoutSelect);
  popoutSelect.activate();
  Drupal.openlayers.popout.popoutSelect = popoutSelect;
});
