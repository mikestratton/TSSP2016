<?php
/**
 * @file
 * cartaro_demo.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function cartaro_demo_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'frontmap';
  $openlayers_maps->title = 'Frontmap';
  $openlayers_maps->description = 'This is the default map that will be shown on the frontmap.';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'profiles/cartaro/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'profiles/cartaro/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => array(),
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'capitals_wfs' => 'capitals_wfs',
        ),
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'capitals_wfs' => 'capitals_wfs',
    ),
    'layer_weight' => array(
      'capitals_wfs' => '0',
      'postgis_formatter_layer' => '0',
      'openlayers_geojson_picture_this' => '0',
    ),
    'layer_styles' => array(
      'openlayers_geojson_picture_this' => '0',
      'postgis_formatter_layer' => '0',
      'capitals_wfs' => '0',
    ),
    'layer_styles_select' => array(
      'openlayers_geojson_picture_this' => '0',
      'postgis_formatter_layer' => '0',
      'capitals_wfs' => '0',
    ),
    'layer_activated' => array(
      'capitals_wfs' => 'capitals_wfs',
      'openlayers_geojson_picture_this' => 0,
      'postgis_formatter_layer' => 0,
    ),
    'layer_switcher' => array(
      'capitals_wfs' => 'capitals_wfs',
      'openlayers_geojson_picture_this' => 0,
      'postgis_formatter_layer' => 0,
    ),
    'projection' => 'EPSG:3857',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['frontmap'] = $openlayers_maps;

  return $export;
}
