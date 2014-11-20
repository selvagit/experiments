#include <iostream>


class my_base {
    private:
        int _a;
    public:
        my_base(){
            std::cout << "cons" << std::endl; 
        }

        ~my_base(){
            std::cout << "desc" << std::endl; 
        }

        my_base(my_base &temp){
          _a = temp._a;
        }

        void operator=(my_base &temp){
            _a = temp._a;
        }

        void set(int i){
            _a=i; 
        } 

       int get(){return _a;} 
};


int main (){
    my_base a;
    a.set(1);
    std::cout << a.get() << std::endl;

    my_base ab(a);
    std::cout << ab.get() << std::endl;

    my_base abb=a;
    std::cout << abb.get() << std::endl;

    return 0;
}
