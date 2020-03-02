#include <iostream>
#include "Access.h"


int main()
{
    Access A;
    A.activate(1234, 1);
    A.activate(9999, 5);
    A.activate(9876, 9);
    
    while (1)
    {
        int usercode;
        std::cin>>usercode;
    
        if (A.isActive(usercode, 5))
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
    A.activate(9999, 8);
    A.activate(1111, 7);
    
    while (1)
    {
        int usercode;
        std::cin>>usercode;
    
        if (A.isActive(usercode, 7))
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
