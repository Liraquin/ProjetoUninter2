
typedef struct Element {
	void* data;
	Element* next;
} Element;

typedef struct List {
	Element* head;
} List;


void insert_beginning(List* list, Element* element);
Element* pop_element(List* list, int index);
