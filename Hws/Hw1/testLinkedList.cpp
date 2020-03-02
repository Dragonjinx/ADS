#include <cstdio>
#include <iostream>
#include "LinkedList.h"

int main()
{
    Dlist<int, Node> List1(30);
    int a = List1.Back();
    std::cout << "Number: " << a << std::endl;
    for(int i = 0; i < 10; i++)
    {
        List1.pushFront(i);
        List1.pushBack(i * 2);
    }

    std::cout << "Elements: " << List1.getElems() << std::endl; 

    for(int i = 0; List1.getElems() > 0; i++)
    {
        int toprint;
        // List1.popFront(toprint);
        // std::cout << "Popping Front : " << toprint << std::endl;
        List1.popBack(toprint);
        std::cout << "Popping Back: " << toprint << std::endl;
    }
    return 0;
}
