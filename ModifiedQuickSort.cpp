#include "ModifiedQuickSort.h"

const string ModifiedQuickSort::NAME = "Modified Quick Sort";
const int ModifiedQuickSort::RUN = 7; // Should be 10 or less

void ModifiedQuickSort::SortAlgo(vector<int>& a, long long int &n) {
    if (n < 0) {
        ModQuickSort(a, 0, a.size() - 1);
    } else {
        ModQuickSortN(a, 0, a.size() - 1, n);
    }
}

// Mix of tail-recursive quick sort and insertion sort
void ModifiedQuickSort::ModQuickSort(vector<int>& a, int l, int r) {
    while (l < r) {
        // Use insertion sort for small sub-lists
        if (r - l < RUN) {
            InsertSort(a, l, r);
            break; // Break out of this tail-recursion
        } else {
            // Find and sort partition
            int pi = Partition(a, l, r);
            // Recursively solve smaller sub-lists using tail recursion
            // This should reduce chance for stack overflow
            if (pi - l < r - pi) {
                // Sort left sub-list
                ModQuickSort(a, l, pi);
                l = pi + 1;
            } else {
                // Sort right sub-list
                ModQuickSort(a, pi + 1, r);
                r = pi;
            }
        }
    }
}

// Mix of tail-recursive quick sort and insertion sort
void ModifiedQuickSort::ModQuickSortN(vector<int>& a, int l, int r, long long int& n) {
    while (l < r) {
        n++;
        // Use insertion sort for small sub-lists
        if (r - l < RUN) {
            n++;
            InsertSortN(a, l, r, n);
            break; // Break out of this tail-recursion
        } else {
            n++;
            // Find and sort partition
            int pi = PartitionN(a, l, r, n);
            n++;
            // Recursively solve smaller sub-lists using tail recursion
            // This should reduce chance for stack overflow
            if (pi - l < r - pi) {
                n++;
                // Sort left sub-list
                ModQuickSortN(a, l, pi, n);
                l = pi + 1;
                n++;
            } else {
                n++;
                // Sort right sub-list
                ModQuickSortN(a, pi + 1, r, n);
                r = pi;
                n++;
            }
        }
    }
    n++;
}

// Selects a pivot to sort around
int ModifiedQuickSort::Partition(vector<int>& a, int l, int r) {
    // Select middle pivot value
    int pivot = a.at(l + (r - l) / 2);
    // Index of smaller sub-list
    int i = l - 1;
    int j = r + 1;
    int tmp;
    while (true) {
        // Hoare's partition used to reduce swaps
        do {
            i++;
        } while (a.at(i) < pivot);
        do {
            j--;
        } while (a.at(j) > pivot);
        if (i >= j) return j;
        tmp = a.at(i);
        a.at(i) = a.at(j);
        a.at(j) = tmp;
    }
}

// Selects a pivot to sort around
int ModifiedQuickSort::PartitionN(vector<int>& a, int l, int r, long long int& n) {
    // Select middle pivot value
    int pivot = a.at(l + (r - l) / 2);
    n++;
    // Index of smaller sub-list
    int i = l - 1;
    n++;
    int j = r + 1;
    n++;
    int tmp;
    while (true) {
        n++; // Unsure?
        // Hoare's partition used to reduce swaps
        do {
            i++;
            n += 2;
        } while (a.at(i) < pivot);
        do {
            j--;
            n += 2;
        } while (a.at(j) > pivot);
        if (i >= j) {
            n++;
            return j;
        }
        n++;
        tmp = a.at(i);
        n++;
        a.at(i) = a.at(j);
        n++;
        a.at(j) = tmp;
        n++;
    }
}

// Traverses a from index l to r inserting
// each new element into a sorted sub-list
void ModifiedQuickSort::InsertSort(vector<int>& a, int l, int r) {
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
void ModifiedQuickSort::InsertSortN(vector<int>& a, int l, signed int r, long long int& n) {
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
