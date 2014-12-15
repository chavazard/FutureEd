<?php

/*----------------------- Consultar Usuarios Sugeridos -----------------------*/

function consultar_item_usuarios_sugeridos_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 1',
      'link_usuario' => 'usuario1',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 2',
      'link_usuario' => 'usuario2',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 3',
      'link_usuario' => 'usuario3',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 4',
      'link_usuario' => 'usuario4',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
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