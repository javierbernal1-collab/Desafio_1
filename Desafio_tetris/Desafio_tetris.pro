TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Tablero.cpp \
        main.cpp \
        movimiento.cpp \
        piezas.cpp

HEADERS += \
    Tablero.h \
    movimiento.h \
    piezas.h
