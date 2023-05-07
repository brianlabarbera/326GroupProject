#ifndef SORTINGALGO
#define SORTINGALGO

#include <string>
#include <vector>

using namespace std;

// Virtual C++ interface equivalent
// Enforces method implementation in child classes
class SortingAlgo {
    public:
        virtual void Sort(vector<int>& a, long long int& n) = 0;
        virtual string GetName() = 0;
};

#endif
