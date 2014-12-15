<div class="preguntas-frecuentes-cursos">
   
<?php
    foreach($items as $item)
    {?>
       <h3><?=$item['pregunta'];?></h3>
       <p><?=$item['respuesta'];?></p>
    <?php    
    }  
?>
</div>