#include "QuickSort.h"

const string QuickSort::NAME = "Quick Sort";

// QuickSort Algo; // NOT NEEDED //

void QuickSort::SortAlgo(vector<int>& arr, long long int& n) {

    if (n < 0) {

        QuickSort::quickSort(arr, 0, arr.size() - 1);

    }
    else {

        QuickSort::quickSortN(arr, 0, arr.size() - 1, n);

    }

    // n++; // NOT NEEDED //
}

void QuickSort::quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);  // Partition the array

        // Recursive calls to sort the sub-arrays
        quickSort(a, low, pi - 1);   // Elements before partition
        quickSort(a, pi + 1, high);  // Elements after partition
    }
}

void QuickSort::quickSortN(vector<int>& a, int low, int high, long long int& n) {
    if (low < high) {
        int pi = partitionN(a, low, high, n);  // Partition the array
        n++;

        // Recursive calls to sort the sub-arrays
        quickSortN(a, low, pi - 1, n);
        // Elements before partition
        quickSortN(a, pi + 1, high, n);
        // Elements after partition
    }
    n++;
}


int QuickSort::partition(vector<int>& a, int low, int high) {
    int pivot = a.at(high);  // Choose the rightmost element as pivot
    int i = low - 1;      // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (a.at(j) <= pivot) {
            i++;  // Increment index of smaller element
            swap(a.at(i), a.at(j));  // Swap current element with the element at the smaller index
        }
    }

    swap(a.at(i + 1), a.at(high));  // Swap pivot with the element at the smaller index + 1
    return i + 1;             // Return the partitioning index
}

int QuickSort::partitionN(vector<int>& a, int low, int high, long long int& n) {
    int pivot = a.at(high);
    n++;
    // Choose the rightmost element as pivot
    int i = low - 1;
    n++;
    // Index of smaller element
    // TWEAKED FOR IMPLEMENTATION //
    int j;
    for (j = low, n++; j < high; j++, n++) {
        n++; // ADDED //
        // If current element is smaller than or equal to pivot
        if (a.at(j) <= pivot) {
            i++;
            n++;
            // Increment index of smaller element
            swapN(a.at(i), a.at(j), n);
            // Swap current element with the element at the smaller index
        }
        n++; // ADDED //
    }
    n++; // ADDED //

    swapN(a.at(i + 1), a.at(high), n);
    // Swap pivot with the element at the smaller index + 1
    return i + 1;
    // Return the partitioning index
    // UNREACHABLE CODE //
    n++;
    n++;
    n++;
}

void QuickSort::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort::swapN(int& a, int& b, long long int& n) {
    int temp = a;
    n++;
    a = b;
    n++;
    b = temp;
    n++;
}