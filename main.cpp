#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "ImprovedBubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "TimSort.h"
#include "ModifiedQuickSort.h"
#include "HeapSort.h"
#include "SortingAlgoDriver.h"
#include "SortingAlgo.h"
#include <vector>
using namespace std;

// CCollection of algorithms to be tested
const vector<SortingAlgo*> algos = {
        new InsertionSort(),
        new SelectionSort(),
        new BubbleSort(),
        new ImprovedBubbleSort(),
        new MergeSort(),
        new TimSort(),
        new QuickSort(),
        new ModifiedQuickSort(),
        new HeapSort()
};

int main() {
    SortingAlgoDriver::CalcSortPerformance(algos);
    return 0;
}