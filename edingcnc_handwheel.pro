QT -= gui
QT += core

CONFIG += c++11 console
CONFIG -= app_bundle

# https://github.com/jazzycamel/QtFirmata
QTFIRMATA_DIR="C:\Users\anwender\Desktop\QtFirmata"
QTFIRMATA_LIB="C:\Users\anwender\Desktop\QtFirmata\build-QtFirmata-Desktop_Qt_5_6_2_MinGW_32bit-Debug\debug"

CNCAPI_DIR="C:/CNC4.02/cncapi"

INCLUDEPATH += $$QTFIRMATA_DIR
DEPENDPATH += $$QTFIRMATA_DIR
LIBS += -L$$QTFIRMATA_LIB -lQtFirmata

INCLUDEPATH += $$CNCAPI_DIR
DEPENDPATH += $$CNCAPI_DIR
LIBS += -L$$CNCAPI_DIR -lcncapi

SOURCES += main.cpp \
    handwheel.cpp

HEADERS += \
    handwheel.h
