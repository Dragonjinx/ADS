#include <iostream>
#include "Access.h"

void Access::activate(unsigned int code, unsigned int level)
{
    container[code] = level;
}

void Access::deactivate(unsigned int code)
{
    container.erase(code);
}

bool Access::isActive(unsigned int code, unsigned int level) const
{
    if (container.count(code))
    {
        unsigned int Storage = container.at(code);
        /*  Question fotr TA. I could not use the index operator for this
            and had to use the at function instead. Any reasons why?     */
        std::cout << "Stored Level = " << Storage << std::endl;
        {
            return true;
        }
    }

    return false;
}
