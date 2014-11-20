#include <iostream>

class my_base {

    private:
        int _a;

    public:
        my_base(){}
        ~my_base(){}
        void print_attri(){
            std::cout << _a << std::endl;
        }

    friend class my_friend;
};

class my_friend{

    private:
        int _i;

    public:
        my_friend(){}
        ~my_friend(){}

        int get( my_base tst ){
            std::cout << tst._a << std::endl;
            return 0;
        }
};

class my_compos{

    private:
        int _i;

    public:
        my_compos(){}
        ~my_compos(){}

        // since my_compos is not a friend class it 
        // cannot access the private variable
        int get(my_base tst){
            std::cout << tst._a << std::endl;
            return 0;
        }

        // however local object can still 
        // be created
        my_base t2;
};


int main ()
{
  my_base b;
  my_friend c;

  b.print_attri();

  return 0;
}
