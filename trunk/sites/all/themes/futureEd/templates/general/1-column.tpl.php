  <div class="row" style="padding: 0; margin: 0">

        <div class="small-12 medium-12 large-12 columns">

              <div class="row">
                <div class="small-12 medium-12 large-12 columns">
                    <?php if (!empty($page['highlighted'])): ?>
                      <div class="highlight panel callout">
                        
                      </div>
                    <?php endif; ?>
                    <?php if ($breadcrumb): print $breadcrumb; endif; ?>
                </div>
              </div>              
              <div class="row" style="padding: 0; margin: 0">                                
                <div class="small-12 medium-12 large-12 columns" style="background-color: #AAAAAA;">

    
              
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
                  <!--/.main region -->
                </div>
              </div>
                   
        </div>
        

  </div>  