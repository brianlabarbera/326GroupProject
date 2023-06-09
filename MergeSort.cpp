#include "MergeSort.h"

const string MergeSort::NAME = "Merge Sort";

// MergeSort Algo; // NOT NEEDED //

void MergeSort::SortAlgo(vector<int>& arr, long long int& n) {

    if (n == -1) {

        MergeSort::mergeSort(arr, 0, arr.size() - 1);

    }
    else {

        MergeSort::mergeSortN(arr, 0, arr.size() - 1, n);

    }

    // n++; // NOT NEEDED //
}


void MergeSort::mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);

    }
}

void MergeSort::mergeSortN(vector<int>& arr, int left, int right, long long int& n) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        n++;

        // Sort first and second halves
        mergeSortN(arr, left, mid, n);

        mergeSortN(arr, mid + 1, right, n);

        // Merge the sorted halves
        mergeN(arr, left, mid, right, n);

    }

    n++;

}


// Merge two sorted subarrays into a single sorted subarray
void MergeSort::merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Create temporary subarrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary subarrays
    for (int i = 0; i < n1; i++)
        L.at(i) = arr.at(left + i);
    for (int j = 0; j < n2; j++)
        R.at(j) = arr.at(mid + 1 + j);

    // Merge the temporary subarrays back into arr
    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = left;  // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L.at(i) <= R.at(j)) {
            arr.at(k) = L.at(i);
            i++;
        }
        else {
            arr.at(k) = R.at(j);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1) {
        arr.at(k) = L.at(i);
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        arr.at(k) = R.at(j);
        j++;
        k++;
    }
}

void MergeSort::mergeN(vector<int>& arr, int left, int mid, int right, long long int& n) {
    int n1 = mid - left + 1;  // Size of the left subarray
    n++;
    int n2 = right - mid;     // Size of the right subarray
    n++;
    // Create temporary subarrays
    vector<int> L(n1); // THESE MAY NEED n++ //
    vector<int> R(n2); // THESE MAY NEED n++ //

    // Copy data to temporary subarrays
    // TWEAKED FOR IMPLEMENTATION //
    int i, j;
    for (i = 0, n++; i < n1; i++, n++) {
        n++; // MOVED //
        L.at(i) = arr.at(left + i);
        n++;
    }
    n++; // ADDED //
    // TWEAKED FOR IMPLEMENTATION //
    for (j = 0, n++; j < n2; j++, n++) {
        n++; // MOVED //
        R.at(j) = arr.at(mid + 1 + j);
        n++;
    }
    n++; // ADDED //
    // Merge the temporary subarrays back into arr
    i = 0;
    n++;
    // Initial index of left subarray
    j = 0;
    n++;
    // Initial index of right subarray
    int k = left;
    n++;
    // Initial index of merged subarray

    while (i < n1 && j < n2) {
        n++; // ADDED //
        if (L.at(i) <= R.at(j)) {
            arr.at(k) = L.at(i);
            n++;
            i++;
            n++;
        }
        else {
            arr.at(k) = R.at(j);
            n++;
            j++;
            n++;
        }
        n++; // ADDED //
        k++;
        n++;
    }
    n++; // ADDED //

    // Copy the remaining elements of L[]
    while (i < n1) {
        n++; // ADDED //
        arr.at(k) = L.at(i);
        n++;
        i++;
        n++;
        k++;
        n++;
    }
    n++; // ADDED //

    // Copy the remaining elements of R[]
    while (j < n2) {
        n++; // ADDED //
        arr.at(k) = R.at(j);
        n++;
        j++;
        n++;
        k++;
        n++;
    }
    n++; // ADDED //
}
