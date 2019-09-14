#include <stdio.h>
#include "list.h"

int main(){

    List list;
    Element e1, e2, e3;
    e1.data = (void*) 1;
    e2.data = (void*) 2;
    e3.data = (void*) 3;

    insert_beginning(&list, &e3);
    insert_beginning(&list, &e2);
    insert_beginning(&list, &e1);
    
    Element *popped_element = pop_element(&list, 1); //second element
    if (popped_element == &e2){
        printf("e2 got popped");
    }
    popped_element = list.head->next;
    if (popped_element == &e3){
        printf("e3 is last element popped");
    }
}
