<?php
//print_r($items);
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
	case 'confcuenta-historialcompras':
		print("<div id='wrapperHistorialCompras'>");
		$my_form=drupal_get_form('configuracioncuenta_historial_compras');
		print drupal_render($my_form);
		print("</div>");
 
	break;
	case 'confcuenta-historialventas':
		print("<div id='wrapperHistorialVentas'>");
		$my_form=drupal_get_form('configuracioncuenta_historial_ventas');
		print drupal_render($my_form);
		print("</div>");
 
	break;
}
?>

<script type="text/javascript">

jQuery(function($) {
	$("#edit-btnagregarinteres").click(function() {
		alert("Funciona");
	});
});


</script>