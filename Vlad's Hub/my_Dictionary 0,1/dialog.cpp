#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include <string>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    currentLetter(-1),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // проход по всем буквам
    // Создаем список из всех букв
    char letA = 'A';
    while (int(letA) <= int('Z'))
    {
        Letter *newLetter = new Letter();
        newLetter->value = QChar::fromLatin1(letA);
        listLetters.append(*newLetter);
        //ui->textOut->append(newLetter->value); // тестовый вывод всех букв из списка букв
        letA = char(1 + (int(letA)));
    }



    // читаем и выводим все строки из файла
    QFile file("RedmondLanguage.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             ui->textOut->append("can not read file");
    else
    {
        QTextStream in(&file);
        in.setCodec("UnicodeUTF8");
        int stop = 0;
        while (!in.atEnd() && stop < 4000) {
          QString slot = in.readLine();
          parseString(slot);
          //ui->textOut->append(slot);
          stop++;
        }

    }
    file.close();
    sort();
    connect(ui->load,SIGNAL(clicked()), this,  SLOT(printFile()));
    connect(ui->stat, SIGNAL(clicked()), this, SLOT(printStat()));
    connect(ui->find, SIGNAL(clicked()), this, SLOT(findWord()));
    connect(ui->add, SIGNAL(clicked()), this, SLOT(addWord()));
    connect(ui->save, SIGNAL(clicked()), this, SLOT(saveFile()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::printFile()
{
    ui->textOut->setText("");
    for (int i = 0; i < listLetters.length(); i++) {
        QString slot = ".";
        slot.append(listLetters.at(i).value);
        ui->textOut->append(slot);
        for (int j = 0; j < listLetters.at(i).listWords.length(); j++) {
            QString slot2;
            slot2.append(*listLetters.at(i).listWords.at(j).english);
            slot2.append(" = ");
            slot2.append(*listLetters.at(i).listWords.at(j).meaning);
            ui->textOut->append(slot2);
        }

    }
}

void Dialog::printStat()
{
    ui->textOut->setText("");

    ui->textOut->append("статистика слов по буквам : ");
    int counter = 0;

    // обход всех букв
    for (int i = 0; i < listLetters.length(); i++) {
        QString slot;
        slot.append("буква = ");
        slot.append(listLetters[i].value);
        slot.append(" количетво слов = ");
        slot.append(QString::number(listLetters[i].listWords.length()));
        ui->textOut->append(slot);
        counter += listLetters[i].listWords.length();
    }
    QString slot = "всего слов = ";
    slot.append(QString::number(counter));
    ui->textOut->append(slot);
}

void Dialog::findWord()
{
    ui->textOut->setText("ищем слово:");
    ui->textOut->append(ui->engInput->text());
    std::string slot = ui->engInput->text().toStdString();
    char firstLet = slot.at(0);
    int index = firstLet - 'a';
    //ui->textOut->append(QString::number(index));
    bool res = false;
    for (int i = 0; i < listLetters[index].listWords.length(); i++) {
        if (*listLetters[index].listWords[i].english == ui->engInput->text()) {
            ui->textOut->append("слово найдено в базе");
                    res = true;
        }
    }
    if (!res)
        ui->textOut->append("слово не найдено в базе");
}

void Dialog::addWord()
{
    ui->textOut->setText("добавляем слово:");
    ui->textOut->append(ui->engInput->text());
    ui->textOut->append("со значением:");
    ui->textOut->append(ui->meaningInput->text());

    std::string slot = ui->engInput->text().toStdString();
    char firstLet = slot.at(0);
    int index = firstLet - 'a';

    Word *newOne = new Word();
    newOne->english = new QString(ui->engInput->text());
    newOne->meaning = new QString(ui->meaningInput->text());
    listLetters[index].listWords.append(*newOne);
    sort();
}

void Dialog::saveFile()
{
    ui->textOut->setText("сохраняем в RedmondLanguage.txt (он же исходный)");
    QFile file("RedmondLanguage.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);

    //QString aa= "test";

    //out << aa << "\n";
    for (int i = 0; i < listLetters.length(); i++) {
        QString slot = ".";
        slot.append(listLetters.at(i).value);
        out << slot << endl;
        for (int j = 0; j < listLetters.at(i).listWords.length(); j++) {
            QString slot2;
            slot2.append(*listLetters.at(i).listWords.at(j).english);
            slot2.append(" = ");
            slot2.append(*listLetters.at(i).listWords.at(j).meaning);
            out << (slot2) << endl;
        }

    }
    file.close();

}

void Dialog::parseString(QString input)
{
    // смена буквы
    if (input.indexOf('.') != -1) {
        currentLetter++;
        //ui->textOut->append(input);
    }
    else
    {
        // это слово
        if (input.length() > 1) {
            Word *newWord = new Word();

            // нашли позицию разделителя
            int bondPosition = 0;
            while (bondPosition < input.length() ) {
               if (input[bondPosition] == '-' || input[bondPosition] == '=')
                   break;
               bondPosition++;
            }

            // английское написание слова
            QString *eng = new QString();
            int i = 0;
            while (i < bondPosition) {
                eng->append(input[i]);
                i++;
            }
           // ui->textOut->append(*eng);

            // значение английского слова
            QString *meaning = new QString();
            for (int i = bondPosition + 1; i < input.length(); i++) {
                meaning->append(input[i]);
            }
            //ui->textOut->append(*meaning);

            newWord->english = eng;
            newWord->meaning = meaning;
            listLetters[currentLetter].listWords.append(*newWord);
            //ui->textOut->append(*newWord->english);
            //ui->textOut->append(*newWord->meaning);
        }
    }
}

void Dialog::sort()
{
    for (int i = 0; i < listLetters.length(); i++) {
        for (int m = 0; m < listLetters[i].listWords.length() - 1; m++ ) {
        for (int j = 0; j < listLetters[i].listWords.length() - 1; j++) {
            QString a =  *listLetters[i].listWords.at(j).english;
            QString b =  *listLetters[i].listWords.at(j + 1).english;
            int counter = 0;
            int res = 0;
            while( counter < a.length() && counter < b.length()) {
                if (a.at(counter) != b.at(counter)) {
                    if (a.at(counter) > b.at(counter)) {
                        res = 1;
                    }
                    else
                        res = 2;
                    break;
                }
                counter++;
            }
            if (res == 1) {
                listLetters[i].listWords.swap(j, j + 1);
            }
        }
        }
    }
}
