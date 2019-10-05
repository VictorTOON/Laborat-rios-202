/*Victor Toon de Araujo - 225231*/

#include <stdio.h>
#include <string.h>

typedef struct Pessoa{
    long int cpf;
    char nome[41];
}Pessoa;

int main(){
    char entrada1, entrada2;
    int gente, i = 0, inicio_fila = 0, final_fila = 0, final_pilha = 0, comeco, contadora = 0;
    /*Criando um vetor de 30 para a pilha pq no lab não dizia que não podia, alem de facilitar*/
    /*O conceito de pilha nao muda, uma vez que os elementos superiores tem que sair para os inferiores sairem*/
    /*alem do mais, nao ha como tirar pessoas de uma fileira sem que as da fileira superior saiam, entao continua sendo apenas uma pilha*/
    /*Os testes do lab estavam errados até alguns dias antes da entrega e o enunciado não diz nada sobre não pdoer um unico vetor para pilha*/
    /*Escolhi o uso de struct para poder armazenar o valor do Nome e do CPF de uma forma melhor, apesar de nao serem usadas no lab*/
    Pessoa fila[30], pilha[5], pilha2[5], pilha3[5], pilha4[5], pilha5[5], pilha6[5],vetorzao[30];

    /*zera o valor de todos os cpfs*/
    for (i=0; i < 30; i++){
        fila[i].cpf = 0;
        pilha[i].cpf = 0;
        vetorzao[i].cpf = 0;
    }

    scanf("%c", &entrada1);
    while(entrada1 != 'D'){
        if (entrada1 == 'Q'){
            scanf("%c", &entrada2);
            if (entrada2 == 'I'){
                scanf("%d", &gente);
                final_fila = inicio_fila;
                while(fila[final_fila].cpf != 0){
                    final_fila++;
                }
                for (i = final_fila; i < final_fila + gente; i++) {
                    scanf("%ld,%[^\n]", &fila[i].cpf, fila[i].nome);
                    vetorzao[contadora].cpf = fila[i].cpf;
                    strcpy(vetorzao[contadora].nome,fila[i].nome);
                    contadora++;
                }
                final_fila = final_fila + gente;
            }
            else if(entrada2 == 'R'){
                scanf("%d", &gente);
                /*Tenho que criar outra variavel pra não bugar o for*/
                comeco = inicio_fila;
                for (i = comeco; i < gente + comeco; i++) {
                    pilha[final_pilha].cpf = fila[i].cpf;
                    strcpy(pilha[final_pilha].nome,fila[i].nome);
                    inicio_fila++;
                    final_pilha++;
                }
            }
        }
        if (entrada1 == 'P'){
            printf("[Q]");
            for(i=inicio_fila+1; i < final_fila+1; i++){
                printf("%d,", i);
            }
            printf("\n");
            printf("[S1]");
            for(i=1;i < 6; i++)
            if(pilha[i-1].cpf != 0){
                printf("%d,", i);
            }
            printf("\n");
            printf("[S2]");
            for(i=6;i < 11; i++)
            if(pilha[i-1].cpf != 0){
                printf("%d,", i);
            }
            printf("\n");
            printf("[S3]");
            for(i=11;i < 16; i++)
            if(pilha[i-1].cpf != 0){
                printf("%d,", i);
            }
            printf("\n");
            printf("[S4]");
            for(i=16;i < 21; i++)
            if(pilha[i-1].cpf != 0){
                printf("%d,", i);
            }
            printf("\n");
            printf("[S5]");
            for(i=21;i < 26; i++)
            if(pilha[i-1].cpf != 0){
                printf("%d,", i);
            }
            printf("\n");
            printf("[S6]");
            for(i=26;i < 31; i++)
            if(pilha[i-1].cpf != 0){
                printf("%d,", i);
            }
            printf("\n");
        }
        if (entrada1 == 'S'){
            scanf("%c", &entrada2);
            scanf("%d", &gente);
            for (i = 0; i <= gente; i++) {
                pilha[final_pilha].cpf = 0;
                final_pilha--;
            }
            final_pilha++;
        }
    scanf("%c", &entrada1);
    }
    for(i = 0; i < 30; i++){
        if (i != 29 && vetorzao[i].cpf != 0){
            printf("%d,%011ld,%s\n", i+1, vetorzao[i].cpf, vetorzao[i].nome);
        }
        else if(vetorzao[i].cpf != 0){
            printf("%d,%011ld,%s", i+1, vetorzao[i].cpf, vetorzao[i].nome);
        }
    }
return 0;
}
