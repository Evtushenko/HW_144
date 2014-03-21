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
    void testSwitchCalcHashFunctions() {
        test = new HashInterface;

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

        delete test;
    }

    void testAddHashTable() {

        test = new HashInterface;
        test->numberHF = 0;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        char testWord4[] = "qw";
        int result1 = 0;
        int result2 = 119;

        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        test->addHT(testWord4);

        QCOMPARE(test->arrayWords[result1]->word, testWord1);
        QCOMPARE(test->arrayWords[result1]->next->word, testWord2);
        QCOMPARE(test->arrayWords[result1]->next->next->word, testWord3);
        QCOMPARE(test->arrayWords[result2]->word, testWord4);
        delete test;

    }
    void testDeleteHashTable() {
        test = new HashInterface;
        test->numberHF = 0;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        char testWord4[] = "qw";
        int result1 = 0;
        int result2 = 119;

        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        test->addHT(testWord4);

        test->deleteHT(testWord2);
        QCOMPARE(test->arrayWords[result1]->word, testWord1);
        QCOMPARE(test->arrayWords[result1]->next->word, testWord3);

        test->deleteHT(testWord1);
        test->deleteHT(testWord3);
        test->deleteHT(testWord4);

        QVERIFY(test->arrayWords[result1] == NULL);
        QVERIFY(test->arrayWords[result2] == NULL);
        delete test;

    }

    void testSearchHashTable() {

        test = new HashInterface;
        char testWord1[] = "what";
        char testWord2[] = "qwerty";
        test->numberHF = 0;
        test->addHT(testWord1);
        test->addHT(testWord2);
        QVERIFY(test->searchHT(testWord1) != -1);
        QVERIFY(test->searchHT(testWord2) != -1);
        delete test;
    }
};
