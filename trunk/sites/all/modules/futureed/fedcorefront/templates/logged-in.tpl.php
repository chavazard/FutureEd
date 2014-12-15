<!--- INCLUYENDO ROW hace que no abarque toda la pantalla ---->
<div class="top-bar" id="header-container">
  <div class="static-width" id="main-menu-container">
      <div class="row" >
            <div class="small-2 medium-2 large-2 columns">
              <ul class="title-area">
                <li class="name"><h1>LOGO</h1></li>            
              </ul>
            </div>
            <div class="small-3 medium-3 large-3 columns top-bar-section">
              
                    <!---- INICIO MENU SUP --->
                    <?php //if ($top_bar_main_menu) :?>
                      <?php //print $top_bar_main_menu; ?>
                    <?php //endif; ?>
                    <!---- FIN MENU SUP --->
            </div>      
            <div class="small-3 medium-3 large-3 columns ">
                      <input type="text-field" style="width: 100px;">
                    <img src="<?php echo base_path() . 'sites/all/themes/futureEd/images/thumbnail-perfil.jpg' ?>">
                    <a href="#" id="expandir-perfil">
                      <img src="<?php echo base_path() . 'sites/all/themes/futureEd/images/btn-expand-perfil.gif' ?>" >
                    </a>                    
            </div>
        
    
            <div class="small-2 medium-2 large-2 columns" id="contenedor-botones-header" >                
                    
                    
                    <div class="btn-notificaciones">
                      <a href="javascript:mostrarModalNotificaciones('modal-notificaciones')" id="notificaciones1" onclick="" >
                        <img src="<?php echo base_path() . 'sites/all/themes/futureEd/images/btn-notificaciones.gif'; ?>" >
                      </a>
                    </div>
                    
                    <div class="conteo-notificaciones" id="conteo-notificaciones">1</div>
        
                    <div id="modal-notificaciones">
                       Notificaciones recientes 1                
                    </div>                      
                    
                    <div class="btn-notificaciones" id="btn-carrito" >
                      <a href="#" id="notificaciones2" >
                        <img src="<?php echo base_path() . 'sites/all/themes/futureEd/images/btn-carrito.gif'; ?>" >
                        <!---<img src="<?php //echo base_path() . 'sites/all/themes/futureEd/images/nubecita.svg'; ?>" >-->
                      </a>
                    </div>
                                                                                                  
                    <div class="conteo-notificaciones" id="conteo-carrito">2</div>             
                    
                    <div class="btn-notificaciones" id="btn-wishlist">
                      <a href="#" id="notificaciones3" >
                        
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
</div>

<script>
  $( document ).ready(function() {
       document.getElementById('main-container').className = "main-cointainer-margin-top";
  });  
</script>
