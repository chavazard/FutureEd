<div class="small-12 columns text-left menu-acordeon" >	
	<?php 
	$i = 0;
	foreach ($item[0] as $key => $val) { ?>
		<ul id="grupo_categoria_<?=$i;?>" class="menu-categorias-ul outside no-margin">
			<li id="categoria_li_<?=$i;?>" onclick="muestraChildsMenu('categoria_li_<?=$i;?>');" class="inactive-menu-li elemento-menu no-margin">
				
					<a href="javascript:muestraChildsMenu('categoria_li_<?=$i;?>');location.href='<?=$val[0];?>';"><?=t($key);?>  </a>
			</li>
			<li class="submenu inactive-panel">
				<ul id="subcategorias_li_<?=$i;?>" class="no-margin" >
				<?php
				foreach ($val[1] as $subcategoria) {	?>
					<li class="elemento-submenu" onclick="location.href='<?=$subcategoria[1];?>'">	
						
					<?=l(t($subcategoria[0]), $subcategoria[1]);?>
					</li>		
				<?php } ?>
				</ul>			
			</li>
		</ul>
	<?php
		$i++;
	}
	?>
</div>

