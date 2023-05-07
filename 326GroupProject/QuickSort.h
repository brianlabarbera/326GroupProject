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
    void quickSort(vector<int>& a, int low, int high);
    void quickSortN(vector<int>& a, int low, int high, long long int& n);
    int partition(vector<int>& a, int low, int high);
    int partitionN(vector<int>& a, int low, int high, long long int& n);
    void swap(int& a, int& b);
    void swapN(int& a, int& b, long long int& n);
};

#endif

