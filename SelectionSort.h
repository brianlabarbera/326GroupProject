#ifndef SELECTIONSORT
#define SELECTIONSORT

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class SelectionSort : public SortingAlgoImpl<SelectionSort> {
    public:
        static void SortAlgo(vector<int>& arr, long long int& n);
        static string GetAlgoName() { return NAME; };
    private:
        static const string NAME;
        static void swap(int& a, int& b);
        static void swapN(int& a, int& b, long long int& n);
};

#endif