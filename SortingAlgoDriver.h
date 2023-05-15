#ifndef SORTINGALGODRIVER
#define SORTINGALGODRIVER

#include <chrono>
#include <vector>
#include "DataSetGenerator.h"
#include "SortingAlgoImpl.h"

const int SET_SIZES[] = {100, 300, 500, 1000, 3000, 5000, 10000, 50000};
const int NUM_SETS = 50;

// Consumes a collection of algorithms and a collection of datasets
// Generates CPU times and step count for each algorithm for each set size
class SortingAlgoDriver {
    public:
        static vector<double> CalcSortCPU(DataSetGenerator* data, const vector<SortingAlgo*>& algos);
        static vector<double> CalcSortSteps(DataSetGenerator* data, const vector<SortingAlgo*>& algos);
        static void CalcSortPerformance(const vector<SortingAlgo*>& algos);
    private:
        static void PrintAlgoTimes(vector<double>& times, vector<double>& steps, const vector<SortingAlgo*>& algos);
};

#endif
