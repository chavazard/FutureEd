<?php

$string_busqueda = "Matematicas";

?>

<div class="row">
	<div>
		<?php print drupal_render(drupal_get_form('filtrar_cursos_form'));?>
	</div>
</div>

<script type="text/javascript">
jQuery(function($) {

	$("#edit-opciones-modalidad").click(function(){
		busquedaFiltros('string_busqueda: "<?=$string_busqueda?>"', 'contenedor_busqueda_general_cursos');
  	});

  	$("#edit-opciones-categoria").click(function(){
		busquedaFiltros('string_busqueda: "<?=$string_busqueda?>"', 'contenedor_busqueda_general_cursos');
  	});

});
</script>