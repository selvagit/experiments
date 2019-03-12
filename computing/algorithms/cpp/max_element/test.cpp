#include <iostream>
#include <sstream>
#include <cstring>

#include "rma_min_max_data.h"

int main ()
{
    RMAMinMaxData a;

    a.insert(1);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(2);
    a.insert(3);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    
    std::cout << "max=" <<static_cast<unsigned int>( a.get_max()) << std::endl;
    std::cout << "min=" <<static_cast<unsigned int>( a.get_min()) << std::endl;
    std::cout << "avg=" <<static_cast<unsigned int>( a.get_avg()) << std::endl;
}
