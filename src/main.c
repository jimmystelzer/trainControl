#include <stdio.h>
#include "conio_linux.h"

/*****************Structs**************/
struct trem{
    int destX;		// X que o trem deve ir
    int destY;		// Y que o trem deve ir
    int id;			// identidade
    int posX;		// posição em relação ao eixo X
    int posY;		// eixo Y
    int espera;		// usado no embarque/desembarque, decrementado em cada turno
};
/**********Variáveis Globais***********/
struct trem L[8];

/****************Funções****************/
void turno(void);				// espera o segundo atual do sistema mudar
void moveTrem(void);			// função que é chamada para mover os trens
void desenhaEstacoes(void);		// primeira função de desenho chamada a cada turno
void inicializaVariaveis(void); // inicializa variaveis

int main(){
    inicializaVariaveis();
	desenhaEstacoes();
	return 0;
}

void inicializaVariaveis(void){
	int i;
	int posX[8] = {2,2,2,7,7,31,31,43};
	int posY[8] = {2,3,4,8,10,6,7,12};
	int destX[8] = {13,13,14,17,39,36,49};
	int destY[8] = {1,3,7,9,11,6,9,11};
	for(i=0;i<8;i++){
		L[i].id = i+1;
		L[i].posX = posX[i];
		L[i].posY = posY[i];
		L[i].destX = destX[i];
		L[i].destY = destY[i];
		L[i].espera = 5;
	}
}

void desenhaEstacoes(void){
    int i;
	/*
	* TODO limpara tela antes de plotar para garantir consistência na execução.
	*/
	// estacao 1
    for(i=2;i<5;i++){
        gotoxy(1,i);
        printf("###");
    }
	// estacao 2
    for(i=8;i<11;i++){
        gotoxy(6,i);
        printf("###");
    }
	// estacao 3
    for(i=1;i<4;i++){
        gotoxy(12,i);
        printf("###");
    }
	// estacao 4
    for(i=5;i<8;i++){
        gotoxy(13,i);
        printf("###");
    }
	// estacao 5
    for(i=9;i<12;i++){
        gotoxy(16,i);
        printf("###");
    }
	// estacao 6
    for(i=2;i<5;i++){
        gotoxy(22,i);
        printf("###");
    }
	// estacao 7 principal
    for(i=6;i<9;i++){
        gotoxy(27,i);
        printf("#####");
    }
	// estacao 8
    for(i=9;i<12;i++){
        gotoxy(35,i);
        printf("###");
    }
	// estacao 9
    for(i=5;i<8;i++){
        gotoxy(38,i);
        printf("###");
    }
	// estacao 10
    for(i=1;i<4;i++){
        gotoxy(41,i);
        printf("###");
    }
	// estacao 11
    for(i=10;i<13;i++){
        gotoxy(42,i);
        printf("###");
    }
	// estacao 12
    for(i=9;i<12;i++){
        gotoxy(48,i);
        printf("###");
    }
	// estacao 13
    for(i=5;i<8;i++){
        gotoxy(53,i);
        printf("###");
    }
}
