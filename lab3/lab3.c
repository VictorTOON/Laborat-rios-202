#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No{
    long int cpf;
    char nome[41];
    char email[31];
    int idade;
    struct No *prox;
}No;
/*  */
No *criar_no(No aluno){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        exit(1);
    }
    novo->cpf = aluno.cpf;
    strcpy(novo->nome, aluno.nome);
    strcpy(novo->email, aluno.email);
    novo->idade = aluno.idade;
    novo->prox = NULL;
    return(novo);
}

void inserir_lista(No aluno, No **No_passado){
    No *novoNo;
    if ((*No_passado) == NULL){
        novoNo = criar_no(aluno);
        (*No_passado) = novoNo;
    }
    else{
        if (aluno.idade < (*No_passado)->idade){
            novoNo = criar_no(aluno);
            novoNo->prox = (*No_passado);
            (*No_passado) = novoNo;
        }
        else if (aluno.idade == (*No_passado)->idade && aluno.cpf < (*No_passado)->cpf){
            novoNo = criar_no(aluno);
            novoNo->prox = (*No_passado);
            (*No_passado) = novoNo;
        }
        else{
            inserir_lista(aluno, &((*No_passado)->prox));
        }
    }
}

void printa_limpa(No *inicio){
    if (inicio!=NULL){
        printf("%011ld, %s, %s, %d \n", inicio->cpf, inicio->nome, inicio->email, inicio->idade);
        printa_limpa(inicio->prox);
        free(inicio);
    }

}

int main(){
    int contadora = 0,i;
    No aluno;
    No *inicio = NULL;
    while(scanf("%ld,%[^,],%[^,],%d",&aluno.cpf, aluno.nome, aluno.email, &aluno.idade)!= EOF){
        contadora++;
        inserir_lista(aluno, &inicio);
    }
    for (i=0;i<contadora;i++){
        printf("%011ld, %s, %s, %d \n", inicio->cpf, inicio->nome, inicio->email, inicio->idade);
        inicio = inicio->prox;
    }

return 0;
}
