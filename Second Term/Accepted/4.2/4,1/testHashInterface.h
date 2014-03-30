#include <QtTest/QTest>
#include <QtCore/QObject>
#include "hashInterface.h"

using namespace std;

class TestHashInterface: public QObject , HashInterface
{
    Q_OBJECT
public:
    explicit TestHashInterface(QObject *parent = 0) : QObject(parent) {}
private:
    HashInterface *test;
private slots:
    void init() {
        test = new HashInterface;
    }
    void cleanup() {
        delete test;
    }

    void correctCalcHashFunctionFirst() {
        test->numberHF = 0;
        char testWord[] = "hello";
        int resultFisrt = 0;
        int lengthWord = strlen(testWord);
        for (int i = 0 ; i < lengthWord ; i++) {
            resultFisrt += int(testWord[i])*i;
            resultFisrt = resultFisrt % amountElements;
        }
        QVERIFY(test->calcHash(testWord) == resultFisrt );
    }

    void correctCalcHashFunctionSecond() {
        char testWord[] = "hello";
        int lengthWord = strlen(testWord);
        test->numberHF = 1;
        int resultSecond = 0;
        int simpleNumber = 3;
        for (int i = 0 ; i < lengthWord; i++) {
            resultSecond += int(testWord[i])*pow(simpleNumber, i);
            resultSecond = resultSecond % amountElements;
        }
        QVERIFY(test->calcHash(testWord) == resultSecond ); 
    }

    void correctSwitchCalcHashFunctions() {
           test->numberHF = 0;
           char testWord[] = "hello";
           int resultFisrt = 0;
           int lengthWord = strlen(testWord);
           for (int i = 0 ; i < lengthWord ; i++) {
               resultFisrt += int(testWord[i])*i;
               resultFisrt = resultFisrt % amountElements;
           }
           QVERIFY(test->calcHash(testWord) == resultFisrt );
           test->numberHF = 1;
           int resultSecond = 0;
           int simpleNumber = 3;
           for (int i = 0 ; i < lengthWord; i++) {
               resultSecond += int(testWord[i])*pow(simpleNumber, i);
               resultSecond = resultSecond % amountElements;
           }
           QVERIFY(test->calcHash(testWord) == resultSecond );
       }

    void correctAddingOneWord() {
        test->numberHF = 0;
        char testWord1[] = "q";
        test->addHT(testWord1);
        int result1 = 0;
        QCOMPARE(test->arrayWords[result1]->word, testWord1);
    }

    void correctAddingList() {
        test->numberHF = 0;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        int result1 = 0;
        QCOMPARE(test->arrayWords[result1]->word, testWord1);
        QCOMPARE(test->arrayWords[result1]->next->word, testWord2);
        QCOMPARE(test->arrayWords[result1]->next->next->word, testWord3);
    }

    void correctDeleteHashTableOne() {
        test->numberHF = 0;
        char testWord1[] = "q";
        int result1 = 0;
        test->addHT(testWord1);
        test->deleteHT(testWord1);
        QVERIFY(test->arrayWords[result1] == NULL);
    }

    void correctDeleteHashTableListBegin() {
        test->numberHF = 0;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        int result1 = 0;
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        test->deleteHT(testWord1);

        QCOMPARE(test->arrayWords[result1]->word, testWord2);
        QCOMPARE(test->arrayWords[result1]->next->word, testWord3);
    }

    void correctDeleteHashTableListMiddle() {
        test->numberHF = 0;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        int result1 = 0;
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        test->deleteHT(testWord2);

        QCOMPARE(test->arrayWords[result1]->word, testWord1);
        QCOMPARE(test->arrayWords[result1]->next->word, testWord3);
    }

    void correctDeleteHashTableListEnd() {
        test->numberHF = 0;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        int result1 = 0;
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        test->deleteHT(testWord3);

        QCOMPARE(test->arrayWords[result1]->word, testWord1);
        QCOMPARE(test->arrayWords[result1]->next->word, testWord2);
        QVERIFY(!test->arrayWords[result1]->next->next);
    }

    void testSearchHashTableOne() {
        char testWord1[] = "w";
        test->numberHF = 0;
        test->addHT(testWord1);
         QVERIFY(test->searchHT(testWord1) != -1);
    }

    void testSearchHashTableListMiddle() {
        char testWord1[] = "w";
        char testWord2[] = "a";
        char testWord3[] = "s";
        test->numberHF = 0;
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
         QVERIFY(test->searchHT(testWord2) != -1);
    }

    void testSearchHashTableListEnd() {
        char testWord1[] = "w";
        char testWord2[] = "a";
        char testWord3[] = "s";
        test->numberHF = 0;
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
         QVERIFY(test->searchHT(testWord3) != -1);
    }


};
