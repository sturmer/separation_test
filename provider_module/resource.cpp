#include "resource.hpp"
#include <map>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>

using std::map;
using std::string;
using std::out_of_range;
using std::exception;
using std::cerr;
using std::clog;

Resource::Resource()
{
    clog << "Resource::Resource()\n";
    dict_["Lovelace"] = "Ada";
    dict_["Wilkes"] = "Mary Allen";
    dict_["Liskov"] = "Barbara";
}

std::string Resource::GetName(const std::string& surname)
{
    clog << "Resource::GetName(surname=" << surname << ")\n";
    string res;
    try {
        res = dict_.at(surname);
    } catch (const out_of_range& oor) {
        cerr << "Element not in map:\n" << surname << '\n';
        throw;
    } catch (const exception& ex) {
        cerr << "Unknown exception!\n" << ex.what();
        throw;
    }
    clog << "res = [" << res << "]\n";
    return res;
}
