#include "QuickSort.h"

const string QuickSort::NAME = "Quick Sort";


void QuickSort::SortAlgo(vector<int>& arr, long long int& n) {

    if (n == -1) {

        quickSort(arr, 0, arr.size() - 1);

    }

    else (n >= 0); {

        quickSortN(arr, 0, arr.size() - 1, n);

    }
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);  // Partition the array

        // Recursive calls to sort the sub-arrays
        quickSort(a, low, pi - 1);   // Elements before partition
        quickSort(a, pi + 1, high);  // Elements after partition
    }
}

void quickSortN(vector<int>& a, int low, int high, long long int& n) {
    if (low < high) {
        int pi = partitionN(a, low, high, n);  // Partition the array
        n++;

        // Recursive calls to sort the sub-arrays
        quickSortN(a, low, pi - 1, n);
        n++;
        // Elements before partition
        quickSortN(a, pi + 1, high, n);
        n++;
        // Elements after partition
    }
}


int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];  // Choose the rightmost element as pivot
    int i = low - 1;      // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (a[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(a[i], a[j]);  // Swap current element with the element at the smaller index
        }
    }

    swap(a[i + 1], a[high]);  // Swap pivot with the element at the smaller index + 1
    return i + 1;             // Return the partitioning index
}

int partitionN(vector<int>& a, int low, int high, long long int& n) {
    int pivot = a[high];
    n++;
    // Choose the rightmost element as pivot
    int i = low - 1;
    n++;
    // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (a[j] <= pivot) {
            i++;  // Increment index of smaller element
            swapN(a[i], a[j], n);
            n++;
            // Swap current element with the element at the smaller index


        }

        swapN(a[i + 1], a[high], n);
        n++;
        // Swap pivot with the element at the smaller index + 1
        return i + 1;
        n++;
        // Return the partitioning index
    }

}

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void swapN(int& a, int& b, long long int& n) {
        int temp = a;
        n++;
        a = b;
        n++;
        b = temp;
        n++;
    }

