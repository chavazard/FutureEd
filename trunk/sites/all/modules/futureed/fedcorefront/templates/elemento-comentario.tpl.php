<?php $uid = 9; ?>
<div>
    <hr>
    <img src="<?=$item['imagen-usuario'];?>">
    <?=$item['nombre-usuario']?> - <?=$item['fecha-hora']?> <br>
    <p><?=$item['comentario']?></p>
    
    <div id="me-gusta-<?=$item['nid'];?>">
        <?php if ($item['field_comentario_megusta']) { ?>
            <a href="javascript: callAjax('me-gusta-<?=$item['nid'];?>','toggle_me_gusta','nid:<?=$item['nid'];?>, me_gusta: true, uid: <?=$uid?>');" onclick="this.parentNode.removeChild(this);"><?=t('Me gusta');?></a>
        <?php } else { ?>
            <a href="javascript: callAjax('me-gusta-<?=$item['nid'];?>','toggle_me_gusta','nid:<?=$item['nid'];?>, me_gusta: false, uid: <?=$uid?>');" onclick="this.parentNode.removeChild(this);"><?=t('Ya no me gusta');?></a>
        <?php } ?>
    </div>    
    <?=$item['field_comentario_megusta_total']?> Me gusta
    
    <?php if ($item['calc_comentario_respuestas'] != null) {    
        foreach($item['calc_comentario_respuestas'] as $respuesta)
        { ?>
            <div class="respuesta-comentario">
                <img src="<?=$respuesta['imagen-usuario'];?>">
                <?=$respuesta['nombre-usuario']?> - <?=$respuesta['fecha-hora']?> <br>
                <p><?=$respuesta['comentario']?></p>
                <div id="me-gusta-<?=$respuesta['nid'];?>">
                    <?php if ($item['field_comentario_megusta']) { ?>
                        <a href="javascript: callAjax('me-gusta-<?=$respuesta['nid'];?>','toggle_me_gusta','nid:<?=$respuesta['nid'];?>, me_gusta: true, uid: <?=$uid?>');" onclick="this.parentNode.removeChild(this);"><?=t('Me gusta');?></a>
                    <?php } else { ?>
                        <a href="javascript: callAjax('me-gusta-<?=$respuesta['nid'];?>','toggle_me_gusta','nid:<?=$respuesta['nid'];?>, me_gusta: false, uid: <?=$uid?>');" onclick="this.parentNode.removeChild(this);"><?=t('Ya no me gusta');?></a>
                    <?php } ?>
                </div>
                <?=$respuesta['field_comentario_megusta_total']?> Me gusta
                <hr>
            </div>
        <?php        
        }
    } ?>
    <a id="link-responder-comentario-<?=$item['nid'];?>" href="javascript: mostrarElemento('responder-comentario-<?=$item['nid'];?>', true);mostrarElemento('link-responder-comentario-<?=$item['nid'];?>',false);">Responder</a>
    <div id="responder-comentario-<?=$item['nid'];?>" style="display: none">
        Formulario Responder comentario
    </div>
</div>