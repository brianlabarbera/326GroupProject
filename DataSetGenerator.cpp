#include "DataSetGenerator.h"

// Fills each dataset in this object with incremental data
void DataSetGenerator::FillIncrement() {
    if (dataSet->empty()) return;
    int n = 1;
    generate(dataSet->at(0).begin(), dataSet->at(0).end(), [&n]{return n++;});
    for (auto i = begin(*dataSet) + 1, e = end(*dataSet); i != e; i++) {
        *i = dataSet->at(0);
    }
}

// Fills each dataset in this object with decremental data
void DataSetGenerator::FillDecrement() {
    if (dataSet->empty()) return;
    int n = dataSet->at(0).size();;
    generate(dataSet->at(0).begin(), dataSet->at(0).end(), [&n]{return n--;});
    for (auto i = begin(*dataSet) + 1, e = end(*dataSet); i != e; i++) {
        *i = dataSet->at(0);
    }
}

// Fills each dataset in this object with random data in the range of [1...size]
void DataSetGenerator::FillRandom() {
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    auto e = default_random_engine(seed);
    for (auto& it : *dataSet) {
        unsigned int size = it.size();
        for (unsigned int i = 0; i < size; i++) {
            it.at(i) = (int)(e() % size) + 1;
        }
    }
}

// Fills each dataset in this object with a random permutation of ordered data
void DataSetGenerator::FillRandomPerm() {
    FillIncrement();
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    auto e = default_random_engine(seed);
    for (auto& it : *dataSet) {
        ShuffleDataSet(it, e);
    }
}

// Returns a clone of the dataset to maintain dataset order between sort tests
vector<vector<int>> DataSetGenerator::GetDataSet() const {
    return *dataSet;
}

// Helper function solely used for testing dataset generation
void DataSetGenerator::PrintDataSet() const {
    for (const auto& it1 : *dataSet) {
        for (const auto& it2 : it1)
            cout << it2 << " ";
        cout << endl << endl;
    }
}

// Swaps each element in the dataset forward to a random location in the dataset
// Generates an acceptably random permutation of the original dataset
void DataSetGenerator::ShuffleDataSet(vector<int>& v, default_random_engine& e) {
    unsigned int size = v.size();
    for (unsigned int i = 0; i < size - 1; i++) {
        unsigned int target = i + e() % (size - i);
        int tmp = v.at(i);
        v.at(i) = v.at(target);
        v.at(target) = tmp;
    }
}