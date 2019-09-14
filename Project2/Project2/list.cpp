#include "list.h"

void insert_beginning(List *list, Element *element){
    Element *head = list->head;
	if (head == NULL){
        list->head = element;
        element->next = NULL;
	}
	else{
        element->next = head;
        list->head = element;
	}
}

Element* pop_element(List *list, int index){
    /*
    Unlinks the element at the position 'index' from the list and return it.
    If list is empty, return the null pointer.
    If index is out of range, returns null
    */
    Element *head = list->head;
    Element *pop_element, *prev_element;
    if (head == NULL)
        return NULL;
    if (index == 0){
        //special case since it involves updating the head pointer
        pop_element = head;
        list->head = pop_element->next;
        return pop_element;
    }
    pop_element = head;
    for (int i = 0; i < index; i++){
        prev_element = pop_element;
        pop_element = prev_element->next;
    }
    prev_element->next = pop_element->next;
    return pop_element;
}
