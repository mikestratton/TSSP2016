
; Makefile to build a development release of Cartaro 
; which includes development snapshots of contrib projects.
; Execute a normal build-cartaro.make, then run this Makefile and
; move all modules, themes and libraries to profiles/cartaro.

; API
api = 2

; Core
core = 7.x

; Contrib modules
projects[ctools][version] = 1.9
projects[ctools][subdir]  = contrib
projects[diff][version] = 3.2
projects[diff][subdir]  = contrib
projects[features][version] = 2.7
projects[features][subdir]  = contrib
projects[feeds][version] = 2.0-beta1
projects[feeds][subdir]  = contrib
projects[gdal][version] = 1.0
projects[gdal][subdir]  = contrib
projects[geoserver][version] = 1.4
projects[geoserver][subdir]  = contrib
projects[job_scheduler][version] = 2.0-alpha3
projects[job_scheduler][subdir] = contrib
projects[libraries][version] = 2.2
projects[libraries][subdir]  = contrib
projects[module_filter][version] = 2.0
projects[module_filter][subdir]  = contrib
projects[nodetype_access][version] = 1.0-beta5
projects[nodetype_access][subdir]  = contrib
projects[nodetype_access][download][revision] = 6ea2263af7d198d1c33a91ad433a35affb31e048
projects[ole][version] = 1.1
projects[ole][subdir]  = contrib
projects[openlayers][version] = 2.0-beta11
projects[openlayers][subdir]  = contrib
projects[openlayers][download][revision] = f69da5b6436aac6019f638b9d378f20a745fa98c
projects[openlayers_filters][version] = 2.0
projects[openlayers_filters][subdir] = contrib
projects[openlayers_layer_assistant][version] = 1.0-beta3
projects[openlayers_layer_assistant][subdir]  = contrib
projects[openlayers_print][version] = 1.0-beta1
projects[openlayers_print][subdir]  = contrib
projects[pathauto][version] = 1.3
projects[pathauto][subdir]  = contrib
projects[postgis][version] = 1.5
projects[postgis][subdir]  = contrib
projects[proj4js][version] = 1.2
projects[proj4js][subdir]  = contrib
projects[token][version] = 1.6
projects[token][subdir]  = contrib
projects[strongarm][version] = 2.0
projects[strongarm][subdir]  = contrib
projects[views][version] = 3.11
projects[views][subdir]  = contrib

; Contrib themes
projects[frontmap][version] = 1.0-rc2
projects[frontmap][type] = theme
projects[zen][version] = 5.5
projects[zen][type] = theme

; Libraries
libraries[openlayers][download][type] = file
libraries[openlayers][download][url] = http://github.com/openlayers/openlayers/releases/download/release-2.13.1/OpenLayers-2.13.1.zip
libraries[openlayers][directory_name] = openlayers
libraries[openlayers][destination] = libraries