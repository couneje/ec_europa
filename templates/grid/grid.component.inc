<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function ec_europa_atomium_theme_grid() {
  return array(
    'grid' => array(
      'variables' => array(
        'rows' => NULL,
      ),
      'template' => 'grid',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_grid() {
  return array(
    'label' => 'Grid',
    'description' => 'Grid layout.',
    'preview' => array(
      'rows' => array(
        array(
          '1 of 2',
          '1 of 2',
        ),
        array(
          '1 of 3',
          '2 of 3',
          '3 of 3',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_grid(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'ecl-container');
}
