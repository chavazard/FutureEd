<?php
  $main_content  = "small-9 medium-9 large-9 columns";
  
  $right_sidebar = "small-3 medium-3 large-3 columns";

  /*if ($content_type == "blog")
  {
    */$blog = false;/*
  }
  */
?>



<div class="row">
  <div class="small-12 medium-12 large-12 columns">
    <?php if ($blog) { ?>
        <div class="row">           
              <h2>Blog</h2>
        </div>             
    <?php } ?>
    
    <div class="row">               
      <div class="<?php print $main_content;?>" style="background-color: #AAAAAA;">
        <div class="row">           
              <div class="small-12 medium-12 large-12 columns" style="background-color: #225555;"> &nbsp
                  <?php if (!empty($page['highlighted'])): ?>
                    <div class="highlight panel callout">
                      <?php print render($page['highlighted']); ?>
                    </div>
                  <?php endif; ?>
                  <?php if ($breadcrumb): print $breadcrumb; endif; ?>
              </div>          
        </div>  
          
        <div >   

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
        
        
      <div class="<?php print $right_sidebar;?>" style="background-color: #DDDDDD;">
          aa
          <?php if (!empty($page['sidebar_second'])): ?>
            <div role="complementary" class="sidebar-second columns sidebar">
              <?php print render($page['sidebar_second']); ?>
            </div>
          <?php endif; ?>
      </div>          
    
    
    </div>
 
  </div>
  
</div>
 