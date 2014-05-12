#include "client.h"
#include "server.h"
#include <QApplication>

// based on http://qt-doc.ru/realizacia-klienta-s-pomoschu-klassa-qtcpsocket.html
// and http://qt-doc.ru/realizacia-servera-s-pomoschu-klassa-qtcpserver.html

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client w("localhost", 2323);
    Server s(2323);
    s.show();
    w.show();

    return a.exec();
}
