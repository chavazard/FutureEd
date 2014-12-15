<div class="active-panel" id="panel-1">
	<div id="titulos">
		<div class="large-4 columns">
			<div id='misgrupos' target="panelB-1" class="row tab-anidado active-tab-anidado" ><?= TITULO_MIS_GRUPOS ?></div>
		</div>
		<div class="large-4 columns">
			<div id='administrados' target="panelB-2" class="row tab-anidado inactive-tab-anidado" ><?= TITULO_GRUPOS_ADMINISTRADOS ?></div>
		</div>
		<div class="large-4 columns">
			<div id='crear' target="panelB-3" class="row tab-anidado inactive-tab-anidado" ><?= TITULO_CREAR_GRUPO ?></div>
		</div>                          
	</div>    
	<div class="contenedor-panels-anidado">
		<div class="active-panel-anidado" id="panelB-1">
			<?php

			$my_form=module_invoke('fed_redsocial','block_view','mis-grupos');
			//print_r($my_form);
			print_r($my_form['content']);


			//print render($my_form);


			?>
		</div>
		<div class="inactive-panel-anidado" id="panelB-2">
			<?php

			$my_form=module_invoke('fed_redsocial','block_view','grupos-administrados');
			print_r($my_form['content']);
			?>
		</div> 
		<div class="inactive-panel-anidado" id="panelB-3" >
			<?php
			print("<div id='wrapperFormGrupo'>");
			$my_form=drupal_get_form('grupo_formulario');


			
			if(strlen($my_form['#validated'])>0){
				?>
				<div id="validandoFormulario" style="height:0px;"><?php //print_r($my_form['#validated']); ?></div>
				<?php
			}
			print drupal_render($my_form);
			print("</div>");
			?>
		</div>        
	</div>        
</div>


<script type="text/javascript">
		
var currentValue = window.location.hash.substr(1);


	
jQuery(function($) {

	
	console.log(currentValue);
		jQuery("#misgrupos").click(function(){
			callAjax('panelB-1','show_mis_grupos','nid_curso: 0, pagina: 1, div_contenedor: \'panelB-1\'');

			imprimir("panelB-1",this); });

		jQuery("#administrados").click(function(){
			callAjax('panelB-2','show_grupos_administrados','nid_curso: 0, pagina: 1, div_contenedor: \'panelB-2\'');

			imprimir("panelB-2",this); });

		jQuery("#crear").click(function(){imprimir("panelB-3",this); });


	});


	//muestra el tab que corresponde al hash que se envía
	jQuery("#titulos").children().children().each(function(){
		//console.log($(this).attr('id'));
		if($(this).attr('id')==currentValue){
			//console.log("llamando a la funcion imprimir");
			imprimir($(this).attr('target'), this);
			//console.log("se llamó a la función imprimir");
		}
	});

	console.log(jQuery("#validandoFormulario").html());
	if (jQuery("#validandoFormulario")=== undefined){}
	else imprimir("panelB-3",document.getElementById("crear"));

	function imprimir(idEl, trigger){
		//console.log("abrir: "+idEl);

		//Cargar el tpl.

		el = jQuery("#"+idEl);
		//console.log("trigger: "+trigger);
		window.location.hash = trigger.id;
		//console.log(el.html());
		//i++;
		//el.html("Funciona: "+i);
		muestraPanelTab(idEl, trigger.id,'anidado');

	}
</script>