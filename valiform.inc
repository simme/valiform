<?php
/** NOT IMPLEMENTED YET!! **/


/**
 * @file
 *  Contains some basic validation methods to ease form development
 */

/**
 * Validate form as email
 */
function valiform_validate_email($element, &$form_state) {

}

/**
 * Validate form as url
 */
function valiform_validate_url($element, &$form_state) {

}

/**
 * Validate as only digits
 */
function valiform_validate_num($element, &$form_state) {
  $value = trim($form_state['values'][$element['#name']]);
  if (preg_match('/^[^0-9]*$/', $value)) {
    $title = empty($element['#title']) ? $element['#name'] : $element['#title'];
    return t('@title may only contain numbers.', array('@title' => $title));
  } else {
    return TRUE;
  }
}