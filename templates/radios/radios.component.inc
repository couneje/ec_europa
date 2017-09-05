<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_radios() {
  return array(
    'label' => 'Radio group',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function ec_europa_atomium_definition_form_radios($form, &$form_state) {
  $form['element1'] = array(
    '#title' => 'Radios component',
    '#type' => 'radios',
    '#options' => array(
      'item1' => 'Item 1',
      'item2' => 'Item 2',
      'item3' => 'Item 3',
    ),
    '#default_value' => 'item2',
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_radios(&$variables, $hook) {
  $element = $variables['element'];

  $variables['attributes_array']['class'][] = 'ecl-radio-group';
  $variables['attributes_array']['role'][] = 'radiogroup';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    $variables['attributes_array']['aria-labelledby'] = $title;

    $variables['small_description'] = t('List of options for @title', array('@title' => $title));

    $descr_attributes_array['class'] = array('ecl-sr-only');
    if (isset($element['#id'])) {
      $descr_attributes_array['id'] = $element['#id'] . "-description";
    }
    $variables['descr_attributes_array'] = $descr_attributes_array;
  }

  if (!empty($element['#description'])) {
    $variables['description'] = $element['#description'];
  }
}