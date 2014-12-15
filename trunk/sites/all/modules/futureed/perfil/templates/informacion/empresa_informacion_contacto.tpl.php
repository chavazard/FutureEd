<?php

define ("INFO_NOSOTROS_TXT1", t('CONTACTO'));
define ("", t(''));
define ("", t(''));
define ("", t(''));

?>

<style type="text/css">
#sobre_nosotros{
    background-color: #F5F5F5;
    margin: 0;
    padding: 0;
}

#titulo_sobre_nosotros{
    background-color: #D85034;
    color: #FFFFFF;
}
</style>

<div class="row" id="sobre_nosotros">
    <h5 id="titulo_sobre_nosotros"><?= INFO_NOSOTROS_TXT1;?></h5>

    <b><?= t('Dirección');?></b> 
    <p><?= $item[0]['calc_usuario_direccion'];?></p>

    
    <b><?= t('Telefono');?></b> 
    <p><?= $item[0]['field_empresa_telefono'];?></p>
    
    <b><?= t('Sitio web');?></b> 
    <a href="<?= $item[0]['field_usuario_sitio_web'];?>"><p><?= $item[0]['field_usuario_sitio_web'];?></p></a>

</div>
