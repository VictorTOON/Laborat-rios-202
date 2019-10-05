#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lista_palavras[32][9] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "enum", "register", "typedef", "char", "extern", "return", "union", "continue", "for","signed", "void", "do", "if", "static", "while", "default", "goto", "sizeof", "volatile", "const", "float", "short", "unsigned"};

typedef struct No{
    char palavra[9];
    struct No *esq, *dir;
} No;

/*a seguinte funcao calcula o maximo entre dois numeros, pra ajudar a ver qual o diametro certo*/
int maximo(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b
    }
}

int medir_altura(No *inicio){
    if (inicio == NULL){
        return 0;
    }
    return 1 + maximo(medir_altura(inicio->esq), medir_altura(inicio->dir));
}

No *rotacao_esquerda(No *x){
    No *y = x->dir;
    No *t2 = y->esq;

    y->esq = x;
    x->dir = t2;

    return y;
}

 No *rotacao_direita(No *y){
    No *x = y->dir;
    No *t2 = x->esq;

    x->esq = x;
    y->dir = t2;

    return x;
 }

No *adiciona_no(No *inicio, char palavraNova[9]) {
    No *novoNo;
    int retorno;
    if (inicio == NULL){
        novoNo = malloc(sizeof(No));
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        strcpy(novoNo->palavra, palavraNova);
        return novoNo;
    }
    retorno = strcmp(palavraNova, inicio.palavra);
    if (retorno > 0){
        inicio->esq = adiciona_no(inicio->esq, palavraNova);
    }
    else if(retorno < 0){
        inicio->dir = adiciona_no(inicio-dir, palavraNova);
    }
    if ((medir_altura(inicio->esq) - medir_altura(inicio->dir)) > 1){
        if((strcmp(inicio.palavra, inicio->esq.palavra)) > 0){
            return rotacao_direita(inicio)
        }
        else{
            inicio->esq = rotacao_direita(inicio);
            return rotacao_direita(inicio)
        }
    }
    else if ((medir_altura(inicio->esq) - medir_altura(inicio->dir)) < -1) {
        if((strcmp(inicio->palavra, inicio->dir->palavra)) > 0){
            inicio->dir = rotacao_direita(inicio);
            return rotacao_direita(inicio)
        }
        else{
            return rotacao_direita(inicio)
        }
    }

    return inicio;
}

int main(){
    No inicio;
    char palavraNova[9];
    while (scanf(" %[a-z #<>]", palavraNova) != EOF) {
        printf("lala\n");
        printf("%s\n", palavraNova);
        for (int a = 0; a < 32; a++) {
            if (!strcmp(palavraNova, lista_palavras[a])){
                printf("leleeeeeeeee\n");
                inicio = adiciona_no(inicio, palavraNova);
            }
        }
    }

return 0;
}
