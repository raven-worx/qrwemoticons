TEMPLATE = app
QT += core gui widgets svg xml
CONFIG += c++11

TARGET = test-app

INCLUDEPATH += \
    ../include \
    src

HEADERS += \
    src/MainWindow.h

SOURCES += \
    main.cpp \
    src/MainWindow.cpp

LIBS += -L$$PWD/../build/ -lQrwEmoticons
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/ -lQrwEmoticons
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/ -lQrwEmoticonsd
#else:unix: LIBS += -L$$PWD/../build/ -lQrwEmoticons
