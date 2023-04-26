#ifndef DATASETGENERATOR
#define DATASETGENERATOR

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// Static class for generating integer data sets
class DataSetGenerator {
    public:
        explicit DataSetGenerator(unsigned int n = 0, unsigned int num = 1) : dataSet(new vector<vector<int>*>(num)) {
            for(auto& it : *dataSet) {
                it = new vector<int>(n);
            }
        };
        ~DataSetGenerator() {
            for (auto& it : *dataSet)
                delete it;
            delete dataSet;
        };
        void FillIncrement();
        void FillDecrement();
        void FillRandom();
        [[nodiscard]]vector<vector<int>*>* GetDataSet();
        void PrintDataSet() const;
        static void ShuffleDataSet(vector<int>* v, default_random_engine& e);
    private:
        vector<vector<int>*>* dataSet;
};

#endif