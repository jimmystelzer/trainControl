#include <stdio.h>
#include "conio_linux.h"

/*****************Structs**************/
struct trem
{
    int destX;//X que o trem deve ir
    int destY;//Y que o trem deve ir
    int id;//identidade
    int posX;// posição em relação ao eixo X
    int posY;// eixo Y
    int espera = 5;//usado no embarque/desembarque, decrementado em cada turno
};
/**********Variáveis Globais***********/
struct trem L1, L2, L3, L4, L5, L6, L7, L8;

/****************Funções****************/
void turno(void);//espera o segundo atual do sistema mudar
void moveTrem(void);//função que é chamada para mover os trens
void desenhaEstacoes(void);//primeira função de desenho chamada a cada turno

int main(){

   //inicialização das variáveis do tipo trem
    L1.id = 1;L1.posX = 2;L1.posY = 2;L1.destX = 13;L1.destY = 1;
    L2.id = 2;L2.posX = 2;L2.posY = 3;L2.destX = 13;L2.destY = 3;
    L3.id = 3;L3.posX = 2;L3.posY = 4;L3.destX = 14;L3.destY = 7;
    L4.id = 4;L4.posX = 7;L4.posY = 8;L4.destX = 17;L4.destY = 9;
    L5.id = 5;L5.posX = 7;L5.posY = 10;L5.destX = 17;L5.destY = 11;
    L6.id = 6;L6.posX = 31;L6.posY = 6;L6.destX = 39;L6.destY = 6;
    L7.id = 7;L7.posX = 31;L7.posY = 7;L7.destX = 36;L7.destY = 9;
    L8.id = 8;L8.posX = 43;L8.posY = 12;L8.destX = 49;L8.destY = 11;
    return 0;
}

void desenhaEstacoes(void){
    int i;
//estacao generica
/*    for(i=Y_inicial;i<Y_final-1;i++){
        gotoxy(X_inicial,i);
        printf(":::");
    }*/
//estacao 1
    for(i=2;i<5;i++){
        gotoxy(1,i);
        printf("###");
    }
//estacao 2
    for(i=8;i<11;i++){
        gotoxy(6,i);
        printf("###");
    }
//estacao 3
    for(i=1;i<4;i++){
        gotoxy(12,i);
        printf("###");
    }
//estacao 4
    for(i=5;i<8;i++){
        gotoxy(13,i);
        printf("###");
    }
//estacao 5
    for(i=9;i<12;i++){
        gotoxy(16,i);
        printf("###");
    }
//estacao 6
    for(i=2;i<5;i++){
        gotoxy(22,i);
        printf("###");
    }
//estacao 7 principal
    for(i=6;i<9;i++){
        gotoxy(27,i);
        printf("#####");
    }
//estacao 8
    for(i=9;i<12;i++){
        gotoxy(35,i);
        printf("###");
    }
//estacao 9
    for(i=5;i<8;i++){
        gotoxy(38,i);
        printf("###");
    }
//estacao 10
    for(i=1;i<4;i++){
        gotoxy(41,i);
        printf("###");
    }
//estacao 11
    for(i=10;i<13;i++){
        gotoxy(42,i);
        printf("###");
    }
//estacao 12
    for(i=9;i<12;i++){
        gotoxy(48,i);
        printf("###");
    }
//estacao 13
    for(i=5;i<8;i++){
        gotoxy(53,i);
        printf("###");
    }
}