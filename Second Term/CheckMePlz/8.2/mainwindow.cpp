#include "mainwindow.h"
#include <iostream>
#include <string>

using namespace std;

MainWindow::MainWindow(int amount, QWidget *parent)
    : QDialog(parent),
      amountQuotes(amount),
      menu(new QVBoxLayout),
      load(new QPushButton),
      exit(new QPushButton),
      text(new QTextEdit),
      lineEdit(new QLineEdit),
      plus(new QPushButton),
      minus(new QPushButton),
      label(new QLabel),
      view(new QWebView)
{

    text->setReadOnly(true);
    lineEdit->setText("for ex: 428106");
    load->setText("Take 10");
    exit->setText("Exit");
    plus->setText("+");
    minus->setText("-");
    label->setText("Enter number of quote for voting");

    load->setFont(QFont("Times", 18, QFont::Bold));
    exit->setFont(QFont("Times", 18, QFont::Bold));
    minus->setFont(QFont("Times", 18, QFont::Bold));
    plus->setFont(QFont("Times", 18, QFont::Bold));
    label->setFont(QFont("Times", 18, QFont::Bold));

    networkAccessManager= new QNetworkAccessManager();

    menu->addWidget(text);
    menu->addWidget(load);
    menu->addWidget(label);
    menu->addWidget(lineEdit);
    menu->addWidget(minus);
    menu->addWidget(plus);
    menu->addWidget(exit);
    setLayout(menu);

    connect(load, SIGNAL(clicked()), this, SLOT(getText()));
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(plus, SIGNAL(clicked()), this, SLOT(voteUp()));
    connect(minus, SIGNAL(clicked()), this, SLOT(voteDown()));
}

MainWindow::~MainWindow() {
    menu->removeWidget(text);
    menu->removeWidget(load);
    menu->removeWidget(exit);
    menu->removeWidget(plus);
    menu->removeWidget(minus);
    menu->removeWidget(lineEdit);
    menu->removeWidget(label);
    delete menu;
    delete text;
    delete load;
    delete exit;
    delete plus;
    delete minus;
    delete lineEdit;
    delete label;
    delete view;
}

void MainWindow::readData() {
    int statusCode = networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
       if (statusCode >= 200 && statusCode < 300)
       {
           QByteArray data = networkReply->readAll();
           QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
           xmlStreamReader.addData(codec->toUnicode(data));
           parseXml();
       }
}


// Голосование происходит путем перехода по ссылке.
// http://bash.im/quote/428106(номер цитаты)/rulez(если +) и sux(если -)
// те для того, чтобы проголосовать достаточно просто перейти по этим ссылкам

const QString begin("http://bash.im/quote/");
const QString goodEnd("/rulez");
const QString badEnd("/sux");

void MainWindow::voteUp()
{
    QString number = lineEdit->text();
    text->append("<br><b>successfuly voted for </b>" + number + "<br>");
    view->load(QUrl(begin + number + goodEnd));

}

void MainWindow::voteDown()
{
    QString number = lineEdit->text();
    //text->textCursor().insertHtml(begin+number+badEnd+ "<br>");
    text->append("<br><b>successfuly voted against </b>" + number + "<br>");
    view->load(QUrl(begin + number + badEnd));
}

void MainWindow::getText()
{
    if (!networkReply)
    {
        networkReply->disconnect(this);
        networkReply->deleteLater();
    }
    networkReply = networkAccessManager->get(QNetworkRequest(QUrl("http://bash.im/rss/")));
    connect(networkReply, SIGNAL(readyRead()), this, SLOT(readData()));
}


void MainWindow::parseXml() {
    int amount = 0; // counter
    while (!xmlStreamReader.atEnd() && amount < amountQuotes) // while is not end of file
    {
        xmlStreamReader.readNext(); // читает токен,  возвращает тип
        if (xmlStreamReader.isStartElement()) // true если токен == StartElement
        {
            if (xmlStreamReader.name() == "item") // возращает имя <тега>
            {
                while (!xmlStreamReader.atEnd() && amount < amountQuotes )
                {
                    xmlStreamReader.readNext();
                    QStringRef token = xmlStreamReader.name();
                    if (xmlStreamReader.isStartElement() && (token == "title" || token == "pubDate"))
                    {
                        xmlStreamReader.readNext();
                        QString slot = xmlStreamReader.text().toString();
                        //text->textCursor().insertHtml("slot = " + slot);
                        int num = slot.indexOf("+", 0);
                        if (num != -1) {
                            slot.remove(num, 5);
                        }
                        //
                        text->textCursor().insertHtml("<b>" + slot + "<b><br>");
                    }
                    if (xmlStreamReader.isCDATA())
                    {
                        text->textCursor().insertHtml(xmlStreamReader.text().toString() + "<br><br>");
                        amount++;
                    }
                }
            }
        }
    }
    if (xmlStreamReader.error() && xmlStreamReader.error() != QXmlStreamReader::PrematureEndOfDocumentError)
    {
        qWarning() << "XML ERROR:" << xmlStreamReader.lineNumber() << ": " << xmlStreamReader.errorString();
    }
}
