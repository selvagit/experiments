#include <iostream>


template <class T>
class node{
    private :
        T _item;
        node <T> *_next;

    public:
        node():_next(){}

        node(T item):_item(item),_next(){}

        ~node(){}

        void set_item(T item) {
            _item = item;
        }

        void set_node(node<T> *next) {
            _next = next;
        }

        T get_item (){
            return _item;
        }

        node<T>* get_node (){
            return _next;
        }

        void operator= (T &that){
            _next = that.next;
            _item = that.next;
        }
};

template <class T>
class my_list{
    private:
    node<T> *head;
    node<T> *tail;

    public:
    my_list():head(),tail(){}
    ~my_list();

    int add_node(const T item);
    void list_nodes();
};

template <class T>
my_list<T>::~my_list(){
    node <T>* temp = head;
    while ( temp != NULL){
        head = head->get_node();
        delete temp ;
        temp = head;
    }
}

template <class T>
int my_list<T>::add_node(const T new_item)
{
    node<T> *temp = new node<T>;
    temp->set_item(new_item);

    if (head == NULL){
        head = temp;
        tail = temp;
    } else {
        tail->set_node(temp);
        tail = temp;
    }

    return 0;
}


template<class T>
void my_list<T>::list_nodes(){
    node<T> *temp = head;

    while ( temp != NULL){
        std::cout << temp->get_item() << std::endl;
        temp = temp->get_node();
    }
}


int main(){

    my_list <int> my_list;

    my_list.add_node(1);
    my_list.add_node(2);
    my_list.add_node(3);

    my_list.list_nodes();

}


