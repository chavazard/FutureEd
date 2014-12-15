<?php

  //unset($page['sidebar_first']);

  // Logic to define layout 
  // Content wrapper 
  $content_classes = null;
  if ($page['sidebar_first']){
    if ($page['sidebar_second']){
      if ($page['sidebar_mini_first']){
        $content_classes = 'small-4';
      }else{
        $content_classes = 'small-6';
      }
    }else{
      if ($page['sidebar_mini_first']){
        $content_classes = 'small-7';
      }else{
        $content_classes = 'small-9';
      }
    }
  }else if ($page['sidebar_mini_first']){
    if ($page['sidebar_second']){
      $content_classes = 'small-7';
    }else{
      $content_classes = 'small-10';
    }
  }else if ($page['sidebar_second']){
    $content_classes = 'small-9';
  }

  // Featured
  $featured_classes = 'small-12';

  // Content sidebars
  $content_sidebar_first_classes = 'small-12';
  $content_sidebar_second_classes = 'small-12';
  if ($page['content_sidebar_first'] && $page['content_sidebar_second']){
    $content_sidebar_first_classes = 'small-5';
    $content_sidebar_second_classes = 'small-7';
  }

  // Subcontent sidebars
  $subcontent_classes_first = 'small-12';
  $subcontent_classes_second = 'small-12';
  if ($page['subcontent_sidebar_first'] && $page['subcontent_sidebar_second']){
    $subcontent_classes_first = 'small-6';
    $subcontent_classes_second = 'small-6';
  }
  // Content sidebars larger / smaller
  $subcontent_sidebar_first_classes_larger = 'small-12';
  $subcontent_sidebar_second_classes_smaller = 'small-12';
  if ($page['subcontent_sidebar_first_larger'] && $page['subcontent_sidebar_second_smaller']){
    $subcontent_sidebar_first_classes_larger = 'small-8';
    $subcontent_sidebar_second_classes_smaller = 'small-4';
  }

?>

<!-- header -->
<?php if ($page['header']){ ?>
    <div id="header" class="full-width bg">
      <?= render($page['header']); ?>
    </div>
<?php } ?>
<!-- header -->

<!-- container -->
<div id="main-container" class="main-cointainer-margin-top">
  <div class="row static-width" >
    <?php if ($page['featured']){ ?>
        <div id="featured" class="<?= $featured_classes; ?> columns">
          <?= render($page['featured']); ?>
        </div>
    <?php } ?>

    <?php if ($page['sidebar_mini_first']){ ?>
        <div id="sidebar-mini-first" class="small-2 columns">
          <?= render($page['sidebar_mini_first']); ?>
        </div>
    <?php } ?>

    <?php if ($page['sidebar_first']){ ?>
        <div id="sidebar-first" class="small-3 columns">
          <?= render($page['sidebar_first']); ?>
        </div>
    <?php } ?>
 
    <div id="content-content" class="<?= $content_classes; ?> columns">
      <?php if ($page['content']){ ?>
          <?= render($page['content']); ?>
      <?php } ?>

      <?php if ($page['content_sidebar_first'] || $page['content_sidebar_second']){ ?>
          <div class="row">
              <?php if ($page['content_sidebar_first']){ ?>
                  <div id="content-sidebar-first" class="<?= $content_sidebar_first_classes; ?> columns">
                    <?= render($page['content_sidebar_first']); ?>
                  </div>
              <?php } ?>
              <?php if ($page['content_sidebar_second']){ ?>
                  <div id="content-sidebar-second" class="<?= $content_sidebar_second_classes; ?> columns">
                    <?= render($page['content_sidebar_second']); ?>
                  </div>
              <?php } ?>
          </div>
      <?php } ?>

      <?php if ($page['subcontent_sidebar_first'] || $page['subcontent_sidebar_second']){ ?>
          <div class="row">
              <?php if ($page['subcontent_sidebar_first']){ ?>
                  <div id="subcontent-sidebar-first" class="<?= $subcontent_classes_first; ?> columns">
                    <?= render($page['subcontent_sidebar_first']); ?>
                  </div>
              <?php } ?>
              <?php if ($page['subcontent_sidebar_second']){ ?>
                  <div id="subcontent-sidebar-second" class="<?= $subcontent_classes_second; ?> columns">
                    <?= render($page['subcontent_sidebar_second']); ?>
                  </div>
              <?php } ?>
          </div>
      <?php } ?>

      <?php if ($page['subcontent_sidebar_first_larger'] || $page['subcontent_sidebar_second_smaller']){ ?>
          <div class="row">
              <?php if ($page['subcontent_sidebar_first_larger']){ ?>
                  <div id="subcontent-sidebar-first-larger" class="<?= $subcontent_sidebar_first_classes_larger; ?> columns">
                    <?= render($page['subcontent_sidebar_first_larger']); ?>
                  </div>
              <?php } ?>
              <?php if ($page['subcontent_sidebar_second_smaller']){ ?>
                  <div id="subcontent-sidebar-second-smaller" class="<?= $subcontent_sidebar_second_classes_smaller; ?> columns">
                    <?= render($page['subcontent_sidebar_second_smaller']); ?>
                  </div>
              <?php } ?>
          </div>
      <?php } ?>

    </div>

    <?php if ($page['sidebar_second']){ ?>
        <div id="sidebar-second" class="small-3 columns">
          <?= render($page['sidebar_second']); ?>
        </div>
    <?php } ?>

  </div>
</div>
<!-- container -->

<!-- footer -->
<?php if ($page['footer']){ ?>
  <div id="footer" class="full-width bg">
    <?= render($page['footer']); ?>
  </div>
<?php } ?>
<!-- footer -->

<!-- Foundation execution -->
<script>
  jQuery(document).foundation();
</script>
<!-- Foundation execution -->