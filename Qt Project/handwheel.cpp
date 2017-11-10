#include "handwheel.h"
#include <QDebug>
#include <QCoreApplication>
#include <QTimer>

#include "qtfirmata.h"
#include "cncapi.h"

Handwheel::Handwheel(QString port, QObject *parent) : QObject(parent), port(port)
{
    qDebug("Starting...");
}

void Handwheel::init(){
    qDebug("Connecting to EdingCNC ...");
    CNC_RC rc = CncConnectServer((char *)"cnc.ini");
    if (rc == CNC_RC_OK || rc == CNC_RC_ALREADY_RUNS) {
        qDebug("Connection to CNC ready");

        //Load empty file, this loads macro.cnc, otherwoze we cannot home.
        rc = CncLoadJob(L"");
    }else {
        qDebug("Error connecting!");
        exit(2);
    }

    handwheel = new QtFirmata(port);
    connect(handwheel, SIGNAL(deviceReady()), this, SLOT(start()));

    qDebug("Connecting to Firmata/Handwheel ...");
    if(handwheel->connect()) qDebug("Successfully connected!");
    else {
        qDebug("Error connecting!");
        exit(3);
    }
}

void Handwheel::start(){
    handwheel->pinMode(13, QtFirmata::PINMODE_OUTPUT);

    statusTimer= new QTimer(this);
    statusTimer->setInterval(1000);
    connect(statusTimer, SIGNAL(timeout()), this, SLOT(getStatus()));
    statusTimer->start();
}

void Handwheel::getStatus(){
    if(CncGetTrafficLightStatus()->trafficLightBlink){
        qDebug("blinking");
        handwheel->digitalWrite(13,1);
    }else{
        qDebug("NOT blinking");
        handwheel->digitalWrite(13,0);
    }
}
