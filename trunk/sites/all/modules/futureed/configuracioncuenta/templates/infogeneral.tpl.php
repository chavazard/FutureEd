<?php
print_r($items);
switch($items['tipo']){
	case 'cc-menu':
		?>
		<h2 class="clase2">asdfasdfasf</h2>
		<?php
		print("<div id='menuPrincipal'>");
		print drupal_render(drupal_get_form('configuracioncuenta_get_header'));
		print("</div>");
	break;
	case 'cc-infogeneral':

 
	break;
}
?><h1>Está funcionando adecuadamente</h1>

<style> 
.clase2{
	color: #345;


}


</style>