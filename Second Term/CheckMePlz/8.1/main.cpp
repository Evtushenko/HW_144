#include "client.h"
#include "server.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client w("localhost", 2323);
    Server s(2323);
    s.show();
    w.show();

    return a.exec();
}
