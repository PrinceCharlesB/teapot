QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
    main.cpp \
    myopenglwidget.cpp

HEADERS += \
    glut-3.7.6/glut.h \
    myopenglwidget.h


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


LIBS += -lGL -lGLU

LIBS +=-L/usr/lib/x86_64-linux-gnu -lglut

