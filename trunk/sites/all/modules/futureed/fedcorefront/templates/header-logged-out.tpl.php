

<div class="static-width" id="header-container">
  <div class="static-width" id="header-invitacion-suscribete"  >
    <div class="row">
	 <?=t('Crea tus propios cursos de manera sencilla en el taller de producción de FutureED ¡REGISTRATE ES GRATIS!');?>
	 <div id="close-invitacion-header" onclick="ocultarBannerHeader();">X</div>
    </div>
    
  </div> 
  <div class="static-width" id="main-menu-container">
      <div class="row" >
	    <div class="small-6 columns" >
	      <div class="row">
		  <div class="small-3 columns" id="contenedor-logo-header"><img src="<?php echo base_path()  .drupal_get_path('module','fedcorefront') .'/images/logo-FED.svg' ?>"></div>
		  <div id="main-menu" class="small-9 columns" >
			  <span class="menu-link"><?= t('CURSOS'); ?></span>
			  <span class="menu-link"><?= t('TIENDA'); ?></span>
			  <span class="menu-link"><?= t('COMUNIDAD'); ?></span>
			  <span class="menu-link menu-link-last"><?= t('NOTICIAS'); ?></span>
		  </div> 
	      </div>
	    </div>    
	    
	    <div class="small-1 columns no-margin  small-offset-4" >
		<div class="row">
		    <div class="small-3 columns  no-margin" >
			<div class="btn-header-icons " id="btn-carrito-logout"></div>
			<div class="conteo-notificaciones conteo-inactivo"  id="conteo-carrito"><?=$items['cantidad_carrito'];?></div>
		    </div>
		    <div class="small-9 columns no-margin"  >
			<div id="btn-iniciar-sesion" onclick="mostrarModalNotificaciones('modal-user-login-form');">
			    INICIAR <br>SESIÓN
			</div>    
			<div id="modal-user-login-form">
			  <?php
			    //drupal_render(  drupal_get_form('user_login_block'));
			    print(drupal_render(drupal_get_form('user_login')));
			  ?>  
			</div>			
			
		    </div>
		</div>				
	    </div>	
	    
	    <div class="small-1 columns no-margin"  >
		    <div class="btn-standard  ">Registrarme</div>
	    </div>	
      </div>
  </div>
</div>



   
<script>
  $( document ).ready(function() {    
       document.getElementById('main-container').className = 'main-cointainer-margin-top-invitacion';
  });  
 
</script>