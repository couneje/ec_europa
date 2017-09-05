<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element_label(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'ecl-form-label';

  if (isset($variables['attributes_array']['for'])) {
    $variables['attributes_array']['aria-label'] = $variables['attributes_array']['for'];
  }

  $variables['attributes_array']['id'] = $variables['element']['element']['#id'] . '_label';
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_form_element_label__form_element__textarea(&$variables, $hook) {
  $variables['attributes_array']['class'] = array_diff($variables['attributes_array']['class'], array('ecl-form-label'));
}