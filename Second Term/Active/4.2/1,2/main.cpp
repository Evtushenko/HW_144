#include "testArrayStack.h"
#include "testPointStack.h"

using namespace std;

int main() {
    TestArrayStack test1;
    QTest::qExec(&test1);
    TestPointStack test2;
    QTest::qExec(&test2);
    /*
    StackGeneral* bubble = new PointStack();
    StackGeneral* bead = new ArrayStack();

    char input[maxBufferSize];
    for (int i = 0; i < maxBufferSize; i++)
        input[i] = '\0';
    cout << "enter the expressions:\n";
    cin.getline(input,maxBufferSize);
    cout << "Point Stack:\n";
    bubble->infix(input);
    cout << endl;
    cout << "Array Stack:\n";
    bead->infix(input);
    cout << endl;

    delete bubble;
    delete bead;
    */
    return 0;
}
