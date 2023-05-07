#include "ImprovedBubbleSort.h"

const string ImprovedBubbleSort::NAME = "Improved Bubble Sort";

void ImprovedBubbleSort::SortAlgo(vector<int>& a, long long int& n) {
    if (n < 0) {
        unsigned int i, j, k;
        int tmp;
        bool flag;
        for (i = 0; i < a.size() - 1; i++) {
            flag = true;
            for (j = k = i; j < a.size() - i - 1; j++) {
                if (a.at(j) > a.at(j + 1)) {
                    tmp = a.at(j);
                    a.at(j) = a.at(j + 1);
                    a.at(j + 1) = tmp;
                    flag = false;
                }
                if (a.at(j) < a.at(k))
                    k = j;
            }
            if (flag) break;
            tmp = a.at(k);
            a.at(k) = a.at(i);
            a.at(i) = tmp;
        }
    }
    else {
        unsigned int i, j, k;
        int tmp;
        bool flag;
        for (i = 0, n++; i < a.size() - 1; i++, n++) {
            n++;
            flag = true;
            n++;
            for (j = k = i, n++; j < a.size() - i - 1; j++, n++) {
                n++;
                if (a.at(j) > a.at(j + 1)) {
                    tmp = a.at(j);
                    n++;
                    a.at(j) = a.at(j + 1);
                    n++;
                    a.at(j + 1) = tmp;
                    n++;
                    flag = false;
                    n++;
                }
                n++;
                if (a.at(j) < a.at(k)) {
                    k = j;
                    n++;
                }
                n++;
            }
            n++;
            if (flag) {
                n++;
                break;
            }
            n++;
            tmp = a.at(k);
            n++;
            a.at(k) = a.at(i);
            n++;
            a.at(i) = tmp;
            n++;
        }
        n++;
    }
}