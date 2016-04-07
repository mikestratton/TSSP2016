<?php

/**
 * Implements hook_openlayers_behaviors().
 */
function frontmap_openlayers_behaviors() {
  return array(
    'openlayers_behavior_popout' => array(
      'title' => t('Pop Out for Features'),
      'description' => t('Adds clickable info boxes to points or shapes on maps, loaded into external container.'),
      'type' => 'map',
      'path' => drupal_get_path('module', 'frontmap') .'/includes/behaviors',
      'file' => 'openlayers_behavior_popout.inc',
      'behavior' => array(
        'file' => 'openlayers_behavior_popout.inc',
        'class' => 'openlayers_behavior_popout',
        'parent' => 'openlayers_behavior',
      ),
    ),
  );
}