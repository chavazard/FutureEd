<nav class="top-bar-registrate"<?php print $top_bar_options; ?>>
  <div class="row">
    crea tu propio canal... <a href="#">Registrate</a>
  </div>
</nav>          

<!--- INCLUYENDO ROW hace que no abarque toda la pantalla ---->
<div class="top-bar"<?php print $top_bar_options; ?>>
  <div class="row">

          <div class="small-2 medium-2 large-2 columns">
            <ul class="title-area">
              <li class="name"><h1>LOGO</h1></li>             
            </ul>
          </div>
          <div class="small-4 medium-4 large-4 columns top-bar-section">
            
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
                  <div id="modal-notificaciones">
                     Notificaciones recientes 1                
                  </div>                      
                  
                  <div class="btn-notificaciones" id="btn-carrito-logout" >
                    <a href="#" id="notificaciones2" >
                      <img src="<?php echo base_path() . path_to_theme() . '/images/btn-carrito.gif'; ?>" >
                    </a>
                  </div>
                                                                                                
                  <div class="conteo-notificaciones" id="conteo-carrito-logout">2</div>             
                  
                  <div class="btn-notificaciones" id="btn-wishlist-logout">
                    <a href="#" id="notificaciones3" >
                      <img src="<?php echo base_path() . path_to_theme() . '/images/btn-wishlist.gif'; ?>" >
                    </a>
                  </div>
      
                  <div class="conteo-notificaciones" id="conteo-wishlist-logout">3</div>
          </div>
  
          <div class="small-1 medium-1 large-1 columns top-bar-section">    
                  <a href="#" id="crear-curso">
                    Crear curso
                  </a>
                  <a href="/drupal-tema/user/logout" id="crear-curso">
                    X
                  </a>                      
          </div>


    
  </div>  
</div>