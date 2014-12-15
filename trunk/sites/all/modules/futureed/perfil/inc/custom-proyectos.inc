<?php

/*------------------------------------------- Consultar Proyectos -------------------------------------------*/

function consultar_proyectos_usuario_db($uid_usuario){
    $arrResultados = array();

    array_push($arrResultados,
            array(
                
                'field_usuario_privacidad_proyectos' => 1,
                'calc_usuario_nombre' => 'Esteban Patiño',
                'array_proyectos' =>array(
                              
                             array(
                                  'nid' => 1,
                                  'field_proyecto_nombre' => 'Proyecto 1',
                                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                                  'link_proyecto' => 'proyecto/proyecto1'
                                  ),
                             array(
                                  'nid' => 2,
                                  'field_proyecto_nombre' => 'Proyecto 2',
                                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                                  'link_proyecto' => 'proyecto/proyecto1'
                                  ),
                             array(
                                  'nid' => 3,
                                  'field_proyecto_nombre' => 'Proyecto 3',
                                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                                  'link_proyecto' => 'proyecto/proyecto1'
                                  ),
                             array(
                                  'nid' => 4,
                                  'field_proyecto_nombre' => 'Proyecto 4',
                                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                                  'link_proyecto' => 'proyecto/proyecto1'
                                  ),
                             array(
                                  'nid' => 5,
                                  'field_proyecto_nombre' => 'Proyecto 5',
                                  'field_proyecto_imagen' => 'http://placehold.it/200x200',
                                  'link_proyecto' => 'proyecto/proyecto1'
                                  )
                             )                
            )
          );    
    return $arrResultados;      
}
