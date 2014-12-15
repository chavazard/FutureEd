<div class="item">
    <div class="item-lista-chica">
            <div class="top">
                <a href="<?=$item['link_curso'];?>" class="action">
                    <img src="<?=$item['field_curso_imagen'];?>">
                </a>
                <img class="main" src="<?= $item['field_curso_imagen']; ?>">
                <img class="secundaria" src="<?= $item['imagenSecundaria']; ?>">

            </div>

            <div class="contenido">

                <div class = "row titulo">
                <div class = "large-12 columns"><h1><?= $item['field_curso_nombre'];?></h1></div>

                <?php if ($item['field_empresa_certificado'] == 1){?>
                    <img src="http://placehold.it/10x10">
                <?php }?>


                </div>
                <div class="row info">
                    <div class = "large-12 columns">
                        <p><?= CREADOR;?>: <a href="<?=$item['link_curso_creador'];?>"><?=$item['creador_curso_nombre'];?></a></p>
                        <p><?= CATEGORIA; ?>:<a href="<?=$item['link_curso_categoria'];?>"><?=$item['field_curso_categoria'];?></a></p>
                        <p><?= CANALES; ?>:<a href="<?= $item['link_canales'];?>"><?= $item['field_empresa_canales'];?></a></p>
                    </div>
                </div>

                <div class = "row info">
                    <?php mostrar_calificacion_estrellas($item['field_curso_calificacion'],$item['field_curso_numero_votos']);?>
                </div>
                                
            </div>

    </div>
    
</div>




 <!---<div class="btn-wishlist-elemento-listado" onclick="agregarWishlist(<?//=$item['nid_curso'];?>)"></div>--->
