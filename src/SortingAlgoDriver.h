#ifndef SORTINGALGODRIVER
#define SORTINGALGODRIVER

#include <chrono>
#include "DataSetGenerator.h"
#include "SortingAlgoImpl.h"

const int SET_SIZES[] = {100,300, 500, 1000, 3000, 5000, 10000, 50000};
//const int NUM_SIZES = 8;
const int NUM_SETS = 50;

template<class T>
class SortingAlgoDriver {
    public:
        static float CalcSortCPU(DataSetGenerator* data, SortingAlgoImpl<T>* algo) {
            long int n = -1;
            chrono::microseconds runtime{0};
            float iterations = 0.0f;
            for (auto& it : *(data->GetDataSet())) {
                auto start = chrono::high_resolution_clock::now();
                algo->Sort(it, n);
                auto stop = chrono::high_resolution_clock::now();
                runtime += duration_cast<chrono::microseconds>(stop - start);
                iterations++;
            }
            if(iterations <= 0.0f) return -1.0f;
            return runtime.count()/iterations;
        };
        static float CalcSortSteps(DataSetGenerator* data, SortingAlgoImpl<T>* algo) {
            long int n = 0;
            float iterations = 0.0f;
            for (auto& it : *(data->GetDataSet())) {
                algo->Sort(it, n);
                iterations++;
            }
            if(iterations <= 0.0f) return -1.0f;
            return n/iterations;
        };
        static void CalcSortPerformance(SortingAlgoImpl<T>* algo) {
            float time;
            cout << "[Calculating " << algo->GetName() << " Performance]" << endl;
            for (int i : SET_SIZES) {
                auto* ds = new DataSetGenerator(i);

                cout << "CPU Times:" << endl;
                ds->FillIncrement();
                time = SortingAlgoDriver<ImprovedBubbleSort>::CalcSortCPU(ds, algo);
                cout << "Incremental n = " << i << ": " << time << " microseconds" << endl;
                ds->FillDecrement();
                time = SortingAlgoDriver<ImprovedBubbleSort>::CalcSortCPU(ds, algo);
                cout << "Decremental n = " << i << ": " << time << " microseconds" << endl;
                ds->FillRandom();
                time = SortingAlgoDriver<ImprovedBubbleSort>::CalcSortCPU(ds, algo);
                cout << "Random n = " << i << ": " << time << " microseconds" << endl;

                cout << "Num Steps:" << endl;
                ds->FillIncrement();
                time = SortingAlgoDriver<ImprovedBubbleSort>::CalcSortSteps(ds, algo);
                cout << "Incremental n = " << i << ": " << time << " steps" << endl;
                ds->FillDecrement();
                time = SortingAlgoDriver<ImprovedBubbleSort>::CalcSortSteps(ds, algo);
                cout << "Decremental n = " << i << ": " << time << " steps" << endl;
                ds->FillRandom();
                time = SortingAlgoDriver<ImprovedBubbleSort>::CalcSortSteps(ds, algo);
                cout << "Random n = " << i << ": " << time << " steps" << endl;

                delete ds;
            }
        };
};

#endif
