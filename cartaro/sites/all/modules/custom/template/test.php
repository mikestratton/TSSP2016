<?php
/**
 * @file
 * Template containing necessary files for module development.
 */
 
 /**
  * Implements hook_help().
  */
  function template_help($path, $arg){
      switch($path) {
          case 'admin/help#template':{
              $ret_val = '<h3>' . t('About') . '</h3>';
              $ret_val .= '<p>' . t('The Template module contains all the necessary files needed for module development.') . '</p>';
              return $ret_val;
              break;
          }
      }
  }
  
 /**
  * Implements hook_permission().
  */
  function template_permission(){
      return array(
          'administer template' => array(
              'title' => t('Administer Template'),
              'description' => t('Perform administrative tasks on Template functionality'),
          ),
      );
  }
  
 /**
  * Implements hook_menu().
  */
  function template_menu(){
      $items = array();
      
      // Admin configuration group.
      $items['admin/config/template'] = array(
          'title' => 'Template',
          'description' => 'Administer Template',
          'access arguments' => array('administer template'),
      );
      
      // Admin configuration - Settings.
      $items['admin/config/template/manage'] = array(
          'title' => 'Template settings',
          'description' => 'Manage Template settings and configurations.',
          'access arguments' => array('administer template'),
          'page callback' => 'drupal_get_form',
          'page arguments' => array('template_admin_settings_form'),
      );
      
      return $items;
  }
  
 /**
  * Implements hook_form().
  */
  function template_admin_settings_form($node, &$form_state){
      $form = array();
      
      $form['overview'] = array(
          '#markup' => t('This interface allows administrators to manage 
              general Template Settings'),
          '#prefix' => '<p>',
          '#suffix' => '</p>',
      );
      
      $form['template_gmap'] = array(
          '#title' => t('Enable Google Maps'),
          '#description' => t('When enabled, Google Maps will be rendered 
              if latitude and longitude are known'),
          '#type' => 'checkbox',
          '#default_value' => 1,
      );
      
      $form['default_center'] = array(
          '#title' => t('Map Center'),
          '#description' => t('Location of the center of the map of Template'),
          '#type' => 'fieldset',
          '#collapsible' => TRUE,
          '#collapsed' => FALSE,
      );
      
      $form['default_center']['template_default_center_lat'] = array(
          '#title' => t('Latitude'),
          '#description' => t('Signed degrees format DDD.dddd'),
          '#type' => 'textfield',
          '#default_value' => 41.0997803,
          'required' => TRUE,
      );
      
      $form['default_center']['template_default_center_long'] = array(
          '#title' => t('Longitude'),
          '#description' => t('Signed degrees format DDD.dddd'),
          '#type' => 'textfield',
          '#default_value' => -80.64951940000003, 
          'required' => TRUE,
      );
      
      $options = range(0,20, 1);
      $options[0] = t('0 - Furthest');
      $options[20] = t('20 - Closest');
      
      $form['template_default_gmap_zoom'] = array(
          '#title' => t('Google Map zoom'),
          '#description' => t('Default level of zoom, between 0 and 20.'),
          '#type' => 'select',
          '#options' => $options,
          '#default_value' => 8,
          '#required' => TRUE,
      );
      
      $form['submit'] = array(
          '#type' => 'submit',
          '#value' => t('Save'),
      );
            
      return $form;
  }