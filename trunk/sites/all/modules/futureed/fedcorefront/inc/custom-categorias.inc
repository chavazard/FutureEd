<?php

/*----------------------- Categorias -----------------------*/
function consultar_categorias($nid_categoria){
  //var_dump($nid_categoria);
  $data = '?f_name=get_todas_categorias&vid=2';
  $data = get_data_from_service($data, false);
  //print_r($data);
  
  $arrResultados = array();
  array_push($arrResultados, $data
    /*array(
      'categoria' => $data,//l('Administracion','#'),
      'subcategoria' => array(
        'subcategoria1' => l('Administracion1','subcategoria.com'),
        'subcategoria2' => l('Administracion2', 'subcategoria.com'),
      )
    ),
    array(
      'categoria' => l('Arte','#'),
      'subcategoria' => array(
        'subcategoria1' => l('Arte1','subcategoria.com'),
        'subcategoria2' => l('Art2', 'subcategoria.com'),
      )
    ),
    array(
      'categoria' => l('Ciencias','#'),
      'subcategoria' => array(
        'subcategoria1' => l('Ciencas1','subcategoria.com'),
        'subcategoria2' => l('Ciencias2', 'subcategoria.com'),
      )
    ),
    array(
      'categoria' => l('Derecho','#'),
      'subcategoria' => array(
        'subcategoria1' => l('Derecho1','subcategoria.com'),
        'subcategoria2' => l('Derecho2', 'subcategoria.com'),
      )
    )*/
  );  
  return $arrResultados;   
}