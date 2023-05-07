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
    explicit DataSetGenerator(unsigned int n = 0, unsigned int num = 1) : dataSet(new vector<vector<int>>(num)) {
        for (auto& it : *dataSet) it = vector<int>(n);
    };
    ~DataSetGenerator() {
        delete dataSet;
    };
    void FillIncrement();
    void FillDecrement();
    void FillRandom();
    void FillRandomPerm();
    [[nodiscard]] vector<vector<int>> GetDataSet() const;
    void PrintDataSet() const;
    static void ShuffleDataSet(vector<int>& v, default_random_engine& e);
private:
    vector<vector<int>>* dataSet;
};

#endif
