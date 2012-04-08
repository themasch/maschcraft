#-------------------------------------------------
#
# Project created by QtCreator 2012-04-07T19:16:13
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = maschcraft
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    GLWidget.cpp \
    Renderable.cpp \
    GLCube.cpp \
    GLLightSource.cpp \
    GLCamera.cpp \
    GLSceneNode.cpp

HEADERS  += MainWindow.h \
    GLWidget.h \
    Renderable.h \
    GLCube.h \
    GLLightSource.h \
    GLCamera.h \
    GLSceneNode.h

FORMS    += MainWindow.ui

LIBS += -lglut -lGLU
