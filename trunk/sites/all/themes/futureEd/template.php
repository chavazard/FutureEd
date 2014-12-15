<?php

/**
 * Implements template_preprocess_html().
 *
 */
//function futureEd_preprocess_html(&$variables) { 
//  // Add conditional CSS for IE. To use uncomment below and add IE css file
//  drupal_add_css(path_to_theme() . '/css/ie.css', array('weight' => CSS_THEME, 'browsers' => array('!IE' => FALSE), 'preprocess' => FALSE));
//
//  // Need legacy support for IE downgrade to Foundation 2 or use JS file below
//  // drupal_add_js('http://ie7-js.googlecode.com/svn/version/2.1(beta4)/IE7.js', 'external');
//}

/**
 * Implements template_preprocess_page
 *
 */
function futureEd_preprocess_page(&$variables) {
  
  //drupal_add_js(array('path'=>arg(0)),'setting');

  $variables['left_empty_2columns_size']    = 'small-2 medium-2 large-2 columns';
  $variables['right_empty_2columns_size']   = 'small-2 medium-2 large-2 columns';  
  $variables['left_empty_3columns_size']    = 'small-2 medium-2 large-2 columns';
  $variables['right_empty_3columns_size']   = 'small-2 medium-2 large-2 columns';  
  $variables['left_sidebar_2columns_size']  = 'small-2 medium-2 large-2 columns';
  $variables['left_sidebar_3columns_size']  = 'small-1 medium-1 large-1 columns';
  $variables['right_sidebar_2columns_size'] = 'small-2 medium-2 large-2 columns';
  $variables['right_sidebar_3columns_size'] = 'small-3 medium-3 large-3 columns';
  $variables['maincontent_2columns_size']   = 'small-6 medium-6 large-6 columns';
  $variables['maincontent_3columns_size']   = 'small-8 medium-8 large-8 columns';
  
  $variables['maincontainer_3columns_size']   = 'small-8 medium-8 large-8 columns';
  
  
  $variables['logo_loggedin_size']          = 'small-2 medium-2 large-2 columns';
  $variables['menu_loggedin_size']          = 'small-4 medium-4 large-4 columns';
  $variables['buscar_loggedin_size']        = 'small-1 medium-1 large-1 columns';
  $variables['perfil_loggedin_size']        = 'small-1 medium-1 large-1 columns';
  $variables['botones_loggedin_size']       = 'small-3 medium-3 large-3 columns';
  $variables['crear_curso_loggedin_size']   = 'small-1 medium-1 large-1 columns';
  
  $variables['logo_loggedout_size']          = 'small-2 medium-2 large-2 columns';
  $variables['menu_loggedout_size']          = 'small-4 medium-4 large-4 columns';
  $variables['buscar_loggedout_size']        = 'small-1 medium-1 large-1 columns';
  $variables['botones_loggedout_size']       = 'small-4 medium-4 large-4 columns';
  $variables['crear_curso_loggedout_size']   = 'small-1 medium-1 large-1 columns';  

 
           
}

/**
 * Implements template_preprocess_node
 *
 */
//function futureEd_preprocess_node(&$variables) {
//}

/**
 * Implements hook_preprocess_block()
 */
//function futureEd_preprocess_block(&$variables) {
//  // Add wrapping div with global class to all block content sections.
//  $variables['content_attributes_array']['class'][] = 'block-content';
//
//  // Convenience variable for classes based on block ID
//  $block_id = $variables['block']->module . '-' . $variables['block']->delta;
//
//  // Add classes based on a specific block
//  switch ($block_id) {
//    // System Navigation block
//    case 'system-navigation':
//      // Custom class for entire block
//      $variables['classes_array'][] = 'system-nav';
//      // Custom class for block title
//      $variables['title_attributes_array']['class'][] = 'system-nav-title';
//      // Wrapping div with custom class for block content
//      $variables['content_attributes_array']['class'] = 'system-nav-content';
//      break;
//
//    // User Login block
//    case 'user-login':
//      // Hide title
//      $variables['title_attributes_array']['class'][] = 'element-invisible';
//      break;
//
//    // Example of adding Foundation classes
//    case 'block-foo': // Target the block ID
//      // Set grid column or mobile classes or anything else you want.
//      $variables['classes_array'][] = 'six columns';
//      break;
//  }
//
//  // Add template suggestions for blocks from specific modules.
//  switch($variables['elements']['#block']->module) {
//    case 'menu':
//      $variables['theme_hook_suggestions'][] = 'block__nav';
//    break;
//  }
//}

//function futureEd_preprocess_views_view(&$variables) {
//}

/**
 * Implements template_preprocess_panels_pane().
 *
 */
//function futureEd_preprocess_panels_pane(&$variables) {
//}

/**
 * Implements template_preprocess_views_views_fields().
 *
 */
//function futureEd_preprocess_views_view_fields(&$variables) {
//}

/**
 * Implements theme_form_element_label()
 * Use foundation tooltips
 */
//function futureEd_form_element_label($variables) {
//  if (!empty($variables['element']['#title'])) {
//    $variables['element']['#title'] = '<span class="secondary label">' . $variables['element']['#title'] . '</span>';
//  }
//  if (!empty($variables['element']['#description'])) {
//    $variables['element']['#description'] = ' <span data-tooltip="top" class="has-tip tip-top" data-width="250" title="' . $variables['element']['#description'] . '">' . t('More information?') . '</span>';
//  }
//  return theme_form_element_label($variables);
//}

/**
 * Implements hook_preprocess_button().
 */
//function futureEd_preprocess_button(&$variables) {
//  $variables['element']['#attributes']['class'][] = 'button';
//  if (isset($variables['element']['#parents'][0]) && $variables['element']['#parents'][0] == 'submit') {
//    $variables['element']['#attributes']['class'][] = 'secondary';
//  }
//}

/**
 * Implements hook_form_alter()
 * Example of using foundation sexy buttons
 */
//function futureEd_form_alter(&$form, &$form_state, $form_id) {
//  // Sexy submit buttons
//  if (!empty($form['actions']) && !empty($form['actions']['submit'])) {
//    $classes = (is_array($form['actions']['submit']['#attributes']['class']))
//      ? $form['actions']['submit']['#attributes']['class']
//      : array();
//    $classes = array_merge($classes, array('secondary', 'button', 'radius'));
//    $form['actions']['submit']['#attributes']['class'] = $classes;
//  }
//}

/**
 * Implements hook_form_FORM_ID_alter()
 * Example of using foundation sexy buttons on comment form
 */
//function futureEd_form_comment_form_alter(&$form, &$form_state) {
  // Sexy preview buttons
//  $classes = (is_array($form['actions']['preview']['#attributes']['class']))
//    ? $form['actions']['preview']['#attributes']['class']
//    : array();
//  $classes = array_merge($classes, array('secondary', 'button', 'radius'));
//  $form['actions']['preview']['#attributes']['class'] = $classes;
//}


/**
 * Implements template_preprocess_panels_pane().
 */
// function zurb_foundation_preprocess_panels_pane(&$variables) {
// }

/**
* Implements template_preprocess_views_views_fields().
*/
/* Delete me to enable
function THEMENAME_preprocess_views_view_fields(&$variables) {
 if ($variables['view']->name == 'nodequeue_1') {

   // Check if we have both an image and a summary
   if (isset($variables['fields']['field_image'])) {

     // If a combined field has been created, unset it and just show image
     if (isset($variables['fields']['nothing'])) {
       unset($variables['fields']['nothing']);
     }

   } elseif (isset($variables['fields']['title'])) {
     unset ($variables['fields']['title']);
   }

   // Always unset the separate summary if set
   if (isset($variables['fields']['field_summary'])) {
     unset($variables['fields']['field_summary']);
   }
 }
}

// */

/**
 * Implements hook_css_alter().
 */
//function futureEd_css_alter(&$css) {
//  // Always remove base theme CSS.
//  $theme_path = drupal_get_path('theme', 'zurb_foundation');
//
//  foreach($css as $path => $values) {
//    if(strpos($path, $theme_path) === 0) {
//      unset($css[$path]);
//    }
//  }
//}

/**
 * Implements hook_js_alter().
 */
//function futureEd_js_alter(&$js) {
//  // Always remove base theme JS.
//  $theme_path = drupal_get_path('theme', 'zurb_foundation');
//
//  foreach($js as $path => $values) {
//    if(strpos($path, $theme_path) === 0) {
//      unset($js[$path]);
//    }
//  }
//}


function futureEd_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#size'] = 40;  // define size of the textfield
    $form['search_block_form']['#default_value'] = t('Buscar...'); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = t('GO!'); // Change the text on the submit button
    $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search-button.png');
    // Add extra attributes to the text box
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
    $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
    // Prevent user from searching the default text
    $form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";
    // Alternative (HTML5) placeholder attribute instead of using the javascript
    $form['search_block_form']['#attributes']['placeholder'] = t('Search');
  }
}

