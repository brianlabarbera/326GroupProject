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
    void mergeSort(vector<int>& arr, int left, int right);
    void mergeSortN(vector<int>& arr, int left, int right, long long int& n);
    void merge(vector<int>& arr, int left, int mid, int right);
    void mergeN(vector<int>& arr, int left, int mid, int right, long long int& n);
};

#endif
