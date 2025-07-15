#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/queue.h>


struct entry {

LIST_ENTRY(entry) entries;

int i;

} *n1, *n2 , *np;

void list (void) {

    printf("list example\n");
    LIST_HEAD(listhead, entry) head;

    LIST_INIT(&head); 

    n1 = malloc(sizeof(struct entry));
    LIST_INSERT_HEAD(&head,n1,entries);
    n1->i = 1;

    n2 = malloc(sizeof(struct entry));
    LIST_INSERT_AFTER(n1,n2,entries);
    n2->i = 0xff;

    for (np = head.lh_first; np != NULL; np = np->entries.le_next)
        printf("%d\n", np->i);

    while(head.lh_first != NULL){
        LIST_REMOVE(head.lh_first,entries);
    }

    free(n2);
    free(n1);

    return;
}

void stack (void) {
    printf("stack example\n");

    LIST_HEAD(listhead, entry) head;

    LIST_INIT(&head); 

    n1 = malloc(sizeof(struct entry));
    LIST_INSERT_HEAD(&head,n1,entries);
    n1->i = 1;

    n2 = malloc(sizeof(struct entry));
    LIST_INSERT_HEAD(&head,n2,entries);
    n2->i = 0xff;

    for (np = head.lh_first; np != NULL; np = np->entries.le_next)
        printf("%d\n", np->i);

    while(head.lh_first != NULL){
        struct entry *temp = head.lh_first;
        LIST_REMOVE(head.lh_first,entries);
        free(temp);
    }

}

int main(void) {
    list();
    stack();
}
