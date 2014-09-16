/*
 * If we my_list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>
#include <cstdlib>

class my_list {

    private:

    public:

     my_list();
     ~my_list();

      struct node{
            int element;
            struct node *next;
      };

      node *_head;
      node *_tail;
      int _total_nodes;

     int  add_node(int a); // inset node to the end of the list
     int  delete_node(int a); // find the node and delete
     int  sum_all_nodes(void);
     int  total_nodes(void);
     void print_nodes(void);
     void *get_head_node(void);

     //friend class find_msum;
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
            _tail->element = a;
      }else{
            _tail->next = new node;
            _tail = _tail->next;
            _tail->element = a;
            _tail->next = NULL;
      }
      _total_nodes++;
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
                  _total_nodes--;
                  break;
            }
            inter = temp;
            temp = temp->next;
      }

      return 0;
}

void my_list::print_nodes(void){

      node *temp = _head;

      while(temp != NULL){
            std::cout << temp->element << std::endl ;
            temp = temp->next;
      }
}

int my_list::total_nodes(void){
      return _total_nodes;
}

void *my_list::get_head_node(void){
      return _head;
}

int my_list::sum_all_nodes(void){
      int sum = 0;
      node *temp = _head;
      while(temp != NULL){
            sum += temp->element;
            temp = temp->next;
      }
      return sum;
}

class find_msum : public my_list {

    private :
        int _sum ;
        int _mul_1;
        int _mul_2;

    public :
        find_msum(int multiple_1, int multiple_2): 
            _mul_1(multiple_1), _mul_2(multiple_2)
      {
        _sum = 0;
      }

        int mul_sum(my_list &lst){
              node *temp_node = (node *)lst.get_head_node(); 
              while(temp_node != NULL){
                    if (((temp_node->element % _mul_1) == 0)
                            ||((temp_node->element % _mul_2) == 0)){
                          _sum += temp_node->element;
                    }
                    temp_node = temp_node->next;
              }
              return _sum;
        }
};



int main(int argv , char *argc[])
{
    my_list single_lst;

    if (argv < 2){
          std::cout << "Please give no of elements to be used " << std::endl;
        return -1;
    }

    int number_of_elements = atoi(argc[1]);

    for ( int i = 1 ; i <  number_of_elements ; i++){
        single_lst.add_node(i);
    }

    //single_lst.print_nodes();
    //std::cout << "Total nodes = " << single_lst.total_nodes() << std::endl;

    find_msum test(3,5);
    std::cout << "Sum of multiple nodes = " << test.mul_sum(single_lst) << std::endl;

    return 0;
}

