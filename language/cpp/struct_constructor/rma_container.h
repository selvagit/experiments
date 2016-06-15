#include <iostream>
#include <sstream>
#include <cstring>

#include <cstdint>


struct __attribute__((__packed__)) ContainerTest 
{
    RMAMinMaxData _data;
    RMAMinMaxData _data_array[10];
    RMAMinMaxData *_data_list[10];
    RMAMinMaxData *_data_one;

    ContainerTest():_data()
    {
        for ( int i = 0 ; i < 10 ; i ++)
        {
            _data_array[i] = RMAMinMaxData();
        }
        std::cout << "Complted the building of the array element " << std::endl;

        {
            uint16_t size = sizeof(RMAMinMaxData)*10;

            uint8_t *temp = new uint8_t[size];

            _data_list[0] = new (temp) RMAMinMaxData;

            _data_list[1] = new (temp) RMAMinMaxData;
        }
        std::cout << "Complted the building of the array of pointers " << std::endl;

        {
            uint16_t size = sizeof(RMAMinMaxData)*10;

            uint8_t *temp = new uint8_t[size];

            _data_one = new (temp) RMAMinMaxData[10];
        }
        std::cout << "Complted the building of the pointer to an array " << std::endl;

        std::cout << "inside the constructor ContainerTest " << std::endl;
    }

    ~ContainerTest()
    {

    }
     
};

