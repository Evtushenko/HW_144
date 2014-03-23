#include <QtTest/QTest>
#include <QtCore/QObject>
#include "file.h"

using namespace std;

class TestFile: public QObject
{
    Q_OBJECT
public:
    explicit TestFile(QObject *parent = 0) : QObject(parent) {}
private:
    File *test;
private slots:
    void testCorrectReading() {
        test = new File;
        test->readFromFile();
        int numbersFromFile[ ] = {1, 2, 3,
                                 4, 5, 6,
                                 7, 8, 9};
        int *arrayMatrix = test->returnMatrix();
        for (int i = 0; i < amountElements * amountElements; i++)
            QCOMPARE(arrayMatrix[i], numbersFromFile[i]);
        delete[] arrayMatrix;
        delete test;
    }

    void testCorrectSpiralOrder(){
        test = new File;
        test->readFromFile();
        test->spiralOrder();
        int numbersSpiralOrder[ ] = {5, 4, 1, 2, 3, 6, 9, 8, 7};
        int *arraySpiralOrder = test->returnSpiralOrder();
        for (int i = 0; i < amountElements * amountElements; i++)
            QCOMPARE(arraySpiralOrder[i], numbersSpiralOrder[i]);
        delete[] arraySpiralOrder;
    }

    void testCorrectWriteFile() {
        test = new File;
        test->readFromFile();
        test->spiralOrder();

        int *arraySpiralOrder = test->returnSpiralOrder();
        ofstream outFile;
        outFile.open("out.txt", ios::out);
        for (int i = 0; i < amountElements*amountElements; i++) {
                outFile << arraySpiralOrder[i] << " ";
            }
        outFile.close();

        ifstream inFile;
        inFile.open("out.txt", ios::in);
        int *inputArray = new int[amountElements * amountElements];
        for (int i = 0; i < amountElements * amountElements; i++) {
                inFile >> inputArray[i];
            }
        inFile.close();
        for (int i = 0; i < amountElements * amountElements; i++)
            QCOMPARE(inputArray[i], arraySpiralOrder[i]);
        delete[] arraySpiralOrder;
        delete[] inputArray;
        delete test;
    }
};
