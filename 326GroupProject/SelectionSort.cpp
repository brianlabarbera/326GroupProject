#include "SelectionSort.h"

const string SelectionSort::NAME = "SelectionSort";

void SelectionSort::SortAlgo(vector<int>* arr, long int& n)
{
    if (n < 0)
    {
            int i, j, min_idx;
           
            for (i = 0; i < n - 1; i++)
            {
                min_idx = i;
                for (j = i + 1; j < n; j++)
                {
                    if (arr.at(j) < arr.at(min_idx)
                        min_idx = j;
                }
                if (min_idx != i)
                    swap(&arr.at(min_idx), &arr.at(i);
            }
    }


    else
    {
        int i, j, min_idx;

        for (i = 0,n++; i < n - 1; i++,n++)
        {
            n++;
            min_idx = i;
            for (j = i + 1,n++; j < n; j++,n++)
            {
                n++;
                if (arr.at(j) < arr.at(min_idx)
                    n++;
                    min_idx = j;
            }
            if (min_idx != i)
                n++;
                swap(&arr.at(min_idx), &arr.at(i);
            n++;
        }
        n++;
    }

    void BubbleSort::swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }