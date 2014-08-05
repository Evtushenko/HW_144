#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QList>
#include "word.h"
#include "letter.h"

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
    void printFile();
    void printStat();
    void findWord();
    void addWord();
    void saveFile();

private:
    Ui::Dialog *ui;
    QList <Letter> listLetters;
    int currentLetter;
    void parseString(QString input);
    bool isLatinLetter(QChar input) {
        return (input >= 'a' && input <= 'z' || input >= 'A' && input <= 'Z');
    }
    void sort();
    void print();
};

#endif // DIALOG_H
