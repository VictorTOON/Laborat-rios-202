/*Victor Toon de Araujo - 225231*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *esq, *dir;
} No;
/*essa funcao cria um no novo e adiciona ele na arvore, iniciando esquerda e direita com null*/
No *adiciona_no(No *inicio, int chave) {
    No *novoNo;
    if (inicio == NULL){
        novoNo = malloc(sizeof(No));
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        novoNo->valor = chave;
        return novoNo;
    }
    if (chave < inicio->valor){
        inicio->esq = adiciona_no(inicio->esq, chave);
    }
    else{
        inicio->dir = adiciona_no(inicio->dir, chave);
    }
    return inicio;
}
/*as seguintes funcoes apenas printam nas diferentes ordens, a diferença eh apenas no lugar do print*/
void exibirEmOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esq);
        printf("%d ", pRaiz->valor);
        exibirEmOrdem(pRaiz->dir);
    }
}

void exibirPreOrdem(No *pRaiz){
    if(pRaiz != NULL){
        printf("%d ", pRaiz->valor);
        exibirPreOrdem(pRaiz->esq);
        exibirPreOrdem(pRaiz->dir);
    }
}

void exibirPosOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esq);
        exibirPosOrdem(pRaiz->dir);
        printf("%d ", pRaiz->valor);
    }
}
/*a seguinte funcao calcula o maximo entre dois numeros, pra ajudar a ver qual o diametro certo*/
int maximo(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}
/*uma funcaozinha pra limpar a arvore bem simples*/
void limpa(No *pRaiz){
    if(pRaiz != NULL){
        limpa(pRaiz->esq);
        limpa(pRaiz->dir);
        free(pRaiz);
    }
}
/*essa funcao mede recursivamente a altura, usando a funcao maximo, a cada passada na recursao, ela soma 1, basicamente*/
int medir_altura(No *inicio){
    if (inicio == NULL){
        return 0;
    }
    return 1 + maximo(medir_altura(inicio->esq), medir_altura(inicio->dir));
}
/*essa eh a medir diametro em si, que retorna o maior valor entre a soma das alturas da esquerda e da direita +1 recursivamente entre todos os nos*/
/*nem sempre o diametro na raiz vai ser o maior, entao ele recursivamente olha o diametro nos filhos*/
int medir_diametro(No *inicio){
    if(inicio == NULL){
        return 0;
    }
    int altura_esquerda = medir_altura(inicio->esq), altura_direita = medir_altura(inicio->dir);
    int diametro_esquerda = medir_diametro(inicio->esq), diametro_direita = medir_diametro(inicio->dir);

    return maximo(altura_direita + altura_esquerda + 1, maximo(diametro_esquerda, diametro_direita));
}

int main(){
    /*nos = quantos nos inseri - i eh a contadora do for - diametro eh trivial e chave eh o valor que eu adiciono na arvore*/
    int nos, i, diametro = 0, chave;
    /*tipo eh onde eu guardo o tipo do print da arvore*/
    char tipo[4];
    /*iniciamos como ponteiro*/
    No *inicio;
    scanf("%d %s", &nos, tipo);
    while (nos != 0) {
        inicio = NULL;
        for (i = 0; i < nos; i++) {
            scanf("%d", &chave);
            inicio = adiciona_no(inicio, chave);
        }
        diametro = medir_diametro(inicio);
        printf("Diametro da arvore binaria: %d\n", diametro);
        if(tipo[1] == 'n'){
            exibirEmOrdem(inicio);
            printf("\n");
        }

        if(tipo[1] == 'o'){
            exibirPosOrdem(inicio);
            printf("\n");
        }

        if(tipo[1] == 'r'){
            exibirPreOrdem(inicio);
            printf("\n");
        }
        limpa(inicio);
        scanf("%d %s", &nos, tipo);
    }
    return 0;
}
