#!/bin/bash

# Builds a Cartaro distribution based on the current content of the Cartaro checkout.
# Unless changes have been made locally this should give the same as an official Cartaro download.
# Local changes are retained to allow for testing the Drush make files locally.

# Folder where the distribution will be made available.
DESTINATION=/tmp/cartaro-deploy

# Keep a note of local changes.
pushd $(dirname $0)
git diff > /tmp/cartaro-deploy.patch
popd

# Drush make file which applies local change to a fresh checkout. Build is controlled by the locally
# changed versions of the Drush make files in the Cartaro checkout.
echo "
; API
api = 2

; Core
core = 7.x

projects[drupal][version] = 7.41

projects[cartaro][type] = profile
projects[cartaro][version] = 1.x-dev
projects[cartaro][patch][] = file:///tmp/cartaro-deploy.patch" > /tmp/cartaro-deploy.make

# Remove Drush's cache of local files.
rm ~/.drush/cache/download/file*

# Let Drush build the Cartaro distribution.
rm -rf $DESTINATION
drush make /tmp/cartaro-deploy.make $DESTINATION

# Dispose temporary files.
rm /tmp/cartaro-deploy.make /tmp/cartaro-deploy.patch

echo "
Cartaro distribution now in: $DESTINATION"