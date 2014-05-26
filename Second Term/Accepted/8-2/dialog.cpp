#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    position(0),
    plus(new QPushButton),
    minus(new QPushButton),
    smile(new QPushButton),
    menu(new QVBoxLayout),
    firstLine(new QHBoxLayout),
    rating(new QLineEdit),
    next(new QPushButton),
    text(new QTextEdit),
    view(new QWebView ),
    voterF(new QWebView),
    voterA(new QWebView),
    ui(new Ui::Dialog)
{
    for (int i = 0; i < amount; i++)
        votes[i] = 0;

    plus->setText("+");
    minus->setText("-");
    smile->setText("0_o");
    rating->setText("???");
    next->setText("next");

    next->setEnabled(false);
    plus->setEnabled(false);
    minus->setEnabled(false);
    text->setReadOnly(true);
    rating->setReadOnly(true);

    plus->setFont(QFont("Times", 18, QFont::Bold));
    minus->setFont(QFont("Times", 18, QFont::Bold));
    smile->setFont(QFont("Times", 18, QFont::Bold));
    rating->setFont(QFont("Times", 18, QFont::Bold));
    next->setFont(QFont("Times", 18, QFont::Bold));
    text->setFont(QFont("Arial", 12, QFont::Bold));

    firstLine->addWidget(plus);
    firstLine->addWidget(smile);
    firstLine->addWidget(minus);
    firstLine->addWidget(rating);

    menu->addLayout(firstLine);
    menu->addWidget(next);
    menu->addWidget(text);

    setLayout(menu);

    ui->setupUi(this);

    view->load(QUrl("http://bash.im/"));

    // как только загрузится страница будет доступен next
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
    // показываем цитату по запросу
    connect(next, SIGNAL(clicked()), this, SLOT(showQuote()));
    // меняем смайлик
    connect(smile,SIGNAL(clicked()), this, SLOT(smileChange()));
    // кнопка +
    connect(plus, SIGNAL(clicked()), this, SLOT(voteFor()));
    // кнопка -
    connect(minus, SIGNAL(clicked()), this, SLOT(voteAgainst()));
    // как только завершена отправка голосования
    connect(voterF, SIGNAL(loadFinished(bool)), this, SLOT(successFor(bool)));
    connect(voterA, SIGNAL(loadFinished(bool)), this, SLOT(successAgainst(bool)));
}

Dialog::~Dialog()
{
    firstLine->removeWidget(plus);
    firstLine->removeWidget(smile);
    firstLine->removeWidget(minus);
    firstLine->removeWidget(rating);
    menu->removeWidget(next);
    menu->removeWidget(text);

    delete ui;
    delete text;
    delete next;
    delete plus;
    delete minus;
    delete smile;
    delete rating;
    delete firstLine;
    delete menu;

    delete view;
    //delete voterF;
    //delete voterA;
}

void Dialog::voteFor() {
    if (votes[position -1] != 1  ) {
        QString number = id.at(position -1).toPlainText();
        voterF->load(begin + number +goodEnd);
        QString slot = rating->text();
        int value = slot.toInt();
        if (votes[position -1] == -1)
            value += 2;
        else
            value++;
        votes[position -1] = 1;
        rating->setText(QString::number(value));
        QMessageBox msgBox;
        msgBox.setWindowTitle("success +");
        msgBox.setText("u like it!("+id.at(position -1).toPlainText()+")");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        plus->setEnabled(false);
    }
}

void Dialog::voteAgainst() {
    if (votes[position -1] != -1  ) {
        QString number = id.at(position -1).toPlainText();
        voterA->load(begin + number + badEnd);
        QString slot = rating->text();
        int value = slot.toInt();
        if (votes[position -1] == 1)
            value -= 2;
        else
            value--;
        votes[position -1] = -1;
        rating->setText(QString::number(value));
        QMessageBox msgBox;
        msgBox.setWindowTitle("success -");
        msgBox.setText("u dislike it!("+id.at(position -1).toPlainText()+")");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        minus->setEnabled(false);
    }
}

void Dialog::loadFinished(bool) {
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

void Dialog::showQuote() {
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

void Dialog::smileChange() {
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
