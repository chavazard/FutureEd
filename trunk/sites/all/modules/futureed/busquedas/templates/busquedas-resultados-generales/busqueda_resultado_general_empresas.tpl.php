<?php 

$string_busqueda = "Matematicas";

?>

<h5><?= EMPRESAS; ?></h5>

<div id="contenedor_resultado_general_empresas"></div>

<?= l(VER_MAS, drupal_get_path_alias('busqueda').'/empresas')?>

<script type="text/javascript">
	callAjax('contenedor_resultado_general_empresas','show_busqueda_empresas','string_busqueda: "<?= $string_busqueda;?>"');
</script>