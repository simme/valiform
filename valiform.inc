<?php
/**
 * @file
 *  Contains some basic validation methods to ease form development
 */

/**
 * Validate form as email
 */
function valiform_validate_email($element, &$form_state) {
  $value = trim($form_state['values'][$element['#name']]);
  if (!filter_var($value, FILTER_VALIDATE_EMAIL)) {
    return t('@title is not a valid email.', array('@title' => valiform_element_title($element)));
  }
}

/**
 * Validate as only digits
 */
function valiform_validate_num($element, &$form_state, $allow_empty = FALSE) {
  $value = trim($form_state['values'][$element['#name']]);
  if ($allow_empty && empty($value)) {
    return TRUE;
  }
  if (preg_match('/^[^0-9]*$/', $value)) {
    return t('@title may only contain numbers.', array('@title' => valiform_element_title($element)));
  } else {
    return TRUE;
  }
}