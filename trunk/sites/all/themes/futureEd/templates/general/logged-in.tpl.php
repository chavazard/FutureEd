<?php
  $variables['logo_loggedin_size']          = 'small-2 medium-2 large-2 columns';
  $variables['menu_loggedin_size']          = 'small-4 medium-4 large-4 columns';
  $variables['buscar_loggedin_size']        = 'small-1 medium-1 large-1 columns';
  $variables['perfil_loggedin_size']        = 'small-1 medium-1 large-1 columns';
  $variables['botones_loggedin_size']       = 'small-3 medium-3 large-3 columns';
  $variables['crear_curso_loggedin_size']   = 'small-1 medium-1 large-1 columns';
  
  $variables['logo_loggedout_size']          = 'small-2 medium-2 large-2 columns';
  $variables['menu_loggedout_size']          = 'small-4 medium-4 large-4 columns';
  $variables['buscar_loggedout_size']        = 'small-1 medium-1 large-1 columns';
  $variables['botones_loggedout_size']       = 'small-4 medium-4 large-4 columns';
  $variables['crear_curso_loggedout_size']   = 'small-1 medium-1 large-1 columns';  

?>


<!--- INCLUYENDO ROW hace que no abarque toda la pantalla ---->
<div class="top-bar"<?php print $top_bar_options; ?>>
  <div class="row" >
        <div class="small-2 medium-2 large-2 columns">
          <ul class="title-area">
            <li class="name"><h1>LOGO</h1></li>            
          </ul>
        </div>
        <div class="small-3 medium-3 large-3 columns top-bar-section">
          
                <!---- INICIO MENU SUP --->
                <?php if ($top_bar_main_menu) :?>
                  <?php print $top_bar_main_menu; ?>
                <?php endif; ?>
                <!---- FIN MENU SUP --->
        </div>      
        <div class="small-3 medium-3 large-3 columns ">
          
                  <input type="text-field" style="width: 100px;">
                <img src="<?php echo base_path() . path_to_theme() . '/images/thumbnail-perfil.jpg' ?>">
                <a href="#" id="expandir-perfil">
                  <img src="<?php echo base_path() . path_to_theme() . '/images/btn-expand-perfil.gif' ?>" >
                </a>                    
        </div>
    

        <div class="small-2 medium-2 large-2 columns" id="contenedor-botones-header" >                
                
                
                <div class="btn-notificaciones">
                  <a href="javascript:mostrarModalNotificaciones('modal-notificaciones')" id="notificaciones1" onclick="" >
                    <img src="<?php echo base_path() . path_to_theme() . '/images/btn-notificaciones.gif'; ?>" >
                  </a>
                </div>
                
                <div class="conteo-notificaciones" id="conteo-notificaciones">1</div>
    
                <div id="modal-notificaciones">
                   Notificaciones recientes 1                
                </div>                      
                
                <div class="btn-notificaciones" id="btn-carrito" >
                  <a href="#" id="notificaciones2" >
                    <img src="<?php echo base_path() . path_to_theme() . '/images/btn-carrito.gif'; ?>" >
                  </a>
                </div>
                                                                                              
                <div class="conteo-notificaciones" id="conteo-carrito">2</div>             
                
                <div class="btn-notificaciones" id="btn-wishlist">
                  <a href="#" id="notificaciones3" >
                    <img src="<?php echo base_path() . path_to_theme() . '/images/btn-wishlist.gif'; ?>" >
                  </a>
                </div>
    
                <div class="conteo-notificaciones" id="conteo-wishlist">3</div>
        </div>

        <div class="small-2 medium-2 large-2 columns top-bar-section">    
                <a href="#" id="crear-curso">
                  Crear curso
                </a>
                <a href="/drupal-tema/user/logout" id="crear-curso">
                  X
                </a>                      
        </div>
  </div>
</div>