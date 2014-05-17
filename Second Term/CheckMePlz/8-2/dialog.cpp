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

    // как только загрузится  страница будет доступен next
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
    // показываем цитату по запросу
    connect(next, SIGNAL(clicked()), this, SLOT(showQuote()));
    // меняем смайлик
    connect(smile,SIGNAL(clicked()), this, SLOT(smileChange()));
    // кнопка +
    connect(plus, SIGNAL(clicked()), this, SLOT(voteFor()));
    // кнопка -
    connect(minus, SIGNAL(clicked()), this, SLOT(voteAgainst()));
    // успешно повысили
    connect(voterF, SIGNAL(loadFinished(bool)), this, SLOT(successFor(bool)));
    // успешно понизили
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
    delete voterF;
    delete voterA;
}
