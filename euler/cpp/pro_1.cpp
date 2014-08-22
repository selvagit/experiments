/*
 * If we my_list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 i*/

#include <iostream>


class my_list {

    private:
      struct node{
            int element;
            struct node *next;
      };

      node *_head;
      node *_tail;

    public:

     my_list();
     ~my_list();

     int  add_node(int a); // inset node to the end of the list
     int  delete_node(int a); // find the node and delete
     int  sum_all_nodes();
};


my_list::my_list(){
      _head = NULL;
      _tail = NULL;
}

my_list::~my_list(){
      node *temp = NULL;
      while (_head != NULL){
            temp = _head->next;
            delete _head;
            _head = temp;
      }
      _head = NULL;
      _tail = NULL;
}

int my_list::add_node(int a){
      if ( _head == NULL){
            _head = new node;
            _tail = _head;
      }else{
            _tail->next = new node;
            _tail = _tail->next;
            _tail->next = NULL;
      }
      return 0;
}

int my_list::delete_node(int a){

      node *temp = _head;
      node *inter = _head;

      while(temp != NULL){
            if (temp->element == a ){
                  if(temp == _head ){
                        _head = temp->next;
                        delete temp;
                  }else{
                        inter = temp->next;
                        delete temp;
                  }
                  break;
            }
            inter = temp;
            temp = temp->next;
      }

      return 0;
}

int my_list::sum_all_nodes(){
      int sum = 0;
      node *temp = _head;
      while(temp != NULL){
            sum += temp->element;
            temp = temp->next;
      }
      return sum;
}

int main(int argv , char *argc[])
{
    my_list single_lst;
    single_lst.add_node(3);
    single_lst.add_node(5);
    single_lst.add_node(1);
    single_lst.add_node(3);
    single_lst.add_node(6);
}
