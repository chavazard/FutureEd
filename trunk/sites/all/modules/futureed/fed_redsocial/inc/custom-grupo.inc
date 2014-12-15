<?php
/*Cursos Comprados*/
//$global = $user;
function show_mis_grupos($nid_curso, $pagina, $div_contenedor){

 

  //$items = consultar_grupo_detalle_db($idGrupo);
  //$items = consultar_canal_db($nid_canal);
  //return theme('grupo-detalle', array('item' => $items));

  $nid_curso = 0;
  $resultadosPorPagina = 8;
  $resultadosPorLinea = 4;

  if ($pagina == null)
      $pagina = 1;

  $lim_ini = (($pagina - 1)* $resultadosPorPagina) + 1;
  $lim_fin = $pagina * $resultadosPorPagina;

  $items = consultar_mis_grupos_db($nid_curso, $lim_ini, $lim_fin);
  $itemsProyectos = $items[0]['items'];

  $theme_individual = 'mis_grupos';

  mostrar_listado($resultadosPorLinea, $resultadosPorPagina, $itemsProyectos,  $theme_individual);

  //Paginación
  $f_name = 'show_mis_grupos'; 
  $parametros = 'nid_curso: '.$nid_curso;
  $tema_paginacion = 'paginacion';
    
  $totalResultados = $items[0]['totalResultados']; 

  mostrar_paginacion($resultadosPorPagina,$itemsProyectos,$totalResultados,$f_name,$parametros,$div_contenedor,$tema_paginacion, $pagina);
}

/*Cursos Comprados*/
function show_grupos_administrados($nid_curso, $pagina, $div_contenedor){
  $nid_curso = 0;
  $resultadosPorPagina = 8;
  $resultadosPorLinea = 4;

  if ($pagina == null)
      $pagina = 1;

  $lim_ini = (($pagina - 1)* $resultadosPorPagina) + 1;
  $lim_fin = $pagina * $resultadosPorPagina;

  $items = consultar_grupos_administrados_db($nid_curso, $lim_ini, $lim_fin);
  $itemsProyectos = $items[0]['items'];

  $theme_individual = 'grupos_administrados';

  mostrar_listado($resultadosPorLinea, $resultadosPorPagina, $itemsProyectos,  $theme_individual);

  //Paginación
  $f_name = 'show_grupos_administrados'; 
  $parametros = 'nid_curso: '.$nid_curso;
  $tema_paginacion = 'paginacion';
    
  $totalResultados = $items[0]['totalResultados']; 

  mostrar_paginacion($resultadosPorPagina,$itemsProyectos,$totalResultados,$f_name,$parametros,$div_contenedor,$tema_paginacion, $pagina);
}

function show_grupo_detalle($idGrupo, $trigger, $destino="none"){

  $miembros = array();
  $miembros['trigger']=$trigger;
  $miembros['destino']=$destino;
  $miembros['idGrupo']=$idGrupo;
  $miembros['perteneciente']=get_usuarioPerteneceGrupo(1,1);//Índice para determinar si el usuario que está logueado actualmente pertenece al grupo que se está cargando
  $miembros['usuario']=1;//El usuario que está cargado actualmente
  $miembros['detalles'] = consultar_miembros_grupo_db($idGrupo);
  $items = consultar_grupo_detalle_db($idGrupo);

  ?>
  <div class="row">
    <?php print theme('grupo-miembros', array('miembros' => $miembros)); ?>
    <?php print theme('grupo-detalle', array('item' => $items)); ?>
  </div>
  <?php
}

function consultar_mis_grupos_db($nid_curso, $limite_inicial, $limite_final){

  $arrResultados = array();
  for($i=0;$i<=8;$i++){
    array_push($arrResultados,
      array(
        'idGrupo' => $i,
        'imagen' => 'http://placehold.it/230x150',
        'imagenSecundaria' => 'http://placehold.it/35x35',
        'titulo' => $per,
        'canal' => 'CEDIM',
        'tutor' => 'Eduardo Salas',
        'tipoGrupo' => 'Privado',
        'ultimaActividad' => '01/01/2015',
        'miembros' => '25 miembros',
        'categoria' => l('Nombre categoria','categoria/3'),
        'pathRedireccion' => 'grupo/'.$i,
      )
    ); 
  } 
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

function consultar_grupos_administrados_db($nid_curso, $limite_inicial, $limite_final){

  $arrResultados = array();

  $per='';
  for ($i=0;$i<=8;$i++){
    $per.='Perspectiva de los niños ';
    array_push($arrResultados,
      array(
        'idGrupo' => $i,
        'imagen' => 'http://placehold.it/230x150',
        'imagenSecundaria' => 'http://placehold.it/35x35',
        'titulo' => $per,
        'canal' => 'CEDIM',
        'tutor' => 'Eduardo Salas',
        'tipoGrupo' => 'Privado',
        'ultimaActividad' => '01/01/2015',
        'miembros' => '25 miembros',
        'categoria' => l('Nombre categoria','categoria/3'),
        'pathRedireccion' => 'grupo/'.$i,
      )
    ); 
  } 

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



function consultar_grupo_detalle_db($nid_grupo){

  $arrResultados=
    array(
      'imagen' => 'http://placehold.it/728x150',
      'titulo' => 'grupote ',
      'secreto' => true,
      'descripcion' => 'texto texto texto texto texto texto texto texto texto texto texto texto texto 
                        texto texto texto texto texto texto texto texto texto texto texto texto texto 
                        texto texto texto texto texto texto texto texto texto texto texto texto texto 
                        texto texto texto texto texto texto texto texto texto texto texto texto texto ',
      'categoria' => 'Cienias sociales',
      'subcategoria' => 'Historia',
      'miembros' => '25',
      'privacidad' => 'Público',
    );
  return $arrResultados;   
}


function consultar_miembros_grupo_db($nid_grupo){

  $arrResultados = array();

  for($i=0;$i<=8;$i++){
    array_push($arrResultados,
      array(
        'imagen' => 'http://placehold.it/40x40',
        'nombre' => 'nombre usuario =) '.$i,
        'usuario' => $i,
        'link' => l('usuario', 'usuario/'.'usuario'),
        'admin' => $i%2==0?false:true,
      )
    ); 
  }
  return $arrResultados;
}


/**
* Función para definir si un usuario pertenece a un grupo determinado
*
*/
function get_usuarioPerteneceGrupo($usuario,$grupo){


  return false;
}

/**
* Función para inscribir un usuario a un grupo determinado
*
*/
function inscribir_usuario_grupo($usuario,$grupo){

  return true;

}

function reportar_grupo($grupo){

  return true;

}


/****
 * Función que trae los grupos al que pertenece un usuario
 *
 */

 function consultar_grupos_usuario_db($uid_usuario){
    $arrResultados = array();

    array_push($arrResultados,
            array(
                
                'field_usuario_privacidad_grupos' => 1,
                'calc_usuario_nombre' => 'Esteban Patiño',
                'array_grupos' =>array(
                              
                             array(
                                  'nid' => 1,
                                  'field_grupo_nombre' => 'Grupo 1',
                                  'field_grupo_imagen' => 'http://placehold.it/200x200',
                                  'link_grupo' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 2,
                                  'field_grupo_nombre' => 'Grupo 2',
                                  'field_grupo_imagen' => 'http://placehold.it/200x200',
                                  'link_grupo' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 3,
                                  'field_grupo_nombre' => 'Grupo 3',
                                  'field_grupo_imagen' => 'http://placehold.it/200x200',
                                  'link_grupo' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 4,
                                  'field_grupo_nombre' => 'Grupo 4',
                                  'field_grupo_imagen' => 'http://placehold.it/200x200',
                                  'link_grupo' => 'canal/canal1'
                                  ),
                             array(
                                  'nid' => 5,
                                  'field_grupo_nombre' => 'Grupo 5',
                                  'field_grupo_imagen' => 'http://placehold.it/200x200',
                                  'link_grupo' => 'canal/canal1'
                                  )
                             )                
            )
          );    
    return $arrResultados;      
}
 
 