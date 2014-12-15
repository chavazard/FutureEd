<style type="text/css">
#bloque_usuarios{
	margin: 0;
	padding: 0;
	border: 1px #CAD4D4 solid;
	background-color: #FFFFFF;
}

#bloque_usuarios h5{
	background-color: #CAD4D4;
}

#bloque_usuarios u{
	float: right;
}
</style>

<div class="row" id="bloque_usuarios">
	<h5><b><?php echo USUARIOS_SUGERIDOS; ?></b></h5>
	<div id="usuarios_sugeridos"></div>
	<a href="#"><u><?php echo VER_MAS; ?></u></a>
</div>

<script type="text/javascript">
	callAjax('usuarios_sugeridos','show_item_usuarios_sugeridos','uid: 0, pagina: 1, div_contenedor: \'usuarios_sugeridos\'');
</script>