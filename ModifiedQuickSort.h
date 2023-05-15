#ifndef MODIFIEDQUICKSORT_H
#define MODIFIEDQUICKSORT_H

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class ModifiedQuickSort : public SortingAlgoImpl<ModifiedQuickSort> {
    public:
        static void SortAlgo(vector<int>& a, long long int& n);
        static string GetAlgoName() { return NAME; };
    private:
        static const string NAME;
        static const int RUN;
        static void ModQuickSort(vector<int>& a, int l, int r);
        static void ModQuickSortN(vector<int>& a, int l, int r, long long int& n);
        static int Partition(vector<int>& a, int l, int r);
        static int PartitionN(vector<int>& a, int l, int r, long long int& n);
        static void InsertSort(vector<int>& a, int l, int r);
        static void InsertSortN(vector<int>& a, int l, int r, long long int& n);
};

#endif
