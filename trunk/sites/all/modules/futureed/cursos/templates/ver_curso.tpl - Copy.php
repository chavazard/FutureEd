<?php $info_curso = $items['data'][0];
$nid_curso = arg(1);


if ($nid_curso == null){
    $nid_curso = 1;    
}

?>

<?php $module_path = base_path().drupal_get_path('module', 'cursos').'/inc/proyectos_curso.php';?>
<div class="row">
    <div class="large-2 columns">
        <img src="<= $info_curso['imagen']; ?>" style="width:100%;">
    </div>
    <div class="large-10 columns">
        <h1>
            <?= $info_curso['titulo']; ?>
        </h1>        
        <div class="row">
            <div class="small-4 columns">
                <ul>
                    <li>
                        <?=t('Categor&iacute;a');?>: <?= $info_curso['categoria']; ?>
                    </li>
                    <li>
                        <?=t('Subcategor&iacute;a');?>: <?= $info_curso['subcategoria']; ?>
                    </li>
                    <li>
                        <?=t('Tutor');?>: <?= $info_curso['info-tutor']['nombre']; ?>
                    </li>                                        
                </ul>
                <?php print theme('ver_rate_stars', array('item' => $info_curso['rate'] ));?>
            </div>
            <div class="small-4 columns minilistado">
                <?=t('Usuarios populares que han tomado el curso');?>
                <div class="row">
                    <?php mostrar_listado(5, 5, $info_curso['usuarios-populares-curso'], 'elemento_lista_usuarios');?>
                </div>
                <?php //print theme('elemento_lista_usuarios', array('items' => null ));?>                
            </div>
            <div class="small-4 columns end">
                <div class="row">                    
                    <div class="large-5 columns">
                        <b> <?= $info_curso['likes']; ?></b>
                        Me gusta
                    </div>
                    <div class="large-7 columns">
                        <div class="btn_generico"><?=t('ME GUSTA');?></div>
                    </div>                    
                </div>
            </div>            
        </div>                    
    </div>
</div>



    <div class="row">
        <div class="large-3 columns">
            <div id='tab-1' onclick="muestraPanelTab('panel-1', this.id,'')" class="row tab active-tab"><?=t('Informaci&oacute;n');?></div>
        </div>
        <div class="large-2 columns">
            <div id='tab-2' onclick="muestraPanelTab('panel-2', this.id,'');" class="row tab inactive-tab"><?=t('Temario');?></div>
        </div>
        <div class="large-2 columns">
            <div id='tab-3' onclick="muestraPanelTab('panel-3', this.id,'');jQuery('#panel-3').load('proyectos-curso');" class="row tab inactive-tab"><?=t('Proyectos');?></div>
        </div>
        
        <div class="large-2 columns">
            <div id='tab-4' onclick="muestraPanelTab('panel-4', this.id,'');jQuery('#resumen-calificacion-curso').load('resumen-calificaciones-curso');jQuery('#listado-opiniones-curso').load('calificaciones-curso');" class="row tab inactive-tab"><?=t('Calificaciones');?></div>
        </div>
        <div class="large-3 columns">
            <div id='tab-5' onclick="muestraPanelTab('panel-5', this.id,'');jQuery('#panel-5').load('mostrar-preguntas-frecuentes-curso');" class="row tab inactive-tab"><?=t('Preguntas frecuentes');?></div>
        </div>            
        
    </div>

    <div class="row">
        <div class="large-8 columns">
            <div class="contenedor-panels row">
                <div class="large-12 columns active-panel" id="panel-1">
                    <?php if ($info_curso['video'] != null) {?>
                    <iframe width="100%" height="450" src="<?=$info_curso['video'];?>" frameborder="0" allowfullscreen></iframe>
                    <?php }?>
                    <p>
                        <?= $info_curso['descripcion']; ?>                
                    </p>
                    <h3><?= t('OBJETIVOS PRINCIPALES'); ?></h3>
                    <p>
                        <?= $info_curso['objetivosPrincipales']; ?>
                    </p>
                    <h3><?= t('PR&Oacute;XIMAS FECHAS PARA INICIAR EL CURSO'); ?></h3>
                    <?php
                        foreach ($info_curso['fechas'] as $fecha) {
                            print ($fecha.'<br>');
                        }
                    ?>
                </div>
                <div class="large-12 columns inactive-panel" id="panel-2">
                    <?=$info_curso['temario'];?>                    
                </div>
                <div class="inactive-panel" id="panel-3"  >
                    Cargando...    
                </div>
                <div class="inactive-panel calificaciones-curso" id="panel-4">
                    <div id="resumen-calificacion-curso"></div>
                    <h3><?= t('Opiniones más útiles de alumnos que han tomado el curso');?></h3>

                    <div id="listado-opiniones-curso"></div>
                    
                </div>
                <div class="inactive-panel" id="panel-5">
                    Cargando...
                </div>            
            </div>
            
            <h3 class="titulo-carrusel"><?=t('CURSOS RECOMENDADOS');?></h3>
            <div class="row" id="contenedor-carrusel-cursos-sugeridos" >
                
                
            </div>
            
            <div class="row">
                <h3><?=t('COMENTARIOS SOBRE EL CURSO');?></h3>
                <hr>
                <form>
                    <input type="text">
                    <div class="nota-formulario"><?=t('Máx. 600 caracteres');?></div>    
                </form>
                <div class="btn-continuar">Comentar</div>
                <hr>
                <div id='contenedor-comentarios'>
                    
                </div>
                <a href="javascript: obtenerSiguientesComentarios(1,'contenedor-comentarios','mas-comentarios');" id="mas-comentarios" >Ver más</a>
            </div>            
            
            
        </div>
        <div class="large-4 columns">
            <div class="precio-tomar-curso">
                <?=t('Precio FutureED');?><br>
                $ <?=$info_curso['precio']?><br>
                <div class="btn-agregar-carrito"><?= t('A&Ntilde;ADIR AL CARRITO');?></div>
                <div class="btn-agregar-wishlist"><?= t('AGREGAR A CURSOS POR TOMAR');?></div>
                
            </div>
            <div class="informacion-adicional">
                <h3><?= t('FECHA PR&Oacute;XIMA DE INICIO'); ?></h3>
                                
            </div>
            <div class="informacion-adicional">
                <?php print theme('compartir_redes_sociales', array('items' => $items ));?>
            </div>
            <div class="informacion-adicional">
                <h3><?=t('VISTA R&Aacute;PIDA');?></h3>
                <ul>
                    <?php
                        foreach ($info_curso['caracteristicas-principales'] as $info_adicional) {
                            print ('<li>'.$info_adicional.'</li>');
                        }
                    ?>                    
                    
                </ul>            
            </div>
            <div class="informacion-adicional">
                <h3><?=t('SOBRE EL TUTOR');?></h3>
                <div class="row">
                    <div class="large-3 columns">
                        <img src="">
                    </div>
                    <div class="large-9 columns">
                        <?php //var_dump($info_curso['info-tutor']); ?>
                        <a href="usuario/<?= $info_curso['info-tutor']['uid']; ?>"><?= $info_curso['info-tutor']['nombre']; ?></a><br>
                        <?= $info_curso['info-tutor']['institucion']; ?><br>
                        <div class="row">
                            <div class="large-4 columns">
                                <a href="#" class="btn-seguir-usuario">seg</a>
                            </div>
                            <div class="large-4 columns">
                                <a href="#" class="btn-mensaje-usuario">msg</a>
                            </div>
                            <div class="large-4 columns">
                                &nbsp;
                            </div>    
                        </div>
                    </div>                    
                </div>
                <div class="row">
                    <p>
                        <?= $info_curso['info-tutor']['biografia-breve']; ?>
                    </p>
                    <a href="usuario/<?= $info_curso['info-tutor']['uid']; ?>">Ver perfil</a>
                    <? var_dump($info_curso['grupos']); ?>
                </div>
            </div>            
            
            
        </div>
    </div>  



<div id="modal-likes-curso">
    <h3>Usuarios que les ha gustado el curso (<?= $info_curso['likes']; ?>)</h3>
    <hr>
    <div id="contenedor-likes-usuarios">Cargando...</div>
    
    
    <div id="mas-likes-usuarios-curso"><a href="javascript: obtenerSiguientesLikesUsuariosCurso(1,'contenedor-likes-usuarios','mas-likes-usuarios-curso');"  >Ver más</a> </div>
</div>


<script>
    obtenerSiguientesComentarios(<?=$nid_curso?>,'contenedor-comentarios','mas-comentarios');    
    jQuery('#contenedor-carrusel-cursos-sugeridos').load('carrusel-cursos-sugeridos');
    
    
    
    obtenerSiguientesLikesUsuariosCurso(1,'contenedor-likes-usuarios','mas-likes-usuarios-curso');
</script>

  
 

