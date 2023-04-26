#include "DataSetGenerator.h"

void DataSetGenerator::FillIncrement() {
    for (auto& it : *dataSet) {
        int n = 1;
        generate(it->begin(), it->end(), [&n]{return n++;});
    }
}

void DataSetGenerator::FillDecrement() {
    for (auto& it : *dataSet) {
        int n = it->size();
        generate(it->begin(), it->end(), [&n]{return n--;});
    }
}

void DataSetGenerator::FillRandom() {
    unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
    auto e = default_random_engine(seed);
    for (auto& it : *dataSet) {
        int n = 1;
        generate(it->begin(), it->end(), [&n]{return n++;});
        ShuffleDataSet(it, e);
    }
}

vector<vector<int>*>* DataSetGenerator::GetDataSet() {
    return dataSet;
}

void DataSetGenerator::PrintDataSet() const {
    for (const auto& it1 : *dataSet) {
        for (const auto& it2 : *it1)
            cout << it2 << " ";
        cout << endl;
    }
}

void DataSetGenerator::ShuffleDataSet(vector<int>* v, default_random_engine& e) {
    unsigned int size = v->size();
    for (unsigned int i = 0; i < size - 1; i++) {
        unsigned int target = i + e() % (size - i);
        int tmp = v->at(i);
        v->at(i) = v->at(target);
        v->at(target) = tmp;
    }
}
