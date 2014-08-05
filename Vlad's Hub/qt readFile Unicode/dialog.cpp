#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QTextCodec>
#include <QTextStream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // reading file
    QFile file("in.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             ui->textOut->append("can not read file");
    else
    {
        QTextStream in(&file);
        in.setCodec("UnicodeUTF8");
        while (!in.atEnd()) {
          QString slot = in.readLine();
          ui->textOut->append(slot);
        }
        /*
        while (!file.atEnd()) {
                QByteArray line = file.readLine();
                //QString line = file.readLine();
                QTextCodec *codec = QTextCodec::codecForName("UTF-8");
                ui->textOut->append(codec->toUnicode(line));
            }
         */
    }

}

Dialog::~Dialog()
{
    delete ui;
}
