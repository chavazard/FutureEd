<?php
  $PLANTILLA_1_COLUMNA  = 1;
  $PLANTILLA_2_COLUMNAS_IZQUIERDA = 2;
  $PLANTILLA_2_COLUMNAS_DERECHA = 3;
  $PLANTILLA_3_COLUMNAS = 4;
  
  $TAMANO_PEQUENO = 1;
  $TAMANO_MEDIANO = 2;
  $TAMANO_GRANDE  = 3;

  global $tamano_columna_izquierda_debug;
  $tamano_columna_izquierda_debug = $TAMANO_PEQUENO;  //Aplica sólo para template de 3 columnas
  $tipo_plantilla = $PLANTILLA_3_COLUMNAS;
 	
?>

<!--.page -->
<div role="document" class="page">

  <!--.l-header region -->
  <header role="banner" class="l-header">

    <?php if ($top_bar): ?>
      <!--.top-bar -->
      <?php if ($top_bar_classes): ?>
      <div class="<?php print $top_bar_classes; ?>" >
      <?php endif; ?>
      
      
      
      
      
          <?php /*if ($user->uid <= 0) 
              include 'general/logged-out.tpl.php';
            else
              include 'general/logged-in.tpl.php';
            */
           ?>

      <?php if ($top_bar_classes): ?>
      </div>
      <?php endif; ?>
      <!--/.top-bar -->
    <?php endif; ?>

    
    <!-- Title, slogan and menu -->
    <?php if ($alt_header): ?>
    <section class="row <?php print $alt_header_classes; ?>">

      <?php if ($linked_logo): print $linked_logo; endif; ?>

      <?php if ($site_name): ?>
        <?php if ($title): ?>
          <div id="site-name" class="element-invisible">
            <strong>
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </strong>
          </div>
        <?php else: /* Use h1 when the content title is empty */ ?>
          <h1 id="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>
      <?php endif; ?>

      <?php if ($site_slogan): ?>
        <h2 title="<?php print $site_slogan; ?>" class="site-slogan"><?php print $site_slogan; ?></h2>
      <?php endif; ?>

      <?php if ($alt_main_menu): ?>
        <nav id="main-menu" class="navigation" role="navigation">
          <?php print ($alt_main_menu); ?>
        </nav> <!-- /#main-menu -->
      <?php endif; ?>

      <?php if ($alt_secondary_menu): ?>
        <nav id="secondary-menu" class="navigation" role="navigation">
          <?php print $alt_secondary_menu; ?>
        </nav> <!-- /#secondary-menu -->
      <?php endif; ?>

    </section>
    <?php endif; ?>
    <!-- End title, slogan and menu -->

    <?php if (!empty($page['header'])): ?>
      <!--.l-header-region -->
      <section >
        <div class="large-12 columns">
          <?php print render($page['header']); ?>
        </div>
      </section>
      <!--/.l-header-region -->
    <?php endif; ?>

  </header>
  <!--/.l-header -->
  
  
  
  
  

  <?php if (!empty($page['featured'])): ?>
    <!--/.featured -->
    <section class="l-featured row">
      <div class="large-12 columns">
        <?php print render($page['featured']); ?>
      </div>
    </section>
    <!--/.l-featured -->
  <?php endif; ?>

  <?php if ($messages && !$zurb_foundation_messages_modal): ?>
    <!--/.l-messages -->
    <section class="l-messages row">
      <div class="large-12 columns">
        <?php if ($messages): print $messages; endif; ?>
      </div>
    </section>
    <!--/.l-messages -->
  <?php endif; ?>

  <?php if (!empty($page['help'])): ?>
    <!--/.l-help -->
    <section class="l-help row">
      <div class="large-12 columns">
        <?php print render($page['help']); ?>
      </div>
    </section>
    <!--/.l-help -->
  <?php endif; ?>

  <main role="main" class="row l-main">

    <!--/.main region -->
    


  
    <div class="regiones-principales">
      <?php
          /* Codigo sólo para debug*/
          /*
          switch ($tipo_plantilla)
          {
            case $PLANTILLA_1_COLUMNA:
              include 'general/1-column.tpl.php';
              break;
            case $PLANTILLA_2_COLUMNAS_IZQUIERDA:
              include 'general/2-columns-left.tpl.php';
              break;        
            case $PLANTILLA_2_COLUMNAS_DERECHA:
              include 'general/2-columns.tpl.php';
              break;
            case $PLANTILLA_3_COLUMNAS:
              include 'general/3-columns.tpl.php';
              break;        
          }*/
          /* Fin de codigo para debug*/
      
      /*    Este codigo es el bueno*/
              if (empty($page['sidebar_first']) && empty($page['sidebar_second'])){ 
                  include 'general/1-column.tpl.php';
                }else if (empty($page['sidebar_first'])){
                  include 'general/2-columns.tpl.php';
                }else if (empty($page['sidebar_second'])){
                  include 'general/2-columns-left.tpl.php';
                }else
                  include 'general/3-columns.tpl.php';
            
       ?>  
    </div>
  </main>
  <!--/.main-->   
   
   
  
  <?php if (!empty($page['triptych_first']) || !empty($page['triptych_middle']) || !empty($page['triptych_last'])): ?>
    <!--.triptych-->
    <section class="l-triptych row">
      <div class="triptych-first large-2 columns">
        <?php print render($page['triptych_first']); ?>
      </div>
      <div class="triptych-middle large-4 columns">
        <?php //print render($page['triptych_middle']); ?>
      </div>
      <div class="triptych-last large-4 columns">
        <?php print render($page['triptych_last']); ?>
      </div>
    </section>
    <!--/.triptych -->
  <?php endif; ?>
  

  <?php if (!empty($page['footer_firstcolumn']) || !empty($page['footer_secondcolumn']) || !empty($page['footer_thirdcolumn']) || !empty($page['footer_fourthcolumn'])): ?>
    <!--.footer-columns -->
    <section class="row l-footer-columns">
      <?php if (!empty($page['footer_firstcolumn'])): ?>
        <div class="footer-first large-3 columns">
          <?php print render($page['footer_firstcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_secondcolumn'])): ?>
        <div class="footer-second large-3 columns">
          <?php print render($page['footer_secondcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_thirdcolumn'])): ?>
        <div class="footer-third large-3 columns">
          <?php print render($page['footer_thirdcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_fourthcolumn'])): ?>
        <div class="footer-fourth large-3 columns">
          <?php print render($page['footer_fourthcolumn']); ?>
        </div>
      <?php endif; ?>
    </section>
    <!--/.footer-columns-->
  <?php endif; ?>

  
  
 
  <!--.l-footer-->
   <?php if (!empty($page['footer'])): ?>
    <footer class="l-footer panel" role="contentinfo">
      <div class="row">
        
          <div class="footer large-12 columns">
            <?php print render($page['footer']); ?>
          </div>
        <?php endif; ?>
    
        <?php if ($site_name) :?>

        
      </div>      
    </footer>
  <?php endif; ?>
  <!--/.footer-->

  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div>
<!--/.page -->





  <?php

  ?>