/*
Write a generalised C function to traverse all the nodes in a binary tree.
The tree is composed using the following structures:

struct link;
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

tmp= list_entry(pos, struct kool_list, list);

A given tree will consist entirely of "struct item".
Your function should apply a supplied callback function to each node visited.
Write a C program to do the following:

-- print each value of c found
-- add up all values of c found
-- count the occurrences of each value of c found

Code this in a way which allows both the visitor and the callback functions
to be reentrant.

*/

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
		if( list == NULL )
			return ;

    list->pA = list;
    list->pB = list;
}



void node_add( struct link *new , struct link *curr)
{
	if ((new == NULL) 
			||(curr == NULL))
	{
		return ;
	}

	struct item *tmp_curr_item = NULL;
	struct item *tmp_new_item = NULL;

	tmp_curr_item = list_entry (curr,struct item, link);

	tmp_new_item  = list_entry (new,struct item,link);

	if ( tmp_curr_item->c > tmp_new_item->c )
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

	return ;
}


void print(int c , int *output)
{
	printf ("c =%d\n",c);   
	return ;
}

void sum(int c , int *output)
{
	if( output == NULL) 
		return ;

	*output = *output + c;    

	return;
}


void walk_tree_pre_order ( struct link *curr, 
                void ( *func_ptr )(int c, int *outout ),
                int *output)
{
		if( (curr == NULL)
				|| ( func_ptr == NULL)
				|| ( output == NULL ))
		{
			return ;
		}

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
            walk_tree_pre_order(tmp_curr_item->link.pA,func_ptr,output);
        }

        if ( &tmp_curr_item->link != tmp_curr_item->link.pB)
        {
            walk_tree_pre_order(tmp_curr_item->link.pB,func_ptr,output);
        }
    } 
		return ;
}

void walk_tree_in_order ( struct link *curr, 
                void ( *func_ptr )(int c, int *outout ),
                int *output)
{
		if( (curr == NULL)
				|| ( func_ptr == NULL)
				|| ( output == NULL ))
		{
			return ;
		}

    struct item *tmp_curr_item = list_entry (curr,struct item, link);

    if (tmp_curr_item->link.pA == tmp_curr_item->link.pB  )
    {
       func_ptr( tmp_curr_item->c, output); 
    }
    else
    {
        if ( &tmp_curr_item->link != tmp_curr_item->link.pA)
        {
            walk_tree_in_order(tmp_curr_item->link.pA,func_ptr,output);
        }

        func_ptr( tmp_curr_item->c, output); 

        if ( &tmp_curr_item->link != tmp_curr_item->link.pB)
        {
            walk_tree_in_order(tmp_curr_item->link.pB,func_ptr,output);
        }
    } 
		return ;
}

void walk_tree_post_order ( struct link *curr, 
                void ( *func_ptr )(int c, int *outout ),
                int *output)
{
		if( (curr == NULL)
				|| ( func_ptr == NULL)
				|| ( output == NULL ))
		{
			return ;
		}

    struct item *tmp_curr_item = list_entry (curr,struct item, link);

    if (tmp_curr_item->link.pA == tmp_curr_item->link.pB  )
    {
       func_ptr( tmp_curr_item->c, output); 
    }
    else
    {
        if ( &tmp_curr_item->link != tmp_curr_item->link.pA)
        {
            walk_tree_post_order(tmp_curr_item->link.pA,func_ptr,output);
        }

        if ( &tmp_curr_item->link != tmp_curr_item->link.pB)
        {
            walk_tree_post_order(tmp_curr_item->link.pB,func_ptr,output);
        }

        func_ptr( tmp_curr_item->c, output); 
    } 
		return ;
}


int main ( int argc , char *argv[] )
{
    struct item head;
    struct item *temp ;

		#define NO_OF_NODES (11)

		int inp_ary[NO_OF_NODES] = {18,5,10,6,11,22,20,1,4,13,29};

    INIT_LIST_NODE(&head.link);
    head.c = inp_ary[0];

		for ( int i = 1 ; i < NO_OF_NODES ; i++ )
		{
			temp = (struct item *)malloc (sizeof (struct item ));
			if (temp != NULL)
			{
				INIT_LIST_NODE(&temp->link);
				temp->c = inp_ary[i];
				node_add(&temp->link,&head.link);
			}
		}

    int output=0; 

		printf("\npre_order \n");
    walk_tree_pre_order(&head.link,print,&output);

		printf("\nin_order \n");
    walk_tree_in_order(&head.link,print,&output);
		
		printf("\npost_order \n");
    walk_tree_post_order(&head.link,print,&output);

    return 0;
}
