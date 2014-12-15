<?php /*<div class="small-<?= $anchoColumnas;?> columns end">

    <div class="row">
        <img src="<?= $item['field_empresa_imagen'];?>">
        <h5><?= $item['field_empresa_nombre'];?></h5>
        <?php if ($item['field_empresa_certificado'] == 1){?>
            <img src="http://placehold.it/10x10">
        <?php }?>
        <div><?= $item['field_empresa_ubicacion'];?></div>
        <?= SEGUIDORES; ?>:<a href="#"><?= $item['field_empresa_seguidores'];?></a><br>
        <?= CANALES; ?>:<a href="<?= $item['link_canales'];?>"><?= $item['field_empresa_canales'];?></a><br>
    </div>
    <div class="row">
        <div class="small-8 columns">
            <b><?= t('Canales populares')?></b>
            <div>
            <?php foreach ($item['field_empresa_canales_populares'] as $items){ ?>
                <img src="<?php echo $items?>">
            <?php }?>
            </div>
        </div>
        <div class="small-4 columns">
            <a href="<?= $item['link_cursos'];?>"><?= $item['field_empresa_cursos'];?></a>
            <b><?= CURSOS; ?></b>
        </div>
    </div>
    <div class="row">
        <div class="small-4 columns">
            <a href="<?= $item['link_empresa'];?>"><button><?= VER_EMPRESA;?></button></a>
        </div>
        <div class="small-4 columns">
            <?= $item['field_empresa_calificacion'];?>
        </div>
        <div class="small-4 columns">
            <?= $item['field_empresa_likes'];?>
        </div>
    </div>   

</div>
*/?>


<div class="small-<?= $anchoColumnas;?> columns end item">
    <div class="item-lista-chica">
            <div class="top">
                <a href="javascript:void(0)" onclick="console.log('funciona =)');console.log('<?= $item['idGrupo']?>')" class="action">
                    <img src="<?= $item['imagen']; ?>">
                </a>
                <img class="main" src="<?= $item['field_empresa_imagen']; ?>">
                <img class="secundaria" src="<?= $item['imagenSecundaria']; ?>">

            </div>

            <div class="contenido">

                <div class = "row titulo">
                    <div class = "large-12 columns"><h1><?= $item['field_empresa_nombre'];?></h1></div>

                    <?php if ($item['field_empresa_certificado'] == 1){?>
            <img src="http://placehold.it/10x10">
        <?php }?>


                </div>
                <div class="row info">
                    <div class = "large-12 columns">
                        <p><?= $item['field_empresa_ubicacion'];?></p>
                        <p><?= SEGUIDORES; ?>:<a href="#"><?= $item['field_empresa_seguidores'];?></a></p>
                        <p><?= CANALES; ?>:<a href="<?= $item['link_canales'];?>"><?= $item['field_empresa_canales'];?></a></p>
                    </div>
                </div>


                <?php 
                /*<div class = "row info">
                    <div class = "large-2 columns"><i>PANT.</i></div>
                    <div class = "large-10 columns"><p><?= $item['tipoCurso']; ?></p></div>
                    <div class = "large-10 columns"><p><?= $item['tipoCurso']; ?></p></div>
                </div>
                */ ?>
                <?php 
                /*<div class = "row info">
                    <div class = "large-2 columns"><i>CAL.</i></div>
                    <div class = "large-10 columns">
                        <p><?= INICIO_2;?>: <?= $item['fechaInicio']; ?></p>
                        <p><?= TERMINO;?>: <?= $item['fechaFin']; ?></p>
                    </div>
                </div>
                */ ?>

                <?php 
                /*<div class = "row info">
                    <h2><?= PRECIO ?>: <?= l("$1,500.00",'path.com');?></h2>
                </div>
                */ ?>
                <div class = "row info">
                    <?php foreach ($item['field_empresa_canales_populares'] as $items){ ?>
                        <img src="<?php echo $items?>">
                    <?php }?>
                </div>
                
                <div class = "row botones">
                    <div class = "large-12 columns">
                        
                        <a class="btn" href="<?= $item['link_empresa'];?>"><?= VER_EMPRESA ?></a>
                    </div>
                </div>
                <div class = "row info">
                    
                    <div class="small-6 columns">
                        <?= $item['field_empresa_calificacion'];?>
                    </div>
                     <div class="small-6 columns">
                        <?= $item['field_empresa_likes']; ?>
                    </div>
                </div>
                
                
                <?php /*
                <div class = " foot">
                        <p><?= APOYO_FUNDACION; ?></p>
                        <p><?= $item['fundacion'];?></p>
                    
                </div>
                */ ?>
            </div>

    </div>
    
</div>


