
<div class="row">
<?php
    $estrellasDisponibles = 5;
    $numeroEstrellasEnteras = intval($item['calificacion']);
    $pathImagenes = base_path().drupal_get_path('module','fedcorefront').'/images/';
            
    if ($item['calificacion'] > $numeroEstrellasEnteras){
        $mediaEstrella = true;
        $numeroEstrellasVacias = $estrellasDisponibles - $numeroEstrellasEnteras - 1;        
    }
    else{
        $mediaEstrella = false;
        $numeroEstrellasVacias = $estrellasDisponibles - $numeroEstrellasEnteras; 
    }
    
    for ($i = 1; $i <= $numeroEstrellasEnteras; $i++)
    { ?>
        <div class="small-2 columns end rate-stars">
            <img class="rate-stars-img" src="<?=$pathImagenes;?>rate-full.jpg">
        </div>
    <?php         
    }
 
    if ($mediaEstrella == true) { ?>
        <div class="small-2 columns end rate-stars">
            <img class="rate-stars-img" src="<?=$pathImagenes;?>rate-half.jpg">
        </div>
    <?php
    }
    
    for ($i = 1; $i <= $numeroEstrellasVacias; $i++)
    { ?>
        <div class="small-2 columns end rate-stars " style="text-align: right">
            <img class="rate-stars-img" src="<?=$pathImagenes;?>rate-empty.jpg">
        </div>    
    
    <?php         
    }    
    

    
?>
    <?php
    if (isset($item['numero-votos']))
    {?>          
        <div class="small-2 columns end rate-stars numero-votos">
           (<?=$item['numero-votos']?>)
        </div>
    <?php
    }    
    ?>

</div>



