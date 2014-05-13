#include "interpreter.h"

//using namespace std;


int const bufferSize = 100;

Interpreter::Interpreter(char nameFile[]) throw(ExceptionRead()):

    beginLS(nullptr),
    endLS(nullptr),
    amountString(0),
    currentString(0),
    top(nullptr),
    bottom(nullptr)
{

    for (int i = 0; i < bufferSize * 10; i++ )
        Memory[i] = -1;


    // читаем строки в список строк
    char slot[bufferSize];
    ifstream inFile;
    inFile.open(nameFile, ios::in);
    if (!(inFile.is_open())) {
            throw ExceptionRead();
    }
    while (inFile.good()) {
        inFile.getline(slot, bufferSize);
        pushLS(slot);
        amountString++;
    }
    inFile.close();

    // заполняем массив строк
    ListStrings *slot1 = beginLS;
    int c = 0;
    while (slot1) {
        arrayString[c] = slot1;
        slot1 = slot1->next;
        c++;
    }

}

Interpreter::~Interpreter() {
    Stack *slot;
    while (top) {
        slot = top;
        top = top->previous;
        delete slot;
    }
    for (int i = 0; i < amountString; i++)
        delete arrayString[i];
}

void Interpreter::pushLS(char str[]) {
    ListStrings *slot = new ListStrings(str);
    if (endLS == nullptr) {
        endLS = slot;
        beginLS = slot;
    }
    else  {
        endLS->next = slot;
        endLS = slot;
    }
}

void Interpreter::pushStack(int num) {
    Stack *slot = new Stack(num);
    if (!top) {
        top = slot;
        bottom = slot;
    }
    else
    {
        slot->previous = top;
        top = slot;
    }

}

int Interpreter::popStack() {
    if (!top)
        return -1;
    int slot = top->num;
    Stack *slot1 = top;
    top = top->previous;
    delete slot1;
    return slot;
}

int Interpreter::getInt(int numberStr, int position) {
    int result = 0;
    int length = strlen(arrayString[numberStr]->str);
    for (int i = position; i < length; i++) {
        result += (int(arrayString[numberStr]->str[i]) -int('0') )*pow(10,strlen(arrayString[numberStr]->str) - i -1);
    }
    return result;
}

int Interpreter::findPoint(char name[]) {
    //cout << "call find with " << name << endl;
    int nameLen = strlen(name);
    for (int i = 0; i < amountString; i++) {
        int len = strlen(arrayString[i]->str);
        if (len == nameLen + 1) {
            bool res = true;
            for (int j = 0; j < nameLen; j++)
                if (name[j] != arrayString[i]->str[j] )
                    res = false;
            if (res)
                return i;
        }
    }
    return -1;
}

char *Interpreter::getPoint(int numberStr, int position) {
    char *result = new char(strlen(arrayString[numberStr]->str) - position);
    int len = strlen(arrayString[numberStr]->str);
    for (int i = position; i < len; i++ )
        result[i - position] = arrayString[numberStr]->str[i];
    int lenRes = strlen(result);
    for (int i = len - position; i < lenRes; i++ )
        result[i] = '\0';
    return result;
}

void Interpreter::execute() {
    for(;;) {
        // ;... = комментарий
        if (strlen(arrayString[currentString]->str) >= 1 && arrayString[currentString]->str[0] == ';')
            continue;

        // ret = завершение работы
        if (strlen(arrayString[currentString]->str) >= 3 && arrayString[currentString]->str[0] == 'r'
                && arrayString[currentString]->str[1] == 'e' && arrayString[currentString]->str[2] == 't'
                )
        {
            break;
        }

        // st <adress> = из стека в дату (из стека удаляется)
        if (strlen(arrayString[currentString]->str) >= 3 && arrayString[currentString]->str[0] == 's'
                && arrayString[currentString]->str[1] == 't' && arrayString[currentString]->str[2] == ' '
                )
        {
            Memory[ getInt(currentString, 3)] = popStack();
        }

        // ldc <number> = константа на вершину стека
        if (strlen(arrayString[currentString]->str) >= 5 && arrayString[currentString]->str[0] == 'l'
                && arrayString[currentString]->str[1] == 'd' && arrayString[currentString]->str[2] == 'c'
                )
        {
            pushStack(getInt(currentString, 4));
        }

        // ld <adress> = загружает на вершину стека число из даты по данному адресу
        if (strlen(arrayString[currentString]->str) >= 4 && arrayString[currentString]->str[0] == 'l'
                && arrayString[currentString]->str[1] == 'd' && arrayString[currentString]->str[2] == ' '
                )
        {
            pushStack(Memory[ getInt(currentString, 3)]);
        }

        // add  = константа на вершину стека. сумма топ и предТоп. Сами числа не уходят
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 'a'
                && arrayString[currentString]->str[1] == 'd' && arrayString[currentString]->str[2] == 'd'
                )
        {
            pushStack(popStack()+ popStack());
        }

        // sub = константа на вершину стека. разность топ и предТоп. Сами числа не уходят
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 's'
                && arrayString[currentString]->str[1] == 'u' && arrayString[currentString]->str[2] == 'b'
                )
        {
            pushStack(popStack() - popStack());
        }

        // cmp = сравнение 2 чисел на вершине стека: 0(равны) 1(первое больше) -1(второе больше). Сами числа не уходят
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 'c'
                && arrayString[currentString]->str[1] == 'm' && arrayString[currentString]->str[2] == 'p'
                )
        {
            int slot1 = popStack();
            int slot2 = popStack();
            (slot1 == slot2) ?
                        pushStack(0) :
                        slot1 > slot2 ?
                            pushStack(1) :
                            pushStack(-1);
        }

        //  jmp<метка> - в индекс поинтер помещается адресс команды соответствующей метки
        if (strlen(arrayString[currentString]->str) >= 3  && arrayString[currentString]->str[0] == 'j'
                && arrayString[currentString]->str[1] == 'm' && arrayString[currentString]->str[2] == 'p'
                )
        {

            if (findPoint(getPoint(currentString,4)) != -1) {
                currentString = findPoint(getPoint(currentString,4));
            }
        }

        //  jz<метка> - в индекс поинтер помещается адресс команды соответствующей метки. ЕСЛИ НОЛЬ.
        if (strlen(arrayString[currentString]->str) >= 3  && arrayString[currentString]->str[0] == 'j'
                && arrayString[currentString]->str[1] == 'z' && arrayString[currentString]->str[2] == ' '
                )
        {

            if (top && !top->num)
                if (findPoint(getPoint(currentString,3)) != -1) {
                    currentString = findPoint(getPoint(currentString,3));
                    // inc = true; //
                }
        }

        //  jzn<метка> - в индекс поинтер помещается адресс команды соответствующей метки. ЕСЛИ HE НОЛЬ.
        if (strlen(arrayString[currentString]->str) >= 3  && arrayString[currentString]->str[0] == 'j'
                && arrayString[currentString]->str[1] == 'n' && arrayString[currentString]->str[2] == 'z'
                )
        {

            if (top && top->num != 0)
                if (findPoint(getPoint(currentString,4)) != -1) {
                    currentString = findPoint(getPoint(currentString,4));
                    // inc = true; //
                }
        }

        //  jg<метка> - в индекс поинтер помещается адресс команды соответствующей метки. ЕСЛИ  БОЛЬШЕ НОЛЯ.
        if (strlen(arrayString[currentString]->str) >= 3  && arrayString[currentString]->str[0] == 'j'
                && arrayString[currentString]->str[1] == 'g' && arrayString[currentString]->str[2] == ' '
                )
        {
            if (top && top->num > 0) {
                if (findPoint(getPoint(currentString,3)) != -1) {
                    currentString = findPoint(getPoint(currentString,3));
                }
            }
        }


        //  jl<метка> - в индекс поинтер помещается адресс команды соответствующей метки. ЕСЛИ  БОЛЬШЕ НОЛЯ.
        if (strlen(arrayString[currentString]->str) >= 3  && arrayString[currentString]->str[0] == 'j'
                && arrayString[currentString]->str[1] == 'l' && arrayString[currentString]->str[2] == ' '
                )
        {
            if (top && (top->num < 0)) {
                if (findPoint(getPoint(currentString,3)) != -1) {
                    currentString = findPoint(getPoint(currentString,3));
                    // inc = true; //
                }
            }
        }

        //  std- очистить весь стек
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 's'
                && arrayString[currentString]->str[1] == 't' && arrayString[currentString]->str[2] == 'd'
                )
        {
            Stack *slot;
            while (top) {
                slot = top;
                top = top->previous;
                delete slot;
            }

        }

        // mul = константа на вершину стека. произведение топ и предТоп. Сами числа не уходят
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 'm'
                && arrayString[currentString]->str[1] == 'u' && arrayString[currentString]->str[2] == 'l'
                )
        {
            pushStack(popStack() * popStack());
        }

        // div = константа на вершину стека. деление топ и предТоп. Сами числа не уходят
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 'd'
                && arrayString[currentString]->str[1] == 'i' && arrayString[currentString]->str[2] == 'v'
                )
        {
            pushStack(popStack() / popStack());
        }

        // abs = модулю вершины на вершину
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 'a'
                && arrayString[currentString]->str[1] == 'b' && arrayString[currentString]->str[2] == 's'
                )
        {
            pushStack(abs(popStack()));
        }

        // mod = остаток от деления
        if (strlen(arrayString[currentString]->str) == 3  && arrayString[currentString]->str[0] == 'm'
                && arrayString[currentString]->str[1] == 'o' && arrayString[currentString]->str[2] == 'd'
                )
        {
            int slot1 = popStack();
            int slot2 = popStack();
            pushStack(slot1 % slot2);
        }

        //идем дальше по строкам
        currentString++;
    }
}

void Interpreter::printStrs() {
    // первый вариант печати

    /*
    ListStrings *slot = beginLS;
    while (slot) {
        cout << slot->str << endl;
        slot = slot->next;
    }
    */

    for (int i = 0; i < amountString; i++)
        cout << arrayString[i]->str << endl;
}

void Interpreter::printMemory() {
    cout << "Memory List:\n";
    for (int i = 0; i < maxAmount * 10; i++)
        if (Memory[i] != -1)
            cout <<"index: " << i << " value: " <<  Memory[i] << endl;
}

void Interpreter::printStack() {
    cout << "Stack List:\n";
    Stack *slot = top;
    while (slot) {
        cout << slot->num << endl;
        slot = slot->previous;
    }
}

Interpreter::ListStrings::ListStrings(char strI[]):
    next(nullptr)
{
    char *slot = new char(strlen(strI));
    int lenStrI = strlen(strI);
    for (int i = 0; i < lenStrI; i++)
        slot[i] = strI[i];
    str = slot;
    int lenSlot = strlen(slot);
    for (int i = lenStrI; i < lenSlot; i++) {
        slot[i] = '\0';
    }
}
