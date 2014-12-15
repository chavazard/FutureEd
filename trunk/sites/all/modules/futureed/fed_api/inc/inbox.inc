<?php

//ESTATUS DE NOTIFICACIONES
define("INBOX_NO_VISTA", 0);
define("INBOX_NO_LEIDA", 1);
define("INBOX_LEIDA", 2);
define("INBOX_ELIMINADA", 3);


/**
 * Funcion para listar y crear notificaciones pedidas con respecto a un usuario
 * @param int $uid id de usuario
 * @return array  lista de notificaciones
 */
function get_all_inbox_by_user($uid, $limit = 20)
{
	$query = "SELECT id_inbox, last_message, status FROM inbox_users WHERE uid = ".$uid." AND status != ".NOTIFICACION_ELIMINADA.
		" ORDER BY dt_update desc LIMIT ".$limit.";";
		
	$result = db_query($query);
	$record = $result->fetchAll();
	
	//var_dump($record );
	
	$arr_inbox = '';
	
	foreach ($record as $inbox)
	{
		$arr_inbox .= $inbox->id_inbox.",";
	}
	
	$arr_inbox = substr($arr_inbox, 0, -1);
	
	
	$query = "SELECT uid, id_inbox FROM inbox_users WHERE id_inbox IN (".$arr_inbox.") AND uid !=  ".$uid." ORDER BY dt_update desc LIMIT ".$limit.";";
	$result = db_query($query);
	$record_users = $result->fetchAll();	
	
	$conversaciones = array();
	foreach ($record as $inbox)
	{
		$conversaciones[]['inbox'] = $inbox;
		
		$len = count($conversaciones)-1;
		
		$conversaciones[$len]['users'] = array();
		foreach ($record_users as $user)
		{
			if ($user->id_inbox == $inbox->id_inbox)
				$conversaciones[$len]['users'][] = $user->uid;
		}
	}
	
	//var_dump($conversaciones );
	
	return $conversaciones;
}

/**
 * Funcion para listar los mensajes de una conversacion
 * @param int $id_inbox id de conversacion
 * @return array  lista de notificaciones
 */
function get_mensajes_inbox($id_inbox, $uid, $limit = 20)
{
	$query = "SELECT last_message FROM inbox_users WHERE id_inbox = ".$id_inbox." AND  uid = ".$uid.";";
	$result = db_query($query);
	$record = $result->fetchAll();
	
	if (count($record) > 0)
	{
		$query = "SELECT uid, dt_date, message, status, file FROM inbox_messages WHERE id_inbox = ".$id_inbox." AND id_inbox_msg > ".$record[0]->last_message.
			" AND status != ".NOTIFICACION_ELIMINADA." ORDER BY dt_date desc LIMIT ".$limit.";";
		
		$result = db_query($query);
		$record = $result->fetchAll();
	}
	//var_dump($record);
	return $record;
}


/**
 * Funcion que retorna la cantidad de conversaciones no leidas del momento.
 * @param int $uid id de usuario
 * @return int  calc_inbox - retorna cantidad de notificaciones 
 */
function get_count_inbox($uid)
{
	$query = "SELECT count(id_inbox) as calc_inbox FROM inbox_users WHERE uid = ".$uid." AND status = ".NOTIFICACION_NO_LEIDA." ;";
	$result = db_query($query);
	$record = $result->fetchAll();
	
	return $record;
}

/**
 * Funcion para cambia el estatus de varias conversaciones de inbox a la vez
 * @param int $uid id de usuario
 * @param int $prev_status id de estatus previo a cambiar
 * @param int $status id de estatus nuevo
 * @return 
 */
function update_conversaciones_inbox($uid, $prev_status, $status)
{
	$query = db_update ('inbox_users')
		->fields(array('status' => $status,
			        'dt_update' => date('Y-m-d H:i:s')))
		->condition('status', $prev_status)
		->condition('uid', $uid);
	$rows = $query->execute();

	return $rows;
}

/**
 * Funcion para cambiar el estatus de una conversacion de inbox
 * @param int $id_inbox id de inbox de conversacion
 * @param int $status id de status a cambiar
 * @return 
 */
function update_conversacion_inbox($id_inbox, $status, $uid)
{
	if ($status == INBOX_ELIMINADA)
	{
		//Buscar cual es el ultimo id del mensaje que fue enviado
		$query = "SELECT id_inbox_msg FROM inbox_message WHERE id_inbox = ".$id_inbox.
			" ORDER BY id_inbox_msg DESC LIMIT 1;";
		$result = db_query($query);
		$id_inbox_msg = $result->fetchAll();
		
		$fields = array('status' => $status,
				'dt_update' => date('Y-m-d H:i:s'),
				'last_message' => $id_inbox_msg);
	}else
		$fields = array('status' => $status,
				 'dt_update' => date('Y-m-d H:i:s'));
		

	$query = db_update ('inbox_users')
		->fields($fields)
		->condition('id_inbox', $id_inbox)
		->condition('uid', $uid);
	
	$rows = $query->execute();
	
	return $rows;
}


/**
 * Funcion para agregar notifiaciones de cualquier tipo a BD
 * @param int $id_inbox id de conversacion
 * @param int $uid id de usuario
 * @param string $message mensaje enviado en la conversacion
 * @param string $url url estatico para ir a seccion de plataforma
 * @param array $users arreglo de los usuarios dentro de la conversacion sin el uid del usuario que manda el mensaje
 * @return int id de notificacion creada en BD
 */
function insert_inbox($id_inbox, $uid, $msg, $users,  $url = '')
{
	///Si el id_inbox es 0 se asume que es una nueva conversacion en el inbox
	//TODO - revisar si es necesario verificar que exista una conversacion entre los usuarios dados
	$users = explode(",", $users);
	
	if ($id_inbox == 0)
	{
		$id_inbox = time();
		
		//Guardar conversacion para el usuario que manda el mensaje como leida
		$insert = db_insert('inbox_users')
		->fields(array(
			'id_inbox' => $id_inbox,
			'uid' => $uid,
			'last_message' => 0,
			'dt_create' =>  date('Y-m-d H:i:s'),
			'dt_update' =>  date('Y-m-d H:i:s'),
			'status' => INBOX_LEIDA
		))
		->execute();
		
		//Guardar conversacion para los usuarios que reciben el mensaje como no leida
		foreach ($users as $user)
		{
			$insert = db_insert('inbox_users')
			->fields(array(
				'id_inbox' => $id_inbox,
				'uid' => $user,
				'last_message' => 0,
				'dt_create' =>  date('Y-m-d H:i:s'),
				'dt_update' =>  date('Y-m-d H:i:s'),
				'status' => INBOX_NO_LEIDA
			))
			->execute();
		}
	}else
	{
		//Actualizar estatus de mensaje a leido por ser mandado por el mismo usuario
		$query = db_update ('inbox_users')
			->fields(array('status' => INBOX_LEIDA,
				       'dt_update' => date('Y-m-d H:i:s')))
			->condition('id_inbox', $id_inbox)
			->condition('uid', $uid)
			->execute();
		
		//Actualizar estatus de mensaje a no leido a los usuarios de la conversacion
		$query = db_update ('inbox_users')
			->fields(array('status' => INBOX_NO_LEIDA,
				       'dt_update' => date('Y-m-d H:i:s')))
			->condition('id_inbox', $id_inbox)
			->condition('uid', $users, 'IN')
			->execute();
	}
	
	//Guardar mensaje enviado
	$insert = db_insert('inbox_messages')
	->fields(array(
		'id_inbox' => $id_inbox,
		'uid' => $uid,
		'message' => $msg,
		'file' => $url,
		'dt_date' =>  date('Y-m-d H:i:s'),
		'status' => INBOX_NO_LEIDA
	))
	->execute();
	return $insert;
}
 
