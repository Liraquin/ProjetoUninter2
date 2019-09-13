#include<stdio.h>							   
#include<stdlib.h>

int menu();
void InserirInicio(int num);
void InserirFim(int num);
void InserirMeio(int num, int posicao);
int Remover(int num);
void Listar();

struct PlaylistElements {
	// elementos da playlist
	char songname[200];
	int songtime;
	struct PlaylistElements* next;
} *Head;

int  main() {
	int op, num, pos, c;
	Head = NULL;

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer
			InserirInicio(num);
			break;
		case 2:
			int res;
			printf("Digite o numero a ser removido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer
			res = Remover(num);
			if (res == 1)
				printf("Numero removido.");
			else
				printf("Numero nao encontrado.");
			break;
		case 3:
			Listar();
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


void InserirInicio(int num)
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


int Remover(int num)
{
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
	}
	return 0;
}

void Listar()
{
	PlaylistElements* ElementoVarredura;
	ElementoVarredura = (struct PlaylistElements*)malloc(sizeof(struct PlaylistElements));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		printf("%d ", ElementoVarredura->songtime);
		ElementoVarredura = ElementoVarredura->next;
	}
	printf("\n");

	system("pause");
	return;
}