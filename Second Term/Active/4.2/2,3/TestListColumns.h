#include <QtTest/QTest>
#include <QtCore/QObject>
#include "Sorter.h"

using namespace std;

class TestListColumns : public QObject
{
    Q_OBJECT
public:
    explicit TestListColumns (QObject *parent = 0) : QObject(parent) {}
private:
    ListColumns *one;
    ListColumns *two;
private slots:
     void testCorrectCompareStruct() {
         one = new ListColumns;
         two = new ListColumns;
         for (int i = 0; i < lengthString; i++) {
             one->elementsOfColumn[i] = rand() % 9;
             two->elementsOfColumn[i] = one->elementsOfColumn[i] + 1;
         }
         QVERIFY(*two > *one);
     }

     void testCorrectSwap(){
         one = new ListColumns;
         two = new ListColumns;
         int *first = new int[lengthString];
         int *second = new int[lengthString];
         for (int i = 0; i < lengthString; i++) {
              one->elementsOfColumn[i] = i+1;
              two->elementsOfColumn[i] = i-1;
              first[i] =  one->elementsOfColumn[i];
              second[i] =  two->elementsOfColumn[i];
         }
         this->change(one,two);
         for (int i = 0; i < lengthString; i++) {
             QCOMPARE(one->elementsOfColumn[i],second[i]);
             QCOMPARE(two->elementsOfColumn[i],first[i]);
         }
         delete[] first;
         delete[] second;
     }
};
