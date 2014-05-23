#include "comparator.h"

// универсальная функция сортировки пузырьком для любого класс с компаратором
template <class D>
void  bubbleSort(D array[], int const amount, Comparater<D> rule) {
        for (int i = 0; i < amount; i++)
            for (int j = i + 1; j < amount; j++ )
                if (rule.bigger(array[i], array[j])) {
                    D slot = array[i];
                    array[i] = array[j];
                    array[j] = slot;
                }
}
