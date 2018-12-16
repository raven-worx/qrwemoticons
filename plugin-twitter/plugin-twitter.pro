TEMPLATE = lib
CONFIG += plugin
QT += core svg xml

TARGET = $$qtLibraryTarget(emoticons_twitter)

RESOURCES += \
    emoticons_twitter_0.qrc \
    emoticons_twitter_1.qrc \
    emoticons_twitter_2.qrc

INCLUDEPATH += \
    ../include \
    ../shared/src

HEADERS = \
    src/plugin.h \
    ../shared/src/QrwEmoticonsHelper.h

SOURCES = \
    src/plugin.cpp \
    ../shared/src/QrwEmoticonsHelper.cpp

OTHER_FILES = \
    plugin.json

# install to Qt plugins
target.path = $$[QT_INSTALL_PLUGINS]/emoticons
INSTALLS += target
