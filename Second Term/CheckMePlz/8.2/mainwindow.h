#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QtNetwork/QtNetwork>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(int amount, QWidget *parent = 0 );
    ~MainWindow();
private slots:
    void getText();
    void readData();
private:
    int amountQuotes;
    void parseXml();
    QVBoxLayout *menu;
    QPushButton *load;
    QPushButton *exit;
    QTextEdit *text;
    QNetworkAccessManager *networkAccessManager;
    QNetworkReply *networkReply;
    QXmlStreamReader xmlStreamReader;

};

#endif // MAINWINDOW_H
