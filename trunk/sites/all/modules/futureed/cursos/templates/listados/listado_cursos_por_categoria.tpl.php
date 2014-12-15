<?php

    $lista_categorias = array();
    $lista_categorias = consultar_categorias();
    
    $tid_categoria = -1;
    if (is_numeric($item['tid_categoria']) ) {
        $tid_categoria = $item['tid_categoria'];
    }
    
    
    ?>
    
    <!---
    <div>
        <label class="labelSelectNoBorde">
            <select class="select-filtro">
                <option value="1">1</option>
                <option value="2">2</option>
                <option value="3">3</option>
            </select>
        </label>
    </div>    
    ---->
<div class="row">
    <div >
        <div class="btn-categorias" onclick="switchMostrarElemento('listado-de-categorias');">
            Categorias        
        </div>
        
        <?php
            $subcategoria_string = "";
            $largo_columnas_categoria = 3;
            if(!is_null($item['nombre_subcategoria'])){
                $subcategoria_string = "&nbsp;&nbsp;>&nbsp;&nbsp;&nbsp;".$item['nombre_subcategoria'];
                $largo_columnas_categoria = 6;
            }
        ?>    
        
        <div class="ubicacion-categoria">            
            >&nbsp;&nbsp;&nbsp; <?=$item['nombre_categoria'].$subcategoria_string;?> 
        </div>
        
        
    </div>
    <hr class="no-margin">
    
    
    <div class="inactive-panel menu-categorias-modal" id="listado-de-categorias">
       <?php print theme('busqueda_categoria_izq', array('item' => $lista_categorias)); ?>
    </div>
</div>        





<?php
    $itemFiltros = array('contenedor' => 'contenedor-listado-cursos-por_categoria',
                         'f_name'     => 'mostrar_grid_cursos_categoria',
                         'parametros_extra'     => 'categoria:'.$tid_categoria);

    print theme('filtros-cursos',array('item' => $itemFiltros));


?>
     
<div id="contenedor-listado-cursos-por_categoria" class="contenedor-listado-grid">
    
</div>

<script>

    parametros = 'categoria:<?=$tid_categoria;?>';
    parametros += ',modalidad:-1';
    parametros += ',tipo:-1';
    parametros += ',ordenamiento:-1';
    parametros += ',calificacion:-1';
    parametros += ',rango_precio_min:-1';
    parametros += ',rango_precio_max:-1';
    callAjax('contenedor-listado-cursos-por_categoria','mostrar_grid_cursos_categoria','pagina: 1, '+parametros+',div_contenedor: \'contenedor-listado-cursos-por_categoria\'');
</script>
