#ifndef SORTINGALGOIMPL
#define SORTINGALGOIMPL

#include <string>
#include <vector>
#include "SortingAlgo.h"

using namespace std;

// Virtual C++ interface implementation
// Enforces static method implementation in child classes
template<class T>
class SortingAlgoImpl : public SortingAlgo {
    public:
        void Sort(vector<int>& a, long long int& n) override { return T::SortAlgo(a, n); };
        string GetName() override { return T::GetAlgoName(); };
};

#endif
