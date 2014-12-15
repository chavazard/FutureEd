<?php

/*------------------------------------------- Consultar Canales -------------------------------------------*/

function consultar_mis_canales_db($nid_canal, $limite_inicial, $limite_final){
  $arrResultados = array();
  //return $arrResultados;
  array_push($arrResultados,
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 1','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 2','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 3','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 4','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 5','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 6','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 7','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 8','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 9','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Medicina 10','canal.com'),
      'categoria' => l('Humanidades','categoria.com'),
      'subcategoria' => l('Medicina','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '10',
      'boton' => 'Ver Canal',
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




function consultar_canales_administrar_db($nid_canal, $limite_inicial, $limite_final){
  $arrResultados = array();
  array_push($arrResultados,
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 1','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 2','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 3','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 4','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 5','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 6','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 7','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 8','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 9','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
    ),
    array(
      'imagen' => 'http://placehold.it/100x50',
      'titulo' => l('Matematicas 10','canal.com'),
      'categoria' => l('Ciencias','categoria.com'),
      'subcategoria' => l('Matematicas','subcategoria.com'),
      'descripcion' => '(texto de descripcion)',
      'totalCursos' => '25',
      'boton' => 'Ver Canal',
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

/* Crear Canal - Consultar Tutores */
function consultar_crear_canal_tutores_db($uid_tutor){
  $arrResultados = array();
  switch ($uid_tutor){
    case '11':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 1'),
        )
      );
    return $arrResultados;
    break;

    case '12':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 2'),
        )
      );
    return $arrResultados;
    break;

    case '13':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 3'),
        )
      );
    return $arrResultados;
    break; 

    case '14':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 4'),
        )
      );
    return $arrResultados;
    break; 

    case '15':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 5'),
        )
      );
    return $arrResultados;
    break; 

    case '16':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 6'),
        )
      );
    return $arrResultados;
    break; 

    case '17':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 7'),
        )
      );
    return $arrResultados;
    break; 

    case '18':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 8'),
        )
      );
    return $arrResultados;
    break; 

    case '19':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 9'),
        )
      );
    return $arrResultados;
    break;

    case '20':
      array_push($arrResultados,
        array(
          'nombre' => t('Tutor 10'),
        )
      );
    return $arrResultados;
    break;
  }
}

/* Crear Canal - Consultar Agregar Cursos */
function consultar_crear_canal_cursos_db($uid_curso){
  $arrResultados = array();
  switch ($uid_curso){
    case '21':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 1'),
        )
      );
    return $arrResultados;
    break;

    case '22':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 2'),
        )
      );
    return $arrResultados;
    break;

    case '23':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 3'),
        )
      );
    return $arrResultados;
    break; 

    case '24':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 4'),
        )
      );
    return $arrResultados;
    break; 

    case '25':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 5'),
        )
      );
    return $arrResultados;
    break; 

    case '26':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 6'),
        )
      );
    return $arrResultados;
    break; 

    case '27':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 7'),
        )
      );
    return $arrResultados;
    break; 

    case '28':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 8'),
        )
      );
    return $arrResultados;
    break; 

    case '29':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 9'),
        )
      );
    return $arrResultados;
    break;

    case '30':
      array_push($arrResultados,
        array(
          'nombre' => t('Curso 10'),
        )
      );
    return $arrResultados;
    break;
  }
}

/* Crear Canal - Consultar Administradores */
function consultar_crear_canal_administradores_db($uid_administrador){
  $arrResultados = array();
  switch ($uid_administrador){
    case '31':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 1'),
        )
      );
    return $arrResultados;
    break;

    case '32':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 2'),
        )
      );
    return $arrResultados;
    break;

    case '33':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 3'),
        )
      );
    return $arrResultados;
    break; 

    case '34':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 4'),
        )
      );
    return $arrResultados;
    break; 

    case '35':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 5'),
        )
      );
    return $arrResultados;
    break; 

    case '36':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 6'),
        )
      );
    return $arrResultados;
    break; 

    case '37':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 7'),
        )
      );
    return $arrResultados;
    break; 

    case '38':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 8'),
        )
      );
    return $arrResultados;
    break; 

    case '39':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 9'),
        )
      );
    return $arrResultados;
    break;

    case '40':
      array_push($arrResultados,
        array(
          'nombre' => t('Administrador 10'),
        )
      );
    return $arrResultados;
    break;
  }
}

