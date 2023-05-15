#ifndef HEAPSORT
#define HEAPSORT

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class HeapSort : public SortingAlgoImpl<HeapSort> {
    public:
        static void SortAlgo(vector<int>& a, long long int& n);
        static string GetAlgoName() { return NAME; };
    private:
        static const string NAME;
        static void HSort(vector<int>& a);
        static void HSortN(vector<int>& a, long long int& n);
        static void Heapify(vector<int>& a, int i, int r);
        static void HeapifyN(vector<int>& a, int i, int r, long long int& n);
};

#endif
