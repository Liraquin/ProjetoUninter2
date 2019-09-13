#include<stdio.h>							   
#include<stdlib.h>

int menu();
void InsertBegining(int num);
void InserirFim(int num);
void InserirMeio(int num, int posipoint);
int Remove(int num);
void List();

struct PlaylistElements {
	// elementos da playlist
	char songname[200];
	int songtime;
	struct PlaylistElements* next;
} *Head;

int  main() {
	int op, num, c;	
	Head = NULL;
	/* I need a vector here that can collect the name and the time - check case 1
	 this same Vector is gonna be used on the functions below, so we can treat them all using 1 vector rather than 2 variables for name and time */

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite o nome da musica: ");
			// scanf_s("%s", &somethingsomething, 200)
			while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer
			printf("Qual a duracao da musica em minutos?: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer
			InsertBegining(num);
			break;
		case 2:
			// I had a 
			int res;
			printf("Digite a posicao a ser removida: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer
			res = Remove(num);
			if (res == 1)
				printf("musica removida.");
			else
				printf("Numero nao encontrado.");
			break;
		case 3:
			List();
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


void InsertBegining(int num)
{
	PlaylistElements* NewElement;
	NewElement = (struct PlaylistElements*)malloc(sizeof(struct PlaylistElements));
	NewElement->songtime = num;

	if (Head == NULL)
	{
		Head = NewElement;
		Head->next = NULL;
	}
	else
	{
		NewElement->next = Head;
		Head = NewElement;
	}
}


int Remove(int num) {
	PlaylistElements* ScanElement;
	ScanElement = (struct PlaylistElements*)malloc(sizeof(struct PlaylistElements));
	PlaylistElements* PrevPointer;
	PrevPointer = (struct PlaylistElements*)malloc(sizeof(struct PlaylistElements));

	ScanElement = Head;
	while (ScanElement != NULL) {
		if (ScanElement->songtime == num) {
			if (ScanElement == Head) {
				Head = ScanElement->next;
				free(ScanElement);
				return 1;
			}
			else {
				PrevPointer->next = ScanElement->next;
				free(ScanElement);
				return 1;
			}
		}
		else {
			PrevPointer = ScanElement;
			ScanElement = ScanElement->next;
		}
	} // fim if 1
	return 0;
}// fim remove

void List(){
	PlaylistElements* ElementoVarredura;
	ElementoVarredura = (struct PlaylistElements*)malloc(sizeof(struct PlaylistElements));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		printf("%d ", ElementoVarredura->songtime); // lista o tempo
		printf("%s ", ElementoVarredura->songname); // lista os nomes
		ElementoVarredura = ElementoVarredura->next;
	} // fim while
	printf("\n");

	system("pause");
	return;
}// fim List