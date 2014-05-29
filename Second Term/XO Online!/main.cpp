#include "client.h"
#include "server.h"
#include <QApplication>

// чистить память в Widget

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client w("localhost", 2323, 3);
    Server s(2323, 3);
    s.show();
    w.show();

    return a.exec();
}
