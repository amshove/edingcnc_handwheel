#include <QCoreApplication>
#include "handwheel.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc != 2){
        qDebug() << "Usage: edingcnc_handwheel <port>";
        return -1;
    }

    Handwheel handwheel(argv[1]);
    handwheel.init();

    return a.exec();
}
