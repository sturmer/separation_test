#ifndef SERVICE_OPERATIONS
#define SERVICE_OPERATIONS

#include <string>

using std::string;

class ServiceOps
{
public:    
    std::string GetResource(const string& name);
};

#endif // SERVICE_OPERATIONS
