<?php

//ESTATUS DE NOTIFICACIONES
define("NOTIFICACION_NO_VISTA", 0);
define("NOTIFICACION_NO_LEIDA", 1);
define("NOTIFICACION_LEIDA", 2);
define("NOTIFICACION_ELIMINADA", 3);

$GLOBALS['tipos_notificaciones']  = array(
	///Cursos
		1 => array ( 'mensaje' => t('El curso nid que están por caducar en tu carrito.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///1 - curso por caducar carrito
		2 => array ( 'mensaje' => t('El curso nid que están por caducar en tu whislist.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///1 - curso por caducar wishlish
		3 => array ( 'mensaje' => t('El curso nid que están por empezar en tu carrito.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///2 - curso por empezar carrito
		4 => array ( 'mensaje' => t('El curso nid que están por empezar en tu wishlist.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///2 - curso por empezar wishlist
		5 => array ( 'mensaje' => t('Hay nueva fecha del curso nid Conoce más detalles en tu carrito.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///3 - nueva fecha de curso en carrito
		6 => array ( 'mensaje' => t('Hay nueva fecha del curso nid Conoce más detalles en tu wishlist.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///3 - nueva fecha de curso en wishlist
		7 => array ( 'mensaje' => t('El curso nid tiene una nueva fecha disponible.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///4 - curso con nueva fecha
		8 => array ( 'mensaje' => t('Se autorizó la modificación de tu curso %%%'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///5 - autorizacion de curso o cambio en curso creado
		9 => array ( 'mensaje' => t('El curso nid tiene una nueva actividad.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///6 - nueva actividad en curso propio
		10 => array ( 'mensaje' => t('El curso nid ha sido vendido.'), 'action' => array(
			'action' => 'get_curso_detail_info', 'param' => 'nid', 'param_field' => 'field_curso_nombre' , 'picture_field' => 'field_curso_imagen')), ///7 - nueva venta de curso propio
	///Canal
		11 => array ( 'mensaje' => t('Hay nuevos cursos en el canal %%%'), 'action' => array()), ///8 - nuevo curso en canal suscrito
		12 => array ( 'mensaje' => t('Has sido asignado como administrador en el canal %%%'), 'action' => array()), ///9 - asignacion de admnistrador en canal
	///Grupo
		13 => array ( 'mensaje' => t('Has sido asignado como administrador del grupo %%%'), 'action' => array()), ///10 - asignacion de administrador de grupo
		14 => array ( 'mensaje' => t('Has sido asignado como miembro del grupo %%%'), 'action' => array()), ///10 - aceptacion de miembro de grupo
		15 => array ( 'mensaje' => t('El grupo %%% tiene una nueva actividad.'), 'action' => array()), ///11 - actividad en grupo
	///Usuario
		16 => array ( 'mensaje' => t('Tu perfil ha sido verificado correctamente.'), 'action' => array(
			'action' => 'get_usuario_header', 'param' => 'uid', 'param_field' => array() , 'picture_field' => '', 'pattern' => '')),///12 - cuenta verificada
	///Actividad social
		17 => array ( 'mensaje' => t('Han compartido algo en tu muro.'), 'action' => array()), ///13 - contenido compartido en muro
		18 => array ( 'mensaje' => t('Han respondido a tu comentario.'), 'action' => array()), ///14 - respuesta a comentario
		20 => array ( 'mensaje' => t('uid_otro desea seguirte.'), 'action' => array(
											'action' => 'get_usuario_header', 'param' => 'uid_otro')), ///16 - confirmar seguimiento
	///Market Place
		19 => array ( 'mensaje' => t('El vendedor %%% ha pedido tu valoración del producto $$$'), 'action' => array()), ///15 - solicitud de valoracion de producto
	);

/**
 * Funcion para cambiar de un stdClass a un array
 * @param object $object 
 * @return object  
 */
function object_to_array($object) {
 
	if (is_object($object)) {
		return array_map(__FUNCTION__, get_object_vars($object));
	} else if (is_array($object)) {
		return array_map(__FUNCTION__, $object);
	} else {
		return $object;
	}
}

/**
 * Funcion para listar y crear notificaciones pedidas con respecto a un usuario
 * @param int $uid id de usuario
 * @return array  lista de notificaciones
 */
function get_notificaciones($uid, $limit = 20)
{
	$query = "SELECT uid, tipo, dt_creacion, nid, uid_otro, status, entity_type  FROM notificaciones WHERE uid = ".$uid." AND status != ".NOTIFICACION_ELIMINADA." ORDER BY dt_update desc LIMIT ".$limit."  ;";
	$result = db_query($query);
	$record = $result->fetchAll();
	
	$result = array();
	$resultQuery = array();
	
	$tipos_notificaciones = $GLOBALS['tipos_notificaciones'];
	
	
	$result = [];
	foreach ($record as $notificacion)
	{
		$notificacion = object_to_array($notificacion);
		
		if (function_exists($tipos_notificaciones[$notificacion['tipo']]['action']['action']))
		{
			$param = $notificacion[$tipos_notificaciones[$notificacion['tipo']]['action']['param']];
			
			$custom = $tipos_notificaciones[$notificacion['tipo']]['action']['action']($param);
			
			$notificacion['mensaje'] = str_replace($tipos_notificaciones[$notificacion['tipo']]['action']['param'],
				"l(". $custom[$tipos_notificaciones[$notificacion['tipo']]['action']['param_field']]. ", '".create_urls($notificacion['entity_type'], $param)."')" ,
				$tipos_notificaciones[$notificacion['tipo']]['mensaje']);
			$notificacion['picture'] = $custom[$tipos_notificaciones[$notificacion['tipo']]['action']['picture_field']];
			
			$result[] =  $notificacion;
		}
	}
	
	var_dump($result);
	
	return $record;
}

/**
 * Funcion que retorna la cantidad de notificaciones no leidas del momento.
 * @param int $uid id de usuario
 * @return int  calc_notificaciones - retorna cantidad de notificaciones 
 */
function get_count_notificaciones($uid)
{
	$query = "SELECT count(id_notificacion) as calc_notificaciones FROM notificaciones WHERE uid = ".$uid." AND status = ".NOTIFICACION_NO_LEIDA." ;";
	$result = db_query($query);
	$record = $result->fetchAll();
	
	return $record;
}

/**
 * Funcion para cambia el estatus de varias notificaciones a la vez
 * @param int $uid id de usuario
 * @param int $prev_status id de estatus previo a cambiar
 * @param int $status id de estatus nuevo
 * @return 
 */
function update_notificaciones($uid, $prev_status, $status)
{
	$query = db_update ('notificaciones')
		->fields(array('status' => $status))
		->condition('status', $prev_status)
		->condition('uid', $uid);
	$rows = $query->execute();

	return $rows;
}

/**
 * Funcion para cambiar el estatus de una notificacion
 * @param int $id_notificacion id unico en tabla de notificaciones
 * @param int $status id de status a cambiar
 * @return 
 */
function update_notificacion($id_notificacion, $status)
{
	$query = db_update ('notificaciones')
		->fields(array('status' => $status))
		->condition('id_notificacion', $id_notificacion);
	$rows = $query->execute();

	return $rows;
}


/**
 * Funcion para agregar notifiaciones de cualquier tipo a BD
 * @param int $uid id de usuario
 * @param int $tipo tipo de notificaciones
 * @param string $url url estatico para ir a seccion de plataforma
 * @param int $nid nodo id referente
 * @param string $entity_type tipo de entidad general [nodo, user]
 * @param int $uid_externo id de usuario secundario posible
 * @return int id de notificacion creada en BD
 */
function insert_notificacion($uid, $tipo, $url, $nid = 0, $entity_type = 'node', $uid_externo = 0)
{
	$url = '';
	
	$insert = db_insert('notificaciones')
	->fields(array(
		'uid' => $uid,
		'tipo' => $tipo,
		'dt_creacion' => date('Y-m-d H:i:s'),
		'url' => $url,
		'nid' => $nid,
		'entity_type' => $entity_type,
		'uid_otro' => $uid_externo,
		'dt_update' => date('Y-m-d H:i:s'),
		'status' => NOTIFICACION_NO_VISTA
	))
	->execute();
	
	return $insert;
}
 


/**
 * Hook para crear jobs dentro del Cron
 * @return items
 */
function fed_api_cronapi() {
  $items = array();

 //https://www.drupal.org/node/2195411
$items['notificacion_job'] = array(
    'title' => t('This is my cron job #1'),
    'file' => 'notificaciones.inc',
    'file path' => drupal_get_path('module', 'fed_api') . '/inc',
    'callback' => 'notificacion_job_callback',
    'callback arguments' => array('tipo' => '0'),
    'enabled' => TRUE,
    'tags' => array('notificacion'),
    'settings' => array(
      'example_plugin' => array(
        'example_setting' => 'example_value',
      ),
    ),
    'scheduler' => array(
      'name' => 'simple',
      'crontab' => array(
        'rules' => array('*/10 * * *'),
      ),
    ),
    'launcher' => array(
      'name' => 'serial',
      'serial' => array(
        'thread' => 'any',
      ),
    ),
    'logger' => array(
      'name' => 'cache',
      'cache' => array(
        'bin' => 'my_cache_bin',
      ),
    ),
  );

  return $items;
}

function notificacion_job_callback($tipo)
{
    //$json = json_encode($valores);
  
  $insert = db_insert('custom_log')
		->fields(array('vc_module', 'vc_function','vc_content','dt_date'))
    ->values(array(
              'vc_module' => "prueba",
              'vc_function' => "custom",
              'vc_content' => "prueba de cron corriendo",
	      'dt_date' => date('Y-m-d H:i:s'),
            ));
        $insert->execute();
  
}

