TEMPLATE = lib
CONFIG += plugin
QT += core svg

TARGET = $$qtLibraryTarget(emoticons_joypixels)

INCLUDEPATH += \
    ../include

RESOURCES += \
    $$files($$PWD/*.qrc)

HEADERS = \
    src/plugin.h

SOURCES = \
    src/plugin.cpp

OTHER_FILES = \
    plugin.json

# install to Qt plugins
target.path = $$[QT_INSTALL_PLUGINS]/emoticons
INSTALLS += target
