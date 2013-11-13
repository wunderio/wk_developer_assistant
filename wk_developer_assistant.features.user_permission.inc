<?php
/**
 * @file
 * wk_developer_assistant.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wk_developer_assistant_user_default_permissions() {
  $permissions = array();

  // Exported permission: access devel information.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'techtest' => 'techtest',
    ),
    'module' => 'devel',
  );

  return $permissions;
}
