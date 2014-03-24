#pragma once
#include "iostream"
using namespace std;

enum StatesAdding {exitA, changeA, addA};
enum StatesSearching {exitS, changeS, searchS};
enum StatesDeleting {exitD, changeD, deletingD};


class TestPlenty;

/**
@brief class for working with plenties
*/
template <typename T, int maxAmountPlenty = 10>
class Plenty
{
    /**
    @brief  included for using private fields
    */
    friend class TestPlenty;
public:
    /**
    @brief intialization arrayElements and start state
    */
    Plenty();
    /**
    @brief free memory from arrayElements
    */
    ~Plenty();
    /**
    @brief searching all lists for value
    */
    void itHere();
    /**
    @brief add to end of selected list
    */
    void add();
    /**
    @brief remove from selected list
    */
    void remove();
    /**
    @brief do list of all kinds of elements
    */
    void intergrate();
    /**
    @brief print this list
    */
    void printIntergate();
    /**
    @brief do list of all common kinds of elements
    */
    void cross();
    /**
    @brief print selected list
    */
    void print();
private:
    /**
    @brief works as list keeper
    */
    struct Elements{
        T value;
        Elements *next;
    };
    /**
    @brief array of lists
    */
    Elements *arrayElements[maxAmountPlenty];
    /**
    @brief switch current list for user activities
    */
    int currentPositionArray;
    /**
    @brief support function for adding
    */
    void addEnd(T value);
    /**
    @brief support function for removing
    */
    void deleteE(Elements *result);
    /**
    @brief if element is in list returns pointer
    @detailed has code here because it is not easy to declarate code below
    */
    Elements* findElements(T value) {
        Elements *result = arrayElements[currentPositionArray];
        while (result) {
            if (result->value == value)
                return result;
            result = result->next;
        }
        return result;
    }
};

template <typename T, int maxAmountPlenty>
Plenty<T, maxAmountPlenty>::Plenty() {
    for (int i = 0; i < maxAmountPlenty; i++) {
        arrayElements[i] = NULL;
    }
    currentPositionArray = 0;
}

template <typename T, int maxAmountPlenty>
Plenty<T, maxAmountPlenty>::~Plenty() {
    for (int i = 0; i < maxAmountPlenty; i++) {
        Elements *start = arrayElements[i];
        Elements *helper =  NULL;
        while (start) {
            helper = start;
            start = start->next;
            delete helper;
        }
    }
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::cross() {
    intergrate();
    int queue[maxAmountPlenty -1];
    for (int i = 0; i < maxAmountPlenty -1; i++ )
        queue[i] = 0;
    int queueAmount = 0;
    for (int i = 0; i < maxAmountPlenty - 1 ; i++ ) {
        currentPositionArray = i;
        Elements *slot = arrayElements[maxAmountPlenty-1];
        while (slot) {
            if (!findElements(slot->value)) {
                queue[queueAmount++] = slot->value;
            }
            slot = slot->next;
        }
        currentPositionArray = maxAmountPlenty-1;
        for (int i = 0; i < queueAmount; i++ )
            deleteE(findElements(queue[i]));
    }
    currentPositionArray = 0;
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::printIntergate() {
    Elements *slot = arrayElements[maxAmountPlenty -1];
    Elements *helper = NULL;
    //cout << "union of elements of plenties:\n";
    while (slot) {
        cout << slot->value << ", ";
        helper = slot;
        slot = slot->next;
        delete helper;
    }
    arrayElements[maxAmountPlenty -1] = NULL;
    cout << endl;
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::intergrate() {
    currentPositionArray = maxAmountPlenty -1;
    for (int i = 0; i < maxAmountPlenty -1 ; i++) {
        Elements *slot = arrayElements[i];
        while (slot) {
            if (!findElements(slot->value))
                addEnd(slot->value);
            slot = slot->next;
        }
    }
    currentPositionArray = 0;

}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::print() {
    Elements *slot = arrayElements[currentPositionArray];
    cout << endl;
    while (slot) {
        cout << slot->value << " ";
        slot = slot->next;
    }
    cout << endl;
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::itHere() {
    cout << "current numbers of List = " << currentPositionArray << endl;
    cout << "amount of Lists: \n" << maxAmountPlenty-1 << endl;
    cout << "searching menu:\n";
    cout << " 0 = stop searching\n";
    cout << " 1 = change current List\n";
    cout << " 2 = search 1 element\n";
    int state = -1;
    for (; state != exitS && state <= 2;) {
        cout << "enter state\n";
        cin >> state;
        if ( state == changeS) {
            cout << "enter number of list\n";
            cin >> currentPositionArray;
            if (currentPositionArray < 0 || currentPositionArray > 9 ) {
                cout << "error!\n";
                currentPositionArray = 0;
            }
        }
        if (state == searchS) {
            T value;
            cout << "enter value\n";
            cin >> value;
            if (!findElements(value))
                 cout << "not found in this List\n";
            else {
                cout << "here is it\n";
            }
        }
    }
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::deleteE(Elements *result) {
    Elements *previous = NULL;
    Elements *next = NULL;
    Elements *start = arrayElements[currentPositionArray];
    while (start) {
          if (start->next == result)
                 previous = start;
          if (start == result && start->next) {
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
                        arrayElements[currentPositionArray] = result->next;
                    else
                        if (!next && !previous)
                            arrayElements[currentPositionArray] = NULL;
            delete result;
            result = NULL;
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::remove() {
    cout << "current numbers of List = " << currentPositionArray << endl;
    cout << "amount of Lists: \n" << maxAmountPlenty-1 << endl;
    cout << "removing menu:\n";
    cout << " 0 = stop removing\n";
    cout << " 1 = change current List\n";
    cout << " 2 = delete 1 element\n";
    int state = -1;
    for (; state != exitD && state <= 2;) {
        cout << "enter state\n";
        cin >> state;
        if ( state == changeD) {
            cout << "enter number of list\n";
            cin >> currentPositionArray;
            if (currentPositionArray < 0 || currentPositionArray > 9 ) {
                cout << "error!\n";
                currentPositionArray = 0;
            }
        }
        if (state == deletingD) {
            T value;
            cout << "enter value\n";
            cin >> value;
            Elements *result = findElements(value);
            if (!result)
                 cout << "not found in this List\n";
            else {
               deleteE(result);
            }
        }
    }
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::addEnd(T value) {
    Elements *newObject = new Elements;
    newObject->value = value;
    newObject->next = NULL;
    if (arrayElements[currentPositionArray] == NULL) {
       arrayElements[currentPositionArray] = newObject;
    }
    else {
        Elements *slot = arrayElements[currentPositionArray];
        while (slot->next) {
            slot = slot->next;
        }
        slot->next = newObject;
    }
}

template <typename T, int maxAmountPlenty>
void Plenty<T, maxAmountPlenty>::add() {
   cout << "current numbers of List = " << currentPositionArray << endl;
   cout << "amount of Lists: \n" << maxAmountPlenty-1 << endl;
   cout << "adding menu:\n";
   cout << " 0 = stop adding\n";
   cout << " 1 = change current List\n";
   cout << " 2 = add 1 elements\n";
   int state = -1;
   for (; state != exitA && state <= 2;) {
       cout << "enter state\n";
       cin >> state;
       if ( state == changeA) {
           cout << "enter number of list\n";
           cin >> currentPositionArray;
           if (currentPositionArray < 0 || currentPositionArray > 9 ) {
               cout << "error!\n";
               currentPositionArray = 0;
           }
       }
       if (state == addA) {
           T value;
           cout << "enter value\n";
           cin >> value;
           if (!findElements(value))
                addEnd(value);
       }
   }
}
