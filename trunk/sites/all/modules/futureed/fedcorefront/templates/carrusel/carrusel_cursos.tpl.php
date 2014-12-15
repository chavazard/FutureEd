<?/*<div class="small-<?= $anchoColumnas;?> columns end">

    <div class="row">
        <img src="<?= $item['field_curso_imagen'];?>">
        <h5><?= $item['field_curso_titulo'];?></h5>
        <?= CREADOR ?>:<a href="<?= $item['link_creador'];?>"><?= $item['field_curso_creador'];?></a><br>
        <?= CATEGORIA ?>:<a href="<?= $item['link_categoria'];?>"><?= $item['field_curso_categoria'];?></a><br>
    </div>
    <div class="row">
        <div class="small-4 columns">
            <a href="<?= $item['link_curso'];?>"><button><?= VER_CURSO ?></button></a>
        </div>
        <div class="small-4 columns">
            <?= $item['field_curso_calificacion'];?>
        </div>
         <div class="small-4 columns">
            <?= $item['field_curso_likes']; ?>
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
                <img class="main" src="<?= $item['field_curso_imagen']; ?>">
                <img class="secundaria" src="<?= $item['imagenSecundaria']; ?>">

            </div>

            <div class="contenido">

                <div class = "row titulo">
                    <div class = "large-12 columns"><h1><?= $item['field_curso_titulo'];?></h1></div>
                </div>
                <div class="row info">
                    <div class = "large-12 columns">
                        <p><?= CREADOR ?>:<?= l($item['field_curso_creador'],$item['link_creador'])?></p>
                        <p><?= CATEGORIA ?>:<?= l($item['field_curso_categoria'],$item['link_categoria'])?></p>
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
                <?php 
                /*<div class = "row info">
                    
                    <img src="http://placehold.it/50x50">
                    <img src="http://placehold.it/50x50">
                    <img src="http://placehold.it/50x50">
                    <img src="http://placehold.it/50x50">
                </div>
                */ ?>
                <div class = "row botones">
                    <div class = "large-12 columns">
                        
                        <a class="btn" href="<?= $item['link_curso'];?>"><?= VER_CURSO ?></a>
                    </div>
                </div>
                <div class = "row info">
                    
                    <div class="small-6 columns">
                        <?= $item['field_curso_calificacion'];?>
                    </div>
                     <div class="small-6 columns">
                        <?= $item['field_curso_likes']; ?>
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

