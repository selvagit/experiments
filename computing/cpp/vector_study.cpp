
#include <iostream>
#include <vector>

int main ( )
{
    std::vector <int> dy_ary;

    for( int i = 0 ; i < 10 ; i ++ ) dy_ary.push_back(i) ;

    for( int i = 0 ; i < 10 ; i ++ ) 
    {
        std::cout << dy_ary[i] << std::endl;
    }

}
