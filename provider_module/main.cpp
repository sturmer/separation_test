#include "provider.hpp"
#include <iostream>

int main()
{
    Provider p;
    std::string surname("Wilkes");
    std::cout << "Wilkes, " << p.GetResource(surname) << '\n';
    return 0;
}
