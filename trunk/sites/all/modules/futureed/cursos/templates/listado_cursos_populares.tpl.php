<h3>+ <?=CURSOS_POPULARES; ?></h3>

<div id="contenedor-listado-cursos-populares">
    
</div>

<?php     
            
    if ($item['resumen'] == true)
    {
        $resumen = 'true';
    ?>
        <div class="">
            <a href="<?= base_path().'cursos-populares'?>"><?=VER_MAS;?></a>
        </div>
    <?php
    }else{
         $resumen = 'false';
    }
?>

<script>
    callAjax('contenedor-listado-cursos-populares','mostrar_grid_cursos_populares','pagina: 1, resumen: <?= $resumen;?>,div_contenedor: \'contenedor-listado-cursos-populares\'');
</script>