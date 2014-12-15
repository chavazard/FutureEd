<style type="text/css">

.cursosSugeridos {
	font-size: 12px;
	padding: 5px;
	/*border:1px solid #333;*/
	border-bottom: 1px #CAD4D4 solid;
	background-color: #FFFFFF;
}

.cursosSugeridos button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.cursosSugeridos p{
	padding: 0;
	margin: 0;
}

</style>

<div class="large-<?= $anchoColumnas;?> columns end">

	<div class="row cursosSugeridos">
		<div class="small-4 columns">
			<img src="<?= $item['field_curso_imagen']; ?>">
		</div>
		<div class="small-8 columns">
			<div class="small-12 columuns">
				<b><?= $item['calc_curso_nombre'];?></b>
			</div>
			<div class="small-12 columuns">
				<?php echo CREADOR; ?>: <a href="<?= $item['link_curso_creador'];?>"><?= $item['calc_curso_creador'];?></a>
			</div>
			<div class="small-12 columuns">
				<b><?php echo PRECIO; ?>: <?= $item['field_curso_precio'];?></b> 
			</div>
			<div class="small-12 columuns">
				<div class="small-8 columns">
					<?= $item['field_curso_calificacion'];?>
				</div>
				<div class="small-4 columns">
					(<?= $item['field_curso_likes'];?>)
				</div>
			</div>
		</div>
	</div>
	
</div>
