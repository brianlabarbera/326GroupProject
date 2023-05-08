#include "InsertionSort.h"

const string InsertionSort::NAME = "InsertionSort";

void InsertionSort::SortAlgo(vector<int>* arr, long int& n)
{
    if (n < 0) 
        {
            int i, key, j;
            for (i = 1; i < n; i++)
            {
                key = arr.at(i);
                j = i - 1;
                while (j >= 0 && arr.at(j) > key)
                {
                    arr.at(j + 1) = arr.at(j);
                    j = j - 1;
                }
                arr.at(j + 1) = key;
            }
        }


    else 
        {
            int i, key, j;
            for (i = 1,n++; i < n; i++,n++)
            {
                n++;
                key = arr.at(i);
                n++;
                j = i - 1;
                n++;
                while (j >= 0 && arr.at(j) > key)
                {
                    n++; n++;
                    arr.at(j + 1) = arr.at(j);
                    n++;
                    j = j - 1;
                    n++;
                }
                n++;
                arr.at(j + 1) = key;
                n++;
            }
            n++;
        }
   