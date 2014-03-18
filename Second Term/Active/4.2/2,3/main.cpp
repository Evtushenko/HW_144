#include "Sorter.h"
#include "BubbleSort.h"
#include "PlugSort.h"
#include "TestBubbleSort.h"
#include "TestPlugSort.h"

using namespace std;

int main() {
    TestBubbleSort testBubbleSort;
    QTest::qExec(&testBubbleSort);
    TestPlugSort testPlugSort;
    QTest::qExec(&testPlugSort);
    /*
    Sorter* bubble = new BubbleSort();
    bubble->sorting();
    delete bubble;

    Sorter* bead = new PlugSort();
    bead->sorting();
    delete bead;
    */
    return 0;
}
