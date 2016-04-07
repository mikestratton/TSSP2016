<?php
/**
 * @file
 * cartaro_demo.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cartaro_demo_user_default_roles() {
  $roles = array();

  // Exported role: demo.
  $roles['demo'] = array(
    'name' => 'demo',
    'weight' => '2',
  );

  return $roles;
}
