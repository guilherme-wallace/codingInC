#include <stdio.h>
#include <stdlib.h>

// Faz o MMC entre 2 numeros
int mmc(int priNum, int segNum) {
    int maiorNum;
    if (priNum > segNum) {
        maiorNum = priNum;
    } else {
        maiorNum = segNum;
    }

    int mmc = maiorNum;
    while ((mmc % priNum != 0) || (mmc % segNum != 0)) {
        mmc = mmc + maiorNum;
    }
    return mmc;
}

// Faz o MMC do array
int arrayMMC(int numeros[], int qtdNum) {
    int resultado = numeros[0];
    for (int i = 1; i < qtdNum; i++) {
        resultado = mmc(resultado, numeros[i]);
    }
    return resultado;
}

// Pega o número digitado e confere se ele e inteiro
int pegaInteiro() {
    int numero;
    while (1) {
        if (scanf("%d", &numero) == 1) {
            return numero;
        } else {
            printf("Favor informar um numero interiro! ");

            while (getchar() != '\n');
        }
    }
}

int main() {
    int qtdNum;
    printf("MMC de quantos numeros? ");
    qtdNum = pegaInteiro();

    if (qtdNum < 2) {
        printf("Precisa ser informado no minimo 2 numeros.\n");
        return 1;
    }

    // Alocação dinâmica do array
    // substitui o int numeros[qtdNum];
    int *numeros = (int *)malloc(qtdNum * sizeof(int));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os %d numeros:\n", qtdNum);
    printf("Obs: A cada numero inserido aperte Enter. \n\n");
    for (int i = 0; i < qtdNum; i++) {
        numeros[i] = pegaInteiro();
    }

    int resultado = arrayMMC(numeros, qtdNum);
    printf("O MMC desses numeros e: %d\n", resultado);

    // Liberar a memória alocada
    free(numeros);

    return 0;
}
