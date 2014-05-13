#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QtNetwork/QtNetwork>
#include <QString>
#include <QLineEdit>
#include <QLabel>
#include <QWebView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = 0 );
       ~MainWindow();
private slots:
    void getText();
    void readData();
    void voteUp();
    void voteDown();
    void changePic();
private:
    Ui::MainWindow *ui;
    void parseXml();
    QNetworkAccessManager *networkAccessManager;
    QNetworkReply *networkReply;
    QXmlStreamReader xmlStreamReader;
    QWebView *view;
    QString *textNumber;
};

#endif // MAINWINDOW_H
