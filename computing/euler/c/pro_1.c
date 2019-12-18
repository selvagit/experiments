/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
      int ele;
      struct node *next;
};

struct list {
      struct node *head;
      struct node *tail;
};


void add_node(int a, struct list *lst)
{
    if ( lst == NULL){
          printf("Null pointer was given as an argument\n");
          return ;
    }else{
          struct node *temp = malloc(sizeof(struct node));
          if( temp != NULL ){
                if (lst->head == NULL ){
                      lst->head = temp;
                      lst->tail = temp;
                      lst->tail->next = NULL;
                      lst->head->ele = a;
                }else{
                      lst->tail->next = temp;
                      lst->tail = lst->tail->next;
                      lst->tail->ele = a;
                      lst->tail->next = NULL;
                }
          }else{
                printf ("Memory allocation failure %s %d\n",__FILE__,__LINE__);
          }
    }
}

void print_node(struct node *cur)
{
    if (cur ==NULL){
          printf("Null pointer was given as an argument %s %d\n", __FILE__,__LINE__);
          return;
    }else{
          while(cur != NULL){
                printf("Print the nodes =%d\n",cur->ele);
                cur = cur->next;
          }
    }
}


void clean_node(struct node *cur)
{
    if (cur ==NULL){
          printf("Null pointer was given as an argument %s %d\n", __FILE__,__LINE__);
          return;
    }else{
          while(cur != NULL){
                struct node *temp = cur->next;
                free(cur);
                cur = temp;
          }
    }
}

void clean_list(struct list *cur)
{
    if (cur ==NULL){
          printf("Null pointer was given as an argument %s %d\n", __FILE__,__LINE__);
          return;
    }else{
          struct node *temp = cur->head;
          free(cur);
          clean_node(temp);
    }
}

struct list * find_multiple(int set_size, void *elements, int (*check)(void *elements,int i) )
{
    struct list *lst = malloc(sizeof(struct list));
    if(lst == NULL){
          printf ("Memory allocation failure %s %d\n",__FILE__,__LINE__);
          return lst;
    }else{
        lst->head=NULL;
        lst->tail=NULL;
        int i = 0;
        for ( i = 1; i < set_size; i++){
              if ( check(elements,i) == 0){
                    add_node(i, lst);
              }
        }
    }
    return lst;
}

int sum_list(struct node *lst)
{
    int ret_val = 0;
    if ( lst == NULL ){
          printf("Null pointer was given as an argument %s %d\n", __FILE__,__LINE__);
          return ret_val;
    }else{
          do{
                ret_val += lst->ele;
                lst = lst->next;
          }while ( lst != NULL);
    }

    return ret_val;
}


int compare_ele(void *ele, int i)
{
    int *elements = (int*)ele;

    if ( ((i % elements[0]) == 0)
            || ((i % elements[1]) == 0) ){
          return 0;
    }

    return 1;
}

int main ( int argc , char *argv[])
{
    if (argc < 2){
          return -1;
    }

    int set_size = atoi(argv[1]);
    printf("Set size = %d\n",set_size); 
    
    int elements[] = {3,5};

    struct list *mp = find_multiple(set_size, (void *)elements,compare_ele);

    printf("Printing the nodes\n");
    print_node(mp->head);

    int sum = sum_list(mp->head);

    printf("Summ of the elements %d\n",sum);

    clean_list(mp);

    return 0;
}
