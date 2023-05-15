#include "SortingAlgoDriver.h"

// Generates a CPU time for each algorithm in algos for each dataset in data
vector<double> SortingAlgoDriver::CalcSortCPU(DataSetGenerator* data, const vector<SortingAlgo*>& algos) {
    long long int n = -1;
    vector<double> ret;
    // Iterate over algorithms
    for (auto& it1 : algos) {
        chrono::microseconds runtime{0};
        double iterations = 0.0;
        // Iterate over datasets
        for (auto& it2 : data->GetDataSet()) {
            auto start = chrono::high_resolution_clock::now();
            it1->Sort(it2, n);
            auto stop = chrono::high_resolution_clock::now();
            runtime += duration_cast<chrono::microseconds>(stop - start);
            iterations++;
        }
        (iterations <= 0.0) ? ret.push_back(-1.0) : ret.push_back(runtime.count()/iterations);
    }
    return ret;
}

// Generates a step count for each algorithm in algos for each dataset in data
vector<double> SortingAlgoDriver::CalcSortSteps(DataSetGenerator* data, const vector<SortingAlgo*>& algos) {
    vector<double> ret;
    // Iterate over algorithms
    for (auto& it1 : algos) {
        long long int n = 0;
        double iterations = 0.0;
        // Iterate over datasets
        for (auto& it2 : data->GetDataSet()) {
            it1->Sort(it2, n);
            iterations++;
        }
        (iterations <= 0.0) ? ret.push_back(-1.0) : ret.push_back(n/iterations);
    }
    return ret;
}

//  Generate performance analysis output
void SortingAlgoDriver::CalcSortPerformance(const vector<SortingAlgo*>& algos) {
    vector<double> cpu, steps;
    for (int i : SET_SIZES) {
        cout << "[Calculating Performance for n = " << i << "]" << endl;
        auto* ds = new DataSetGenerator(i);
        ds->FillIncrement();
        cout << "{Incremental Sorted}" << endl;
        cpu = CalcSortCPU(ds, algos);
        steps = CalcSortSteps(ds, algos);
        PrintAlgoTimes(cpu, steps, algos);
        ds->FillDecrement();
        cout << "{Decremental Sorted}" << endl;
        cpu = CalcSortCPU(ds, algos);
        steps = CalcSortSteps(ds, algos);
        PrintAlgoTimes(cpu, steps, algos);
        ds->FillRandomPerm();
        cout << "{Random Permutation}" << endl;
        cpu = CalcSortCPU(ds, algos);
        steps = CalcSortSteps(ds, algos);
        PrintAlgoTimes(cpu, steps, algos);
        delete ds;
        auto* dsr = new DataSetGenerator(i, NUM_SETS);
        dsr->FillRandom();
        cout << "{Random Values}" << endl;
        cpu = CalcSortCPU(dsr, algos);
        steps = CalcSortSteps(dsr, algos);
        PrintAlgoTimes(cpu, steps, algos);
        delete dsr;
    }
}

// Helper function to attach output times and steps to their respective algorithms
void SortingAlgoDriver::PrintAlgoTimes(vector<double>& times, vector<double>& steps, const vector<SortingAlgo*>& algos) {
    auto i1 = begin(times);
    auto i2 = begin(steps);
    auto i3 = begin(algos);
    for(; i1 != end(times) && i2 != end(steps) && i3 != end(algos); i1++, i2++, i3++)  {
        cout << "For " << (*i3)->GetName() << ": " << *i1 << " microseconds, " << *i2 << " steps"<< endl;
    }
}