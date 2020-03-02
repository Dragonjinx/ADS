#include <iostream>
#include <vector>

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
    std::vector<int> A;
    srand(time(NULL));
    for(int i= 50; i > -1; i--)
    {
        A.push_back(i);
    }

    MergeSort(A, 0, 50);
    // Insertion(A, 0, 50);
    for (int i = 0; i < 50; i++)
    {
        std::cout << A[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}