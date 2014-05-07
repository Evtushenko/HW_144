#include "mainwindow.h"
#include <QApplication>

// based on http://www.tuxradar.com/content/code-project-create-qt-rss-reader
// http://doc.qt.digia.com/4.6/xml-rsslisting.html

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(10);
    w.show();

    return a.exec();
}
