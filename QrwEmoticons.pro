TEMPLATE = subdirs

SUBDIRS += \
    plugin-google \
    plugin-twitter \
    plugin-joypixels \
    plugin-openmoji \
    lib
 
# paths
plugin-google.subdir = plugin-google
plugin-twitter.subdir = plugin-twitter
plugin-emojione.subdir = plugin-emojione 
lib.subdir = lib
 
# dependencies
#test-app.depends = lib
