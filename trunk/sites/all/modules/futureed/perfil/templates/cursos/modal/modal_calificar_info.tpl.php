<div class="large-6 columns">
    <img src="<?= $item[0]["field_curso_imagen"]; ?>">
</div>
<div class="large-6 columns">
    <p><?= $item[0]["field_curso_nombre"]; ?></p> 
    <p><?= CANAL; ?><a href="<?= $item[0]["link_curso_canal"]; ?>"> <?= $item[0]["field_curso_canal"]; ?></a></p> 
    <?php foreach($item[0]["array_curso_tutores"] AS $tutor[0]) { ?>
    <p><?= TUTOR; ?><a href="<?= $tutor[0]["link_nombre_tutor"]; ?>"> <?= $tutor[0]["calc_nombre_tutor"]; ?></a></p> 
    <?php } ?>
</div>
