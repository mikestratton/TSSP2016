<?php
/**
 * @file
 * cartaro_demo.geoserver_layers.inc
 */

/**
 * Implements hook_geoserver_layers().
 */
function cartaro_demo_geoserver_layers() {
  $export = array();

  $geoserver_layers = new stdClass();
  $geoserver_layers->disabled = FALSE; /* Edit this to true to make a default geoserver_layers disabled initially */
  $geoserver_layers->api_version = 1;
  $geoserver_layers->name = 'capitals';
  $geoserver_layers->title = 'Capitals';
  $geoserver_layers->description = '';
  $geoserver_layers->data = array(
    'type' => 'geoserver_layer_type_postgis_field',
    'style' => 'capital',
    'source' => 'node.capital.field_location',
    'openlayers' => array(
      'wfs' => 1,
      'gwc' => 0,
      'gwc_srs' => 'EPSG:4326',
      'wms' => 0,
    ),
    'options' => array(
      'field' => 'node.capital.field_location',
      'srid' => '4326',
      'sql_name' => 'geoserver_capitals_view',
      'sql' => 'DROP VIEW IF EXISTS geoserver_capitals_view;
CREATE VIEW geoserver_capitals_view AS SELECT node.nid as id, node.title as name, field_data_field_location.delta, field_location_geometry, body_value, body_summary as description, body_format
FROM node
LEFT JOIN field_data_field_location ON node.nid = field_data_field_location.entity_id
LEFT JOIN field_data_body ON node.nid = field_data_body.entity_id
WHERE node.type = \'capital\' and node.status = 1 and field_data_field_location.deleted = 0;
CREATE OR REPLACE RULE geoserver_capitals_view_update AS ON UPDATE TO geoserver_capitals_view DO INSTEAD 
  UPDATE field_data_field_location SET field_location_geometry = NEW.field_location_geometry WHERE entity_id = NEW.id;
CREATE OR REPLACE RULE geoserver_capitals_view_insert AS ON INSERT TO geoserver_capitals_view DO INSTEAD (
    INSERT INTO field_data_field_location VALUES (\'node\', \'capital\', 0, nextval(\'node_nid_seq\'), currval(\'node_nid_seq\'), \'und\', 0, NEW.field_location_geometry);        
    INSERT INTO node VALUES (currval(\'node_nid_seq\'), currval(\'node_nid_seq\'), \'capital\', \'und\', \'\', 0, 1, extract(epoch from now())::int, extract(epoch from now())::int, 0, 0, 0, 0, 0);
    INSERT INTO node_revision VALUES (currval(\'node_nid_seq\'), currval(\'node_nid_seq\'), 0, \'\', \'\', extract(epoch from now())::int, 1, 0, 0, 0); 
  );
CREATE OR REPLACE RULE geoserver_capitals_view_delete AS ON DELETE TO geoserver_capitals_view DO INSTEAD 
  DELETE FROM field_data_field_location  WHERE entity_id = OLD.id and delta = OLD.delta;',
      'bounding_box' => array(
        'minx' => '-180',
        'miny' => '-90',
        'maxx' => '180',
        'maxy' => '90',
      ),
    ),
  );
  $export['capitals'] = $geoserver_layers;

  return $export;
}
