#include <stdio.h>

struct trem
{
    int destX;//X que o trem deve ir
    int destY;//Y que o trem deve ir
    int id;//identidade
    int posX;// posição em relação ao eixo X
    int posY;// eixo Y
};

struct trem L1, L2, L3, L4, L5, L6, L7, L8;
int main(){

   //inicialização das variáveis do tipo trem
    L1.id = 1;L1.posX = 1;L1.posY = 2;L1.destX = 12;L1.destY = 1;
    L2.id = 2;L2.posX = 1;L2.posY = 3;L2.destX = 12;L2.destY = 3;
    L3.id = 3;L3.posX = 1;L3.posY = 4;L3.destX = 13;L3.destY = 7;
    L4.id = 4;L4.posX = 6;L4.posY = 8;L4.destX = 16;L4.destY = 9;
    L5.id = 5;L5.posX = 6;L5.posY = 10;L5.destX = 16;L5.destY = 11;
    L6.id = 6;L6.posX = 30;L6.posY = 6;L6.destX = 38;L6.destY = 6;
    L7.id = 7;L7.posX = 30;L7.posY = 7;L7.destX = 35;L7.destY = 9;
    L8.id = 8;L8.posX = 42;L8.posY = 12;L8.destX = 48;L8.destY = 11;
    return 0;
}
