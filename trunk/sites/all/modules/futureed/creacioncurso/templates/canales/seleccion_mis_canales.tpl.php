<div class="large-<?= $anchoColumnas;?> columns end item">
		<div class="item-lista-chica" >
			<div class="canal-seleccionar" onclick="seleccionar_canal(this,<?= $item['nid']?>)"></div>
			
			<div class="top">
				<img class="main" src="<?= $item['field_canal_imagen']; ?>">

			</div>

			<div class="contenido">
				<div class = "row titulo">
					<div class = "large-12 columns"><h1><?= $item['field_canal_nombre'];?></h1></div>
				</div>
				<div class="row info">
					<div class = "large-12 columns">
						<p><?= CANAL;?>: <a href="<?= $item['link_creador_canal']; ?>"><?= $item['calc_creador_nombre']; ?></a></p>
					</div>
				</div>
			</div>


			
		</div>
	
</div>