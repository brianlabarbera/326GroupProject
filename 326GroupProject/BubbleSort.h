#ifndef BUBBLESORT
#define BUBBLESORT

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class BubbleSort : public SortingAlgoImpl<BubbleSort> {
public:
    static void SortAlgo(vector<int>* arr, long int& n);
    static string GetAlgoName() { return NAME; };
private:
    static const string NAME;
    void BubbleSort::swap(int& a, int& b);
    void BubbleSort::swapN(int& a, int& b)
};

#endif
