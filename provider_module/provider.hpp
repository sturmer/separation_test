#ifndef PROVIDER_HPP
#define PROVIDER_HPP

#include <string>

class Resource;

class Provider {
    Resource* r_;

public:    
    Provider();
    std::string GetResource(const std::string& name);
};

#endif // PROVIDER_HPP
