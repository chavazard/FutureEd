<?php 

$string_busqueda = "Matematicas";

?>

<h5><?= BUSQUEDA_USUARIOS; ?></h5>

<div id="contenedor_resultado_general_usuarios"></div>

<?= l(VER_MAS, drupal_get_path_alias('busqueda').'/usuarios')?>

<script type="text/javascript">
	callAjax('contenedor_resultado_general_usuarios','show_busqueda_usuarios','string_busqueda: "<?= $string_busqueda;?>"');
</script>