#include <stdio.h>

// Pega o número digitado e confere se ele é inteiro
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
    int m = a > b ? a : b;
    while (m % a || m % b) m++;
    return m;
}

int calculaMMC(int *nums, int n) {
    int res = nums[0];
    for (int i = 1; i < n; i++)
        res = mmc(res, nums[i]);
    return res;
}

void primos(int num) {
    printf("Os primos são: ");
    for (int i = 2; num > 1; i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    printf("\n");
}

int main() {
    int qtd;
    printf("Quantos números? ");
    qtd = pegaInteiro();
    if (qtd < 2) return 1;

    int nums[qtd];
    printf("Digite os números: \n");
    for (int i = 0; i < qtd; i++) {
        nums[i] = pegaInteiro();
    }

    int resultado = calculaMMC(nums, qtd);
    printf("O MMC é: %d\n", resultado);
    primos(resultado);
    
    return 0;
}
