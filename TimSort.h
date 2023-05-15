#ifndef TIMSORT_H
#define TIMSORT_H

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class TimSort : public SortingAlgoImpl<TimSort> {
    public:
        static void SortAlgo(vector<int>& a, long long int& n);
        static string GetAlgoName() { return NAME; };
    private:
        static const string NAME;
        static const int RUN;
        static void Merge(vector<int>& a, int l, int m, int r);
        static void MergeN(vector<int>& a, int l, int m, int r, long long int& n);
        static void InsertSort(vector<int>& a, int l, int r);
        static void InsertSortN(vector<int>& a, int l, int r, long long int& n);
};

#endif
