#include <iostream>
#include <set>
#include <algorithm>
#include "Access.h"


int main()
{
    Access A;
    A.activate(1234);
    A.activate(9999);
    A.activate(9876);
    while (1)
    {
        int usercode;
        std::cin>>usercode;
    
        if (A.isActive(usercode))
        {
            std::cout << "Door opened successfully." << std::endl;
            A.deactivate(usercode);
            break;

        }
        else
        {
            std::cout << "Access Denied." << std::endl;
        }
    }
    A.deactivate(9999);
    A.activate(1111);
    
    while (1)
    {
        int usercode;
        std::cin>>usercode;
    
        if (A.isActive(usercode))
        {
            std::cout << "Door opened successfully." << std::endl;
            break;

        }
        else
        {
            std::cout << "Access Denied." << std::endl;
        }
    }
    return 0;
}