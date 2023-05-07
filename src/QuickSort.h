#ifndef QUICKSORT
#define QUICKSORT

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class QuickSort : public SortingAlgoImpl<QuickSort> {
public:
    static void SortAlgo(vector<int>& arr, long long int& n);
    static string GetAlgoName() { return NAME; };
private:
    static const string NAME;
};

#endif
