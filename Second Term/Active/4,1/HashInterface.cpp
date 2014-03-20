#include "HashInterface.h"

using namespace std;

HashInterface::HashInterface (){
    for ( int i =0 ; i < amountElements; i++)
        arrayWords[i] = NULL;
    slotWords = NULL;
}

HashInterface::~HashInterface (){
    for ( int i = 0 ; i < amountElements; i++) {
        if (arrayWords[i]) {
            Words *slot1 = arrayWords[i];
            Words *slot2 = NULL;
            while (slot1) {
                slot2 = slot1;
                slot1 = slot1->next;
                delete slot2;
            }
        }
    }
}

int HashInterface::calcHash(char *text) {

    if (numberHF == 0) {

        return firstHF.calcHash(text);
    }
    if (numberHF == 1) {
        return secondHF.calcHash(text);
    }
    return -1;
}

bool HashInterface::itWasHere(Words *slot, char *text) {
    Words *helper = slot;
    int lengthText = strlen(text);
    while (helper) {
        bool result = true;
        if (strlen(text) != strlen(helper->word) )
            result = false;
        else {
            for (int i = 0; i < lengthText  ; i++) {
                if (text[i] != helper->word[i])
                    result = false;
            }
        }
        slotWords = helper;
    helper=helper->next;
    if (result) {
        return true;
    }
    }
    return false;
}

int HashInterface::searchHT(char *buffer) {
    slotWords = NULL;
    bool result = false;
    int i = 0;
    for (i ; i < amountElements; i++) {
        if (itWasHere(arrayWords[i],buffer) ) {
            result = true;
            break;
        }
    }
    if (result) {
        cout << "it is here\n";
        return i;
    }
    cout << "it is not here\n";
    return -1;
}

void HashInterface::addHT() {
    cout << "enter the word\n";
    Words *newOne = new Words;
    newOne->next = NULL;
    for (int i = 0; i < maxLengthWord; i++) {
        newOne->word[i] = '\0';
    }
    cin >> newOne->word;
    Words *position = arrayWords[this->calcHash(newOne->word)];
    if (!itWasHere(position, newOne->word) ) {
        if (!position) {
            arrayWords[this->calcHash(newOne->word)] = newOne;
        }
        else {
            while (position->next) {
                position = position->next;
            }
            position->next = newOne;
        }
    }
    else {
        delete newOne;
    }

}

void HashInterface::deleteHT(char *buffer) {
    int index = searchHT(buffer);
    if ( index  != -1) { // slotWords - указатель на того, кого надо удалить \\ index = номер списка в массиве списков
        Words *start = arrayWords[index];
        Words *previous = NULL;
        Words *next = NULL;
        while (start) {
            if (start->next == slotWords)
                previous = start;
            if (start == slotWords && start->next) {
                next = start->next;
            }
            start = start->next;
        }

        if (previous && next)
            previous->next = next;
        else
            if (previous)
                previous->next = NULL;
            else
                if (next)
                    arrayWords[index] = slotWords->next;
                else
                    if (!next && !previous)
                        arrayWords[index] = NULL;
        delete slotWords;
        slotWords = NULL;
    }
};

/*
void HashInterface::test() {
    cout << "list of index = 1\n";
    Words *helper = arrayWords[1];
    while (helper) {
        cout << helper->word << endl;
        helper = helper->next;
    }

};
*/

void HashInterface::staticHT() {
    int occupyCellcAmount = 0;
    int amountClash = 0;
    int maxLengthClash = 0;
    for (int i = 0; i < amountElements; i++) {
        int currentLengthClash = 1;
        if (arrayWords[i]) {
            occupyCellcAmount++;
        }
        if (arrayWords[i] && arrayWords[i]->next) {
            amountClash++;
            Words *helper = arrayWords[i]->next;
            while (helper) {
                currentLengthClash++;
                helper = helper->next;
            }
            if (currentLengthClash > maxLengthClash)
                maxLengthClash = currentLengthClash;
        }
    }

    double loadFactor = double(occupyCellcAmount) / double(amountElements);
    cout << "total amount of cells: " << amountElements << endl;
    cout << "amount of occupy cells: " << occupyCellcAmount << endl;
    cout << "max length of words: " << maxLengthWord << endl;
    printf("load factor: %lf\n",loadFactor);
    cout << "amount of clashes: " << amountClash << endl;
    cout << "max length of list clashes: " << maxLengthClash << endl;
};
