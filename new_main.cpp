#include "interface.hpp"
#include <iostream>

using std::cout;

int main()
{
    ProviderInterface* iface(new ProviderInterface);
    //string result = iface->GetResource("Lovelace");
    //string result = iface->GetResource("Wilkes");
    string result = iface->GetResource("Liskov");
    cout << "Result is:\n\"\"\"\n";
    cout << result;
    cout << "\"\"\"\n";
    return 0;
}
