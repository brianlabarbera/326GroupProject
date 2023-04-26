#include <iostream>
#include "DataSetGenerator.h"
#include "ImprovedBubbleSort.h"
#include "SortingAlgoDriver.h"
#include "SortingAlgoImpl.h"
using namespace std;

int main() {
    /*
    cout << "Testing:" << endl;
    auto* ds1 = new DataSetGenerator(10);
    ds1->FillIncrement();
    ds1->PrintDataSet();
    delete ds1;
    auto* ds2 = new DataSetGenerator(10);
    ds2->FillDecrement();
    ds2->PrintDataSet();
    delete ds2;
    auto* ds3 = new DataSetGenerator(10);
    ds3->FillRandom();
    ds3->PrintDataSet();
    delete ds3;
    auto* ds4 = new DataSetGenerator(20,5);
    ds4->FillRandom();
    ds4->PrintDataSet();
    SortingAlgoImpl<ImprovedBubbleSort>* sort = new ImprovedBubbleSort();
    float time = SortingAlgoDriver<ImprovedBubbleSort>::CalcSortCPU(ds4, sort);
    cout << time << " microseconds" << endl;
    ds4->PrintDataSet();
    delete ds4;
    */
    SortingAlgoImpl<ImprovedBubbleSort>* sort = new ImprovedBubbleSort();
    SortingAlgoDriver<ImprovedBubbleSort>::CalcSortPerformance(sort);
    return 0;
}