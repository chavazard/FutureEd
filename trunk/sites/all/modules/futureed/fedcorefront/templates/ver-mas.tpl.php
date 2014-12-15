<?php

    if ($item['parametros'] != null && $item['parametros'] != ''){
        //$parametrosExtrasVerMas = ','.$item['parametros'];
        $parametrosExtrasVerMas = $item['parametros'];
    }
    else{
        $parametrosExtrasVerMas = '';
    }
    
    if ($item['ultimo_nid'] != null) {
?>
    <div onclick="appendAjax('<?=$item['div_contenedor'];?>','<?=$item['f_name'];?>','<?=$parametrosExtrasVerMas?>,  ultimo_nid: <?=$item['ultimo_nid'];?>, div_contenedor: \'<?=$item['div_contenedor'];?>\'');this.parentNode.removeChild(this);">
        Ver más
    </div>
<?php

}

?>