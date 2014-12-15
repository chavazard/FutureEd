<?php 

$string_busqueda = "Matematicas";

?>

<h5><?= CURSOS; ?></h5>

<div id="contenedor_resultado_general_cursos"></div>

<?= l(VER_MAS, drupal_get_path_alias('busqueda').'/cursos')?>

<script type="text/javascript">
	callAjax('contenedor_resultado_general_cursos','show_busqueda_cursos','string_busqueda: "<?= $string_busqueda;?>"');
</script>