#include <iostream>


class RMASysSrvAgent {
    public:
        /*
         * Singleton instance getter.
         */
        static RMASysSrvAgent* instance();

    private:
        static RMASysSrvAgent* _instance;

};



RMASysSrvAgent* RMASysSrvAgent::_instance = 0;

RMASysSrvAgent* RMASysSrvAgent::instance()
{
    if(0 == _instance)
    {
        _instance = new RMASysSrvAgent;
    }
    return _instance;
}

int main ( void)
{
    RMASysSrvAgent* test = RMASysSrvAgent::instance();

    delete test;

    return 0;
}
