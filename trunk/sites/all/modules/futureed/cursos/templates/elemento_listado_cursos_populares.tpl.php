<div class="large-<?= $anchoColumnas;?> columns end item">
	<div class="item-lista-chica">                       
			<div class="top">
                                 <div class="btn-wishlist" ></div>
				<img class="main" src="<?=$item['field_curso_imagen'];?>">
				<img class="secundaria" src="<?=$item['field_curso_imagen'];?>">

			</div>

			<div class="contenido">

				<div class = "row titulo">
					<div class = "large-12 columns"><h1><?=$item['field_curso_nombre'];?></h1></div>
				</div>
				<div class="row info">
					<div class = "large-12 columns">
						<p><?= TUTOR;?>: <a href="´"><?=$item['calc_nombre_tutor'];?></a></p> 
						<p><?= CREADOR;?>: <a href="<?=$item['link_curso_creador'];?>"><?=$item['creador_curso_nombre'];?></a></p>
						<p><?= CANAL;?>: <a href="<?=$item['link_curso_canal'];?>"><?=$item['field_curso_canal'];?></a></p>
					</div>
				</div>

                                <div class = "row info">
					
					<div class = "info-duracion"><?=$item['field_curso_duracion'];?></div>
				</div>                                 
                                
                                <?php if ($item['field_curso_costo'] != null && $item['field_curso_costo'] != "0")
                                       $precio = $item['field_curso_costo'];
                                   else
                                       $precio = 'Gratuito';
                                ?>                                                                   
                                
                                <div class = "row info">
					<h2><?= PRECIO ?>: <b class="color-secundario"><?= $precio;?></b></h2>
				</div>  


                                
                                
                                <div class="row contenedor-elementos" >
				    <div class = "large-12 columns"><p><?= USUARIOS_POPULARES; ?></p></div>
                                    <div class="small-9 columns no-margin info">
                                        <div class="right">
                                        <?php foreach($item['array_usuarios_curso'] AS $usuario) { ?>
                                           
                                                <a href="<?=$usuario['link_usuario_curso'];?>"><img class="thumbnail-avatar"
                                                                                                    src="<?=$usuario['field_usuario_imagen'];?>" alt="<?=$usuario['calc_usuario_nombre'];?>" title="<?=$usuario['calc_usuario_nombre'];?>"></a>
                                            
                                        <?php } ?>
                                        </div>
                                    </div>
                                    <div class="small-3 columns end no-margin">
                                        <div class="info-likes">aaa</div>
                                    </div>
                                </div>

				<div class = "row contenedor-btn-elementos" >
					<div class = "small-6 columns no-margin"  >
						<a class="btn no-margin" href="#" ><?=VER_CURSO;?></a>
					</div>
                                        <?php if($item['field_curso_numero_votos'] != 0) { ?>                                        
                                            <div class = "small-5 columns no-margin right end contenedor-rated" >
                                                    <?php mostrar_calificacion_estrellas($item['field_curso_calificacion'],$item['field_curso_numero_votos']);?>                                                   
                                            </div>
                                        <?php } else {?>
                                            <div class = "small-6 columns no-margin right end" >
                                                    <a class="btn no-margin" href="#" ><?=CALIFICAR;?></a>
                                            </div>                                                                                
                                        <?php } ?>
				</div>                                
			</div>

	</div>
	
</div>


