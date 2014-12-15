<style type="text/css">

.usuariosSugeridos {
	font-size: 12px;
	padding: 5px;
	/*border:1px solid #333;*/
	border-bottom: 1px #CAD4D4 solid;
	background-color: #FFFFFF;
}

.usuariosSugeridos button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.usuariosSugeridos p{
	padding: 0;
	margin: 0;
}

</style>

<div class="large-<?= $anchoColumnas;?> columns end">

	<div class="row usuariosSugeridos">
		<div class="small-4 columns">
			<img src="<?= $item['field_usuario_imagen']; ?>">
		</div>
		<div class="small-6 columns">
			<div class="small-12 columns">
				<img src="<?= $item['icono_1']; ?>">
				<img src="<?= $item['icono_2']; ?>">
				<img src="<?= $item['icono_3']; ?>">
				<img src="<?= $item['icono_4']; ?>">
			</div>
			<div class="small-12 columuns">
				<a href="<?= $item['link_usuario'];?>"><?= $item['calc_usuario_nombre'];?></a>
			</div>
			<div class="small-12 columuns">
				<?= $item['field_usuario_numero_seguidores'];?> <?php echo SEGUIDORES; ?>
			</div>
			<div class="small-12 columuns">
				<?= $item['field_usuario_numero_seguidos'];?> <?php echo SIGUIENDO; ?>
			</div>
		</div>
		<div class="small-2 columns">
			<div class="small-12 columuns" id="boton_agregar">
				<img src="http://placehold.it/20x20">
			</div>
			<div class="small-12 columuns" id="mensaje">
				<img src="http://placehold.it/20x20">
			</div>
		</div>
	</div>
	
</div>
