<div class="large-<?=$anchoColumnas;?> columns end item">
	<div class="item-lista-chica">

		<div>
			<img src="<?= $item['field_curso_imagen']; ?>">
		</div>
		<div class="contenido">
			<div class="row titulo">
				<div class="large-12 columns"><a href="<?= $item['link_curso']; ?>"><h1><?= $item['field_curso_nombre'];?></h1></a></div>
			</div>
			<div class="row info">
				<div class = "large-12 columns">
					<p><?= CANAL;?>: <a href="<?= $item['link_curso_canal']; ?>"><?= $item['field_curso_canal']; ?></a></p>
					<p><?= t('Estatus');?>: <?= $item['field_curso_estatus']; ?></p>
				</div>
			</div>
			<div class="row info">
				<? if ($item['field_curso_fechas_imparticion'] == 'cerrado') {?>
                <p><?= t('Fecha de inicio');?>: <?= $item['field_curso_fecha'];?></p> 
                <p><?= t('Alumnos:');?>: <?= $item['calc_numero_alumnos'];?></p>
                <? } else{?>
                <p><?= t('Curso abierto');?>: <?= $item['field_curso_caducidad'];?></p> 
                <? } ?>
			</div>
			<div class = "row info">
				<div class="large-12 columns">
					<? if ($item['field_curso_fechas_imparticion'] == 'cerrado') {?>
					<p><?= $item['field_curso_publicacion']; ?></p>
					<? }?>
				</div>
			</div>
			<hr>
			<div class="foot">
				<a href="javascript:void(0)" onclick="console.log('Editar');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
				<? if($item['field_curso_publicacion'] == 'Publicado') {?>
				<a href="javascript:void(0)" data-reveal-id="error" onclick="console.log('Eliminar');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
				<? } else{?>
				<a href="javascript:void(0)" data-reveal-id="eliminar" onclick="console.log('Eliminar');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
				<? }?>
				<a href="javascript:void(0)" onclick="console.log('Agregar a Canal');console.log('<?= $item['nid']?>')" class="action">
					<img src="http://placehold.it/20x20">
				</a>
			</div>
		</div>

	</div>
</div>