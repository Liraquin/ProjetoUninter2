#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


typedef struct PlaylistElements {
	// elementos da playlist
	char songname[200];
	float songtime;
};


int menu() {
	int op, c;
	system("Cls");

	printf("1.Inserir na lista\n");
	printf("2.Remover da lista\n");
	printf("3.Mostrar playlist\n");
	printf("4.Sair\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer.

	system("Cls");
	return op;
};


struct PlaylistElements reqSongs() {

	// temp structure
	struct PlaylistElements tpe;
	malloc(sizeof(PlaylistElements));

	printf("Enter song name: \n");
	scanf_s("%s", tpe.songname);

	printf("Enter song time: \n");
	scanf_s("%f", tpe.songtime);

	return tpe;
};

void listSongs(struct PlaylistElements tpe) {
	printf(" Song name: %s\n", tpe.songname);
	printf(" Song time: %f\n", tpe.songtime);
};


// function declaration


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

			break;

		case 3:
			// lista as musicas
			for (i = 0; i < 6; i++) {
				printf("\n Song #%d : \n", (i + 1));
				listSongs(playlist[i]);
			};
			break;

		case 4:
			// fecha o loop
			return 0;
		}; // fim do Switch
	}; // fim do while 1
}; // fim da main