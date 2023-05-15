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
    static void quickSort(vector<int>& a, int low, int high);
    static void quickSortN(vector<int>& a, int low, int high, long long int& n);
    static int partition(vector<int>& a, int low, int high);
    static int partitionN(vector<int>& a, int low, int high, long long int& n);
    static void swap(int& a, int& b);
    static void swapN(int& a, int& b, long long int& n);
};

#endif

