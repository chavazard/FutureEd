<?php 

$string_busqueda = "Matematicas";

?>

<div class="row">
	<div class="small-9 columns">
		<h5><?= BUSQUEDA_CANALES;?></h5>
	</div>
	<div class="small-3 columns">
		<?php print drupal_render(drupal_get_form('ordenar_canales_form'));?>
	</div>	
</div>

<div id="contenedor_busqueda_general_canales"></div>

<script type="text/javascript">
	callAjax('contenedor_busqueda_general_canales','show_busqueda_listado_canales','string_busqueda: "<?= $string_busqueda;?>", pagina: 1, div_contenedor: \'contenedor_busqueda_general_canales\'');
</script>