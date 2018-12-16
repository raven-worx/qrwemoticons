TEMPLATE = lib
CONFIG += plugin
QT += core svg

TARGET = $$qtLibraryTarget(emoticons_emojione)

INCLUDEPATH += \
    ../include

RESOURCES += \
    emoticons_emojione_0.qrc \
    emoticons_emojione_1.qrc \
    emoticons_emojione_2.qrc

HEADERS = \
    src/plugin.h

SOURCES = \
    src/plugin.cpp

OTHER_FILES = \
    plugin.json

# install to Qt plugins
target.path = $$[QT_INSTALL_PLUGINS]/emoticons
INSTALLS += target
