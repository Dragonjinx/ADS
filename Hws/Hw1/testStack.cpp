#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int>a(20);
    Stack<int>b(20);
    for(int i = 0; i< 15; i++)
    {
        std::cout<< "a1" <<std::endl;
        a.push(i);
        std::cout<< "a2" <<std::endl;
        a.push(i * i);
        std::cout<< "b" <<std::endl;
        b.push(i);
    }
    std::cout << "A: " << a.getNumEntries() << " B: " << b.getNumEntries() << std::endl;
    std::cout << "Stack A: " << std::endl;
    a.printstack();
    std::cout << "Stack b: modified" << std::endl;
    b.printstack();
    int storage;
    bool check = b.pop(storage);
    if(check)
    {
        std::cout << "It popped" << std::endl;
    }
    else
    {
        std::cout << "No pop" << std::endl;
    }
    a.printstack();
    b.printstack();
    return 0;
}