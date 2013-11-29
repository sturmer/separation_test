#ifndef IFACE_HPP
#define IFACE_HPP

#include <string>

using std::string;

class Provider;

class ProviderInterface {
    Provider* impl_;
    void* so_handle_;

public:
    ProviderInterface();
    string GetResource(const string& name);
    ~ProviderInterface();
};

#endif // IFACE_HPP
