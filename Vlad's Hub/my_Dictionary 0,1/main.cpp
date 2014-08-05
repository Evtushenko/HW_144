#include "dialog.h"
#include <QApplication>

// можно ее оптимизировать
// вытащить exe

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
