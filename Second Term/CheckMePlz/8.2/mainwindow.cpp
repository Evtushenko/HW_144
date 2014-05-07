#include "mainwindow.h"

MainWindow::MainWindow(int amount, QWidget *parent)
    : QDialog(parent),
      amountQuotes(amount),
      menu(new QVBoxLayout),
      load(new QPushButton),
      exit(new QPushButton),
      text(new QTextEdit)
{

    text->setReadOnly(true);
    load->setText("Take 10");
    exit->setText("Exit");

    load->setFont(QFont("Times", 18, QFont::Bold));
    exit->setFont(QFont("Times", 18, QFont::Bold));

    networkAccessManager= new QNetworkAccessManager();

    menu->addWidget(text);
    menu->addWidget(load);
    menu->addWidget(exit);
    setLayout(menu);

    connect(load, SIGNAL(clicked()), this, SLOT(getText()));
    connect(exit, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {
    menu->removeWidget(text);
    menu->removeWidget(load);
    menu->removeWidget(exit);
    delete menu;
    delete text;
    delete load;
    delete exit;
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

void MainWindow::getText()
{
    if (networkReply)
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
                        slot.remove(slot.size() -5, 5);
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

