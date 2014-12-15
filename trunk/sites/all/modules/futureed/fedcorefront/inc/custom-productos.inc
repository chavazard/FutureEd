<?php

/*----------------------- Carrusel - Productos -----------------------*/
function consultar_carrusel_productos($nid_producto){
  $arrResultados = array();

  array_push($arrResultados,
    array(
      array(
        'field_producto_imagen' => 'http://placehold.it/100x100',
        'field_producto_titulo' => 'Producto 1',
        'link_producto' => 'producto/producto1',
        'field_producto_empresa' => 'Playful',
        'link_creador' => 'usuario/empresa1',
        'field_producto_categoria' => 'Educacion',
        'link_categoria' => 'categoria/categoria1',
        'field_producto_calificacion' => '5 Estrellas',
        'field_producto_likes' => '10',
      ),
      array(
        'field_producto_imagen' => 'http://placehold.it/100x100',
        'field_producto_titulo' => 'Producto 2',
        'link_producto' => 'producto/producto2',
        'field_producto_empresa' => 'Playful',
        'link_creador' => 'usuario/empresa2',
        'field_producto_categoria' => 'Educacion',
        'link_categoria' => 'categoria/categoria2',
        'field_producto_calificacion' => '5 Estrellas',
        'field_producto_likes' => '10',
      ),
      array(
        'field_producto_imagen' => 'http://placehold.it/100x100',
        'field_producto_titulo' => 'Producto 3',
        'link_producto' => 'producto/producto3',
        'field_producto_empresa' => 'Playful',
        'link_creador' => 'usuario/empresa3',
        'field_producto_categoria' => 'Educacion',
        'link_categoria' => 'categoria/categoria3',
        'field_producto_calificacion' => '5 Estrellas',
        'field_producto_likes' => '10',
      ),
      array(
        'field_producto_imagen' => 'http://placehold.it/100x100',
        'field_producto_titulo' => 'Producto 4',
        'link_producto' => 'producto/producto4',
        'field_producto_empresa' => 'Playful',
        'link_creador' => 'usuario/empresa4',
        'field_producto_categoria' => 'Educacion',
        'link_categoria' => 'categoria/categoria4',
        'field_producto_calificacion' => '5 Estrellas',
        'field_producto_likes' => '10',
      ),
      array(
        'field_producto_imagen' => 'http://placehold.it/100x100',
        'field_producto_titulo' => 'Producto 5',
        'link_producto' => 'producto/producto5',
        'field_producto_empresa' => 'Playful',
        'link_creador' => 'usuario/empresa5',
        'field_producto_categoria' => 'Educacion',
        'link_categoria' => 'categoria/categoria5',
        'field_producto_calificacion' => '5 Estrellas',
        'field_producto_likes' => '10',
      )
    )
  );    
  return $arrResultados;      
  }