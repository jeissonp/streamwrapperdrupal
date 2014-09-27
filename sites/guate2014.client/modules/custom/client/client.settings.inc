<?php
function client_settings($form, &$form_state) {
  $form['client_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Directory'),
    '#default_value' => variable_get('client_path'),
    '#maxlength' => 255,
    '#after_build' => array('system_check_directory'),
    '#required' => TRUE,
  );

  $form['client_remote'] = array(
    '#type' => 'textfield',
    '#title' => t('Http Remote'),
    '#default_value' => variable_get('client_remote'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  return system_settings_form($form);
}