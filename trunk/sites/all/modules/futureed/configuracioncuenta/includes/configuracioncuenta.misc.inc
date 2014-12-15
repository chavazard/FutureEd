<?php

function get_intereses($uid){
  if($uid == 0)
      return false;
  $result = db_query('SELECT taxonomy_id FROM {intereses} WHERE uid = '.$uid);
  $record = $result->fetchAll();
  return $record;
}
        
function delete_intereses($uid){
  if($uid == 0)
      return false;
  $result = db_delete('intereses')
  ->condition('uid', $uid)
  ->execute();
}
        
function get_tarjeta($uid){
  if($uid == 0)
      return false;
  $fields=array('field_tarjeta_alias','field_tarjeta_numero','field_tarjeta_tipo','field_tarjeta_nombre','field_tarjeta_fecha_vencimiento',
                'field_tarjeta_codigo_seguridad');
  $tarjeta=get_nodes_by_fields($uid, 'tarjeta_de_credito', $fields);
    
  if($tarjeta>0){
        $array=array();
        foreach ($tarjeta as $key=>$row) {
          $array[$key]=array('alias' =>$row->field_tarjeta_alias['und'][0]['value'],
                             'numero' =>substr($row->field_tarjeta_numero['und'][0]['value'],-4),
                             'tipo' =>$row->field_tarjeta_tipo['und'][0]['value'],
                             'nombre' =>$row->field_tarjeta_nombre['und'][0]['value'],
                             'vencimiento' =>$row->field_tarjeta_fecha_vencimiento['und'][0]['value'],
                             'codigo' =>$row->field_tarjeta_codigo_seguridad['und'][0]['value'],
                             'nid'=>$key
                             );
        }
  }
  else
    return false;
  unset($tarjeta,$row,$key);
  return $array;
      
}
  
function get_direcciones($uid){
  if($uid == 0)
      return false;
  $fields=array('field_direcciones_calle','field_direcciones_nexterior','field_direcciones_ninterior','field_direcciones_colonia',
                'field_direcciones_municipio','field_direcciones_estado','field_direcciones_pais','field_direcciones_codigo_postal');
  $direcciones=get_nodes_by_fields($uid, 'direcciones', $fields);

  if($direcciones>0){
        $array=array();
        foreach ($direcciones as $key=>$row) {
          $array[$key]=array('calle' =>$row->field_direcciones_calle['und'][0]['value'],
                             'nexterior' =>$row->field_direcciones_nexterior['und'][0]['value'],
                             'ninterior' =>$row->field_direcciones_ninterior['und'][0]['value'],
                             'colonia' =>$row->field_direcciones_colonia['und'][0]['value'],
                             'municipio' =>$row->field_direcciones_municipio['und'][0]['value'],
                             'estado' =>$row->field_direcciones_estado['und'][0]['value'],
                             'pais' =>$row->field_direcciones_pais['und'][0]['value'],
                             'cp' =>$row->field_direcciones_codigo_postal['und'][0]['value'],
                             'nid'=>$key
                             );
        }
  }
  else
    return false;
  unset($direcciones,$row,$key);
  return $array;
 
}
  
function get_persona($uid){
  if($uid == 0)
      return false;
  $fields=array('field_persona_tipo','field_persona_razon_social','field_persona_rfc','field_direcciones_calle','field_direcciones_nexterior',
                'field_direcciones_ninterior','field_direcciones_colonia','field_direcciones_municipio','field_direcciones_estado',
                'field_direcciones_pais','field_direcciones_codigo_postal');
  $persona=get_nodes_by_fields($uid, 'persona', $fields);
  return $persona;
    
  if($persona>0){
        $array=array();
        foreach ($persona as $key=>$row) {
          $array[$key]=array('tipo' =>$row->field_persona_tipo['und'][0]['value'],
                             'rsocial' =>$row->field_persona_razon_social['und'][0]['value'],
                             'rfc' =>$row->field_persona_rfc['und'][0]['value'],
                             'calle' =>$row->field_direcciones_calle['und'][0]['value'],
                             'nexterior' =>$row->field_direcciones_nexterior['und'][0]['value'],
                             'ninterior' =>$row->field_direcciones_ninterior['und'][0]['value'],
                             'colonia' =>$row->field_direcciones_colonia['und'][0]['value'],
                             'municipio' =>$row->field_direcciones_municipio['und'][0]['value'],
                             'estado' =>$row->field_direcciones_estado['und'][0]['value'],
                             'pais' =>$row->field_direcciones_pais['und'][0]['value'],
                             'cp' =>$row->field_direcciones_codigo_postal['und'][0]['value'],
                             'ciudad' =>$row->field_direcciones_ciudad['und'][0]['value'],
                             'nid'=>$key
                             );
        }
  }
  else
    return false;
  unset($persona,$row,$key);
  return $array;
     
}
  
function get_cuenta($uid){
  if($uid == 0)
      return false;
  $fields=array('field_cuenta_alias','field_cuenta_tipo','field_cuenta_nombre_banco','field_cuenta_numero','field_cuenta_nombre_titular',
                'field_cuenta_clabe');
  $cuenta=get_nodes_by_fields($uid, 'cuenta_de_deposito', $fields);
   
  if($cuenta>0){
        $array=array();
        foreach ($cuenta as $key=>$row) {
          $array[$key]=array('alias' =>$row->field_cuenta_alias['und'][0]['value'],
                             'tipo' =>$row->field_cuenta_tipo['und'][0]['value'],
                             'banco' =>$row->field_cuenta_nombre_banco['und'][0]['value'],
                             'numero' =>substr($row->field_cuenta_numero['und'][0]['value'],-4),
                             'titular' =>$row->field_cuenta_nombre_titular['und'][0]['value'],
                             'clabe' =>$row->field_cuenta_clabe['und'][0]['value'],
                             'nid'=>$key
                             );
        }
  }
  else
    return false;
  unset($cuenta,$row,$key);
  return $array;
      
}

function get_paypal($uid){
  if($uid == 0)
      return false;
  $fields=array('field_usuario_paypal');
  $paypal=get_user_fields($uid, $fields);

  if($paypal>0){
        $array=array();
       
          $array=array('paypal' =>$paypal['field_usuario_paypal'],
                             'nid'=>$uid
                             );
  }
  else
    return false;
  unset($paypal,$fields);
  return $array;
}


function get_informacion_profesional($uid){
  if($uid == 0)
      return false;
  $fields=array('field_usuario_empresa','field_usuario_puesto','field_usuario_empleo_actual','field_usuario_periodo_tiempo');
  $profesional=get_user_fields($uid, $fields);
 #print_r($profesional);
  if($profesional>0){
        $array=array();
       
          $array=array('empresa' =>$profesional['field_usuario_empresa'],
                             'puesto' =>$profesional['field_usuario_puesto'],
                             'actual' =>$profesional['field_usuario_empleo_actual'],
                             'inicio' =>$profesional['field_usuario_periodo_tiempo'],
                             'fin' =>$profesional['field_usuario_periodo_tiempo_value2'],
                             'nid'=>$uid
                             );
       
  }
  else
    return false;
  unset($profesional,$fields);
  return $array;
  
}

function get_informacion_academica($uid){
  if($uid == 0)
      return false;
  $fields=array('field_usuario_escuela','field_usuario_titulo_estudios','field_usuario_tipo_estudio','field_usuario_cursando');
  $academico=get_user_fields($uid, $fields);
  
  if($academico>0){
        $array=array();
       
          $array=array('escuela' =>$academico['field_usuario_escuela'],
                             'titulo' =>$academico['field_usuario_titulo_estudios'],
                             'tipo' =>$academico['field_usuario_tipo_estudio'],
                             'cursando' =>$academico['field_usuario_cursando'],
                             'uid'=>$uid
                             );
       
  }
  else
    return false;
  unset($academico,$fields);
  return $array;
  
}


function insert_direcciones($uid,$calle,$nexterior,$ninterior,$colonia,$municipio,$estado,$pais,$cp){
  if($uid == 0)
      return false;
  $node = new stdClass();
  $node->language = LANGUAGE_NONE;
  $node->type = "direcciones";
  node_object_prepare($node);
  $node->uid = $uid;
  $node->status = 1; //(1 or 0): publicado automaticamente
  $node->promote = 0; //(1 or 0): desabilitado para página principal
  $node->comment = 0; // comentarios sobre el nodo deshabilitados
  $node->field_direcciones_calle[$node->language][0]['value'] = $calle;
  $node->field_direcciones_nexterior[$node->language][0]['value'] = $nexterior;
  $node->field_direcciones_ninterior[$node->language][0]['value'] = $ninterior;
  $node->field_direcciones_colonia[$node->language][0]['value'] = $colonia;
  $node->field_direcciones_municipio[$node->language][0]['value'] = $municipio;
  $node->field_direcciones_estado[$node->language][0]['tid'] = $estado;
  $node->field_direcciones_pais[$node->language][0]['tid'] = $pais;
  $node->field_direcciones_codigo_postal[$node->language][0]['value'] = $cp;
  node_save($node);
  
  $direcciones=get_direcciones($uid);
  return $direcciones;
}


function insert_tarjeta($uid,$alias,$numero,$tipo,$nombre,$vencimiento,$codigo){
  if($uid == 0)
      return false;
  $node = new stdClass();
  $node->language = LANGUAGE_NONE;
  $node->type = "tarjeta_de_credito";
  node_object_prepare($node);
  $node->uid = $uid;
  $node->status = 1; //(1 or 0): publicado automaticamente
  $node->promote = 0; //(1 or 0): desabilitado para página principal
  $node->comment = 0; // comentarios sobre el nodo deshabilitados
  $node->field_tarjeta_alias[$node->language][0]['value'] = $alias; 
  $node->field_tarjeta_numero[$node->language][0]['value'] = $numero;
  $node->field_tarjeta_tipo[$node->language][0]['value'] = $tipo;
  $node->field_tarjeta_nombre[$node->language][0]['value'] = $nombre;
  $node->field_tarjeta_fecha_vencimiento[$node->language][0]['value'] = $vencimiento;
  $node->field_tarjeta_codigo_seguridad[$node->language][0]['value'] = $codigo;
  node_save($node);
  
  $tarjeta=get_tarjeta($uid);
  return $tarjeta;
}

function insert_persona($uid,$tipo,$rsocial,$rfc,$calle,$nexterior,$ninterior,$colonia,$municipio,$pais,$cp,$estado,$ciudad,$email,$telefono){
  if($uid == 0)
      return false;
  $edit=array();
  $u=user_load($uid);
  $node = new stdClass();
  $node->language = LANGUAGE_NONE;
  $node->type = "persona";
  node_object_prepare($node);
  $node->uid = $uid;
  $node->status = 1; //(1 or 0): publicado automaticamente
  $node->promote = 0; //(1 or 0): desabilitado para página principal
  $node->comment = 0; // comentarios sobre el nodo deshabilitados
  $node->field_persona_tipo[$node->language][0]['value'] = $tipo;
  $node->field_persona_razon_social[$node->language][0]['value'] = $rsocial;
  $node->field_persona_rfc[$node->language][0]['value'] = $rfc;
  $node->field_direcciones_calle[$node->language][0]['value'] = $calle;
  $node->field_direcciones_nexterior[$node->language][0]['value'] = $nexterior;
  $node->field_direcciones_ninterior[$node->language][0]['value'] = $ninterior;
  $node->field_direcciones_colonia[$node->language][0]['value'] = $colonia;
  $node->field_direcciones_municipio[$node->language][0]['value'] = $municipio;
  $node->field_direcciones_estado[$node->language][0]['tid'] = $estado;
  $node->field_direcciones_codigo_postal[$node->language][0]['value'] = $cp;
  $node->field_direcciones_pais[$node->language][0]['tid'] = $pais;
  $node->field_direcciones_ciudad[$node->language][0]['value'] = $ciudad;
  $edit['field_usuario_correo'][LANGUAGE_NONE][0]['value'] = $email;
  $edit['field_usuario_telefono_otro'][LANGUAGE_NONE][0]['value'] = $telefono;
  node_save($node);
  user_save($u,$edit);
  
  $persona=get_persona($uid);
  return $persona;
}


function insert_cuenta($uid,$alias,$tipo,$banco,$cuenta,$titular,$clabe){
  if($uid == 0)
      return false;
  $node = new stdClass();
  $node->language = LANGUAGE_NONE;
  $node->type = "cuenta_de_deposito";
  node_object_prepare($node);
  $node->uid = $uid;
  $node->status = 1; //(1 or 0): publicado automaticamente
  $node->promote = 0; //(1 or 0): desabilitado para página principal
  $node->comment = 0; // comentarios sobre el nodo deshabilitados
  $node->field_cuenta_alias[$node->language][0]['value'] = $alias;
  $node->field_cuenta_tipo[$node->language][0]['value'] = $tipo;
  $node->field_cuenta_nombre_banco[$node->language][0]['value'] = $banco;
  $node->field_cuenta_numero[$node->language][0]['value'] = $cuenta;
  $node->field_cuenta_nombre_titular[$node->language][0]['value'] = $titular;
  $node->field_cuenta_clabe[$node->language][0]['value'] = $clabe;
  node_save($node);
  
  $cuentas=get_cuenta($uid);
  return $cuentas;
}

function insert_informacion_profesional($uid,$empresa,$puesto,$eactual,$fechaini,$fechafin){
  if($uid == 0)
      return false;
  $edit=array();
  $u=user_load($uid);
  $edit['field_usuario_empresa'][LANGUAGE_NONE][0]['value'] = $empresa;
  $edit['field_usuario_puesto'][LANGUAGE_NONE][0]['value'] = $puesto;
  $edit['field_usuario_empleo_actual'][LANGUAGE_NONE][0]['value'] = $eactual;
  $edit['field_usuario_periodo_tiempo'][LANGUAGE_NONE][0]['value'] = $fechaini;
  $edit['field_usuario_periodo_tiempo'][LANGUAGE_NONE][0]['value2'] = $fechafin;

  user_save($u,$edit);
  
  $profesional=get_informacion_profesional($uid);
  return $profesional;
}

function insert_informacion_academica($uid,$escuela,$titulo,$tipo,$cursando){
  if($uid == 0)
      return false;
  $edit=array();
  $u=user_load($uid);
  $edit['field_usuario_escuela'][LANGUAGE_NONE][0]['value'] = $escuela;
        $edit['field_usuario_titulo_estudios'][LANGUAGE_NONE][0]['value'] = $titulo;
        $edit['field_usuario_tipo_estudio'][LANGUAGE_NONE][0]['value'] = $tipo;
        $edit['field_usuario_cursando'][LANGUAGE_NONE][0]['value'] = $cursando;
  user_save($u,$edit);
  
  $academica=get_informacion_academica($uid);
  return $academica;
}

function insert_paypal($uid,$paypal){
  if($uid == 0)
      return false;
  $edit=array();
  $u=user_load($uid);
  $edit['field_usuario_paypal'][LANGUAGE_NONE][0]['value']  = $paypal;
  user_save($u,$edit);
  
  $paypal=get_paypal($uid);
  return $paypal;
}

function delete_node($nid){
  if($nid == 0)
      return false;
  node_delete($nid); 
  
}



  

 