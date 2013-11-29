#include "server_operations.hpp"
#include <iostream>

using std::cout;

int main()
{
    ServiceOps ops;
    string result = ops.GetResource("version");
    cout << "Result is:\n\"\"\"\n";
    cout << result;
    cout << "\"\"\"\n";
    return 0;
}
