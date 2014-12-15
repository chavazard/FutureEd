<div class="large-<?= $anchoColumnas;?> columns end item">
	<div class="item-lista-chica">                       
			<div class="top">
				<a href="<?= $item['link_proyecto'];?>"><img class="main" src="<?=$item['field_proyecto_imagen'];?>"></a>
			</div>

			<div class="contenido">

				<div class = "row titulo">
					<div class = "large-12 columns"><h1><?=$item['field_proyecto_nombre'];?></h1></div>
				</div>                         

                                
                                <div class="row contenedor-elementos" >
                                        <div class="info-likes"><?=$item['field_proyecto_likes'];?></div>
                                </div>

				<div class = "row contenedor-elementos " >
    
                                            <div class="large-2 columns no-margin margin-top-10">
                                                <img src="<?= $item['field_usuario_imagen'];?>" class="thumbnail-avatar">
                                            </div>
                                            <div class="large-10 columns"><br>
                                                <a href="<?= $item['link_autor'];?>"><?= $item['calc_nombre_autor'];?></a>
                                            </div>
         
				</div>                                
			</div>
	</div>
	
</div>

