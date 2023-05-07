#include "MergeSort.h"

const string MergeSort::NAME = "Merge Sort";


void MergeSort::SortAlgo(vector<int>& arr, long long int& n) {

    if (n == -1) {
        
        mergeSort(arr, 0, arr.size() - 1);
    
    }

    else (n >= 0); {

        mergeSortN(arr, 0, arr.size() - 1, n);

    }
}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void mergeSortN(vector<int>& arr, int left, int right, long long int& n) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        n++;

        // Sort first and second halves
        mergeSortN(arr, left, mid, n);
        n++;
        mergeSortN(arr, mid + 1, right, n);
        n++;

        // Merge the sorted halves
        mergeN(arr, left, mid, right, n);
        n++;
    }
}


// Merge two sorted subarrays into a single sorted subarray
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Create temporary subarrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary subarrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary subarrays back into arr
    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = left;  // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeN(vector<int>& arr, int left, int mid, int right, long long int& n) {
    int n1 = mid - left + 1;  // Size of the left subarray
    n++;
    int n2 = right - mid;     // Size of the right subarray
    n++;
    // Create temporary subarrays
    vector<int> L(n1);
    n++;
    vector<int> R(n2);
    n++;
    // Copy data to temporary subarrays
    for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
    n++;
}
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        n++;
    }
    // Merge the temporary subarrays back into arr
    int i = 0;
    n++;
    // Initial index of left subarray
    int j = 0;
    n++;
    // Initial index of right subarray
    int k = left;
    n++;
    // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            n++;
        }
        else {
            arr[k] = R[j];
            j++;
            n++;
        }
        k++;
        n++;
    }

    // Copy the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        n++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        n++;
    }
}