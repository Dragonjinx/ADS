#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> A;
    for(int i = 0; i < 30; i++)
    {
        A.push_back(i+1);
    }

    A.push_back(5);
    std::reverse(A.begin(), A.end());
    std::vector<int>::iterator iter;
    for(iter = A.begin(); iter != A.end(); iter++)
    {
        std::cout << *iter << ',';
    }
    std::cout << std::endl;
    std::replace(A.begin(), A.end(), 5, 129);
    
    for(iter = A.begin(); iter != A.end(); iter++)
    {
        std::cout << *iter << ',';
    }
    std::cout << std::endl;
    return 0;
}