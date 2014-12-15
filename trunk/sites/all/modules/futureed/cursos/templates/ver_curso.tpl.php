<?php $info_curso = $items['data'][0]; ?>

<?php $module_path = base_path().drupal_get_path('module', 'cursos').'/inc/proyectos_curso.php';?>
<div class="row">
    <div class="large-2 columns">
        
    </div>
    <div class="large-10 columns">
        <h1>
            <?= $info_curso['titulo']; ?>
        </h1>        
        <a href=""></a>
        <?=t('Categor&iacute;a');?>: <a href="<?= $module_path;?>">llll</a>
        <div class="row">
            <div class="large-4 columns">
                <ul>
                    <li>
                        <?=t('Categor&iacute;a');?>:
                    </li>
                    <li>
                        <?=t('Subcategor&iacute;a');?>:
                    </li>
                    <li>
                        <?=t('Tutor');?>:
                    </li>                                        
                </ul>
            </div>
            <div class="large-5 columns">
                <?=t('Usuarios populares que han tomado el curso');?>                
            </div>
            <div class="large-3 columns">
                <div class="row">
                    <div class="large-5">
                        Me gusta
                    </div>
                    <div class="large-7">
                        <a href="#" class="btn_generico"><?=t('ME GUSTA');?></a>
                    </div>                    
                </div>
            </div>            
        </div>                    
   
    <!---
        <div class="row">
            <div class="large-3 columns tab active-tab" id='tab-1' onclick="muestraPanelTab('panel-1')">
                <?=t('Informaci&oacute;n');?>
            </div>
            <div class="large-2 columns tab inactive-tab" id='tab-2' onclick="muestraPanelTab('panel-2')">
                <?=t('Temario');?>
            </div>
            <div class="large-2 columns tab inactive-tab" id='tab-3'" onclick="muestraPanelTab('panel-3')">
               <?=t('Proyectos');?>
            </div>
            <div class="large-2 columns tab inactive-tab" id='tab-4'"onclick="muestraPanelTab('panel-4')">
                <?=t('Calificaciones');?>
            </div>
            <div class="large-3 columns tab inactive-tab" id='tab-5' onclick="muestraPanelTab('panel-5')">
                <?=t('Preguntas frecuentes');?>
            </div>            
            
        </div>
        -->

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
            <div id='tab-5' onclick="muestraPanelTab('panel-5', this.id,'')" class="row tab inactive-tab"><?=t('Preguntas frecuentes');?></div>
        </div>            
        
    </div>

    <div class="row">
        <div class="large-8 columns">
            <div class="contenedor-panels row">
                <div class="large-12 columns active-panel" id="panel-1">
                    <img src="<= $args['imagen']; ?>" style="width:100%;">
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
                    
                        <div>
                            <div class="large-4 columns">
                                <div id='tabB-1' onclick="muestraPanelTab('panelB-1', this.id,'anidado')" class="row tab-anidado active-tab-anidado" >op 1</div>
                            </div>
                            <div class="large-4 columns">
                                <div id='tabB-2' onclick="muestraPanelTab('panelB-2', this.id,'anidado')" class="row tab-anidado inactive-tab-anidado" >op 2</div>
                            </div>
                            <div class="large-4 columns">
                                <div id='tabB-3' onclick="muestraPanelTab('panelB-3', this.id,'anidado')" class="row tab-anidado inactive-tab-anidado" >op 3</div>
                            </div>                          
                        </div>
                
                        <div class="contenedor-panels-anidado">
                            <div class="active-panel-anidado" id="panelB-1">
                                <p>1 opcion anidada.</p>
                            </div>
                            <div class="inactive-panel-anidado" id="panelB-2">
                                <p>2a opcion anidada.</p>
                            </div> <div class="inactive-panel-anidado" id="panelB-3" >
                                <p>3a opcion anidada.</p>
                            </div>        
                        </div>                   
        
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
                    <p>This is the 5 panel of the basic tab example. This is the fourth panel of the basic tab example.</p>
                </div>            
            </div>
            
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
                <a href="javascript: obtenerSiguientesComentarios()" id="mas-comentarios" >Ver más</a>
            </div>            
            
            
        </div>
        <div class="large-4 columns">
            <div class="precio-tomar-curso">
                <?=t('Precio FutureED');?><br>
                $ <?= '---'?><br>
                <a href="#" class="btn-agregar-carrito"><?= t('A&Ntilde;ADIR AL CARRITO');?></a>
                <a href="#" class="btn-agregar-wishlist"><?= t('AGREGAR A CURSOS POR TOMAR');?></a>
                
            </div>
            <div class="informacion-adicional">
                <h3><?= t('FECHA PR&Oacute;XIMA DE INICIO'); ?></h3>
                                
            </div>
            <div class="informacion-adicional">
                <h3><?=t('COMPARTIR');?></h3>
                <a href="#" class="btn-facebook">&nbsp;</a>
                <a href="#" class="btn-gplus">&nbsp;</a>
                <a href="#" class="btn-twitter">&nbsp;</a>
                <a href="#" class="btn-linkedin">&nbsp;</a>
                <a href="#" class="btn-futureEd">&nbsp;</a>
                <a href="#" class="btn-mail">&nbsp;</a>
            </div>
            <div class="informacion-adicional">
                <h3><?=t('VISTA R&Aacute;PIDA');?></h3>
                <ul>
                    <?php
                        foreach ($info_curso['datos-adicionales'] as $info_adicional) {
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


>>>>>>> .r60
<script>
    //callAjax('contenedor-ajax','print_preguntas_frecuentes','parametro1: 25, parametro2: \'texto\' ');
    /*obtenerSiguientesComentarios(<?=$nid_curso?>,'contenedor-comentarios','mas-comentarios');    
    jQuery('#contenedor-carrusel-cursos-sugeridos').load('carrusel-cursos-sugeridos');
    
    
    
    obtenerSiguientesLikesUsuariosCurso(1,'contenedor-likes-usuarios','mas-likes-usuarios-curso');*/
</script>
  
 

