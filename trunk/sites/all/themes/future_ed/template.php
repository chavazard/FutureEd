<?php

/**
 * Add body classes if certain regions have content.
 */


module_load_include('inc', 'fedcorefront', 'includes/login.copywrite');

function future_ed_preprocess_html(&$variables) {
  if (!empty($variables['page']['featured'])) {
    $variables['classes_array'][] = 'featured';
  }

  if (!empty($variables['page']['triptych_first'])
    || !empty($variables['page']['triptych_middle'])
    || !empty($variables['page']['triptych_last'])) {
    $variables['classes_array'][] = 'triptych';
  }

  if (!empty($variables['page']['footer_firstcolumn'])
    || !empty($variables['page']['footer_secondcolumn'])
    || !empty($variables['page']['footer_thirdcolumn'])
    || !empty($variables['page']['footer_fourthcolumn'])) {
    $variables['classes_array'][] = 'footer-columns';
  }

  // Add conditional stylesheets for IE
  drupal_add_css(path_to_theme() . '/css/ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
  drupal_add_css(path_to_theme() . '/css/ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 6', '!IE' => FALSE), 'preprocess' => FALSE));
}

/**
 * Override or insert variables into the page template for HTML output.
 */
function future_ed_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}

/**
 * Override or insert variables into the page template.
 */
function future_ed_process_page(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($variables['title_suffix']['add_or_remove_shortcut']) && $variables['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

  
  
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function future_ed_preprocess_maintenance_page(&$variables) {
  // By default, site_name is set to Drupal if no db connection is available
  // or during site installation. Setting site_name to an empty string makes
  // the site and update pages look cleaner.
  // @see template_preprocess_maintenance_page
  if (!$variables['db_is_active']) {
    $variables['site_name'] = '';
  }
  drupal_add_css(drupal_get_path('theme', 'bartik') . '/css/maintenance-page.css');
}

/**
 * Override or insert variables into the maintenance page template.
 */
function future_ed_process_maintenance_page(&$variables) {
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
}

/**
 * Override or insert variables into the node template.
 */
function future_ed_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }
}

/**
 * Override or insert variables into the block template.
 */
function future_ed_preprocess_block(&$variables) {
  // In the header region visually hide block titles.
  if ($variables['block']->region == 'header') {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }
}

/**
 * Override or insert variables into the block template.
 */

function theme_block($delta) {
  exit;
  switch ($delta['block']->delta)
  {
    case('cursosHeader_block'):
        if (!isset($variables['info_curso']))
        {
          $variables['info_curso'] = consultar_curso_db($nid_curso);
        }
      
      
        //$delta['block']->variable_personal = '999';
        $delta['block']->info_curso = $variables['info_curso'];
        var_dump($delta['block']);
      break;
  }
  
}


/**
 * Implements theme_menu_tree().
 */
function future_ed_menu_tree($variables) {
  return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_field__field_type().
 */
function future_ed_field__taxonomy_term_reference($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
  }

  // Render the items.
  $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
  }
  $output .= '</ul>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array']) ? ' clearfix' : '') . '"' . $variables['attributes'] .'>' . $output . '</div>';

  return $output;
}

/**
* Customización de los temas que se mostrarán en el ambiente glrafico global.
* Creado por Ricardo Aguilera
* el 18 de Noviembre del 2014
*
*/
function future_ed_theme() {
  $items = array();
  
  /**
  * Modificación del comportamiento del login de usuario
  * Ricardo Aguilera 
  * Agregado el 18 de Noviembre del 2014
  */
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'future_ed') . '/templates',
    'template' => 'user-login',
    'preprocess functions' => array(
       'future_ed_preprocess_user_login'
    ),
  );
  
  /**
  * Modificación del comportamiento del formulario de registro
  * Ricardo Aguilera 
  * Agregado el 18 de Noviembre del 2014
  */
  $items['user_register_form'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'future_ed') . '/templates',
    'template' => 'user-register-form',
    'preprocess functions' => array(
      'future_ed_preprocess_user_register_form'
    ),
  );
  
  /**
  * Modificación del comportamiento del formulario de recuperación de contraseña
  * Ricardo Aguilera 
  * Agregado el 18 de Noviembre del 2014
  */
  $items['user_pass'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'future_ed') . '/templates',
    'template' => 'user-pass',
    'preprocess functions' => array(
      'future_ed_preprocess_user_pass'
    ),
  );
  return $items;
}

function future_ed_user_register_form_submit($form, &$form_state){
  
  print_r($form_state);
  $edit = array(
    'name' => $form_state['values']['name'], 
    'pass' => user_password(),
    'mail' => $form_state['values']['mail'],
    'init' => $form_state['values']['mail'], 
    'status' => 1, 
    'access' => REQUEST_TIME,
  );

  //user_save(drupal_anonymous_user(), $edit);
}

/**
* Control para 
*
*/
function future_ed_preprocess_user_login(&$vars) {
 
}


function future_ed_user_register_form_alter(&$vars, &$form) {
  
  print_r("probando preprocess");


  $form['txtNombre'] = array(
  '#name' => 'txtNombre',
    '#title' =>REGISTRO_NOMBRE,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtNombre']) ? $values['txtNombre'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row label-hidden"><div class="small-12 columns ">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => REGISTRO_NOMBRE),
  );
   
$form['txtApellidos'] = array(
  '#name' => 'txtApellidos',
    '#title' =>REGISTRO_APELLIDOS,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtApellidos']) ? $values['txtApellidos'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row label-hidden"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => REGISTRO_APELLIDOS),
  );
   
$form['txtCorreoElectronico'] = array(
  '#name' => 'txtCorreoElectronico',
    '#title' =>REGISTRO_CORREO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtCorreoElectronico']) ? $values['txtCorreoElectronico'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row label-hidden"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => REGISTRO_CORREO),
  );
   
$form['txtUsuario'] = array(
  '#name' => 'txtUsuario',
    '#title' =>REGISTRO_USUARIO,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtUsuario']) ? $values['txtUsuario'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row label-hidden"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => REGISTRO_USUARIO),
  );
   
$form['txtContrasena'] = array(
  '#name' => 'txtContrasena',
    '#title' =>REGISTRO_CONTRASENA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtContrasena']) ? $values['txtContrasena'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row label-hidden"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => REGISTRO_CONTRASENA),
  );
   
$form['txtConfirmaContrasena'] = array(
  '#name' => 'txtConfirmaContrasena',
    '#title' =>REGISTRO_CONFIRMAR_CONTRASENA,
    '#required' => TRUE,
    '#type' => 'textfield',
    '#default_value' => isset($values['txtConfirmaContrasena']) ? $values['txtConfirmaContrasena'] : NULL,
    '#maxlength' => 60,
    '#prefix' =>'<div class="row label-hidden"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
    '#attributes' =>array('placeholder' => REGISTRO_CONFIRMAR_CONTRASENA),
  );
   
$form['chkBoletin'] = array(
  '#name' => 'chkBoletin',
    '#title' =>REGISTRO_RECIBIR_BOLETIN,
    '#type' => 'checkbox',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );
   
$form['chkCondiciones'] = array(
  '#name' => 'chkCondiciones',
    '#title' =>REGISTRO_CONDICIONES_USO,
    '#type' => 'checkbox',
    '#prefix' =>'<div class="row"><div class="small-12 columns">' ,
    '#suffix' => '</div></div>',
  );

  $form['#validate'] = array('valida_usuario_nuevo');
  $form['#submit'] = array('guarda_usuario_nuevo');
   
  return $form;
}

function future_ed_preprocess_user_pass(&$vars) {
}