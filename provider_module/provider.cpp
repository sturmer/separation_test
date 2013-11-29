#include "provider.hpp"
#include "resource.hpp"
#include <iostream>

Provider::Provider() : r_(new Resource())
{
    std::clog << "Provider::Provider()\n";
}

std::string Provider::GetResource(const std::string& name)
{
    std::clog << "Provider::GetResource()\n";
    return r_->GetName(name);
}
