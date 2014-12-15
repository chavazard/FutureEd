<?php
  $estiloConteoInactivo = 'conteo-inactivo';
  //$estiloConteoInactivo = '';
  $displayConteoNotificaciones = $estiloConteoInactivo;
  $displayConteoCarrito = $estiloConteoInactivo;
  $displayConteoWishlist = $estiloConteoInactivo;
  if (isset($items)){
    if ($items['cantidad_notificaciones'] != null && $items['cantidad_notificaciones'] != 0)
      $displayConteoNotificaciones = '';
      
    if ($items['cantidad_carrito'] != null && $items['cantidad_carrito'] != 0)
      $displayConteoCarrito = '';
      
    if ($items['cantidad_wishlist'] != null && $items['cantidad_wishlist'] != 0)
      $displayConteoWishlist = '';                
  }
?>
<div class="static-width" id="header-container">
  <div class="static-width" id="main-menu-container">
    
    <div class="row" >
	  <div class="small-6 columns" >
	    <div class="row">
		<div class="small-3 columns" id="contenedor-logo-header"><a href="<?= base_path();?>"><img src="<?php echo base_path()  .drupal_get_path('module','fedcorefront') .'/images/logo-FED.svg' ?>"></a></div>
		<div id="main-menu" class="small-9 columns" > <!-- main-menu -->
			<a class="menu-link" href="<?= base_path().drupal_get_path_alias('cursos');?>"><?= t('CURSOS'); ?></a><!--/span-->
			<span class="menu-link"><?= t('TIENDA'); ?></span>
			<span class="menu-link"><?= t('COMUNIDAD'); ?></span>
			<span class="menu-link menu-link-last"><?= t('NOTICIAS'); ?></span>
		</div> <!-- main menu -->
	    </div>
	  </div>    
	  
	  <div class="small-6 columns no-margin" >
	      <div class="row">
		<div class="small-5 columns no-margin" >

			<!-- Colocar nuevo campo Busqueda -->
		    
		    <div class="contenedor-textfield right" id="contenedor-buscar-header">
		      <input placeholder="Buscar..."  type="text-field" id="textfield-buscar-header"
			     onfocus="jQuery('#contenedor-buscar-header').addClass('contenedor-textfielactivo');"
			     onblur="jQuery('#contenedor-buscar-header').removeClass('contenedor-textfielactivo');"
			     onkeypress="call_busqueda(event)" >
		    </div>

		    <!--**-->

		</div>
		<div class="small-5 columns no-margin" >
		    <div class="row">	      
		      <div class="small-5 columns no-margin" >
			  <div class="row">
			      <div class="small-8 columns no-margin" id="contenedor-thumbnail-header" >
				  <img class="thumbnail-avatar" src="<?php echo base_path()  .drupal_get_path('module','fedcorefront') .'/images/thumbnails/t-avatar.jpg' ?> ">
			      </div>
			      <div class="small-4 columns " >
				  <div id="btn-header-perfil" onclick="mostrarModalNotificaciones('modal-opciones-perfil');"></div>
				  <div id="modal-opciones-perfil">
				     Opciones de perfil<br>
				     <a href='user/logout'>logout</a>
				  </div> 			  
			      </div>
			  </div>
		      </div>
		      <div class="small-7 columns " >
			  <div class="btn-header-icons" id="btn-notificaciones" onclick="mostrarModalNotificaciones('modal-notificaciones');"></div>
			  <div class="conteo-notificaciones <?=$displayConteoNotificaciones?>" id="conteo-notificaciones"><?=$items['cantidad_notificaciones'];?></div>
			  
			  <div id="modal-notificaciones">
			     Notificaciones recientes 1                
			  </div> 		  
			  
			  <div class="btn-header-icons" id="btn-carrito"></div>
			  <div class="conteo-notificaciones <?=$displayConteoCarrito?>"  id="conteo-carrito"><?=$items['cantidad_carrito'];?></div>
			  
			  <div class="btn-header-icons" id="btn-wishlist"></div>
			  <div class="conteo-notificaciones <?=$displayConteoWishlist?>" id="conteo-wishlist"><?=$items['cantidad_wishlist'];?></div>
		      </div>
		    </div>
		</div>
		
		<div class="small-2 columns end right no-margin"  >
		    <div class="btn-standard" onclick="window.location = '<?php Global $base_url; echo $base_url.'/cursonuevo/'; ?>'";><?= CREAR_CURSO_HEADER; ?></div>	    	    
		</div>	      
		
		
	      </div>  
	  </div>
    </div>
  </div>
</div>
  
<script>
  $( document ).ready(function() {    
       document.getElementById('main-container').className = 'main-cointainer-margin-top';
  });  
 
 function call_busqueda(event)
 {
    if (event.keyCode == 13)
    {
      window.location.href = "busqueda/?busqueda=" + document.getElementById('textfield-buscar-header').value;
    }
 }
 
 function call_busqueda_home(event)
 {
    if (event.keyCode == 13)
    {
      window.location.href = "busqueda/?busqueda=" + document.getElementById('textfield-buscar-header-home').value;
    }
 }
 
</script>