<style type="text/css">

.siguiendo {
	font-size: 12px;
	padding: 5px;
	border:1px solid #333;
	background-color: #F1F1F1;
}

.siguiendo button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.siguiendo p{
	padding: 0;
	margin: 0;
}

</style>

<div class="large-<?= $anchoColumnas;?> columns end">

	<div class="row siguiendo">
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
				<?= $item['field_usuario_numero_seguidores'];?> <?php echo t('Seguidores');?>
			</div>
			<div class="small-12 columuns">
				<?= $item['field_usuario_numero_seguidos'];?> <?php echo t('Siguiendo');?>
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



