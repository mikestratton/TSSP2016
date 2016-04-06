<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Attribution Behavior
 */
class openlayers_behavior_popout extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layers' => array(),
      'container_id' => '',
    );
  }

  /**
   * Form defintion for per map customizations.
   */
  function options_form($defaults = array()) {
    // Only prompt for vector layers
    $vector_layers = array();
    foreach ($this->map['layers'] as $id => $name) {
      $layer = openlayers_layer_load($id);
      if (isset($layer->data['vector']) && $layer->data['vector'] == TRUE) {
        $vector_layers[$id] = $name;
      }
    }

    return array(
      'layers' => array(
        '#title' => t('Layers'),
        '#type' => 'checkboxes',
        '#options' => $vector_layers,
        '#description' => t('Select layer to apply popouts to.'),
        '#default_value' => isset($defaults['layers']) ?
          $defaults['layers'] : array(),
      ),
      'container_id' => array(
        '#type' => 'textfield',
        '#title' => t('Container ID'),
        '#description' => t('HTML ID of target container.'),
        '#default_value' => isset($defaults['container_id']) ?
          $defaults['container_id'] : '',
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    // Put weight on JS so that we know navigation is included already as this
    // will affect touch devices.
    drupal_add_js(drupal_get_path('module', 'frontmap') .
      '/includes/behaviors/openlayers_behavior_popout.js', array('weight' => 10));
    return $this->options;
  }
}
