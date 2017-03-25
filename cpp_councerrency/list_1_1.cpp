#include <iostream>
#include <thread>

void hello (void) 
{
	std::cout << "Hello World" << std::endl;
}


int main ()
{
	std::thread t(hello);
	t.join();
	while(1);
}
