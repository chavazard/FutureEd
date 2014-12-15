<!--
<div class="contenedor-textfield" id="contenedor-buscar-header">
	<input placeholder="Buscar..."  type="text-field" id="textfield-buscar-header" onfocus="jQuery('#contenedor-buscar-header').addClass('contenedor-textfielactivo');" onblur="jQuery('#contenedor-buscar-header').removeClass('contenedor-textfielactivo');" >
</div>
-->
<div class="row">
	<div class="small-6 columns">
		<div class="small-5 columns no-margin" >

			<!-- Colocar nuevo campo Busqueda -->
		    
		    <div class="contenedor-textfield right" id="contenedor-buscar-header">
		      <input placeholder="Buscar..."  type="text-field" id="textfield-buscar-header-home"
			     onfocus="jQuery('#contenedor-buscar-header').addClass('contenedor-textfielactivo');"
			     onblur="jQuery('#contenedor-buscar-header').removeClass('contenedor-textfielactivo');"
			     onkeypress="call_busqueda_home(event)" >
		    </div>

		    <!--**-->

		</div>
		<?php print drupal_render($home_busqueda);?>
	</div>
	<div class="small-6 columns">
		<div class="small-6 columns">boton lupa</div>
		<?php
		if ($btn_categorias == TRUE){ ?>
			<div onclick="mostrarElemento('contenedor_categorias', true);" class="small-6 columns">boton categorias</div>
			<div id="contenedor_categorias" style="display: none"></div>
		<?php }?>
	</div>
</div>

<script type="text/javascript">
	callAjax('contenedor_categorias','show_busqueda_categorias',null);
</script>
