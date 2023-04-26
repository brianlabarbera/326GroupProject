#ifndef SORTINGALGOEXAMPLE
#define SORTINGALGOEXAMPLE

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class SortingAlgoExample : public SortingAlgoImpl<SortingAlgoExample> {
    public:
        static void SortAlgo(vector<int>* a, long int& n);
        static string GetAlgoName() { return NAME; };
    private:
        static const string NAME;
};

#endif
