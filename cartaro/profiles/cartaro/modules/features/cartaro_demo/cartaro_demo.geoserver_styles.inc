<?php
/**
 * @file
 * cartaro_demo.geoserver_styles.inc
 */

/**
 * Implements hook_geoserver_styles().
 */
function cartaro_demo_geoserver_styles() {
  $export = array();

  $geoserver_styles = new stdClass();
  $geoserver_styles->disabled = FALSE; /* Edit this to true to make a default geoserver_styles disabled initially */
  $geoserver_styles->api_version = 1;
  $geoserver_styles->name = 'capital';
  $geoserver_styles->title = 'Capital';
  $geoserver_styles->description = 'Default Capital Style';
  $geoserver_styles->data = '<?xml version="1.0" encoding="UTF-8"?><sld:StyledLayerDescriptor xmlns="http://www.opengis.net/sld" xmlns:sld="http://www.opengis.net/sld" xmlns:ogc="http://www.opengis.net/ogc" xmlns:gml="http://www.opengis.net/gml" version="1.0.0">
	<sld:NamedLayer>
		<sld:Name>capital</sld:Name>
		<sld:UserStyle>
			<sld:Name>default</sld:Name>
			<sld:Title>Capital</sld:Title>
			<sld:FeatureTypeStyle>
				<sld:Rule>
					<sld:PointSymbolizer>
						<sld:Graphic>
							<sld:Mark>
								<sld:WellKnownName>circle</sld:WellKnownName>
								<sld:Stroke>
									<sld:CssParameter name="stroke">#333333</sld:CssParameter>
									<sld:CssParameter name="stroke-width">2</sld:CssParameter>
								</sld:Stroke>
							</sld:Mark>
							<sld:Size><ogc:Literal>6</ogc:Literal></sld:Size>
						</sld:Graphic>
					</sld:PointSymbolizer>
				</sld:Rule>
			</sld:FeatureTypeStyle>
		</sld:UserStyle>
		<sld:UserStyle>
			<sld:Name>select</sld:Name>
			<sld:Title>Capital selected</sld:Title>
			<sld:FeatureTypeStyle>
				<sld:Rule>
					<sld:PointSymbolizer>
						<sld:Graphic>
							<sld:Mark>
								<sld:WellKnownName>circle</sld:WellKnownName>
								<sld:Fill><sld:CssParameter name="fill">#FFFFFF</sld:CssParameter></sld:Fill>
								<sld:Stroke>
									<sld:CssParameter name="stroke">#000000</sld:CssParameter>
									<sld:CssParameter name="stroke-width">2</sld:CssParameter>
								</sld:Stroke>
							</sld:Mark>
							<sld:Size><ogc:Literal>6</ogc:Literal></sld:Size>
						</sld:Graphic>
					</sld:PointSymbolizer>
				</sld:Rule>
			</sld:FeatureTypeStyle>
		</sld:UserStyle>
	</sld:NamedLayer>
</sld:StyledLayerDescriptor>';
  $export['capital'] = $geoserver_styles;

  return $export;
}
