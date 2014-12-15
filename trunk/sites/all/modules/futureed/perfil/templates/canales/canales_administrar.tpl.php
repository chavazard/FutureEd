<style type="text/css">

.canalesAdministrar {
	font-size: 12px;
	padding: 5px;
	border:1px solid #333;
	background-color: #F1F1F1;
}

.canalesAdministrar button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.canalesAdministrar p{
	padding: 0;
	margin: 0;
}

</style>

<div class="large-<?= $anchoColumnas;?> columns end">

	<div class="row canalesAdministrar">
		<div class="small-12 columns ">
			<div class="panel">
				<img src="<?= $item['imagen']; ?>" style="width:100%;heigt:100%;">
			</div>
		</div>
		<div class="small-12 columns ">
			<h6><?= $item['titulo'];?></h6>
			<p>Categoria: <u><?= $item['categoria']; ?></u></p>
			<p>Subcategoria: <u><?= $item['subcategoria']; ?></u></p>
			<p><?= $item['descripcion']; ?></p>
			<p><b>Cursos: </b><?= $item['totalCursos']; ?></p>
		</div>
		<div class="small-12 columns">
			<div class="small-8 columns">
				<button><?= $item['boton']?></button>
			</div>
			<div class="small-4 columns">
				<img src="http://placehold.it/30x30'">
			</div>
		</div>
	</div>
	
</div>