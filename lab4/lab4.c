#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;

No *criar_no(int numero){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        exit(1);
    }
    novo->valor = numero;
    novo->prox = NULL;
    return(novo);
}

void remove_lista(int numero, No **No_passado){
    No *noAux;
    if (*No_passado == NULL){
        return;
    }
    if ((*No_passado)->valor == numero){
        noAux = *No_passado;
        *No_passado = (*No_passado)->prox;
        free(noAux);
        return;
    }
    else if ((*No_passado)->prox == NULL || (*No_passado)->prox->valor > numero){
        return;
    }
    else if((*No_passado)->prox->valor == numero){
        noAux = (*No_passado)->prox;
        (*No_passado)->prox = (*No_passado)->prox->prox;
        free(noAux);
        return;
    }
    else{
        remove_lista(numero, &((*No_passado)->prox));
    }
}


void inserir_lista(int numero, No **No_passado){
    No *novoNo;
    if ((*No_passado) == NULL){
        novoNo = criar_no(numero);
        (*No_passado) = novoNo;
    }
    else{
        if (numero < (*No_passado)->valor){
            novoNo = criar_no(numero);
            novoNo->prox = (*No_passado);
            (*No_passado) = novoNo;
        }
        else if (numero == (*No_passado)->valor){
            return;
        }
        else{
            inserir_lista(numero, &((*No_passado)->prox));
        }
    }
}


int verifica_numero(int numero, No *No_passado){
    int retorno = 0;
    if (No_passado == NULL){
        return 0;
    }
    else if (No_passado->valor == numero){
        retorno = 1;
    }
    if (No_passado->prox == NULL || retorno == 1){
        return retorno;
    }
    else{
        retorno = verifica_numero(numero, No_passado->prox);
        return retorno;
    }
}

void interseccao(No **lista1, No **lista2){
    int verifica = 0;
    if(*lista1 == NULL){
        return;
    }
    verifica = verifica_numero((*lista1)->valor, *lista2);
    if (verifica == 0){
        remove_lista((*lista1)->valor, lista1);
        interseccao(lista1, lista2);
    }
    else if((*lista1)->prox == NULL){
        return;
    }
    else{
        interseccao(&((*lista1)->prox), lista2);
    }
}

void uniao(No **lista1, No **lista2){
    if(*lista2 == NULL){
        return;
    }
    inserir_lista((*lista2)->valor, lista1);
    uniao(lista1, &((*lista2)->prox));
}

void subtracao(No **lista1, No **lista2){
    if(*lista2 == NULL){
        return;
    }
    remove_lista((*lista2)->valor, lista1);
    subtracao(lista1, &((*lista2)->prox));
}


void printa(No *inicio){
    if (inicio!=NULL){
        if (inicio->prox == NULL){
        printf("%d", inicio->valor);
        }
        else{
            printf("%d,", inicio->valor);
            printa(inicio->prox);
        }
    }

}

void limpa(No *inicio){
    if (inicio!=NULL){
        limpa(inicio->prox);
        free(inicio);
    }

}

int main(){
    No *lista1 = NULL;
    No *lista2 = NULL;
    int numero_lido, numero_conjunto, SimNao;
    char leitura = 'a';

    while (leitura != 's') {
        scanf("%c", &leitura);
        /*inserir*/
        if (leitura == 'i') {
            scanf("%d %d\n", &numero_lido, &numero_conjunto);
            if (numero_conjunto == 1){
                inserir_lista(numero_lido, &lista1);
            }
            else if (numero_conjunto == 2){
                inserir_lista(numero_lido, &lista2);
            }
        }
        /*ver se pertence*/
        else if (leitura == 'p') {
            scanf("%d %d\n", &numero_lido, &numero_conjunto);
            if (numero_conjunto == 1){
                SimNao = verifica_numero(numero_lido, lista1);
                if(SimNao == 1){
                    printf("SIM\n");
                }
                else{
                    printf("NAO\n");
                }
            }
            if (numero_conjunto == 2){
                SimNao = verifica_numero(numero_lido, lista2);
                if(SimNao == 1){
                    printf("SIM\n");
                }
                else{
                    printf("NAO\n");
                }
            }
        }
        /*remove*/
        else if (leitura == 'r') {
            scanf("%d %d\n", &numero_lido, &numero_conjunto);
            if (numero_conjunto == 1){
                remove_lista(numero_lido, &lista1);
            }
            else if (numero_conjunto == 2){
                remove_lista(numero_lido, &lista2);
            }
        }
        /*união*/
        else if (leitura == 'u') {
            scanf("\n");
            uniao(&lista1, &lista2);
        }
        /*intersecção*/
        else if (leitura == 'x') {
            scanf("\n");
            interseccao(&lista1,&lista2);
        }
        /*subtração*/
        else if (leitura == 'b') {
            scanf("\n");
            subtracao(&lista1, &lista2);
        }
        printf("{");
        printa(lista1);
        printf("}\n");
        printf("{");
        printa(lista2);
        printf("}\n");
    }
limpa(lista1);
limpa(lista2);

return 0;
}
