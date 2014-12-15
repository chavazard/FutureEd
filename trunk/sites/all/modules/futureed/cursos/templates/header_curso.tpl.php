<div class="row">
    <div class="large-2 columns">
        <img src="<= $info_curso['field_curso_imagen']; ?>" style="width:100%;">
    </div>
    <div class="large-10 columns">
        <h1>
            <?= $info_curso['title']; ?>
        </h1>
        <h3><a href="<?= $info_curso['link_curso_creador']; ?>"><?= $info_curso['calc_curso_creador']; ?></a></h3>
        <div class="row">
            <div class="small-4 columns">
                <ul>
                    <li>
                        <?=t('Categor&iacute;a');?>: <a href="<?= $info_curso['link_curso_categoria']; ?>"><?= $info_curso['field_curso_categoria']; ?></a>  
                    </li>
                    <li>
                        <?=t('Subcategor&iacute;a');?>: <a href="<?= $info_curso['link_curso_subcategoria']; ?>"><?= $info_curso['field_curso_subcategoria']; ?></a>
                    </li>
                    <li>
                        <?=t('Tutores');?>:
                        <ul>
                            <?php
                            foreach($info_curso['field_curso_profesores'] as $tutor){?>
                                <li><?=$tutor;?></li>                             
                            <?php    
                            }
                            
                            ?>
                        </ul>
                        <?= $info_curso['nombre-tutor']; ?>
                    </li>                                        
                </ul>
                <?php mostrar_calificacion_estrellas($info_curso['field_curso_calificacion'],$info_curso['field_curso_numero_votos']);//print theme('ver_rate_stars', array('item' => $info_curso['rate'] ));?>
            </div>
            <div class="small-4 columns minilistado">
                <?=t('Usuarios populares que han tomado el curso');?>
                <div class="row">
                    <?php mostrar_listado(5, 5, $info_curso['usuarios-populares-curso'], 'elemento_lista_usuarios');?>
                </div>
                             
            </div>
            <div class="small-4 columns end">
                <div class="row">                    
                    <div class="large-5 columns" >                        
                        <b><a href="#" data-reveal-id="modal-usuarios-likes-curso"> <?= $info_curso['field_curso_likes']; ?></a></b>
                        <a href="#" data-reveal-id="modal-usuarios-likes-curso">Me gusta</a>
                    </div>
                    <div class="large-7 columns">
                        <div class="btn_generico"><?=t('ME GUSTA');?></div>
                    </div>                    
                </div>
            </div>            
        </div>                    
    </div>
</div>

<div id="modal-usuarios-likes-curso" class="reveal-modal">
    <?php print theme('likes-usuarios-curso', array('likes' => $info_curso['field_curso_likes'] ));?>   
</div>