<?php $nid_curso = 3; ?>
<h3><?= USUARIOS_GUSTADO_CURSO; ?> (<?=$likes;?>)</h3>
<hr>
<div id="listado-usuarios">

</div>
<hr>
    
<script>
    appendAjax('listado-usuarios','print_lista_megusta_curso','nid_curso: <?=$nid_curso;?>, ultimo_nid: -1, div_contenedor: \'listado-usuarios\'');
</script>    