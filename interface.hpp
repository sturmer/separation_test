#ifndef IFACE_HPP
#define IFACE_HPP

#include <string>

using std::string;

class ProviderInterface {
    string GetResource(const string& name);
};

#endif // IFACE_HPP
