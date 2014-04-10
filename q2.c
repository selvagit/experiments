
#include <stdio.h>
#include <stdlib.h>
 
/** 
 * container_of - cast a member of a structure out to the containing structure 
 * @ptr:        the pointer to the member. 
 * @type:       the type of the container struct this is embedded in. 
 * @member:     the name of the member within the struct. 
 * 
 */ 
#define container_of(ptr, type, member) ({\
        const typeof( ((type *)0)->member ) *__mptr = (ptr);\
        (type *)( (char *)__mptr - offsetof(type,member) );}) 

/** 
 * list_entry - get the struct for this entry 
 * @ptr:        the &struct list_head pointer. 
 * @type:       the type of the struct this is embedded in. 
 * @member:     the name of the list_struct within the struct. 
 */ 
#define list_entry(ptr, type, member) \
        container_of(ptr, type, member)

struct link
{
    struct link *pA;
    struct link *pB;
};

struct item
{
    struct link link;
    uint8_t c;
};


void INIT_LIST_NODE(struct link *list)
{
    list->pA = list;
    list->pB = list;
}



void node_add( struct link *new , struct link *curr)
{
    struct item *tmp_curr_item = NULL;
    struct item *tmp_new_item = NULL;

    tmp_curr_item = list_entry (curr,struct item, link);

    tmp_new_item  = list_entry (new,struct item,link);

    if ( tmp_curr_item->c < tmp_new_item->c )
    {
        if ( tmp_curr_item->link.pA == &tmp_curr_item->link )
        {
            tmp_curr_item->link.pA = &tmp_new_item->link; 
        }
        else
        {
            node_add(new, curr->pA);
        }
    } 
    else
    {
        if ( tmp_curr_item->link.pB == &tmp_curr_item->link )
        {   
            tmp_curr_item->link.pB = &tmp_new_item->link; 
        }
        else
        {
            node_add(new, curr->pB);
        }
    }

}


void print(int c , int *output)
{
    printf ("c =%d\n",c);   
}

void sum(int c , int *output)
{
    *output = *output + c;    
}


void walk_tree ( struct link *curr, 
                void ( *func_ptr )(int c, int *outout ),
                int *output)
{
    struct item *tmp_curr_item = list_entry (curr,struct item, link);

    if (tmp_curr_item->link.pA == tmp_curr_item->link.pB  )
    {
       func_ptr( tmp_curr_item->c, output); 
    }
    else
    {
        func_ptr( tmp_curr_item->c, output); 
        if ( &tmp_curr_item->link != tmp_curr_item->link.pA)
        {
            walk_tree(tmp_curr_item->link.pA,func_ptr,output);
        }

        if ( &tmp_curr_item->link != tmp_curr_item->link.pB)
        {
            walk_tree(tmp_curr_item->link.pB,func_ptr,output);
        }
    } 
}

int main ( int argc , char *argv[] )
{
    struct item head;
    struct item *temp ;

    INIT_LIST_NODE(&head.link);
    head.c = 8;

    temp = (struct item *)malloc (sizeof (struct item ));
    if (temp != NULL)
    {
        INIT_LIST_NODE(&temp->link);
        temp->c = 5;
        node_add(&temp->link,&head.link);
    }


    temp = (struct item *)malloc (sizeof (struct item ));
    if (temp != NULL)
    {
        INIT_LIST_NODE(&temp->link);
        temp->c = 10;
        node_add(&temp->link,&head.link);
    }

    temp = (struct item *)malloc (sizeof (struct item ));
    if (temp != NULL)
    {
        INIT_LIST_NODE(&temp->link);
        temp->c = 6;
        node_add(&temp->link,&head.link);
    }


    temp = (struct item *)malloc (sizeof (struct item ));
    if (temp != NULL)
    {
        INIT_LIST_NODE(&temp->link);
        temp->c = 11;
        node_add(&temp->link,&head.link);
    }

    int output=0; 
    walk_tree(&head.link,print,&output);

    walk_tree(&head.link,sum,&output);
    printf ("sum = %d", output);
    
    return 0;
}
