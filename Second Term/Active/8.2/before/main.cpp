#include <stdio.h>
#include "hashtable.h"
#include "hash31.h"
#include "CRC32Hash.h"
#include "RotatingHash.h"
#include "hashtableTest.h"

enum{
    ShowStatistic, AddElement, FindElement, RemoveElement, ChangeHash

};

void setTypeOfHash(Hashing* &hashCounter){

    int typeOfHash = -1;
    while(typeOfHash == -1){

        printf("What type of hash would you like to use?\n");
        printf("0 - Polynimial31Hash; 1 - CRC32Hash; 2 - RotatingHash: ");
        scanf("%d", &typeOfHash);
        switch(typeOfHash){

        case 0:{
            hashCounter = new hash31;
            break;
        }
        case 1:{
            hashCounter = new CRC32Hash;
            break;
        }
        case 2:{
            hashCounter = new RotatingHash;
            break;
        }
        default:{
            typeOfHash = -1;
            printf("Wrong type of hash\n");
        }

        }
    }
}

void setOperations(Hashtable* &table, Hashing* &hashCounter){

    char string[255];
    Hashing* actualHashCounter;
    int operation = 0;
    while (operation != -1){
        printf("\nAvaliable operations:\n");
        printf("0 - show Statistic;\n");
        printf("1 - add Element\n");
        printf("2 - Find Element\n");
        printf("3 - Remove Element\n");
        printf("4 - Change hash function\n");
        printf("-1 - Exit\n");
        printf("Insert operation: ");
        scanf("%d", &operation);
        switch(operation){

        case ShowStatistic:{
            table->showStatistic();
            break;
        }

        case AddElement:{
            printf("Insert data: ");
            scanf("%s", string);
            table->addElement(string);
            printf("\nAdded succesfully\n\n");
            break;
        }

        case FindElement:{
            printf("Insert data: ");
            scanf("%s", string);
            if(table->findElement(string))
                printf("\nThis element exists\n\n");
            else
                printf("\nThis element is absent\n\n");
            break;
        }

        case RemoveElement:{
            printf("Insert data: ");
            scanf("%s", string);
            table->removeElement(string);
            printf("\nRemoved succesfully\n\n");
            break;
        }

        case ChangeHash:{
            setTypeOfHash(actualHashCounter);
            table->changeHash(actualHashCounter);
            delete hashCounter;
            hashCounter = actualHashCounter;
            break;
        }
        default:{
            if(operation != -1)
                printf("Wrong operation\n");
        }
        }
    }

}

int main()
{
    hashtableTest test;
    QTest::qExec(&test);

    Hashing* hashCounter;
    setTypeOfHash(hashCounter);
    Hashtable* table = new Hashtable(hashCounter);
    setOperations(table, hashCounter);
    delete table;
    delete hashCounter;

    return 0;
}

