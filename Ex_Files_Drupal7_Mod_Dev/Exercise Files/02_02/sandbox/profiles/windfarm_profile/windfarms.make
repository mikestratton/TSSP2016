; Core version
; ------------
core = 7.x
  
; API version
; ------------
api = 2
  
; Core project
; ------------
projects[drupal][version] = 7.15

; Modules
; --------
projects[coder][type] = module
projects[coder][subdir] = contrib
projects[coder][download][type] = "git"
projects[coder][download][url] = "http://git.drupal.org/project/coder.git"
projects[coder][download][revision] = "0d1840ca384f9ed74dadfb11f4cad47d80e39f10"
projects[coder][download][branch] = "7.x-1.x"

projects[ctools][version] = 1.2
projects[ctools][type] = "module"
projects[ctools][subdir] = "contrib"

projects[devel][version] = 1.3
projects[devel][type] = "module"
projects[devel][subdir] = "contrib"

projects[feeds][version] = 2.0-alpha5
projects[feeds][type] = "module"
projects[feeds][subdir] = "contrib"

projects[gmap3_tools][type] = module
projects[gmap3_tools][subdir] = contrib
projects[gmap3_tools][download][type] = "git"
projects[gmap3_tools][download][url] = "http://git.drupal.org/project/gmap3_tools.git"
projects[gmap3_tools][download][revision] = "9f7d63a88f444292ad6bf1c6aaef7ad8e981d161"
projects[gmap3_tools][download][branch] = "7.x-1.x"

projects[job_scheduler][version] = 2.0-alpha3
projects[job_scheduler][type] = "module"
projects[job_scheduler][subdir] = "contrib"

projects[location][version] = 3.0-alpha1
projects[location][type] = "module"
projects[location][subdir] = "contrib"