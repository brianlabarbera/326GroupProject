#ifndef InsertionSort
#define InsertionSort

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class InsertionSort : public SortingAlgoImpl<InsertionSort> {
public:
    static void SortAlgo(vector<int>* arr, long int& n);
    static string GetAlgoName() { return NAME; };
private:
    static const string NAME;
};

#endif