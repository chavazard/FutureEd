<?php
  /*if ($content_type == "blog")
  {
    */$blog = false;/*
  }
  */
?>


  <div class="row">

        <div class="small-2 medium-2 large-2 columns" style="background-color: #DDDDDD;">
          <div  class="row">                
            <div class="<?php print $left_sidebar;?>" >

                <?php if (!empty($page['sidebar_first'])): ?>
                  <div role="complementary" class="sidebar-first columns sidebar">
                    <?php print render($page['sidebar_first']); ?>
                  </div>
                <?php endif; ?>
            </div>               
          </div>
        </div>  
        <div class="small-10 medium-10 large-10 columns" style="background-color: #AAAAAA;">
          <?php if ($blog) { ?>
              <div class="row">           
                    <h2>Blog</h2>
              </div>             
          <?php } ?>
          
          
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
                
              <div class="row">   
                <div class="small-12 medium-12 large-12 columns" >
          
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
              </div>
              <!--/.main region -->
  
        </div>
  </div>  