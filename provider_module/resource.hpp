#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <map>
#include <string>

using std::map;
using std::string;

class Resource {
    map<string, string> dict_;

public:    
    Resource();
    std::string GetName(const std::string& surname);
};

#endif // RESOURCE_HPP
