#ifndef MERGESORT
#define MERGESORT

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class MergeSort : public SortingAlgoImpl<MergeSort> {
public:
    static void SortAlgo(vector<int>& arr, long long int& n);
    static string GetAlgoName() { return NAME; };
private:
    static const string NAME;
};

#endif
