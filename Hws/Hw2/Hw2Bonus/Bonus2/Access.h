#include <map>

class Access
{
public:
    void activate(unsigned int code, unsigned int level);
    void deactivate(unsigned int code);
    bool isActive(unsigned int code, unsigned int level) const;

private:
    std::map<unsigned int, unsigned int> container;
};
