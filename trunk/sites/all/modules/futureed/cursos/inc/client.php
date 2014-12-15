<?php
    /*Archivo de control de llamadas de funciones*/
    /*$_POST['ws_serv'] = 'logIn';*/
    
    
    if (isset($_POST['ws_serv']))
      {
        
        $option = $_POST['ws_serv'];
        
        switch($option)
                    {
                     //CASE PARA LOGIN
                     
                      case 'cargar_proyectos_cursos':
                                  echo drupal_get_path('module', 'cursos');
                                  /*
                                  $result = array();	
                                  if(isset($_POST['user']))
                                          $keyid = $_POST['user'];
                                  else
                                          $keyid = '';

                                  require_once ('inc_cursos.php');
                                  $userClient = new systemClass();
                                  $result = $userClient ->logIn($keyid, $pwd);
                                  unset($userClient);
                                  //$result = $userClient->Login($keyid, $pwd);
                                  echo json_encode($result);
                                  
                                  */
                          break;
                    }
      }              

    
?>