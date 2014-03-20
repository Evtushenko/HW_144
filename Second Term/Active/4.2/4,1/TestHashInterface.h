#include <QtTest/QTest>
#include <QtCore/QObject>
#include "HashInterface.h"

using namespace std;

class TestHashInterface: public QObject
{
    Q_OBJECT
public:
    explicit TestHashInterface(QObject *parent = 0) : QObject(parent) {}
private:
    HashInterface *test;
private slots:
    void testCalcHashFirst() {
        test = new HashInterface;
        test->numberHF = 0;
        char testWord[] = "hello";
        int resultFisrt = strlen(testWord);
        QVERIFY(test->calcHash(testWord) == resultFisrt );
    }
    void testCalcHashSecond() {
        test = new HashInterface;
        test->numberHF = 1;
        char testWord[] = "hello";
        int resultSecond = strlen(testWord)*2;
        QVERIFY(test->calcHash(testWord) == resultSecond );
    }
    void testAddHashTable() {
        test = new HashInterface;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        char testWord4[] = "qw";
        char testWord5[] = "ola";
        test->numberHF = 1;
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        test->numberHF = 0;
        test->addHT(testWord4);
        test->numberHF = 1;
        test->addHT(testWord5);
        QCOMPARE(test->arrayWords[2]->word, testWord1);
        QCOMPARE(test->arrayWords[2]->next->word, testWord2);
        QCOMPARE(test->arrayWords[2]->next->next->word, testWord3);
        QCOMPARE(test->arrayWords[2]->next->next->next->word, testWord4);
        QCOMPARE(test->arrayWords[6]->word, testWord5);
    }
    void testDeleteHashTable() {
        test = new HashInterface;
        char testWord1[] = "q";
        char testWord2[] = "w";
        char testWord3[] = "e";
        char testWord4[] = "qw";
        char testWord5[] = "ola";
        test->numberHF = 1;
        test->addHT(testWord1);
        test->addHT(testWord2);
        test->addHT(testWord3);
        test->numberHF = 0;
        test->addHT(testWord4);
        test->numberHF = 1;
        test->addHT(testWord5);

        test->deleteHT(testWord1);
        test->deleteHT(testWord2);
        test->deleteHT(testWord3);
        test->deleteHT(testWord4);
        test->deleteHT(testWord5);

        QVERIFY(test->arrayWords[2] == NULL);
        QVERIFY(test->arrayWords[6] == NULL);
    }

    void testSearchHashTable() {
        test = new HashInterface;
        char testWord1[] = "qwe";
        char testWord2[] = "rtyu";
        test->numberHF = 1;
        test->addHT(testWord1);
        test->addHT(testWord2);
        QVERIFY(test->searchHT(testWord1) != -1);
        QVERIFY(test->searchHT(testWord2) != -1);
    }
};
