#include <stdio.h>
#include <stdlib.h>

/*funcao pra transformar pra binario*/

int binario(int numero){
    int binario = 0, potencia = 1, bit;
    while (numero > 0){
        bit = numero % 2;
        numero = numero / 2;
        binario = binario + (bit * potencia);
        potencia = potencia * 10;
    }
    return (binario);
}

/*funcao pra transformar pra decimal*/

int decimal(int numero){
    int decimal = 0, potencia = 1, bit;
    while(numero > 0){
        bit = numero % 10;
        numero = numero / 10;
        decimal = decimal + (bit * potencia);
        potencia = potencia * 2;
    }
    return (decimal);
}

int main(){

    char filtro[2];
    int tamanho1, tamanho2, tonMax, i, tamanhoTotal, contadora, letra1, letra2;
    char mensagem;

    /*escaneia as informacoes iniciais*/


    scanf("%s", filtro);
    scanf("%d", &tamanho1);
    scanf("%d", &tamanho2);
    scanf("%d", &tonMax);

    int *matriz;

    tamanhoTotal = tamanho1 * tamanho2;

    /*cria a matriz em um vetor unico com malloc*/

    matriz = malloc(tamanhoTotal * sizeof(int));

    for (i=0; i < tamanhoTotal; i++){
        scanf("%d", &matriz[i]);
        }

    contadora = 0;
    letra1 = 0;
    letra2 = 0;
        /* aqui, a contadora serve pra eu saber quando eu chego em 4 numeros pra fazer um binario*/
    for(i = 0; i < tamanhoTotal; i++){
        contadora = contadora + 1;
        /*pega as duas ultimas casas do binariio*/
        letra1 = binario(matriz[i])%100;
        /*joga os dois ultimos digitos lá pra esquerda e assim em diante*/
        if (contadora == 1){
            letra2 = letra2 + letra1*1000000;
        }
        if (contadora == 2){
            letra2 = letra2 + letra1*10000;
        }
        if (contadora == 3){
            letra2 = letra2 + letra1*100;
        }
        if (contadora == 4){

            letra2 = letra2 + letra1;
            letra1 = decimal(letra2);
            /*trasnforma em char o valor que eu encontrei*/
            mensagem = (char)letra1;
            /*para no \0*/
            if (mensagem == '\0'){
                break;
            }
            /*printa o char*/
            printf("%c", mensagem);
            contadora = 0;
            letra1 = 0;
            letra2 = 0;
        }
    }
    /*Estou liberando espaco pq vc gosta de espaco no pc sobrando, seu gado*/
    free(matriz);
    return 0;
}
