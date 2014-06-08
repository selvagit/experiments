#include <iostream>


class test_static {
    public:
        /*
         * Singleton instance getter.
         */
        static test_static* instance();

    private:
        static test_static* _instance;

};



test_static* test_static::_instance = 0;

test_static* test_static::instance()
{
    if(0 == _instance)
    {
        _instance = new test_static;
    }
    return _instance;
}

int main ( void)
{
    test_static* test = test_static::instance();

    delete test;

    return 0;
}
