#include "TimSort.h"

const string TimSort::NAME = "Tim Sort";
const int TimSort::RUN = 32; // Must be in the range of 32 - 65

void TimSort::SortAlgo(vector<int>& a, long long int& n) {
    if (n < 0) {
        int i, j;
        // Insertion sort each of size/RUN sub-lists
        // This constructs the RUNs that will be merged
        for (i = 0; i < a.size(); i += RUN) {
            int r = (RUN + i > a.size()) ? a.size() - 1 : RUN + i - 1;
            InsertSort(a, i, r);
        }
        // Merge RUNs of exponentially larger size
        // Size of merged lists at each step is j
        for (j = RUN; j < a.size(); j = 2*j) {
            int ml, mm, mr;
            // Merge list from ml to ml + j -1
            // with list from ml + j to 2*j
            for (ml = 0; ml < a.size(); ml += 2*j) {
                // Get merge mid and merge right
                mm = ml + j - 1;
                mr = (ml + 2*j > a.size()) ? a.size() - 1: ml + 2*j - 1;
                // Merge lists
                if(mm < mr) Merge(a, ml, mm, mr);
            }
        }
    } else {
        int i, j;
        // Insertion sort each of size/RUN sub-lists
        // This constructs the RUNs that will be merged
        for (i = 0, n++; i < a.size(); i += RUN, n++) {
            n++;
            int r = (RUN + i > a.size()) ? a.size() - 1 : RUN + i - 1;
            n += 2;
            InsertSortN(a, i, r, n);
        }
        n++;
        // Merge RUNs of exponentially larger size
        // Size of merged lists at each step is j
        for (j = RUN, n++; j < a.size(); j = 2*j, n++) {
            n++;
            int ml, mm, mr;
            // Merge list from ml to ml + j -1
            // with list from ml + j to 2*j
            for (ml = 0, n++; ml < a.size(); ml += 2*j, n++) {
                n++;
                // Get merge mid and merge right
                mm = ml + j - 1;
                n++;
                mr = (ml + 2*j > a.size()) ? a.size() - 1: ml + 2*j - 1;
                n += 2; // Accurate?
                // Merge lists
                if(mm < mr) {
                    MergeN(a, ml, mm, mr, n);
                }
                n++;
            }
            n++;
        }
        n++;
    }
}

// Merges two sorted lists split around m
void TimSort::Merge(vector<int> &a, int l, int m, int r) {
    // Construct temp primitive arrays
    // to store values during merge
    int len1 = m - l + 1, len2 = r - m;
    int tmpl[len1], tmpr[len2];
    int i, j, k;
    // Copy values into temp arrays
    for (i = 0; i < len1; i++) tmpl[i] = a.at(l + i);
    for (i = 0; i < len2; i++) tmpr[i] = a.at(m + i + 1);
    // Compare temp array indices and copy to
    // the correct position in sorted list
    i = j = 0;
    k = l;
    while (i < len1 && j < len2) {
        if (tmpl[i] <= tmpr[j]) {
            a.at(k) = tmpl[i];
            i++;
        } else {
            a.at(k) = tmpr[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of ltmp to the
    // correct position in the sorted list
    while (i < len1) {
        a.at(k) = tmpl[i];
        k++;
        i++;
    }
    // Copy remaining elements of rtmp to the
    // correct position in the sorted list
    while (j < len2) {
        a.at(k) = tmpr[j];
        k++;
        j++;
    }
}

// Merges two sorted lists split around m
void TimSort::MergeN(vector<int> &a, int l, int m, int r, long long int& n) {
    // Construct temp primitive arrays
    // to store values during merge
    int len1 = m - l + 1, len2 = r - m;
    n += 2;
    int tmpl[len1], tmpr[len2];
    int i, j, k;
    // Copy values into temp arrays
    for (i = 0, n++; i < len1; i++, n++) {
        tmpl[i] = a.at(l + i);
        n++;
    }
    n++;
    for (i = 0, n++; i < len2; i++, n++) {
        tmpr[i] = a.at(m + i + 1);\
        n++;
    }
    n++;
    // Compare temp array indices and copy to
    // the correct position in sorted list
    i = j = 0;
    n += 2;
    k = l;
    n++;
    while (i < len1 && j < len2) {
        n += 2;
        if (tmpl[i] <= tmpr[j]) {
            a.at(k) = tmpl[i];
            n++;
            i++;
            n++;
        } else {
            a.at(k) = tmpr[j];
            n++;
            j++;
            n++;
        }
        n++;
        k++;
        n++;
    }
    n += 2;
    // Copy remaining elements of ltmp to the
    // correct position in the sorted list
    while (i < len1) {
        n++;
        a.at(k) = tmpl[i];
        n++;
        k++;
        n++;
        i++;
        n++;
    }
    n++;
    // Copy remaining elements of rtmp to the
    // correct position in the sorted list
    while (j < len2) {
        n++;
        a.at(k) = tmpr[j];
        n++;
        k++;
        n++;
        j++;
        n++;
    }
    n++;
}

// Traverses a from index l to r inserting
// each new element into a sorted sub-list
void TimSort::InsertSort(vector<int> &a, int l, int r) {
    int i, j;
    // Forwards loop
    for(i = l + 1; i <= r; i++) {
        int t = a.at(i); // Element being inserted
        j = i - 1;
        // Backwards loop
        while (j >= l && a.at(j) > t) {
            a.at(j + 1) = a.at(j); // Bubble up elements greater than t
            j--;
        }
        a.at(j + 1) = t; // Insert t into sorted list
    }
}

// Traverses a from index l to r inserting
// each new element into a sorted sub-list
void TimSort::InsertSortN(vector<int> &a, int l, signed int r, long long int &n) {
    int i, j;
    // Forwards loop
    for(i = l + 1, n++; i <= r; i++, n++){
        n++;
        int t = a.at(i); // Element being inserted
        n++;
        j = i - 1;
        n++;
        // Backwards loop
        while (j >= l && a.at(j) > t) {
            n += 2;
            a.at(j + 1) = a.at(j); // Bubble up elements greater than t
            n++;
            j--;
            n++;
        }
        n += 2;
        a.at(j + 1) = t; // Insert t into sorted list
        n++;
    }
    n++;
}