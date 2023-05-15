#include "HeapSort.h"

const string HeapSort::NAME = "Heap Sort";

void HeapSort::SortAlgo(vector<int>& a, long long int& n) {
    if (n < 0) {
        HSort(a);
    } else {
        HSortN(a, n);
    }
}

// Builds a max-heap then calls heapify until sorted
void HeapSort::HSort(vector<int>& a) {
    int i;
    // Build heap by calling heapify on non-leaf nodes
    for (i = (a.size() / 2) - 1; i >= 0; i--) {
        Heapify(a, a.size(), i);
    }
    for (i = (a.size() - 1); i > 0; i--) {
        // Swap max into sorted sub-list
        int tmp = a.at(0);
        a.at(0) = a.at(i);
        a.at(i) = tmp;
        // Heapify root to restore max-heap property
        Heapify(a, i, 0);
    }
}

void HeapSort::HSortN(vector<int>& a, long long int& n) {
    int i;
    // Build heap by calling heapify on non-leaf nodes
    for (i = (a.size() / 2) - 1, n++; i >= 0; i--, n++) {
        n++;
        Heapify(a, a.size(), i);
    }
    n++;
    for (i = (a.size() - 1), n++; i > 0; i--, n++) {
        n++;
        // Swap max into sorted sub-list
        int tmp = a.at(0);
        n++;
        a.at(0) = a.at(i);
        n++;
        a.at(i) = tmp;
        n++;
        // Heapify root to restore max-heap property
        HeapifyN(a, i, 0, n);
    }
    n++;
}

void HeapSort::Heapify(vector<int>& a, int i, int r) {
    // Root set to max
    int max = r;
    // Find left and right children
    int lc = 2 * r + 1;
    int rc = 2 * r + 2;
    // Compare left child with max
    // If not outside sub-list
    if (lc < i && a.at(lc) > a.at(max)) {
        max = lc;
    }
    // Compare right child with max
    // If not outside sub-list
    if (rc < i && a.at(rc) > a.at(max)) {
        max = rc;
    }
    // Call heapify if root isn't max
    if (max != r) {
        // Swap root with max child
        int tmp = a.at(r);
        a.at(r) = a.at(max);
        a.at(max) = tmp;
        // Recursively heapify
        Heapify(a, i, max);
    }
}

void HeapSort::HeapifyN(vector<int>& a, int i, int r, long long int& n) {
    // Root set to max
    int max = r;
    n++;
    // Find left and right children
    int lc = 2 * r + 1;
    n++;
    int rc = 2 * r + 2;
    n++;
    // Compare left child with max
    // If not outside sub-list
    if (lc < i && a.at(lc) > a.at(max)) {
        max = lc;
        n++;
    }
    n += 2;
    // Compare right child with max
    // If not outside sub-list
    if (rc < i && a.at(rc) > a.at(max)) {
        max = rc;
        n++;
    }
    n += 2;
    // Call heapify if root isn't max
    if (max != r) {
        // Swap root with max child
        int tmp = a.at(r);
        n++;
        a.at(r) = a.at(max);
        n++;
        a.at(max) = tmp;
        n++;
        // Recursively heapify
        HeapifyN(a, i, max, n);
    }
    n++;
}