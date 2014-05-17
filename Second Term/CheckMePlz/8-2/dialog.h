#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QDomDocument>
#include <QString>
#include <QMessageBox>

int const amount = 50;

const QString begin("http://bash.im/quote/");
const QString goodEnd("/rulez");
const QString badEnd("/sux");

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    // голосуем
    void voteFor();
    void voteAgainst();

    // уведомляем об успехе голосования
    void successFor(bool);
    void successAgainst(bool);

    // открыли документ для парсинга и парсим
    void loadFinished(bool);

    // показать цитаты по кнопке next
    void showQuote();
    // анимация кнопки smile
    void smileChange();

private:

    // чтобы не больше +1 по модулю рейтинг менялся
    bool upped[amount];
    bool downed[amount];

    //текущий номер цитаты
    int position;
    // vote for
    QPushButton *plus;
    // vote against
    QPushButton *minus;
    // for beauty
    QPushButton *smile;
    // columns
    QVBoxLayout *menu;
    //first line
    QHBoxLayout *firstLine;
    //rating
    QLineEdit *rating;
    // next
    QPushButton *next;
    // text
    QTextEdit *text;

    // типа браузер
    QWebView *view;
    // здесь будут все тексты цитат
    QWebElementCollection elements;
    // рейтинги
    QWebElementCollection ratings;
    // дата
    QWebElementCollection date;
    // номер
    QWebElementCollection id;
    // для голосования +
    QWebView *voterF;
    // для голосования -
    QWebView *voterA;

    Ui::Dialog *ui;
};

#endif // DIALOG_H
