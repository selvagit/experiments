#include <iostream>

using namespace std;


void func2( int *i)
{
    *i=10;
    return;
}

void func1 (void)
{
    static int i = 0;
    
    std::cout << " func1 : 1 : "<< i << std::endl;
    func2(&i);
    std::cout << " func1 : 2 : "<< i << std::endl;
    
    return;
}


int main()
{
   cout << "Hello World" << endl; 
   
   func1();
   
   return 0;
}
