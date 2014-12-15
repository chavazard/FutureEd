<?php
    switch($item['tipo_curso']){
        case 1:
            $estilo_ico_tipo_curso = "ico-curso-creado";
            break;
        case 2:
            $estilo_ico_tipo_curso = "ico-curso-tomado";
            break;        
        default:
            $estilo_ico_tipo_curso = "ico-curso-tomado";
            break;
    }
?>

<div>
    <div>       
        <a href="<?=$item['link_curso'];?>"><img src="<?=$item['field_curso_imagen'];?>"></a>
        <div class="<?=$estilo_ico_tipo_curso;?>"></div>
    </div>
    <h3><?=$item['field_curso_nombre'];?></h3>
</div>
    
    