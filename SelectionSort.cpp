#include "SelectionSort.h"

const string SelectionSort::NAME = "Selection Sort";

void SelectionSort::SortAlgo(vector<int>& arr, long long int& n)
{
    if (n < 0)
    {
            int i, j, min_idx;
           
            for (i = 0; i < arr.size() - 1; i++)
            {
                min_idx = i;
                for (j = i + 1; j < arr.size(); j++)
                {
                    if (arr.at(j) < arr.at(min_idx))
                        min_idx = j;
                }
                if (min_idx != i)
                    swap(arr.at(min_idx), arr.at(i));
            }
    }
    else
    {
        int i, j, min_idx;

        for (i = 0,n++; i < arr.size() - 1; i++,n++)
        {
            n++;
            min_idx = i;
            for (j = i + 1,n++; j < arr.size(); j++,n++)
            {
                n++;
                if (arr.at(j) < arr.at(min_idx)) {
                    min_idx = j;
                    n++;
                }
                n++;
            }
            n++;
            if (min_idx != i) {
                swap(arr.at(min_idx), arr.at(i));
            }
            n++;
        }
        n++;
    }
}

void SelectionSort::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort::swapN(int& a, int& b, long long int& n)
{
    int temp = a;
    n++;
    a = b;
    n++;
    b = temp;
    n++;
}