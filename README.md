wk_developer_assistant
======================

Wunderkraut Germany developer assistant. This Feature module is intended to improve and speed up the Drupal developer experience.

**Never ever enable this module on production instance of your website.**

# Features

* Enables some development related modules: 
	* devel
	* environment_indicator
	* imagecache_defaults
* Following configurations are set for a better development experience:
	* Disables panels hash cache
	* Enables image (cache) defaults
	* Developer information


# Roadmap

* Add Drush command to init some dev settings. For example: Reset user 1 to "admin" with password "admin"
* Add Drush command to remove the dev settings and disable this module.
* Add warning message to detect non-dev environments
* Add modules:
	* search_krumo
	* module_filter
	* final_polish
	* coffee
	* stage_file_proxy
