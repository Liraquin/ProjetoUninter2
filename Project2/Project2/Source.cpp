#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct PlaylistElements {
	// elementos da playlist
	char songname[200];
	int songtime;
};


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


struct PlaylistElements reqSongs() {
	int c;
	// temp structure
	struct PlaylistElements tpe;
	
	//malloc(sizeof(PlaylistElements));

	printf("Enter song name: \n");
	scanf_s("%s", &tpe.songname, 200);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	printf("Enter song time: \n");
	scanf_s("%d", &tpe.songtime, 16);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	return tpe;
};

void listSongs(struct PlaylistElements tpe) {
	printf(" Song name: %s \n", &tpe.songname);
	printf(" Song time: %d \n", &tpe.songtime);
};


int main () {
	
	int op, c, i;

	//creating the struct array var
	struct PlaylistElements playlist[6];
	

	while (1) {

		op = menu();
		switch (op) {

		case 1:
			// case para inserir musica
			for (i = 0; i < 6; i++) {
				printf("Enter the name of the song #%d\n", (i + 1));
				playlist[i] = reqSongs();
			};
			

			break;

		case 2:
			// case para remover

			printf("Digite o numero da musica que deseja apagar: ");
			scanf_s("%d", i);
			playlist[i].songname = "";
			playlist[i].songtime = 0;
			


			break;

		case 3:
			// lista as musicas
			for (i = 0; i < 6; i++) {
				printf("\n Song #%d : \n", (i + 1));
				listSongs(playlist[i]);
			};
			system("PAUSE");
			break;

		case 4:
			// fecha o loop
			return 0;
		}; // fim do Switch
	}; // fim do while 1
}; // fim da main