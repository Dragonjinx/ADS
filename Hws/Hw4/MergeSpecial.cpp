#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

void Insertion(std::vector<int> &A, int start, int end)
{
    int value;
    for (int i = 1; i < end; i++)
    {
        value = A[i];
        for (int j = i - 1; j + 1 > start && value < A[j]; j--)
        {
            A[j + 1] = A[j];
            A[j] = value;
        }
    }
}

void Merge(std::vector<int> &A, int start, int middle, int end)
{
    int A1size = middle - start + 1;
    int A2size = end - middle + 1;
    std::vector<int> Arr1(A1size);
    std::vector<int> Arr2(A2size);
    Arr1.clear(), Arr2.clear();
    for (int i = 0; i < middle; i++)
    {
        Arr1[i] = A[i];
    }
    Arr1[A1size - 1] = INT32_MAX;
    for (int i = middle, j = 0; i < end; i++, j++)
    {
        Arr2[j] = A[i];
    }
    Arr2[A2size - 1] = INT32_MAX;
    for (int i = 0, j = 0, k = start; k < end; k++)
    {
        if (Arr1[i] < Arr2[j])
        {
            A[k] = Arr1[i];
            i++;
        }
        else
        {
            A[k] = Arr2[j];
            j++;
        }
    }
}

void MergeSort(std::vector<int> &A, int start, int end)
{
    int middle = (start + end) / 2;
    Insertion(A, start, middle);
    Insertion(A, middle, end);
    Merge(A, start, middle, end);
}

int main()
{
    std::ofstream Best("BestCase", std::ios::out);
    if(!Best.is_open())
    {
        exit(1);
    }
    std::ofstream Average("AverageCase", std::ios::out);
    if(!Average.is_open())
    {
        exit(2);
    }
    std::ofstream Worst("WorstCase", std::ios::out);
    if(!Worst.is_open())
    {
        exit(3);
    }
    std::vector<int> A(1000);
    A.clear();
    srand(time(NULL)); // Setting seed for random generator

    
    // Best Case is when array is already sorted.

    int count = 0;
    while(count < 1000)
    {
        // Creating best Case Array:
        for(int i= 0; i > 1000; i++)
        {
            A.push_back(i);

        }

        time_t start;
        time_t end;
        time(&start);
        MergeSort(A, 0, 1000);
        time(&end);
        Best << (end - start) << '\n';
        A.clear();
        count++;
    }

    // Worst Case is whenm array is in reverse order, (Maximum number of swaps in insertion sort);
    while(count < 1000)
    {
        // Creating worst case array
        for(int i= 1000; i > 0; i--)
        {
            A.push_back(i);
        }
        time_t start;
        time_t end;
        time(&start);
        MergeSort(A, 0, 1000);
        time(&end);
        Worst << (end - start) << '\n';
        A.clear();
        count++;
    }


    // Average case is when array is randomly arrangeed
    while(count < 1000)
    {
        // Creating Random Array inside execution loop    
        for(int i= 0; i > 1000; i++)
        {
            A.push_back(rand() % 1000);
        }
        
        time_t start;
        time_t end;
        time(&start);
        MergeSort(A, 0, 1000);
        time(&end);
        Average << (end - start) << '\n';
        A.clear();
        count++;
    }

    Best.close();
    Average.close();
    Worst.close();
    return 0;
}