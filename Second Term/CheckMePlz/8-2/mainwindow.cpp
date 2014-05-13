#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow),
    view(new QWebView)
{
        ui->setupUi(this);
        networkAccessManager= new QNetworkAccessManager();
        connect(ui->load, SIGNAL(clicked()), this, SLOT(getText()));
        connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
        connect(ui->plus, SIGNAL(clicked()), this, SLOT(voteUp()));
        connect(ui->minus, SIGNAL(clicked()), this, SLOT(voteDown()));
        connect(ui->smile, SIGNAL(clicked()), this, SLOT(changePic()));
}

MainWindow::~MainWindow()
{
       delete ui;
       delete view;
       delete textNumber;
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
    ui->text->append("<br><b>successfuly voted for </b>" + *textNumber + "<br>");
    view->load(QUrl(begin + *textNumber + goodEnd));

}

void MainWindow::voteDown()
{
    ui->text->append("<b>successfuly voted against </b>" + *textNumber);
    view->load(QUrl(begin + *textNumber + badEnd));
}
void MainWindow::changePic() {
    int static counter = 0;
    switch (counter % 5) {
        case 0: {
            ui->smile->setText("( >＿<)");
            break;
        }
        case 1: {
            ui->smile->setText("( =＿=)");
            break;
        }
        case 2: {
            ui->smile->setText("( ಠ＿ಠ)");
            break;
        }
        case 3: {
             ui->smile->setText("(･_･ )");
            break;
            }
        case 4: {
            ui->smile->setText("(¬_¬ )");
            break;
        }
    }

    counter++;
}

void MainWindow::getText()
{
    ui->text->setText("");
    if (!networkReply)
    {
        networkReply->disconnect(this);
        networkReply->deleteLater();
    }
    networkReply = networkAccessManager->get(QNetworkRequest(QUrl("http://bash.im/rss/")));
    connect(networkReply, SIGNAL(readyRead()), this, SLOT(readData()));
}


void MainWindow::parseXml() {
    bool readed = false;
    while (!xmlStreamReader.atEnd() && !readed) // while is not end of file
    {
        xmlStreamReader.readNext(); // читает токен,  возвращает тип
        if (xmlStreamReader.isStartElement()) // true если токен == StartElement
        {
            if (xmlStreamReader.name() == "item") // возращает имя <тега>
            {
                while (!xmlStreamReader.atEnd() && !readed)
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
                        else
                        {
                            textNumber = new QString;
                            num = slot.indexOf("#",0);
                            for (int i = num + 1; i < slot.size(); i++)
                                textNumber->append(slot[i]);
                        }
                        //
                        ui->text->textCursor().insertHtml("<b>" + slot + "<b><br>");
                    }
                    if (xmlStreamReader.isCDATA())
                    {
                        ui->text->textCursor().insertHtml(xmlStreamReader.text().toString() + "<br><br>");
                        readed = true;
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
