#include <stdio.h>
#include <stdlib.h>
#include "lab07.h"

typedef struct Carro{
  float valores[3];
  int posicoes[3];
}Carro;

typedef struct Heap{
    Carro **v;
    int vagas_usadas, tamanho;
} Heap;

void troca(Carro **carro1, Carro **carro2, int tipo_heap){
    Carro *carroAux;
    int aux;
    carroAux = *carro1;
    *carro1 = *carro2;
    *carro2 = carroAux;
    aux = (*carro1)->posicoes[tipo_heap];
    (*carro1)->posicoes[tipo_heap] = (*carro2)->posicoes[tipo_heap];
    (*carro2)->posicoes[tipo_heap] = aux;
}

void subir_no_heap(Heap *fp, int k, int tipo_heap){
    if (k > 0 && fp->v[PAI(k)]->valores[tipo_heap] < fp->v[k]->valores[tipo_heap]){
        troca(&fp->v[k], &fp->v[PAI(k)], tipo_heap);
        subir_no_heap(fp, PAI(k), tipo_heap);
    }
}

void inserir_heap(Heap *fp, Carro *novo_carro, int tipo_heap){
    novo_carro->posicoes[tipo_heap] = fp->vagas_usadas;
    fp->v[fp->vagas_usadas] = novo_carro;
    fp->vagas_usadas++;
    subir_no_heap(fp, fp->vagas_usadas-1, tipo_heap);
}

void descer_no_heap(Heap *fp, int k, int tipo_heap){
    int maior_filho;
    if (F_ESQ(k) < fp-> vagas_usadas){
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fp->vagas_usadas && fp->v[F_ESQ(k)]->valores[tipo_heap] < fp->v[F_DIR(k)]->valores[tipo_heap]){
            maior_filho = F_DIR(k);
        }
        if (fp->v[k]->valores[tipo_heap] < fp->v[maior_filho]->valores[tipo_heap]){
            troca(&(fp->v[k]), &(fp->v[maior_filho]), tipo_heap);
            descer_no_heap(fp, maior_filho, tipo_heap);
        }
    }
}

Carro extrair_maximo(Heap *fp, int tipo_heap){
    Carro item = *fp->v[0];
    printf("%.2f %.2f %.2f\n", fp->v[0]->valores[0], fp->v[0]->valores[1], fp->v[0]->valores[2]);
    troca(&fp->v[0], &fp->v[fp->vagas_usadas-1], tipo_heap);
    fp->vagas_usadas--;
    descer_no_heap(fp, 0, tipo_heap);
    return item;
}

/*a funcao remover esta em (0)logn*/
void remover_meio_heap(Heap *fp, int tipo_heap, int pos_heap){
    troca(&fp->v[pos_heap], &fp->v[fp->vagas_usadas-1], tipo_heap);
    fp->vagas_usadas--;
    if (pos_heap != 0 && fp->v[pos_heap]->valores[tipo_heap] > fp->v[PAI(pos_heap)]->valores[tipo_heap]){
        subir_no_heap(fp, pos_heap, tipo_heap);
    }
    else{
        descer_no_heap(fp, pos_heap, tipo_heap);
    }

}

int main(){

    scanf("%d", &it);
    scanf("%d", &mc);

    /*criando os vetores do heap*/

    Heap Velociheap, Aceleheap, Contheap;
    Velociheap.vagas_usadas = 0;
    Velociheap.tamanho = mc;
    Velociheap.v = malloc(mc * sizeof(Carro*));
    Aceleheap.vagas_usadas = 0;
    Aceleheap.tamanho = mc;
    Aceleheap.v = malloc(mc * sizeof(Carro*));
    Contheap.vagas_usadas = 0;
    Contheap.tamanho = mc;
    Contheap.v = malloc(mc * sizeof(Carro*));
    Carro *novo_carro, retorno;

    /*O for vai percorrer o numero de iteracoes que o programa quer*/
    for (i = 0; i < it; i++) {
        scanf("%d", &Carros_inseridos);
        scanf("%d", &Carros_escolhidos);
        for (c = 0; c < Carros_inseridos; c++) {
            novo_carro = malloc(sizeof(Carro));
            scanf("%f %f %f", &novo_carro->valores[0], &novo_carro->valores[1], &novo_carro->valores[2]);
            inserir_heap(&Aceleheap, novo_carro, 0);
            inserir_heap(&Velociheap, novo_carro, 1);
            inserir_heap(&Contheap, novo_carro, 2);
        }
        for ( p = 0; p < Carros_escolhidos; p++) {
            scanf("%d", &Heap_escolhido);
            if (Heap_escolhido == 0){
                retorno = extrair_maximo(&Aceleheap, 0);
                remover_meio_heap(&Velociheap, 1, retorno.posicoes[1]);
                remover_meio_heap(&Contheap, 2, retorno.posicoes[2]);
                free(Aceleheap.v[Aceleheap.vagas_usadas]);
            }
            if (Heap_escolhido == 1){
                retorno = extrair_maximo(&Velociheap, 1);
                remover_meio_heap(&Aceleheap, 0, retorno.posicoes[0]);
                remover_meio_heap(&Contheap, 2, retorno.posicoes[2]);
                free(Velociheap.v[Velociheap.vagas_usadas]);
            }
            if (Heap_escolhido == 2){
                retorno = extrair_maximo(&Contheap, 2);
                remover_meio_heap(&Aceleheap, 0, retorno.posicoes[0]);
                remover_meio_heap(&Velociheap, 1, retorno.posicoes[1]);
                free(Contheap.v[Contheap.vagas_usadas]);
            }
        }
    }
    return 0;
}
