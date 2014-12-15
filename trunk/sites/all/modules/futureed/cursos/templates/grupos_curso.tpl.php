<h3><?=t('GRUPOS DEL CURSO');?></h3>
<ul>
<?php

    foreach($items as $info_grupo){   ?>
    
    	<li class="grupos-curso">
            <img src="<?=$info_grupo['field_grupo_imagen'];?>">
	    <a href="<?=$info_grupo['field_grupo_imagen'];?>"><?=$info_grupo['field_grupo_nombre'];?></a>
        </li>	

                
     
     <?php           
    }
?>
</ul>