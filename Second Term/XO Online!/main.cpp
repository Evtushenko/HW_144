#include "client.h"
#include "server.h"
#include <QApplication>

// чистить память
// общий предок
// условия победы
// отображение победы

// based on http://qt-doc.ru/realizacia-klienta-s-pomoschu-klassa-qtcpsocket.html
// and http://qt-doc.ru/realizacia-servera-s-pomoschu-klassa-qtcpserver.html

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client w("localhost", 2323, 3);
    Server s(2323, 3);
    s.show();
    w.show();

    return a.exec();
}
