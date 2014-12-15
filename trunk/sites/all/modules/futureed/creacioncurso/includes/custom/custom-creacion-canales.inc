<?php

/*------------------ Creacion Curso - Consultar Mis Canales ------------------*/

function consultar_seleccionar_mis_canales_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 1',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal1',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 2',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal2',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 3',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal3',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 4',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal4',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 5',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal5',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 6',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal6',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 7',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal7',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 8',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'cana8',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 9',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal9',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 10',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal10',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 11',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal11',
    )
  );
  $totalResultados = sizeof($arrResultados);
        
  $indiceDevueltos = 1;
  
  $arrRegresar = array();
  $arrTemporal = array();
  
  foreach($arrResultados as $item){ 

      if ($indiceDevueltos >= $limite_inicial && $indiceDevueltos <= $limite_final)
      {
          array_push($arrTemporal, $item);
      }

      $indiceDevueltos++;
  } 
  
  array_push($arrRegresar,array(
    'totalResultados' => $totalResultados,
    'items' => $arrTemporal
  ));
  
  return $arrRegresar;  
}




function consultar_seleccionar_canales_administrar_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 11',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal11',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 12',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal12',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 13',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal13',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 14',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal14',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 15',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal15',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 16',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal16',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 17',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal17',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 18',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal18',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 19',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal19',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 20',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal20',
    ),
    array(
      'nid' => '2',
      'field_canal_imagen' => 'http://placehold.it/100x50',
      'field_canal_nombre' => 'Titulo de Canal 21',
      'calc_creador_nombre' => 'CEDIM',
      'link_creador_canal' => 'canal21',
    )
  );

  $totalResultados = sizeof($arrResultados);
        
  $indiceDevueltos = 1;
  
  $arrRegresar = array();
  $arrTemporal = array();
  
  foreach($arrResultados as $item){ 

      if ($indiceDevueltos >= $limite_inicial && $indiceDevueltos <= $limite_final)
      {
          array_push($arrTemporal, $item);
      }

      $indiceDevueltos++;
  } 
  
  array_push($arrRegresar,array(
    'totalResultados' => $totalResultados,
    'items' => $arrTemporal
  ));
  
  return $arrRegresar;   
}