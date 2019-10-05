#include <stdlib.h>
#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i + 1)
#define F_DIR(i) (2*i + 2)
/*os valores e o pos_heap tão na ordem "aceleracao, controle, velocidade"*/


int it, mc, i, c, p, Heap_escolhido, posicao_outro_heap;
/*IT é o numero de iteracoes e MC e o numero maximo de carros*/
int Carros_inseridos, Carros_escolhidos;
