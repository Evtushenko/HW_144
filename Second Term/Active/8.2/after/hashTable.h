#pragma once
#include "tableCell.h"
#include "hashing.h"
#include <iostream>

using namespace std;

class Hashtable{
public:
    int occupiedCells;
    int numberOfConflicts;
    TableCell<char*> *Table;
    Hashing*  previousHashHelper;
    static int const sizeTable = 20400;
    Hashing*  hashHelper;

    int hash(char* string) {
        return hashHelper->hashFunction(string);
    }

    Hashtable (Hashing* typeOfHash) {
        cout << "constructor\n";
        hashHelper = typeOfHash; //
        Table = new TableCell<char*>[sizeTable];
        //cout << Table[hash("ss")].sizeOfCell << endl;
        occupiedCells = 0;
        numberOfConflicts = 0;

    }

    //void addElement(char* string) {
    void addElement(char* string) {
        cout << "call add with " << string << endl;
        //TableCell<char*> *neededList;
        TableCell<char*> *neededList = &Table[hash(string)];
        //cout << "ok\n";
        //cout << &Table[hash(string)] << endl;
        //cout << "ok\n";

        if (neededList->listIsEmpty())
         occupiedCells++;
        else
            if (neededList->sizeOfCell == 1)
                numberOfConflicts++;
        neededList->sizeOfCell++;
        neededList->addList(string);

    }
    bool findElement(char* string) {
        TableCell<char*>* neededList = &Table[hash(string)];
        if (!neededList->listIsEmpty()){
            int i = 0;
        ElementList<char*>* scanningElement = neededList->headList();
        while(scanningElement != NULL){
            i = 0;
            while((scanningElement->data[i] == string[i])&&(string[i] != '\0')) //compare current string with pattern
                i++;
            if (string[i] == '\0')
                return true;
            scanningElement = scanningElement->next;
        }
    }
    return false;
    }

    bool removeElement(char* string) {
        TableCell<char*>* neededList = &Table[hash(string)];
    if (!neededList->listIsEmpty()) {
        cout << "here " << endl;
        neededList->sizeOfCell--;

        if (neededList->sizeOfCell == 1)
            numberOfConflicts--;

        int i = 0;
        ElementList<char*>* previousElement = NULL;
        ElementList<char*>* scanningElement = neededList->headList();
        while (scanningElement != NULL){
            //cout << "here\n";
            i = 0;
            //cout << "start comparing\n";
            while ((scanningElement->data[i] == string[i])&&(string[i] != '\0')) {
                //cout << scanningElement->data[i] << " and " << string[i] << endl;
                i++;
            }
            if (string[i] == '\0') {  //delete scanningElement from neededList

                //cout << "here we come\n";
                if (previousElement == NULL){
                    neededList->removeFromList(1);
                    if (neededList->listIsEmpty())
                        occupiedCells--;
                }
                else{
                    ElementList<char*>* tmp = scanningElement;
                    previousElement->next = scanningElement->next;
                    delete tmp;
                }
                //return false;
                return true;

            }
            previousElement = scanningElement;
            scanningElement = scanningElement->next;

        }
    }
    return false;
    }

    void changeHash(Hashing* typeOfHash) {
        previousHashHelper = hashHelper;
    hashHelper = typeOfHash;
    int actualHash;
    ElementList<char*>* head;
    ElementList<char*>* tmp;
    for(int i = 0; i < sizeTable; i++){
        if(!Table[i].listIsEmpty()){
            head = Table[i].headList();
            actualHash = hashHelper->hashFunction(head->data);

            while((actualHash != i) && (head != NULL)){
                Table[actualHash].addList(head->data);
                Table[actualHash].sizeOfCell++;
                head = head->next;
                tmp = head;
                delete tmp;
                Table[i].sizeOfCell--;
                if (head != NULL)
                    actualHash = hashHelper->hashFunction(head->data);
            }
        }
    }
    }
    void showStatistic() {
        printf("\n\nAll Cells: %d\n", sizeTable);
        printf("Occupied Cells: %d\n", occupiedCells);
        printf("Free Cells: %d\n", sizeTable - occupiedCells);
        //loadFactor = (double)occupiedCells/sizeTable;
        printf("Load Factor: %.8f\n", (double)occupiedCells/sizeTable);
        printf("Count of Conflicts: %d\n", numberOfConflicts);
        printf("Max Size of Cell: %d\n\n", getMaxSize());
    }

    int getMaxSize(){
    int maxSize = 0;
    for(int i = 0; i < sizeTable; i++)
        if(!Table[i].listIsEmpty())
            if(maxSize < Table[i].sizeOfCell)
                maxSize = Table[i].sizeOfCell;

    return maxSize;

}

};
