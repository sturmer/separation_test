#include "server_operations.hpp"

#include <string>
#include <fstream>

using std::string;
using std::ifstream;

string ServiceOps::GetResource(const string& name)
{
    const std::string fn("/proc/" + name);
    ifstream ifs(fn.c_str());
    if (!ifs) {
        return "";
    }

    string line;
    string file_content;
    while (getline(ifs, line)) {
        file_content += line + '\n';
    }
    return file_content;
}
