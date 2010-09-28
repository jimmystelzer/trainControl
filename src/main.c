#include <stdio.h>

struct trem
{
    int destX;//para saber em qual eetapa da viajem o trem está
    int destY;//é o número máximo de movimentos do trem
    int id;//identidade
    int posX;// posição em relação ao eixo X
    int posY;// eixo Y
};

struct trem L1, L2, L3, L4, L5, L6, L7, L8;
int main(){

   //inicialização das variáveis do tipo trem
    L1.id = 1;L1.posX = 4;L1.posY = 2;L1.destXd = 1;L1.destY = //pos(4,2)
    L2.id = 2;L2.posX = 4;L2.posY = 3;L2.destX = 1;
    L3.id = 3;L3.posX = 4;L3.posY = 4;L3.destX = 1;
    L4.id = 4;L4.posX = 9;L4.posY = 8;L4.destX = 1;
    L5.id = 5;L5.posX = 9;L5.posY = 10;L5.destX = 1;
    L6.id = 6;L6.posX = 59;L6.posY = 6;L6.destX = 1;
    L7.id = 7;L7.posX = 59;L7.posY = 6;L7.destX = 1;
    L8.id = 8;L8.posX = 103;L8.posY = 2;L8.destX = 1;
    return 0;
}
