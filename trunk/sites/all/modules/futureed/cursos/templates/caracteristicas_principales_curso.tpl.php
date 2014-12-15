<h3><?=VISTA_RAPIDA;?></h3>
<ul>
        <?php if ($info_curso['field_curso_modalidad'] != null) { ?>           
            <li><?=$info_curso['field_curso_modalidad'];?></li>
        <?php } ?>    
        <?php if ($info_curso['fiel_curso_tutoreo'] != null) { ?>           
            <li><?=$info_curso['fiel_curso_tutoreo'];?></li>
        <?php } ?>
        <?php if ($info_curso['field_curso_idioma'] != null) { ?>           
            <li><?=$info_curso['field_curso_idioma'];?></li>
        <?php } ?>            
</ul>  