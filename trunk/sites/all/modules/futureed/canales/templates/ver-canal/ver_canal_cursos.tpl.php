<style type="text/css">
.canalesCursos {
	font-size: 12px;
	padding: 5px;
	border:1px solid #333;
	background-color: #F1F1F1;
}

.canalesCursos button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.canalesCursos p{
	padding: 0;
	margin: 0;
}
</style>

<div class="large-<?= $anchoColumnas;?> columns end">

	<div class="row canalesCursos">
		<div class="small-12 columns ">
			<div class="panel">
				<img src="<?= $item['imagen']; ?>" style="width:100%;heigt:100%;">
			</div>
		</div>
		<div class="small-12 columns ">
			<h6><?= $item['titulo'];?></h6>
			<p><?=t('Tutor');?>:<u><?= $item['tutor']; ?></u></p>
			<p><?=t('Creador');?>:<u><?= $item['creador']; ?></u></p>
			<p><?=t('Fecha de Inicio');?>:</p><b><?= $item['fechaInicio']; ?></b>
			<p><?=t('Duracion');?>:</p><b><?= $item['duracion']; ?></b>
		</div>
		<div class="row">
			<div class="small-6 columns">
				<p><?=t('Precio');?></p>
				<b><?= $item['precio']; ?></b>
			</div>
			<div class="small-6 columns">
				<p><?=t('Calificacion');?></p>
				<b><?= $item['calificacion']; ?></b>
			</div>
		</div>
	</div>
	
</div>



