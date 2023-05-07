#ifndef IMPROVEDBUBBLESORT
#define IMPROVEDBUBBLESORT

#include <string>
#include <vector>
#include "SortingAlgoImpl.h"

using namespace std;

class ImprovedBubbleSort : public SortingAlgoImpl<ImprovedBubbleSort> {
public:
    static void SortAlgo(vector<int>& a, long long int& n);
    static string GetAlgoName() { return NAME; };
private:
    static const string NAME;
};

#endif
