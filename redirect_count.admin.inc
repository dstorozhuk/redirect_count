<?php

/**
 * @file
 * Settings for bot list ips, that not will be displayed in statistic
 */
function edit_bot_list(){
  return drupal_get_form('edit_bot_list_form');
}

/**
 * Form builder for bot list ips
 */
function edit_bot_list_form(){
  $ips = implode("\n", variable_get('bot_list_ip', array()));
  $form['bot_list_ip'] = array(
    '#type' => 'textarea',
    '#title' => t('Ip`s'),
    '#description' => t('Enter bot ip`s or ip`s that should not be displayed in statistics page'),
    '#default_value' => $ips
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  ); 
  return $form;
}

/**
 * Submit function for bot list ips form
 */
function edit_bot_list_form_submit($form, &$form_state){
  $bot_list_ips = str_replace(array("\r\n", "\r"), array("\n","\n"), $form_state['values']['bot_list_ip']);
  $ips = explode("\n", $bot_list_ips);
  variable_set('bot_list_ip', $ips);
}
