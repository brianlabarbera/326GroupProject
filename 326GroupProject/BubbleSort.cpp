#include "BubbleSort.h"

const string BubbleSort::NAME = "Bubble Sort";

void BubbleSort::SortAlgo(vector<int>* arr, long int& n) 
 {
    if (n < 0)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr.at(j) > arr.at(j + 1))
                {
                    swap(arr.at(j), arr.at(j + 1));
                }
            }
        }
    }

    else {

        if (n < 0) 
        {
            int i, j;
            for (i = 0, n++; i < n - 1; i++, n++)
            {
                n++;
                for (j = 0, n++; j < n - i - 1; j++, n++) 
                {
                    n++;
                    if (arr.at(j) > arr.at(j + 1))
                    {
                        swapN(arr.at(j), arr.at(j + 1));
                    }
                    n++;
                }
                n++;
            }
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
 
 void BubbleSort::swapN(int& a, int& b)
    {
        int temp = a;
        n++;
        a = b;
        n++;
        b = temp;
        n++;
    }
