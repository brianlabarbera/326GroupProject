#include <iostream>
#include "MergeSort.h"
#include "QuickSort.h"
#include "ImprovedBubbleSort.h"
#include "SortingAlgoDriver.h"
#include "SortingAlgo.h"
#include <vector>
using namespace std;

const vector<SortingAlgo*> algos = {
        new MergeSort() // Replace with your sorting algorithm to test its performance
};

int main() {
    SortingAlgoDriver::CalcSortPerformance(algos);
    return 0;
}