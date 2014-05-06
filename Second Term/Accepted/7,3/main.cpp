#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game field;
    field.show();

    return app.exec();
}
