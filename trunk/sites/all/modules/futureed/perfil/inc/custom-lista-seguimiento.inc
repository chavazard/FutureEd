<?php

/*----------------------- Consultar Lista de Seguimiento -----------------------*/

function consultar_usuarios_siguiendo_db($uid, $limite_inicial, $limite_final){
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
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 5',
      'link_usuario' => 'usuario5',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 6',
      'link_usuario' => 'usuario6',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 7',
      'link_usuario' => 'usuario7',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 8',
      'link_usuario' => 'usuario8',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 9',
      'link_usuario' => 'usuario9',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 10',
      'link_usuario' => 'usuario10',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 11',
      'link_usuario' => 'usuario11',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 12',
      'link_usuario' => 'usuario12',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 13',
      'link_usuario' => 'usuario13',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 14',
      'link_usuario' => 'usuario14',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 15',
      'link_usuario' => 'usuario15',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 16',
      'link_usuario' => 'usuario16',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 17',
      'link_usuario' => 'usuario17',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 18',
      'link_usuario' => 'usuario17',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 19',
      'link_usuario' => 'usuario19',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 20',
      'link_usuario' => 'usuario20',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Ana Karen Moreno Salas 21',
      'link_usuario' => 'usuario21',
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






function consultar_usuarios_seguidores_db($uid, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 1',
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
      'calc_usuario_nombre' => 'Rene Camacho 2',
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
      'calc_usuario_nombre' => 'Rene Camacho 3',
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
      'calc_usuario_nombre' => 'Rene Camacho 4',
      'link_usuario' => 'usuario4',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 5',
      'link_usuario' => 'usuario5',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 6',
      'link_usuario' => 'usuario6',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 7',
      'link_usuario' => 'usuario7',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 8',
      'link_usuario' => 'usuario8',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 9',
      'link_usuario' => 'usuario9',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 10',
      'link_usuario' => 'usuario10',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 11',
      'link_usuario' => 'usuario11',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 12',
      'link_usuario' => 'usuario12',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 13',
      'link_usuario' => 'usuario13',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 14',
      'link_usuario' => 'usuario14',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 15',
      'link_usuario' => 'usuario15',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 16',
      'link_usuario' => 'usuario16',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 17',
      'link_usuario' => 'usuario17',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 18',
      'link_usuario' => 'usuario18',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 19',
      'link_usuario' => 'usuario19',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 20',
      'link_usuario' => 'usuario20',
      'field_usuario_numero_seguidores' => '230',
      'field_usuario_numero_seguidos' => '300',
    ),
    array(
      'field_usuario_imagen' => 'http://placehold.it/150x150',
      'icono_1' => 'http://placehold.it/20x20',
      'icono_2' => 'http://placehold.it/20x20',
      'icono_3' => 'http://placehold.it/20x20',
      'icono_4' => 'http://placehold.it/20x20',
      'calc_usuario_nombre' => 'Rene Camacho 21',
      'link_usuario' => 'usuario21',
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