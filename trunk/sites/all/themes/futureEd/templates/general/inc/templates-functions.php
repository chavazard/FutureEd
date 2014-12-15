<?php

  function obtenerTamanoColumnaIzquierda()
  {
    $CONST_PATH_BUSQUEDA = "busqueda";
    
    $TAMANO_PEQUENO = 1;
    $TAMANO_MEDIANO = 2;
    $TAMANO_GRANDE  = 3; 
    
    $current_path_array = explode("/",request_path());
    
    /*Condicion para debug variable de debug*/
    if (isset($GLOBALS['tamano_columna_izquierda_debug']))
      $tamano_columna_izquierda = $GLOBALS['tamano_columna_izquierda_debug'];
    else
    {
      switch ($current_path_array[0])
      {
          case $CONST_PATH_BUSQUEDA:
              $tamano_columna_izquierda = $TAMANO_PEQUENO;
              break;
          default:
              $tamano_columna_izquierda = $TAMANO_GRANDE;
              break;
      }
    }

    if ($tamano_columna_izquierda == $TAMANO_PEQUENO){                              //Busquedas generales
      $GLOBALS['left_sidebar'] = $GLOBALS['left_sidebar_small'];
      $GLOBALS['main_content'] = $GLOBALS['main_content_large'];    
    }else if ($tamano_columna_izquierda == $TAMANO_MEDIANO){                        //
      $GLOBALS['left_sidebar'] = $GLOBALS['left_sidebar_medium'];
      $GLOBALS['main_content'] = $GLOBALS['main_content_medium'];        
    }else if ($tamano_columna_izquierda == $TAMANO_GRANDE){                         //Perfil  
      $GLOBALS['left_sidebar'] = $GLOBALS['left_sidebar_large'];
      $GLOBALS['main_content'] = $GLOBALS['main_content_small'];        
    }    
    
    
    
    
  }
?>