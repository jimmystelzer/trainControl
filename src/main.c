/*
 * Bruno Goulart de Oliveira
 * Jimmy Pinto Stelzer
 * 
 * requer:
 *     pthreads
 *     semaphore
 *     ncurses
 * 
 * para compilar:
 *     make
 * para executar o codigo compilado:
 *     . ./bin/trainControl
 */

#include <pthread.h>
#include <semaphore.h>
#include <curses.h>
#include <unistd.h>

// variaveis do ncurses
static WINDOW *mainwnd;
static WINDOW *screen[8];
WINDOW *my_win;
pthread_mutex_t scrfsh = PTHREAD_MUTEX_INITIALIZER;
pthread_t processo_linha[8],processo_placar[8];
sem_t acesso_leitura_linha[8], acesso_escrita_linha[8];
int posicao_linha[8]           = {  0,  0,120,  0,200,  0,  0,160}; // posicao do trem em relacao ao percurso
int distancia_linha[8]         = {100,150,120,140,200, 80,220,160}; // distancia total do percuros
int velocidade_media[8]        = { 60, 50, 70, 55, 75, 68, 72, 49}; // velocidade media do trem da linha
unsigned char sentido_linha[8] = {  1,  1,  0,  1,  0,  1,  1,  0}; // sentido do trem no trajeto
const int parada_linha[3][8]  = {{25, 36, 28, 20, 32, 24, 40, 31}, // posicao das paradas nas linhas com relacao ao trajeto
                                 { 56, 72, 69, 83,117, 52,130, 70},
                                 { 80,130, 98,122,184, 70,208,150}};
char sentido_literal[2][7] = {"centro\0","bairro\0"};

void *trem(void *p){
    int pos = (int)p;
    int i,pb;
    for(;;){
        if(sentido_linha[pos]){
            for(i=0;i<distancia_linha[pos];i++){
                usleep((500000 - (4000000/velocidade_media[pos])));  //atraso maximo - inverso da velocidade por uma constante limite 
                sem_wait(&acesso_escrita_linha[pos]);
                pb = ++posicao_linha[pos];
                sem_post(&acesso_leitura_linha[pos]);
                if(pb==parada_linha[0][pos]||pb==parada_linha[1][pos]||pb==parada_linha[2][pos]){
                    //na parada espera
                    usleep(2000000);
                }
            }
        }else{
            for(i=0;i<distancia_linha[pos];i++){
                usleep((500000 - (4000000/velocidade_media[pos])));
                sem_wait(&acesso_escrita_linha[pos]);
                pb = --posicao_linha[pos];
                sem_post(&acesso_leitura_linha[pos]);
                if(pb==parada_linha[0][pos]||pb==parada_linha[1][pos]||pb==parada_linha[2][pos]){
                    //na parada espera
                    usleep(2000000);
                }
            }
        }
        //fim da linha
        usleep(4000000);
        sem_wait(&acesso_escrita_linha[pos]);
        sentido_linha[pos] = !sentido_linha[pos];
        sem_post(&acesso_leitura_linha[pos]);
    }
    pthread_exit(NULL);
}

void *placar(void *p){
    int posicao,sentido,tempo,proxima;
    int i = (int)p;
    for(;;){
        sem_wait(&acesso_leitura_linha[i]);
        posicao = posicao_linha[i];
        sentido = sentido_linha[i];
        sem_post(&acesso_escrita_linha[i]);
        
        curs_set(0);
        mvwprintw(screen[i],1,12,"LINHA %d", i+1);
        mvwprintw(screen[i],2,8,"Sentido: %s", &sentido_literal[sentido][0]);
        if(sentido){
            if(posicao <= parada_linha[0][i]){
                tempo = (int)(parada_linha[0][i] - posicao)*(velocidade_media[i]/20); proxima=1;
            }else if(posicao <= parada_linha[1][i]){
                tempo = (int)(parada_linha[1][i] - posicao)*(velocidade_media[i]/20); proxima=2;
            }else if(posicao <= parada_linha[2][i]){
                tempo = (int)(parada_linha[2][i] - posicao)*(velocidade_media[i]/20); proxima=3;
            }else{
                tempo = (int)(distancia_linha[i] - posicao)*(velocidade_media[i]/20); proxima=4;
            }
        }else{
            if(posicao >= parada_linha[2][i]){
                tempo = (int)(posicao - parada_linha[2][i])*(velocidade_media[i]/20); proxima=3;
            }else if(posicao >= parada_linha[1][i]){
                tempo = (int)(posicao - parada_linha[1][i])*(velocidade_media[i]/20); proxima=2;
            }else if(posicao >= parada_linha[0][i]){
                tempo = (int)(posicao - parada_linha[0][i])*(velocidade_media[i]/20); proxima=1;
            }else{
                tempo = (int)(posicao)*(velocidade_media[i]/20); proxima=0;
            }
        }
        if(proxima==0||proxima==4){
            mvwprintw(screen[i],3,3,"%04d min ate fim da linha", tempo);
        }else{
            mvwprintw(screen[i],3,3,"%04d min ate parada %d    ", tempo,proxima);
        }
        if(posicao==parada_linha[0][i]){
            mvwprintw(screen[i],4,8,"Na parada 1 ");
        }else if(posicao==parada_linha[1][i]){
            mvwprintw(screen[i],4,8,"Na parada 2 ");
        }else if(posicao==parada_linha[2][i]){
            mvwprintw(screen[i],4,8,"Na parada 3 ");
        }else if(posicao==0||posicao==distancia_linha[i]){
            mvwprintw(screen[i],4,8,"Fim da Linha");
        }else{
            mvwprintw(screen[i],4,8,"------------");
        }
      
        wrefresh(screen[i]);
        //pthread_mutex_lock(&scrfsh);
        //refresh();
        //pthread_mutex_unlock(&scrfsh);
        usleep(10000); // nao flodar
    }
    pthread_exit(NULL);
}
int main(){
    int t;
    mainwnd = initscr();
    noecho();
    cbreak();
    nodelay(mainwnd, TRUE);
    refresh();
    wrefresh(mainwnd);
    screen[0] = newwin(7, 30, 0, 1);
    screen[1] = newwin(7, 30, 0, 31);
    screen[2] = newwin(7, 30, 7, 1);
    screen[3] = newwin(7, 30, 7, 31);
    screen[4] = newwin(7, 30, 14, 1);
    screen[5] = newwin(7, 30, 14, 31);
    screen[6] = newwin(7, 30, 21, 1);
    screen[7] = newwin(7, 30, 21, 31);
    for(t=0;t<8;t++){
        box(screen[t], ACS_VLINE, ACS_HLINE);
    }
    
    //inicializa flags
    for(t=0;t<8;t++){
        sem_init(&acesso_leitura_linha[t], 0, 0);
        sem_init(&acesso_escrita_linha[t], 0, 1);
    }
    //cria placar e linha
    for(t=0;t<8;t++){
        pthread_create(&processo_placar[t], NULL, placar, (void *)t);
        pthread_create(&processo_linha[t], NULL, trem, (void *)t);
    }
    //espera todos o processo acabarem
    for(t=0;t<8;t++){
        pthread_join(processo_linha[t],NULL);
        pthread_join(processo_placar[t],NULL);
    }
    endwin();
	return 0;
}
