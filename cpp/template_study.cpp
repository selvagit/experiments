

#include <iostream> 

template<typename TYPE>
TYPE Twice(TYPE data)
{
    return data * 2;
}

int sample_1 (void)
{
    std::cout << "sample_1" <<std::endl;
    std::cout << Twice(10) << std::endl;
    std::cout << Twice(3.14) << std::endl;
    std::cout << Twice( Twice(55) ) << std::endl;

    std::cout <<std::endl;
    return 0;
}


template <class T>
double add_all_element_of_array(T n1[] , int array_sz ) 
{
    T temp = T();

    for ( int i = 0 ; i< array_sz ; i++) 
    {
        temp += n1[i];
    }

    return double (temp);
}

void sample_2(void)
{
    int array[3] ={1,2,3};
    double darray[3] ={1.5,2.5,3.5};

    std::cout << "sample_2" <<std::endl;

    std::cout << add_all_element_of_array(array,3) << std::endl;
    std::cout << add_all_element_of_array(darray,3) << std::endl;
    std::cout << std::endl;
}


int sample_3 (void)
{
    int StudentAge;

    std::cout << "Enter Student Age: ";
    std::cin >> StudentAge;

    try 
    {
        if(StudentAge < 0)
            throw " error " ;
        std::cout << "\nStudent Age: " << StudentAge << "\n\n";
    }

    catch(char * arg  )
    {
        std::cout <<  arg << std::endl;
    }

    std::cout << "\n";

    return 0;
}

class node 
{
    private: 
        int _info;

    public:
        node():_info(0){}
        ~node(){}

        node* next;

        int get_info()
        {
            return _info;
        }

        void put_info(int input )
        {
            _info = input;
        }
};


class sllist // single linked list  
{
    private:
        node* head;
        node* tail;
        node* curr_node;

    public:
        sllist( ): head(0),tail(0){}
        ~sllist(){}

        void add_node_to_head(int info);
        void add_node_to_tail(int info);
        void del_node(int info);
        node * get_head_node();
        node * get_tail_node();
        void list_all_nodes();
};


void sllist::add_node_to_head(int info )
{
    if ( head == 0)
    {
        head = new node ;
        head->put_info(info);
        tail = head;
        head->next = 0;
        //std::cout << "head node add = " << head->next << std::endl ;
    }else
    {
        node* temp = head ;
        head = new node ;
        head->put_info(info);
        head->next = temp;
    }
}

void sllist::add_node_to_tail(int info)
{
    tail->next = new node ;
    tail = tail->next ;
    tail->put_info(info);
    tail->next = 0;
}

node * sllist::get_head_node()
{
    return head;
}

node * sllist::get_tail_node()
{
    return tail;
}

void sllist::del_node ( int info)
{
    node * temp = get_head_node();
    node * prev = 0;

    while((temp->get_info()!= info) && (temp != 0))
    {
        prev = temp;
        temp = temp->next;
    }

    if ( temp != 0 ) 
    {
        node *temp_next = temp->next;
    
        std::cout << "Del node is = " << temp->get_info() << std::endl; 

        delete temp;

        prev->next = temp_next;
    }    
}

void sllist::list_all_nodes()
{
    node * temp = head;

    std::cout << "listing all the nodes "  << std::endl;
    while (temp != 0)
    {
        std::cout << temp->get_info() << std::endl;
        temp = temp->next;
    }
}

void sample_4()
{

    sllist list;

    list.add_node_to_head(1);
    list.add_node_to_head(2);
    list.add_node_to_tail(3);
    list.list_all_nodes();

    list.del_node(1);
    list.list_all_nodes();
}

int main (void)
{
    //sample_1();

    //sample_2();

    //sample_3();

    sample_4();
}

