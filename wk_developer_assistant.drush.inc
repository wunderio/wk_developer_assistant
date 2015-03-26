<?php

/**
 * Implements hook_drush_command().
 */
function wk_developer_assistant_drush_command() {

  $items['developer-environment'] = array(
    'description' => 'Set up a developer environment. Enables several modules, disables caching, resets user 1, .',
    'aliases' => array('de', 'dev', 'dev-env', 'dev_env'),
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
  );

  return $items;
}


/**
 * Callback for the drush-demo-command command
 */
function drush_wk_developer_assistant_developer_environment() {
  $uis = array('ds_ui', 'field_ui', 'views_ui');
  $helpers = array('coffee', 'module_filter', 'stage_file_proxy', 'imagecache_defaults', 'admin_language');
  $devtools = array('devel', 'maildebugger', 'krumo', 'search_krumo');

  drush_log('Enabling developer UI\'s...', 'ok');
  drush_invoke_process('@self', 'en', $uis);

  drush_log('Enabling helper modules...', 'ok');
  drush_invoke_process('@self', 'en', $helpers);

  drush_log('Enabling developer modules...', 'ok');
  drush_invoke_process('@self', 'en', $devtools);

  drush_log('Set user 1 login credentials to admin:admin...', 'ok');
  db_update('users')
    ->fields(array(
      'name' => 'admin',
      'status' => 1,
    ))
    ->condition('uid', 1)
    ->execute();
  drush_invoke_process('@self', 'upwd', array('admin'), array('password' => 'admin'));

  if (module_exists('locale')) {
    drush_log('Enable english and configure admin language...', 'ok');
    drush_log('@todo add/enable english language', 'error');
    variable_set('admin_language_translate_admin_menu', 1);
  }

  drush_log('Sanitize user emails...', 'ok');
  db_update('users')
    ->fields(array(
      'mail' => 'sanitized@example.com'
    ))
    ->condition('uid', 1, '!=')
    ->execute();

  drush_log('Enable db logging...', 'ok');
  drush_invoke_process('@self', 'en', array('dblog'));
  variable_set('error_level', 2);
  variable_set('dblog_row_limit', 10000);

  drush_log('Disable caching and aggregation...', 'ok');
  variable_set('cache', 0);
  variable_set('preprocess_css', 0);
  variable_set('preprocess_js', 0);

  if (module_exists('advagg')) {
    variable_set('advagg_enabled', 0);
  }

  if (module_exists('panels')) {
    variable_set('panels_hash_cache_disabled', 1);
  }

  if (module_exists('securepages')) {
    drush_log('Disable https since most dev environments do not support it...', 'ok');
    variable_set('securepages_enable', 0);
  }

  drush_log('Configure imagecache defaults...', 'ok');
  variable_set('imagecache_defaults_default_image_style', 'imagecache_defaults_prepare_default_image');

  drush_log('Generating one-time login link for lazy devs...', 'ok');
  drush_invoke_process('@self', 'uli');
}