#include "DataSetGenerator.h"

void DataSetGenerator::FillIncrement() {
    if (dataSet->empty()) return;
    int n = 1;
    generate(dataSet->at(0).begin(), dataSet->at(0).end(), [&n] {return n++; });
    for (auto i = begin(*dataSet) + 1, e = end(*dataSet); i != e; i++) {
        *i = dataSet->at(0);
    }
}

void DataSetGenerator::FillDecrement() {
    if (dataSet->empty()) return;
    int n = dataSet->at(0).size();;
    generate(dataSet->at(0).begin(), dataSet->at(0).end(), [&n] {return n--; });
    for (auto i = begin(*dataSet) + 1, e = end(*dataSet); i != e; i++) {
        *i = dataSet->at(0);
    }
}

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

void DataSetGenerator::FillRandomPerm() {
    FillIncrement();
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    auto e = default_random_engine(seed);
    for (auto& it : *dataSet) {
        ShuffleDataSet(it, e);
    }
}

vector<vector<int>> DataSetGenerator::GetDataSet() const {
    return *dataSet;
}

void DataSetGenerator::PrintDataSet() const {
    for (const auto& it1 : *dataSet) {
        for (const auto& it2 : it1)
            cout << it2 << " ";
        cout << endl << endl;
    }
}

void DataSetGenerator::ShuffleDataSet(vector<int>& v, default_random_engine& e) {
    unsigned int size = v.size();
    for (unsigned int i = 0; i < size - 1; i++) {
        unsigned int target = i + e() % (size - i);
        int tmp = v.at(i);
        v.at(i) = v.at(target);
        v.at(target) = tmp;
    }
}