<?php
/**
 * @file
 * wk_developer_assistant.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function wk_developer_assistant_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagecache_defaults_default_image_style';
  $strongarm->value = 'imagecache_defaults_prepare_default_image';
  $export['imagecache_defaults_default_image_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_hash_cache_disabled';
  $strongarm->value = 1;
  $export['panels_hash_cache_disabled'] = $strongarm;

  return $export;
}
