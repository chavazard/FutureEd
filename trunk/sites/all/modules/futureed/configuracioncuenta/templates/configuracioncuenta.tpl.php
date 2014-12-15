

<?php
//print_r($items['user']->uid);
switch($items['tipo']){
	case 'confcuenta-menu':
		print("<div id='menuPrincipal'>");
		$my_form=drupal_get_form('configuracioncuenta_get_menu');
		print drupal_render($my_form);
		print("</div>");
	break;
	case 'confcuenta-infogeneral':
		print("<div id='formularioCuenta'>");
		$my_form=drupal_get_form('configuracioncuenta_form');
		print drupal_render($my_form);
		print("</div>");
 
	break;
	case 'confcuenta-historialventas':
		print("<div id='wrapperHistorialVentas'>");
		$my_form=drupal_get_form('configuracioncuenta_historial_ventas');
		print drupal_render($my_form);
		print("</div>");
 
	break;
	case 'confcuenta-path':
		$my_form=drupal_get_form('configuracioncuenta_get_path');
		print drupal_render($my_form);
	break;
}
?>

<script type="text/javascript">
var i = 0;
<?php
	switch($items['tipo']){
		case 'confcuenta-infogeneral':
			?>
			jQuery(function($) {
				
				$(".popup-fecha :input").datepicker($.datepicker.regional['es']);
				
				$(".popup-mes :input").datepicker( );
				$("#edit-btnagregarinteres").click(function() {
					alert("Funciona");
				});

				

				$("#edit-filintervalocompras--2").change(function(){
					i++;
					callAjax('divhistorialCompras','print_historial_compras','nid_usuario: 25 ');
					//$("#divhistorialCompras").html("Cambiando: "+i);

				});

				$("#edit-filventas--2").change(function(){
					i++;
					callAjax('divhistorialVentasActuales','print_historial_ventas_actuales','nid_usuario: 25 ');
					callAjax('divhistorialVentasMesPasado','print_historial_ventas_mes_pasado','nid_usuario: 25 ');
					callAjax('divhistorialVentasFacturadas','print_historial_ventas_facturadas','nid_usuario: 25 ');


					$("#divhistorialVentasActuales").html("Cambiando: "+i);
					$("#divhistorialVentasMesPasado").html("Cambiando: "+i);
					$("#divhistorialVentasFacturadas").html("Cambiando: "+i);

				});

				$("#btnAgregarDireccion").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'insert_direcciones',
						'uid': '<?php print($items['user']->uid)?>',
						'calle':$("#edit-txtcalle--2").val(),
						'nexterior':$("#edit-txtnumeroexterior--2").val(),
						'ninterior':$("#edit-txtnumerointerior--2").val(),
						'colonia':$("#edit-txtcolonia--2").val(),
						'estado':$("#edit-txtestado--2").val(),
						'pais':$("#edit-txtpais--2").val(),
						'cp':$("#edit-txtcodigopostal--2").val(),
						'municipio':$("#edit-txtdelegacionmunicipio--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divDireccionesAgregadasCont').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_direcciones(markup,'divDireccionesAgregadasCont');
					}); 
				});

				$("#btnAgregarPuesto").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'insert_informacion_profesional',
						'uid': '<?php print($items['user']->uid)?>',
						'compania':$("#edit-txtcomapnia--2").val(),
						'tituloPuesto':$("#edit-txttitulopuesto--2").val(),
						'empleoActual':$("#edit-txtnumerointerior--2").val(),
						'mesInicio':$("#edit-selmesinicio--2").val(),
						'mesFin':$("#edit-selmesfin--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divInfoProfesional').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_profesional(markup,'divInfoProfesional');
					}); 
				});

				$("#btnAgregarEstudio").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'insert_informacion_academica',
						'uid': '<?php print($items['user']->uid)?>',
						'escuela':$("#edit-txtescuela--2").val(),
						'tipoEstudio':$("#edit-txttipoestudio--2").val(),
						'cursando':$("#edit-radestudiocursando--2").val(),
						'tituloObtenido':$("#edit-radtituloestudios--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divInfoAcademica').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_academica(markup,'divInfoAcademica');
					}); 
				});



				//insert cuenta
				$("#btnAgregarDireccion").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'insert_direcciones',
						'uid': '<?php print($items['user']->uid)?>',
						'calle':$("#edit-txtcalle--2").val(),
						'nexterior':$("#edit-txtnumeroexterior--2").val(),
						'ninterior':$("#edit-txtnumerointerior--2").val(),
						'colonia':$("#edit-txtcolonia--2").val(),
						'estado':$("#edit-txtestado--2").val(),
						'pais':$("#edit-txtpais--2").val(),
						'cp':$("#edit-txtcodigopostal--2").val(),
						'municipio':$("#edit-txtdelegacionmunicipio--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divDireccionesAgregadasCont').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_direcciones(markup,'divDireccionesAgregadasCont');
					}); 
				});


				//insert persona


				$("#btnAgregarDireccion").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'insert_direcciones',
						'uid': '<?php print($items['user']->uid)?>',
						'calle':$("#edit-txtcalle--2").val(),
						'nexterior':$("#edit-txtnumeroexterior--2").val(),
						'ninterior':$("#edit-txtnumerointerior--2").val(),
						'colonia':$("#edit-txtcolonia--2").val(),
						'estado':$("#edit-txtestado--2").val(),
						'pais':$("#edit-txtpais--2").val(),
						'cp':$("#edit-txtcodigopostal--2").val(),
						'municipio':$("#edit-txtdelegacionmunicipio--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divDireccionesAgregadasCont').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_direcciones(markup,'divDireccionesAgregadasCont');
					}); 
				});

				//insert direcciones


				$("#btnAgregarDireccion").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'insert_direcciones',
						'uid': '<?php print($items['user']->uid)?>',
						'calle':$("#edit-txtcalle--2").val(),
						'nexterior':$("#edit-txtnumeroexterior--2").val(),
						'ninterior':$("#edit-txtnumerointerior--2").val(),
						'colonia':$("#edit-txtcolonia--2").val(),
						'estado':$("#edit-txtestado--2").val(),
						'pais':$("#edit-txtpais--2").val(),
						'cp':$("#edit-txtcodigopostal--2").val(),
						'municipio':$("#edit-txtdelegacionmunicipio--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divDireccionesAgregadasCont').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_direcciones(markup,'divDireccionesAgregadasCont');
					}); 
				});

				//insert tarjeta
				$("#btnAgregarTarjeta").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';

					var d = new Date($("#edit-selmesvencimientotarjeta--2").val());

					 params = {
						'f_name' : 'insert_tarjeta',
						'uid': '<?php print($items['user']->uid)?>',
						'alias':$("#edit-txtaliastarjeta--2").val(),
						'numero':$("#edit-txtnumerotarjeta--2").val(),
						'tipo':$("#edit-seltipotarjeta--2").val(),
						'nombre':$("#edit-strnombreplasticotarjeta--2").val(),
						'vencimiento':d.getTime(),
						'codigo':$("#edit-txtcodigoseguridadtarjeta--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divTarjetasCont').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_tarjetas(markup,'divTarjetasCont');
					}); 
				});

				//insert cuenta
				$("#btnAgregarCuenta").bind('click',function(){
					api_url = Drupal.settings.basePath + 'api';

					var d = new Date($("#edit-selmesvencimientotarjeta--2").val());

					 params = {
						'f_name' : 'insert_cuenta',
						'uid': '<?php print($items['user']->uid)?>',
						'alias':$("#edit-txtaliascuenta--2").val(),
						'tipo':$("#edit-txttipocuenta--2").val(),
						'banco':$("#edit-txtnombrebanco--2").val(),
						'numero':$("#edit-txtnumerocuenta--2").val(),
						'titular':$("#edit-txtnombretitular--2").val(),
						'clabe':$("#edit-txtclabe--2").val(),
					};
					
					//console.log(params);
					$.get(api_url,params,function(data){ // API Ajax		
						//Limpiar la subcategoría
						
						$('#divCuentaCont').html('');
						console.log(data);

						var markup = jQuery.parseJSON($.trim(data));

						mostrar_cuentas(markup,'divCuentaCont');
					}); 
				});
				//divDireccionesAgregadasCont
					//Cargar direcciones
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'get_direcciones',
						'uid': '<?php print($items['user']->uid)?>',
					};
					$.get(api_url,params,function(data){ 
						var markup = jQuery.parseJSON($.trim(data));
						mostrar_direcciones(markup,'divDireccionesAgregadasCont');
					}); 
					//Cargar info profesional
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'get_informacion_profesional',
						'uid': '<?php print($items['user']->uid)?>',
					};
					$.get(api_url,params,function(data){ 
						var markup = jQuery.parseJSON($.trim(data));
						mostrar_profesional(markup,'divInfoProfesional');
					}); 
					//Cargar info académica
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'get_informacion_academica',
						'uid': '<?php print($items['user']->uid)?>',
					};
					$.get(api_url,params,function(data){ 
						var markup = jQuery.parseJSON($.trim(data));
						
						mostrar_academica(markup,'divInfoAcademica');
					}); 
					//Cargar Tarjetas
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'get_tarjeta',
						'uid': '<?php print($items['user']->uid)?>',
					};
					$.get(api_url,params,function(data){ 
						var markup = jQuery.parseJSON($.trim(data));
						
						mostrar_tarjetas(markup,'divTarjetasCont');
					}); 

					//cargar cuentas
					api_url = Drupal.settings.basePath + 'api';
					 params = {
						'f_name' : 'get_cuenta',
						'uid': '<?php print($items['user']->uid)?>',
					};
					$.get(api_url,params,function(data){ 
						var markup = jQuery.parseJSON($.trim(data));
						
						mostrar_cuentas(markup,'divCuentaCont');
					}); 


					//Cargar historiales de ventas
					callAjax('divhistorialVentasActuales','print_historial_ventas_actuales','nid_usuario: 25 ');
					callAjax('divhistorialVentasMesPasado','print_historial_ventas_mes_pasado','nid_usuario: 25 ');
					callAjax('divhistorialVentasFacturadas','print_historial_ventas_facturadas','nid_usuario: 25 ');

					//Cargar historiales de compras
					callAjax('divhistorialCompras','print_historial_compras','nid_usuario: 25 ');


			});

			function mostrar_direcciones(markup,elID){
				$('#'+elID).html('');
				$.each(markup, function( index, text ) {
					console.log(text);
					contenido = '<div class="row"><div class="contenidoDireccion small-9 columns">'
						+text.calle+' '+text.nexterior+' '+text.ninterior+', '+text.colonia+'. '
						+text.municipio+' '+text.estado+' '+text.pais+' CP:'+text.cp 
							+'</div><div class="small-3 columns">'
							+'<a href="javascript:void(0);" onclick="editar(direcciones,'+text+')">Editar</a>'
							+'<a href="javascript:void(0);" onclick="eliminar(direcciones,'+index+')">Eliminar</a>'
						+'</div></div>';
					$('#'+elID).append(contenido);
				});
			}

			function mostrar_profesional(markup,elID){
				$('#'+elID).html('');
				$.each(markup, function( index, text ) {
					console.log(text);
					contenido = '<div class="row"><div class="contenidoDireccion small-9 columns">'
						+text.compania+' Puesto: '+text.tituloPuesto+' Fecha de Inicio: '+text.mesInicio+' Fecha de término: '+text.mesFin+' '
						+text.empleoActual==1?' Empleo Actual':'' 
							+'</div><div class="small-3 columns">'
							+'<a href="javascript:void(0);" onclick="editar(profesional,'+text+')">Editar</a>'
							+'<a href="javascript:void(0);" onclick="eliminar(profesional,'+index+')">Eliminar</a>'
						+'</div></div>';
					$('#'+elID).append(contenido);
				});
			}

			function mostrar_academica(markup,elID){
				$('#'+elID).html('');
				$.each(markup, function( index, text ) {
					console.log(text);
					contenido = '<div class="row"><div class="contenidoDireccion small-9 columns">'
						+text.escuela+' Estudios: '+text.tipoEstudio+' '+text.cursando==1?' Cursando':' Título Obtenido: '+text.tituloObtenido
							+'</div><div class="small-3 columns">'
							+'<a href="javascript:void(0);" onclick="editar(academica,'+text+')">Editar</a>'
							+'<a href="javascript:void(0);" onclick="eliminar(academica,'+index+')">Eliminar</a>'
						+'</div></div>';
					$('#'+elID).append(contenido);
				});
			}

			function mostrar_tarjetas(markup,elID){
				$('#'+elID).html('');
				$.each(markup, function( index, text ) {
					console.log(text);
					contenido = '<div class="row"><div class="contenidoDireccion small-9 columns">'
						+text.alias+'<br> Con terminación: '+text.numero+' Banco:'+text.banco+' Vence en:'+text.vencimiento+''
							+'</div><div class="small-3 columns">'
							+'<a href="javascript:void(0);" onclick="editar(academica,'+text+')">Editar</a>'
							+'<a href="javascript:void(0);" onclick="eliminar(academica,'+index+')">Eliminar</a>'
						+'</div></div>';
					$('#'+elID).append(contenido);
				});
			}

			function mostrar_cuentas(markup,elID){
				$('#'+elID).html('');
				$.each(markup, function( index, text ) {
					console.log(text);
					contenido = '<div class="row"><div class="contenidoDireccion small-9 columns">'
						+text.alias+' Titular '+text.titular+'<br> Con terminación: '+text.clabe+' Banco:'+text.banco+''
							+'</div><div class="small-3 columns">'
							+'<a href="javascript:void(0);" onclick="editar(academica,'+text+')">Editar</a>'
							+'<a href="javascript:void(0);" onclick="eliminar(academica,'+index+')">Eliminar</a>'
						+'</div></div>';
					$('#'+elID).append(contenido);
				});
			}

			<?php
		break;
		case 'confcuenta-historialcompras':
			?>
			
			jQuery(function($) {
				$("#edit-filintervalo").change(function(){
					i++;
					callAjax('divhistorialCompras','print_historial_compras','nid_usuario: 25 ');
					//$("#divhistorialCompras").html("Cambiando: "+i);

				});


			});

			<?php
		break;
		case 'confcuenta-historialventas':
			?>
			jQuery(function($) {
				
				$("#edit-filventas").change(function(){
					i++;
					callAjax('divhistorialVentasActuales','print_historial_ventas_actuales','nid_usuario: 25 ');
					callAjax('divhistorialVentasMesPasado','print_historial_ventas_mes_pasado','nid_usuario: 25 ');
					callAjax('divhistorialVentasFacturadas','print_historial_ventas_facturadas','nid_usuario: 25 ');


					$("#divhistorialVentasActuales").html("Cargando...: "+i);
					$("#divhistorialVentasMesPasado").html("Cargando...: "+i);
					$("#divhistorialVentasFacturadas").html("Cargando...: "+i);

				});


			});

			<?php
		break;
	}


?>

</script>
