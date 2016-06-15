#include <iostream>
#include <sstream>


typedef enum testt {
    one,
    two
}test_e;

class temp {

    public:
        temp(){
            std::cout << "inside const" << std::endl;
        }
        ~temp(){
            std::cout << "inside dest" << std::endl;
        }

        void test_func(test_e test){
            std::cout << test << std::endl;
        }
};

int main ()
{
    temp my_temp;
    my_temp.test_func(one);

    std::stringstream s;

    s << "test" << std::endl;
    s << "temp" << std::endl;

    //printf("%c", s.c_str());

}
