<?php

define ("INFO_SOBRE_TXT1", t('SOBRE NOSOTROS'));
define ("", t(''));
define ("", t(''));

?>

<style type="text/css">
#contacto{
    background-color: #FFFFFF;
    margin: 0;
    padding: 0;
    border: 1px solid #F5F5F5;
}

#titulo_contacto{
    background-color: #44B4C5;
    color: #FFFFFF;
}
</style>

<div class="row" id="contacto">
    <h5 id="titulo_contacto"><?= INFO_SOBRE_TXT1;?></h5>

    <p><?= $item[0]['field_empresa_nosotros'];?></p>
    
    <b><?= t('Misión');?></b> 
    <p><?= $item[0]['field_empresa_mision'];?></p>
    
    <b><?= t('Visión');?></b> 
    <p><?= $item[0]['field_empresa_vision'];?></p>
 
</div>