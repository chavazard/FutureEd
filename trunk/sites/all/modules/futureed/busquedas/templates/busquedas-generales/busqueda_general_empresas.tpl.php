<?php 

$string_busqueda = "Matematicas";

?>

<div class="row">
	<div class="small-9 columns">
		<h5><?= BUSQUEDA_EMPRESAS;?></h5>
	</div>
	<div class="small-3 columns">
		<?php print drupal_render(drupal_get_form('ordenar_empresas_form'));?>
	</div>	
</div>

<div id="contenedor_busqueda_general_empresas"></div>

<script type="text/javascript">
	callAjax('contenedor_busqueda_general_empresas','show_busqueda_listado_empresas','string_busqueda: "<?= $string_busqueda;?>", pagina: 1, div_contenedor: \'contenedor_busqueda_general_empresas\'');
</script>