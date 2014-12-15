<style type="text/css">

.canalesEquipo {
	font-size: 12px;
	padding: 5px;
	border:1px solid #333;
	background-color: #F1F1F1;
}

.canalesEquipo button{
	padding: 5px;
	font-size: 10px;
	background: #00E6E6;
}

.canalesEquipo p{
	padding: 0;
	margin: 0;
}

</style>

<div class="large-<?= $anchoColumnas;?> columns end">

	<div class="row canalesEquipo">
		<div class="small-12 columns ">
			<div class="panel">
				<img src="<?= $item['imagen']; ?>" style="width:100%;heigt:100%;">
			</div>
			<b><?= $item['tutor']; ?></b><br>
			<br>
			<a href="#">Ver Perfil</a>
		</div>
	</div>
	
</div>



