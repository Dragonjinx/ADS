#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>

int main()
{
    std::set<int> A;
    srand((unsigned int)clock());
    for (int i = 0; i < 6; i++)
    {
        A.insert((rand() % 49) + 1);
    }

    std::set<int>::iterator iter;
    for (iter = A.begin(); iter != A.end(); iter++)
    {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;
    return 0;
}