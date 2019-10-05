#include <stdio.h>
#include <math.h>

int main() {
	int filtro1[3][3] = {{1,0,-1}, {2,0,-2}, {1,0,-1}}, filtro2[3][3] = {{1,2,1}, {0,0,0}, {-1,-2,-1}};
	int matriz[98][130], matrizAux[96][128], i, j, k, l, x, y;
	for (i=0; i < 98; i++){
		for (j=0; j<130; j	++){
			matriz[i][j] = 0;
/*coloca os zeros na matriz toda*/
		}
	}
	for (k=1; k<97; k++){
		for (l=1; l<129; l++){
			scanf("%d", &matriz[k][l]);
		}
/*coloca as entradas na matriz*/
	}	
	for (k=1; k<97; k++){
		for (l=1; l<129; l++){
			x = matriz[k-1][l-1]*filtro1[0][0] + matriz[k-1][l]*filtro1[0][1] + matriz[k-1][l+1]*filtro1[0][2] + matriz[k][l-1]*filtro1[1][0] + matriz[k][l]*filtro1[1][1] + matriz[k][l+1]*filtro1[1][2] + matriz[k+1][l-1]*filtro1[2][0] + matriz[k+1][l]*filtro1[2][1] + matriz[k+1][l+1]*filtro1[2][2];
			y = matriz[k-1][l-1]*filtro2[0][0] + matriz[k-1][l]*filtro2[0][1] + matriz[k-1][l+1]*filtro2[0][2] + matriz[k][l-1]*filtro2[1][0] + matriz[k][l]*filtro2[1][1] + matriz[k][l+1]*filtro2[1][2] + matriz[k+1][l-1]*filtro2[2][0] + matriz[k+1][l]*filtro2[2][1] + matriz[k+1][l+1]*filtro2[2][2];
			x = x*x;
			y = y*y;
			matrizAux[k][l] = sqrt(x+y);
			printf("%d ", matrizAux[k][l]);
		}
	printf("\n");
		
/*coloca as entradas na matriz auxiliar*/
	}	
	return 0;	
}
