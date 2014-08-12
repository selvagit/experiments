#include <stdio.h>
#include <stdlib.h>

struct node{
    int a;
    struct node* next;
};

struct list{
    struct node *head;
    struct node *tail;
    int totalnode;
};

void add_node(int a, struct list *lst)
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp != NULL){
        temp->a = a;
        if (lst->head == NULL){
            lst->head = temp;
            lst->tail = temp;
        }else{
            lst->tail->next = temp;
            lst->tail = lst->tail->next;
        }
    } else {
        printf("Memory allocation failure \n");
    }
}

struct node *reverse_list(struct node *cur, struct node **head )
{
    struct node *temp = NULL;
    if (cur->next != NULL){
        temp = reverse_list(cur->next,head);
        temp->next = cur;
    }else{
        *head = cur;
    }

    return cur;
}

void print_lst( struct list *lst)
{
    struct node *temp = lst->head;
    while(temp != NULL){
        printf("Element = %d\n",temp->a);
        temp = temp->next;
    }
}

int main(int argv, char *argc[])
{
    struct list sng_lst;

    sng_lst.head = NULL;
    sng_lst.tail = NULL;

    add_node(1,&sng_lst);
    add_node(2,&sng_lst);
    add_node(3,&sng_lst);
    add_node(4,&sng_lst);
    add_node(5,&sng_lst);

    print_lst(&sng_lst);

    reverse_list(sng_lst.head,&sng_lst.head);

    print_lst(&sng_lst);
    return 0;
}


