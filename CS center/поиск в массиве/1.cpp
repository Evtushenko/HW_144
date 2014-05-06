//ƒано натуральное число 1?n?105 и массив целых чисел A[1Еn], 
//не превосход€щих по модулю 109. Ќеобходимо вывести True, 
//если в массиве A есть число, встречающеес€ строго больше
// n/2 раз, и False в противном случае.
#include <iostream>

using namespace std;
/*
void change( long int first,  long int second, long long mas[]){
    int tmp = mas[first];
    mas[first] = mas[second];
    mas[second] = tmp;
}

void quickSort( long int begin, long int end, long long s[]){
    long int middle = s[(begin + end) / 2];
    long int i = begin;
    long int j = end;

    while (i < j){
        while (s[i] < middle)
            ++i;
        while (s[j] > middle)
            --j;
        if (i <= j)
        {
            if (i < j)
                change(i, j, s);
            ++i;
            --j;
        }
    }

    if (i < end)
        quickSort(i, end, s);
    if (j > begin)
        quickSort(begin, j, s);
}
*/

void downHeap(long long  a[], long int  k, long int  n)
{
    //  процедура просеивани€ следующего элемента
    //  ƒо процедуры: a[k+1]...a[n]  - пирамида
    //  ѕосле:  a[k]...a[n]  - пирамида
    long long new_elem;
    long int child;
    new_elem = a[k];

    while(k <= n/2) // пока у a[k] есть дети
    {
        child = 2*k;

        if( child < n && a[child] < a[child+1] ) //  выбираем большего сына
            child++;
        if( new_elem >= a[child] )
            break;
        // иначе
        a[k] = a[child];    // переносим сына наверх
        k = child;
    }
    a[k] = new_elem;
}

void quickSort(long long a[], long int size)
{
    long int i;
    long long temp;

  // строим пирамиду
    for(i = size / 2 - 1; i >= 0; --i)
        downHeap(a, i, size-1);

  // теперь a[0]...a[size-1] пирамида

    for(i=size-1; i > 0; --i)
    {
        // мен€ем первый с последним
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        // восстанавливаем пирамидальность a[0]...a[i-1]
        downHeap(a, 0, i-1);
    }
}


 int main() {
   long int n = 0;
   cin >> n;
   long long  array[n];
   for (   long int i = 0; i < n ; i++)
       cin >> array[i];
   quickSort(array, n);
   //for (int i = 0; i < n ; i++ )
       //cout << array[i] << " ";
   //cout << endl;

   bool ok = false;
   if ( n % 2 == 1) {
    for (long int i = 0; i <= n/2; i++) {
       if (array[i] == array[i + n/2])
           ok = true;
    }
   }
   else
   {
       for (long int i = 0; i < n/2; i++) {
          if (array[i] == array[i + n/2])
              ok = true;
       }
   }



   ok ?
       cout << "True"
   :
       cout << "False";

   return 0;
}