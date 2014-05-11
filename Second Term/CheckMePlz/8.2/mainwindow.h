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

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(int amount, QWidget *parent = 0 );
    ~MainWindow();
private slots:
    void getText();
    void readData();
    void voteUp();
    void voteDown();
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
    QLineEdit *lineEdit;
    QPushButton * plus;
    QPushButton * minus;
    QLabel *label;
    QWebView *view;

};

#endif // MAINWINDOW_H
