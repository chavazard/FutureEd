<?php 

$string_busqueda = "Matematicas";

?>

<div class="row">
	<div class="small-9 columns">
		<h5><?= BUSQUEDA_GRUPOS;?></h5>
	</div>
	<div class="small-3 columns">
		<?php print drupal_render(drupal_get_form('ordenar_grupos_form'));?>
	</div>	
</div>

<div id="contenedor_busqueda_general_grupos"></div>

<script type="text/javascript">
	callAjax('contenedor_busqueda_general_grupos','show_busqueda_listado_grupos','string_busqueda: "<?= $string_busqueda;?>", pagina: 1, div_contenedor: \'contenedor_busqueda_general_grupos\'');
</script>