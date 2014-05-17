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

    void voteFor() {
        QString number = id.at(position).toPlainText();
        voterF->load(begin + number +goodEnd);
        //number.remove(0,1);
        //cout << number.toInt() << endl;
    }

    void voteAgainst() {
        QString number = id.at(position).toPlainText();
        voterA->load(begin + number + badEnd);
        //number.remove(0,1);
        //cout << number.toInt() << endl;
    }

    void successFor(bool) {
        int static counter = 0;
        // чтобы 1 раз выводилось
        if (counter % 3 == 1) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("up!");
            msgBox.setText("u like it("+id.at(position).toPlainText()+")");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
            QString slot = rating->text();
            int value = slot.toInt();
            value++;
            rating->setText(QString::number(value));
        }
        counter++;
    }
    void successAgainst(bool) {
        int static counter = 0;
        // чтобы 1 раз выводилось
            if (counter % 3 == 1) {
                QMessageBox msgBox;
                msgBox.setWindowTitle("down!");
                msgBox.setText("u dislike it("+id.at(position).toPlainText()+")");
                msgBox.setDefaultButton(QMessageBox::Ok);
                msgBox.exec();
                QString slot = rating->text();
                int value = slot.toInt();
                value--;
                rating->setText(QString::number(value));
            }

        counter++;
    }

    void loadFinished(bool) {
        next->setEnabled(true);
        // весь текст цитат
        elements = view->page()->mainFrame()->findAllElements("div[class=text]");
        // все рейтинги
        ratings = view->page()->mainFrame()->findAllElements("span[class=rating]");
        // все даты
        date = view->page()->mainFrame()->findAllElements("span[class=date]");
        // все номера
        id = view->page()->mainFrame()->findAllElements("a[class=id]");
    }


    void showQuote() {
        text->setText("");

        text->insertPlainText(date.at(position).toPlainText());
        text->insertPlainText("\n");
        text->insertPlainText(id.at(position).toPlainText());
        text->insertPlainText("\n");
        text->insertPlainText(elements.at(position).toPlainText());
        text->insertPlainText("\n");
        rating->setText(ratings.at(position).toPlainText());

        plus->setEnabled(true);
        minus->setEnabled(true);
        position++;

    }

    void smileChange() {
        int static counter = 0;
            switch (counter % 5) {
                case 0: {
                    smile->setText("( >＿<)");
                    break;
                }
                case 1: {
                    smile->setText("( =＿=)");
                    break;
                }
                case 2: {
                    smile->setText("( ಠ＿ಠ)");
                    break;
                }
                case 3: {
                     smile->setText("(･_･ )");
                    break;
                    }
                case 4: {
                    smile->setText("(¬_¬ )");
                    break;
                }
            }

            counter++;
    }

private:
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
