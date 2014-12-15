<?php if ($info_curso['video'] != null) {?>
<iframe width="100%" height="450" src="<?=$info_curso['video'];?>" frameborder="0" allowfullscreen></iframe>
<?php }?>
<p>
    <?= $info_curso['descripcion']; ?>                
</p>
<h3><?= OBJETIVOS_PRINCIPALES; ?></h3>
<p>
    <?= $info_curso['objetivosPrincipales']; ?>
</p>
<h3><?= FECHAS_INICIAR_CURSO; ?></h3>
<?php
    foreach ($info_curso['fechas'] as $fecha) {
        print ($fecha.'<br>');
    }
?>