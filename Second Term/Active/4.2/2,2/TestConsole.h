#include <QtTest/QTest>
#include <QtCore/QObject>
#include "Console.h"

using namespace std;

class TestConsole: public QObject
{
    Q_OBJECT
public:
    explicit TestConsole(QObject *parent = 0) : QObject(parent) {}
private:
    Console *test;
private slots:
    void testCorrectReading() {
        test = new Console;
        test->readFromFile();
        int numbersFromFile[ ] = {1, 2, 3,
                                 4, 5, 6,
                                 7, 8, 9};
        int *arrayMatrix = test->returnMatrix();
        for (int i = 0; i < amountElements * amountElements; i++)
            QCOMPARE(arrayMatrix[i], numbersFromFile[i]);
        delete[] arrayMatrix;
    }

    void testCorrectSpiralOrder(){
        test = new Console;
        test->readFromFile();
        test->spiralOrder();
        int numbersSpiralOrder[ ] = {5, 4, 1, 2, 3, 6, 9, 8, 7};
        int *arraySpiralOrder = test->returnSpiralOrder();
        for (int i = 0; i < amountElements * amountElements; i++)
            QCOMPARE(arraySpiralOrder[i], numbersSpiralOrder[i]);
        delete[] arraySpiralOrder;
    }
};
