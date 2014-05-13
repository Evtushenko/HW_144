#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

class Test;

using namespace std;

int const maxAmount = 100;

class ExceptionRead {
public:
    ExceptionRead() {
        cout << "error reading\n";
    }
};

class Interpreter
{
    friend class Test;
public:

    // читаем строки
    Interpreter(char nameFile[]) throw(ExceptionRead());
    // чистим память
    ~Interpreter();

    // выполняет комманды из файла
    void execute();

private:
/////////////////////////////////////////
    // для хранения строк из файла
    struct ListStrings {
        public:
            ListStrings(char strI[]);
            ListStrings() {}
            ~ListStrings() {}
            char *str;
            ListStrings *next;
    };
    ListStrings  *beginLS;
    ListStrings  *endLS;

    // добавить строку в конец
    void pushLS(char str[]);

    // количество строк в файле
    int amountString;

    // текущий номер строки
    int currentString;

    // массив указателей на строки
    ListStrings *arrayString[maxAmount];

    // печатаем строки
    void printStrs();
/////////////////////////////////////////

    // АТД ПАМЯТЬ
    int Memory[maxAmount * 10];

    //печатаем память
    void printMemory();
/////////////////////////////////////////
    // АТД СТЕК
    struct Stack {
    public:
        Stack(int num):
            num(num),
            previous(nullptr)
        {}
        long int num;
        Stack *previous;
    };
    Stack *top;
    Stack *bottom;

    // Добавить в АТД СТЕК
    void pushStack(int num);
    //выкинуть топовое значение
    int popStack();
    // печатаем стек
    void printStack();
///////////////////////////////////////
    // получить число из комманды
    // пример:
    // дана строка: ld 1488
    // вызов функции getInt(0,3)
    // результат 1488
    int getInt(int numberStr, int position);

    // принимает имя точки перехода и возращает индекс строки если нашлось и -1 иначе
    int findPoint(char name[]);

    // принимает номер индекс строки и начало названия. Возвращает имя метки.
    char* getPoint(int numberStr, int position);

};






