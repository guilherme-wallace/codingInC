#include <stdio.h>

int pegaInteiro() {
    int numero;
    while (1) {
        if (scanf("%d", &numero) == 1) {
            return numero;
        } else {
            printf("Favor informar um número inteiro! \n");
            while (getchar() != '\n');
        }
    }
}

int mmc(int a, int b) {
    int maior = a > b ? a : b;
    while (maior % a || maior % b) maior++;
    return maior;
}

int calculaMMC(int *listaNumeros, int n) {
    int resultado = listaNumeros[0];
    for (int i = 1; i < n; i++)
        resultado = mmc(resultado, listaNumeros[i]);
    return resultado;
}

void ehPrimos(int numeroP) {
    printf("O fator é: ");
    for (int i = 2; numeroP > 1; i++) {
        while (numeroP % i == 0) {
            printf("%d ", i);
            numeroP /= i;
        }
    }
    printf("\n");
}

int main() {
    int qtd;
    printf("Quantos números? ");
    qtd = pegaInteiro();

    int listaNumeros[qtd];
    printf("Digite os números: \n");
    for (int i = 0; i < qtd; i++) {
        listaNumeros[i] = pegaInteiro();
    }

    int resultado = calculaMMC(listaNumeros, qtd);
    printf("O MMC é: %d\n", resultado);
    ehPrimos(resultado);
    
    return 0;
}
