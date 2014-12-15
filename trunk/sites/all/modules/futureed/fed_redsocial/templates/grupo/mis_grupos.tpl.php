<div class="large-<?= $anchoColumnas;?> columns end item">
	<div class="item-lista-chica">
			<div class="top">
				<a href="javascript:void(0)" onclick="console.log('funciona =)');console.log('<?= $item['idGrupo']?>')" class="action">
					<img src="<?= $item['imagen']; ?>">
				</a>
				<img class="main" src="<?= $item['imagen']; ?>">
				<img class="secundaria" src="<?= $item['imagenSecundaria']; ?>">

			</div>

			<div class="contenido">

				<div class = "row titulo">
					<div class = "large-12 columns"><h1><?= $item['titulo'];?></h1></div>
				</div>
				<div class="row info">
					<div class = "large-12 columns">
						<p><?= CATEGORIA;?>: <a><?= $item['categoria']; ?></a></p>
						<p><?= MIEMBROS;?>: <?= $item['miembros']; ?></p>
						<p><?= ULTIMA_ACTIVIDAD;?>: <?= $item['ultimaActividad']; ?></p>
						<p><?= TIPO_GRUPO;?>: <?= $item['tipoGrupo']; ?></p>
					</div>
				</div>
				<div class = "row botones">
					<div class = "large-12 columns">
						<a class="btn" onClick="callAjax('panelB-2','show_grupo_detalle','idGrupo: <?php print $item['idGrupo']?>, trigger: \'show_grupos_administrados\', div_contenedor: \'panelB-2\'');">Ir al Grupo</a>
					</div>
				</div>
			</div>

	</div>
	
</div>

