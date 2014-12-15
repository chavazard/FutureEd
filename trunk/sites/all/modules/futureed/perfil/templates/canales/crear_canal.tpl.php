<?
/* 
drupal_add_js(base_path().drupal_get_path('module','perfil').'js/jquery-1.10.2.js'); 
drupal_add_js(base_path().drupal_get_path('module','perfil').'js/jquery-ui.js'); 
drupal_add_css(base_path().drupal_get_path('module','perfil').'css/jquery-ui.css'); 
*/
?>

<script type="text/javascript">
/*Funcion para autocompletar y agregar tutores*/
jQuery(function($) {
$.widget( "custom.catcomplete", $.ui.autocomplete, {
  _create: function() {
    this._super();
    this.widget().menu( "option", "tutor", "> :not(.ui-autocomplete-category)" );
  },
  _renderMenu: function( ul, items ) {
    var that = this,
      currentCategory = "";
    $.each( items, function( index, item ) {

    var li;
    li = that._renderItemData( ul, item );
    li.attr( "id-tutores", item.id);
    });
  }
});

  $("#edit-agregar-tutores").click(function(){
    var valortutor;
    valorTutor = $( "#edit-hidden-tutores" ).val();
    appendAjax('lista_tutores','show_crear_canal_tutores','uid_tutor: '+ valorTutor +', pagina: 1, div_contenedor: \'lista_tutores\'');
  });

  var tutor = [
    { label: "tutor 1", id:"11"},
    { label: "tutor 2", id:"12"},
    { label: "tutor 3", id:"13"},
    { label: "tutor 4", id:"14"},
    { label: "tutor 5", id:"15"},
    { label: "tutor 6", id:"16"},
    { label: "tutor 7", id:"17"},
    { label: "tutor 8", id:"18"},
    { label: "tutor 9", id:"19"},
    { label: "tutor 10", id:"20"},
  ];  

  //Función 
  function guardaID( message ) {
      $( "#edit-hidden-tutores" ).val( message );
      console.log(message);
    }

  $( "#edit-campo-texto-tutores" ).catcomplete({
    source: tutor,
    select: function( event, ui ) {
        guardaID( ui.item ?
          ui.item.id :
          0);
      }
  });

  $('#lista_tutores').on('click', '.Remove', function() {
      $(this).closest('#item-tutor').remove();
  });
});
</script>

<!--****************************************************************************-->

<script type="text/javascript">
/*Funcion para autocompletar y agregar cursos*/
jQuery(function($) {
$.widget( "custom.catcomplete", $.ui.autocomplete, {
  _create: function() {
    this._super();
    this.widget().menu( "option", "curso", "> :not(.ui-autocomplete-category)" );
  },
  _renderMenu: function( ul, items ) {
    var that = this,
      currentCategory = "";
    $.each( items, function( index, item ) {

    var li;
    li = that._renderItemData( ul, item );
    li.attr( "id-cursos", item.id);
    });
  }
});


  $("#edit-boton-agregar-cursos").click(function(){
    var valorcurso;
    valorCurso = $( "#edit-hidden-agregar-cursos" ).val();
    appendAjax('lista_agregar_cursos','show_crear_canal_cursos','uid_curso: '+ valorCurso +', pagina: 1, div_contenedor: \'lista_agregar_cursos\'');
  });

  var curso = [
    { label: "curso 1", id:"21"},
    { label: "curso 2", id:"22"},
    { label: "curso 4", id:"24"},
    { label: "curso 3", id:"23"},
    { label: "curso 5", id:"25"},
    { label: "curso 6", id:"26"},
    { label: "curso 7", id:"27"},
    { label: "curso 8", id:"28"},
    { label: "curso 9", id:"29"},
    { label: "curso 10", id:"30"},
  ];  

  //Fuynción 
  function guardaID( message ) {
      $( "#edit-hidden-agregar-cursos" ).val( message );
      console.log(message);
    }

  $( "#edit-campo-texto-agregar-cursos" ).catcomplete({
    source: curso,
    select: function( event, ui ) {
        guardaID( ui.item ?
          ui.item.id :
          0);
      }
  });

  $('#lista_agregar_cursos').on('click', '.Remove', function() {
      $(this).closest('#item-curso').remove();
  });
});
</script>

<!--****************************************************************************-->

<script type="text/javascript">
/*Funcion para autocompletar y agregar administradores*/
jQuery(function($) {
$.widget( "custom.catcomplete", $.ui.autocomplete, {
  _create: function() {
    this._super();
    this.widget().menu( "option", "administrador", "> :not(.ui-autocomplete-category)" );
  },
  _renderMenu: function( ul, items ) {
    var that = this,
      currentCategory = "";
    $.each( items, function( index, item ) {

    var li;
    li = that._renderItemData( ul, item );
    li.attr( "id-administradores", item.id);
    });
  }
});


  $("#edit-agregar-administradores").click(function(){
    var valoradmin;
    valorAdmin = $( "#edit-hidden-administradores" ).val();
    appendAjax('lista_administradores','show_crear_canal_administradores','uid_administrador: '+ valorAdmin +', pagina: 1, div_contenedor: \'lista_administradores\'');
  });

  var administrador = [
    { label: "administrador 1", id:"31"},
    { label: "administrador 2", id:"32"},
    { label: "administrador 4", id:"34"},
    { label: "administrador 3", id:"33"},
    { label: "administrador 5", id:"35"},
    { label: "administrador 6", id:"36"},
    { label: "administrador 7", id:"37"},
    { label: "administrador 8", id:"38"},
    { label: "administrador 9", id:"39"},
    { label: "administrador 10", id:"40"},
  ];  

  //Fuynción 
  function guardaID( message ) {
      $( "#edit-hidden-administradores" ).val( message );
      console.log(message);
    }

  $( "#edit-campo-texto-administradores" ).catcomplete({
    source: administrador,
    select: function( event, ui ) {
        guardaID( ui.item ?
          ui.item.id :
          0);
      }
  });

  $('#lista_administradores').on('click', '.Remove', function() {
      $(this).closest('#item-administrador').remove();
  });
});
</script>

<!--****************************************************************************-->

<script type="text/javascript">
jQuery(function($) {
 jQuery("#edit-agregar-tutores").prop("type", "button");
 jQuery("#edit-boton-agregar-cursos").prop("type", "button");
 jQuery("#edit-agregar-administradores").prop("type", "button");
 jQuery("#edit-boton").prop("type", "button");
});

jQuery(function($) {
	console.log("jQuery cargado exitosamente");
});
</script>


<h4>Crear Canal</h4>
<div class="row">
  <div class="small-12 columns">
    <?php print drupal_render(drupal_get_form('canales_form'));?>
  </div>
</div>