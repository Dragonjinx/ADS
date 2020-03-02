#include <set>

class Access
{
private:
    std::set<int> Container;

public:
    void activate(unsigned int code);
    void deactivate(unsigned int code);
    bool isActive(unsigned int code) const;
};
