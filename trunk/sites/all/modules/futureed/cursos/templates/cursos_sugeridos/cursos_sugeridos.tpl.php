<style type="text/css">
#bloque_cursos{
	margin: 0;
	padding: 0;
	border: 1px #CAD4D4 solid;
	background-color: #FFFFFF;
}

#bloque_cursos h5{
	background-color: #CAD4D4;
}

</style>

<div class="row" id="bloque_cursos">
	<h5><b><?php echo CURSOS_SUGERIDOS; ?></b></h5>
	<div id="cursos_sugeridos"></div>
	<a href="#"><u><?php echo VER_MAS; ?></u></a>
</div>

<script type="text/javascript">
	callAjax('cursos_sugeridos','show_item_cursos_sugeridos','nid_curso: 0, pagina: 1, div_contenedor: \'cursos_sugeridos\'');
</script>