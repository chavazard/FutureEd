<?php
//$GLOBALS['left_sidebar_small'] = "small-2 medium-2 large-2 columns";
  global $left_sidebar;
  global $main_content;

  global $left_sidebar_small;
  global $left_sidebar_medium;
  global $left_sidebar_large;
  
  global $main_content_large;
  global $main_content_medium;
  global $main_content_small;  
  
  $left_sidebar_small  = "small-2 medium-2 large-2 columns";  
  $left_sidebar_medium = "small-3 medium-3 large-3 columns";  
  $left_sidebar_large  = "small-5 medium-5 large-5 columns";

  $main_content_large  = "small-10 medium-10 large-10 columns";
  $main_content_medium = "small-9 medium-9 large-9 columns";
  $main_content_small  = "small-7 medium-7 large-7 columns";
  
  include 'inc/templates-functions.php';  //Lineas comentadas para debug, descomentar para desarrollo
  obtenerTamanoColumnaIzquierda();    //Lineas comentadas para debug, descomentar para desarrollo
  

  
?>


  <div class="row">
           
    <div class = "small-9 medium-9 large-9 columns">
      <div class="row">
        <div class="small-12 medium-12 large-12 columns">
            <?php if (!empty($page['highlighted'])): ?>
              <div class="highlight panel callout">
                <?php print render($page['highlighted']); ?>
              </div>
            <?php endif; ?>
            <?php if ($breadcrumb): print $breadcrumb; endif; ?>
        </div>
      </div>              
      <div class="row">
        <div class="<?php print $left_sidebar;?>" style="background-color: #DDDDDD;">
          <?php if (!empty($page['sidebar_first'])): ?>
            <div role="complementary" class="sidebar-first columns sidebar">
              <?php print render($page['sidebar_first']); ?>
            </div>
          <?php endif; ?>
        </div>    
        
        <div class="<?php print $main_content;?>" style="background-color: #AAAAAA;">
          <div>

      
            <a id="main-content"></a>
      
            
      
            <?php if ($title && !$is_front): ?>
              <?php print render($title_prefix); ?>
              <h1 id="page-title" class="title"><?php print $title; ?></h1>
              <?php print render($title_suffix); ?>
            <?php endif; ?>
      
            <?php if (!empty($tabs)): ?>
              <?php print render($tabs); ?>
              <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
            <?php endif; ?>
      
            <?php if ($action_links): ?>
              <ul class="action-links">
                <?php print render($action_links); ?>
              </ul>
            <?php endif; ?>
      
            <?php print render($page['content']); ?>
          </div>
          <!--/.main region -->
        </div>
      </div>
    </div>
    <div class="small-3 medium-3 large-3 columns" style="background-color: #DDDDDD;">
        aa
        <?php if (!empty($page['sidebar_second'])): ?>
          <div role="complementary" class="sidebar-second columns sidebar">
            <?php print render($page['sidebar_second']); ?>
          </div>
        <?php endif; ?>
    </div>
  </div>  