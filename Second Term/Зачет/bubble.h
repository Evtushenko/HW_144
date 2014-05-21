#pragma once
#include <iostream>
using namespace std;

template <class T>
class Bubble {
public:
    Bubble(T input[], int amount) : amount(amount) {
        array = new T(amount);
        for (int i = 0; i < amount; i++) {
            array[i] = input[i];
        }
    }
    ~Bubble() {
        delete[] array;
    }
    void sortInc() {
        for (int i = amount - 1 ; i >= 0 ; i--) {
            for (int j = 0 ; j < i ; j++) {
                if (array[j] > array[j+1]) {
                    swap(array[j],array[j+1]);
                }
             }
        }
    }
    void sortDec() {
        for (int i = amount - 1 ; i >= 0 ; i--) {
            for (int j = 0 ; j < i ; j++) {
                if (array[j] < array[j+1]) {
                    swap(array[j],array[j+1]);
                }
             }
        }
    }
    void print() {
        for (int i = 0; i < amount; i++) {
            cout << array[i] << endl;
        }
    }

private:
  void swap(T &a, T &b) {
      T slot = a;
      a = b;
      b = slot;
  }

  T *array;
  int amount;
};
