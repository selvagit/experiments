#include <iostream>



template <class T>
class my_list{
    private:
    T val;
    my_list *next_node;
    int __total_nodes;

    public:
    int add_node(T &node);
}


