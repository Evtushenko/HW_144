#include "hashTable.h"

void Hashtable::addElement(char* string) {
    TableCell *neededList = &table[hash(string)];
    if (neededList->listIsEmpty())
        occupiedCells++;
    else
        if (neededList->sizeOfCell == 1)
            numberOfConflicts++;
    neededList->sizeOfCell++;
    neededList->addList(string);

}

bool Hashtable::findElement(char* string) {
    TableCell *neededList = &table[hash(string)];
        if (!neededList->listIsEmpty()){
            int i = 0;
            ElementList* scanningElement = neededList->headList();
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

bool Hashtable::removeElement(char* string) {
    TableCell* neededList = &table[hash(string)];
    if (!neededList->listIsEmpty()) {
        neededList->sizeOfCell--;

        if (neededList->sizeOfCell == 1)
            numberOfConflicts--;

        int i = 0;
        ElementList* previousElement = NULL;
        ElementList* scanningElement = neededList->headList();
        while (scanningElement != NULL){
            i = 0;
            while ((scanningElement->data[i] == string[i])&&(string[i] != '\0')) {
                i++;
            }
            if (string[i] == '\0') {  //delete scanningElement from neededList
                if (previousElement == NULL){
                    neededList->removeFromList(1);
                    if (neededList->listIsEmpty())
                        occupiedCells--;
            }
            else{
                ElementList* tmp = scanningElement;
                previousElement->next = scanningElement->next;
                delete tmp;
            }
            return true;
            }
            previousElement = scanningElement;
            scanningElement = scanningElement->next;

        }
    }
    return false;
}

void Hashtable::showStatistic() {
    printf("\n\nAll Cells: %d\n", sizeTable);
    printf("Occupied Cells: %d\n", occupiedCells);
    printf("Free Cells: %d\n", sizeTable - occupiedCells);
    printf("Load Factor: %.8f\n", (double)occupiedCells/sizeTable);
    printf("Count of Conflicts: %d\n", numberOfConflicts);
    printf("Max Size of Cell: %d\n\n", getMaxSize());
}

int Hashtable::getMaxSize(){
    int maxSize = 0;
    for (int i = 0; i < sizeTable; i++)
        if (!table[i].listIsEmpty())
            if (maxSize < table[i].sizeOfCell)
                maxSize = table[i].sizeOfCell;

    return maxSize;
}
