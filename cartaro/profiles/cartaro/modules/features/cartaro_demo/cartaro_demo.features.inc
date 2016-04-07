<?php
/**
 * @file
 * cartaro_demo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cartaro_demo_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "geoserver" && $api == "geoserver_layers") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "geoserver" && $api == "geoserver_styles") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cartaro_demo_node_info() {
  $items = array(
    'capital' => array(
      'name' => t('Capital'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
