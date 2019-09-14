#include<stdio.h>							   
#include<stdlib.h>
#include "list.h"


int menu();


typedef struct Song{
	char name[200];
	float length;
} Song;

int  main() {
	int op, c;	
    List playlist;
	

	while (1) {
		op = menu();
		switch (op) {
		case 1:
            add_song(&playlist);
			break;
		case 2:
            remove_song(&playlist);
		break;
		case 3:
			list_songs(&playlist);
			break;
		case 4:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls");

	printf("1.Inserir na lista\n");
	printf("2.Remover da lista\n");
	printf("3.Mostrar playlist\n");
	printf("4.Sair\n");
	printf("Digite sua escolha: ");
	scanf_s("%d", &op, 1);
	while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer.

	system("Cls");
	return op;
};

void list_songs(List *playlist){
    Element *element = playlist->head;
    Song *song;
    while (element != NULL){
        song = (Song *) element->data;
        printf("%f ", song->length); // lista o tempo
        printf("%s ", song->name); // lista os nomes
        printf("\n");
        element = element->next;
    }
	system("pause");
	return;
}// fim List

void remove_song(List *playlist){
    int index, c;
    printf("Digite a posicao a ser removida: ");   
    scanf_s("%d", &index, 200);
    while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer
    Element *popped = pop_element(playlist, index);
    if (popped != NULL){
        printf("musica removida.");
        return;
	}
	else
        printf("Numero nao encontrado.");
    free(popped->data);
    free(popped);
}

void add_song(List *playlist){
    Song *song = malloc(sizeof(Song));
    Element *element = malloc(sizeof(Element));
    element->data = (void*) song;
    printf("Digite o nome da musica: ");
	scanf_s("%s", &song->name, 200);
    printf("Qual a duracao da musica em minutos?: ");
    scanf_s("%f", &song->length, 8);
    insert_beginning(list, element);
}
