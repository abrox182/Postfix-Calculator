#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct list{int data; struct list *next}list1;
list1 *create_list(int d){
    list1 *l = malloc(sizeof(list1));
    l->data = d;
    l->next = NULL;
    return l;
}
list1 *add_to_front(int d, list1 *h){
    list1
}