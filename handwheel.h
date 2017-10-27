#ifndef HANDWHEEL_H
#define HANDWHEEL_H

#include <QObject>
#include <QTimer>

#include "qtfirmata.h"
#include "cncapi.h"

class Handwheel : public QObject
{
    Q_OBJECT
public:
    explicit Handwheel(QString port, QObject *parent = nullptr);

signals:

public slots:
    void init();
    void start();
    void getStatus();

private:
    QString port;
    QtFirmata *handwheel;
    QTimer *statusTimer;
};

#endif // HANDWHEEL_H
