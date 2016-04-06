<?php
/**
 * @file
 * Enables modules and site configuration for a windfarms site installation.
 */

/**
 * Implements hook_form_alter().
 */
function windfarm_profile_form_alter(&$form, $form_state, $form_id) {
  if ('install_configure_form' == $form_id) {
    $form['site_information']['site_name']['#default_value'] = 'Open Wind Farm Database';
    $form['update_notifications']['update_status_module']["#default_value"] = array();

    // Hack.
    $variables = array();
    $variables['site_slogan'] = 'Powered by Open Energy Information';
    $variables['theme_bartik_settings'] = variable_get('theme_bartik_settings');
    $variables['theme_bartik_settings']['default_logo'] = 0;
    $variables['theme_bartik_settings']['logo_path'] = 'sites/all/images/header3.png';
    foreach ($variables as $name => $value) {
      variable_set($name, $value);
    }
  }
}
