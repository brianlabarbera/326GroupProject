#ifndef SelectionSort
#define SelectionSort

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class SelectionSort : public SortingAlgoImpl<SelectionSort> {
public:
    static void SortAlgo(vector<int>* arr, long int& n);
    static string GetAlgoName() { return NAME; };
private:
    static const string NAME;
};

#endif