<?php
//print_r($items['tipo']);
//print_r($items['user']->uid);
switch($items['tipo']){
	case 'cursocreacion-menu':
		print("<div id='menuPrincipal'>");
		$my_form=drupal_get_form('creacioncurso_get_menu');
		print drupal_render($my_form);
		print("</div>");


				?>
		<script type="text/javascript">
		console.log("funciones XD");

		console.log("funciones del formulario");
		jQuery(function($) {

			//Cargar el panel para la selección de canal
			muestraPanelTab("panel-1", this.id,"");
			callAjax("panel-1","show_seleccionar_mis_canales","nid_canal: 0, pagina: 1, div_contenedor: \"panel-1\"");


			$("#edit-btnsubcategoria").attr('type', 'button');
			$("#edit-btnsubcategoria").bind('click',function(){
				alert("agregando detalle");

			});

			$("#edit-btnagregarinteres").click(function() {
				alert("Funciona");
			});

			$(".popup-fecha :input").datepicker($.datepicker.regional['es']);

			$("#edit-selcategoria").change(function() {
				api_url = Drupal.settings.basePath + 'api';
				 params = {
					'f_name' : 'get_term_children',
					'tid': $("#edit-selcategoria").val(),
				};
				//console.log(params);
				$.get(api_url,params,function(data){ // API Ajax		
					//Limpiar la subcategoría
					$("#edit-selsubcategoria").find('option').remove();
					$('#edit-selsubcategoria').append($('<option/>', { 
					        value: 0,
					        text : '<?= SIN_SUBCATEGORIA ?>' 
					    }));
					var markup = jQuery.parseJSON($.trim(data));
					$.each(markup, function( index, text ) {
						$('#edit-selsubcategoria').append($('<option/>', { 
					        value: index,
					        text : text 
					    }));
					});

				}); 
			});



			$("#btnAgregarPregunta").bind('click',function(){
				api_url = Drupal.settings.basePath + 'api';
				 params = {
					'f_name' : 'add_pregunta_frecuente',
					'nid': '<?php print($items['node']['nid'])?>',
					'p':$("#edit-txtpreguntafrecuente").val(),
					'r':$("#edit-txtrespuestapreguntafrecuente").val(),
				};
				
				//console.log(params);
				$.get(api_url,params,function(data){ // API Ajax		
					//Limpiar la subcategoría
					
					console.log(data);

					var markup = jQuery.parseJSON($.trim(data));

					mostrar_preguntas_frecuentes(markup,'divPreguntasFrecuentes');
				}); 
			});

			//Cargar Preguntas Frecuentes
			api_url = Drupal.settings.basePath + 'api';
			 params = {
				'f_name' : 'get_preguntas_frecuentes',
				'nid': '<?php print($items['node']['nid'])?>',
			};
			$.get(api_url,params,function(data){ 
				var markup = jQuery.parseJSON($.trim(data));
				mostrar_preguntas_frecuentes(markup,'divPreguntasFrecuentes');
			}); 


			$("#tab-1").click(function() {
				muestraPanelTab("panel-1", this.id,"");
				callAjax("panel-1","show_seleccionar_mis_canales","nid_canal: 0, pagina: 1, div_contenedor: \"panel-1\"");
				

			});

			$("#tab-2").click(function() {
				muestraPanelTab("panel-2", this.id,"");callAjax("panel-2","show_seleccionar_canales_administrar","nid_canal: 0, pagina: 1, div_contenedor: \"panel-2\"");
			});

		});
		function seleccionar_canal(el,nid){

			jQuery(".contenedor-panels div").removeClass('canal-seleccionado');
			
			var jqEl= jQuery(el);

			jqEl.addClass('canal-seleccionado');

			jQuery("[name='hCanalSeleccionado']").val(nid);
		}
		function mostrar_preguntas_frecuentes(markup,elID){

			$('#'+elID).html('');
			if(markup.length==0){
				$('#'+elID).append("Ninguna Dirección Registrada");
			}
			else{
				$.each(markup, function( index, text ) {
					console.log(text);
					contenido = '<div class="row"><div class="contenidoDireccion small-9 columns"><h5>'
						+text.pregunta+'</h5><p> '+text.respuesta+'</p> '
							+'</div><div class="small-3 columns">'
							+'<a href="javascript:void(0);" onclick="editar(\'preguntasFrecuentes\',\''+text+'\')">Editar</a>'
							+'<a href="javascript:void(0);" onclick="eliminar(\'preguntasFrecuentes\',\''+text.id_pregunta+'\')">Eliminar</a>'
						+'</div></div>';
					$('#'+elID).append(contenido);
				});
			}
		}
		function eliminar(funcion, id){

			switch(funcion){
				case 'preguntasFrecuentes':

					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'del_pregunta_frecuente',
						'id': id,
					};
					$.get(api_url,params,function(data){ 
						
						api_url = Drupal.settings.basePath + 'api';
						 params = {
							'f_name' : 'get_preguntas_frecuentes',
							'nid': '<?php print($items['node']['nid'])?>',
						};
						$.get(api_url,params,function(data){ 
							var markup = jQuery.parseJSON($.trim(data));
							mostrar_preguntas_frecuentes(markup,'divPreguntasFrecuentes');
						}); 

					}); 

				break;

			}
			

		}
		
</script>
		<?php

	break;
	case 'cursocreacion-formulario':
		print("<div id='contenido'>FORMULARIO");
		$my_form=drupal_get_form('creacioncurso_form');
		print drupal_render($my_form);
		print("</div>");


	break;
	case 'cursocreacion-path':
		$my_form=drupal_get_form('creacioncurso_get_path');
		print drupal_render($my_form);
	break;
}
?>


