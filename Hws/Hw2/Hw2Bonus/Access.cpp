#include "Access.h"
#include <algorithm>

void Access::activate(unsigned int code)
{
    Container.insert(code);
}

void Access::deactivate(unsigned int code)
{
    Container.erase(code);
}

bool Access::isActive(unsigned int code) const
{
    if((unsigned int)*(find(Container.begin(), Container.end(), code)) == code)
    {
        return true;
    }
    return false;
}
