#include <iostream>


class base_cl {
    private:
        int _i;
    public:
        base_cl(){
            //std::cout << "constructor base_cl" << std::endl;
        }
        ~base_cl(){
            //std::cout << "desctructor base_cl" << std::endl;
        }
        int get(){
            return _i;
        }
        void set(int i){
            _i = i;
            std::cout << "base: set the variable" << std::endl;
        }

        virtual int vir (){
            std::cout << "base: virtual method" << std::endl;
            return 0;
        }
};


class derivded_cl: public base_cl{
    private:
        int _j;
    public:
        derivded_cl(){
            //std::cout << "constructor derive_cl" << std::endl;
        }

        ~derivded_cl(){
            //std::cout << "desctructor derive_cl" << std::endl;
        }
        void set(int i){
            _j = i;
            std::cout << "derivded set the variable" << std::endl;
        }
        int vir (){
            std::cout << "derived : virtual method" << std::endl;
            return 0;
        }

};


int main(){

    derivded_cl test;
    test.set(1);
    test.vir();

    base_cl b;
    derivded_cl d;

    base_cl *ptr_b;

    ptr_b = &d;
    ptr_b->set(1); //early binding, binding during the compilation time

    ptr_b->vir(); //late binding, run time binding

}
