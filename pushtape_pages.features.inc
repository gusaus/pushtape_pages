<?php
/**
 * @file
 * pushtape_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pushtape_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function pushtape_pages_field_default_field_instances_alter(&$data) {
  if (isset($data['node-panopoly_page-body'])) {
    $data['node-panopoly_page-body']['settings']['better_formats'] = array(
      'allowed_formats' => array(
        'filtered_html' => 0,
        'full_html' => 0,
        'panopoly_html_text' => 'panopoly_html_text',
        'panopoly_wysiwyg_text' => 'panopoly_wysiwyg_text',
        'plain_text' => 'plain_text',
      ),
      'allowed_formats_toggle' => 1,
      'default_order_toggle' => 0,
      'default_order_wrapper' => array(
        'formats' => array(
          'filtered_html' => array(
            'weight' => 0,
          ),
          'full_html' => array(
            'weight' => 1,
          ),
          'panopoly_html_text' => array(
            'weight' => -9,
          ),
          'panopoly_wysiwyg_text' => array(
            'weight' => -10,
          ),
          'plain_text' => array(
            'weight' => 10,
          ),
        ),
      ),
    ); /* WAS: '' */
    $data['node-panopoly_page-body']['widget']['weight'] = 2; /* WAS: 4 */
  }
  if (isset($data['node-panopoly_page-field_featured_image'])) {
    $data['node-panopoly_page-field_featured_image']['widget']['module'] = 'media'; /* WAS: 'image' */
    $data['node-panopoly_page-field_featured_image']['widget']['settings']['allowed_schemes'] = array(
      'public' => 'public',
      'vimeo' => 0,
      'youtube' => 0,
    ); /* WAS: '' */
    $data['node-panopoly_page-field_featured_image']['widget']['settings']['allowed_types'] = array(
      'audio' => 0,
      'document' => 0,
      'image' => 'image',
      'video' => 0,
    ); /* WAS: '' */
    $data['node-panopoly_page-field_featured_image']['widget']['settings']['browser_plugins'] = array(
      'media_default--media_browser_1' => 'media_default--media_browser_1',
      'media_default--media_browser_my_files' => 0,
      'media_internet' => 0,
      'upload' => 'upload',
      'youtube' => 0,
    ); /* WAS: '' */
    $data['node-panopoly_page-field_featured_image']['widget']['type'] = 'media_generic'; /* WAS: 'image_image' */
    unset($data['node-panopoly_page-field_featured_image']['widget']['settings']['preview_image_style']);
  }
}

/**
 * Implements hook_panelizer_defaults_override_alter().
 */
function pushtape_pages_panelizer_defaults_override_alter(&$data) {
  if (isset($data['node:panopoly_page:default'])) {
    $data['node:panopoly_page:default']->css_id = 'page'; /* WAS: 'page-page' */
    $data['node:panopoly_page:default']->display->content['new-e9afd358-c44d-4777-b376-0fa0151bc99b'] = (object) array(
          'pid' => 'new-e9afd358-c44d-4777-b376-0fa0151bc99b',
          'panel' => 'sidebar',
          'type' => 'views_panes',
          'subtype' => 'news-panel_pane_2',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'fields_override' => array(
              'field_featured_image' => 1,
              'title' => 1,
              'body' => 0,
            ),
            'override_title' => '',
            'override_title_text' => '',
            'override_title_heading' => 'h2',
            'view_settings' => 'fields',
            'header_type' => 'none',
            'view_mode' => 'teaser',
            'widget_title' => 'Recent News',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => array(
              'hide_classes' => array(
                'hidden-xs' => 0,
                'hidden-sm' => 0,
                'hidden-md' => 0,
                'hidden-lg' => 0,
              ),
              'additional_classes' => array(
                'pull-left' => 0,
                'pull-right' => 0,
                'clearfix' => 0,
              ),
            ),
            'style' => 'bootstrap_styles:well',
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
          'uuid' => 'e9afd358-c44d-4777-b376-0fa0151bc99b',
        ); /* WAS: '' */
    $data['node:panopoly_page:default']->display->layout = 'floyd_flipped'; /* WAS: 'radix_bryant' */
    $data['node:panopoly_page:default']->display->panels['sidebar'][0] = 'new-e9afd358-c44d-4777-b376-0fa0151bc99b'; /* WAS: 'new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1' */
    unset($data['node:panopoly_page:default']->display->content['new-c755a7a9-2c4c-4f7e-a0f7-fc3a3c87ddd1']);
  }
}
