#include <stdio.h>

double met_babi(double numero) {
    if (numero == 0) {
        return 0;
    }
    double nvNumero= numero / 2.0;
    double aux;
    while (1) {
        aux = nvNumero;
        nvNumero = (nvNumero + numero / nvNumero) / 2.0;

        if ((aux - nvNumero < 0.00001) && (nvNumero - aux < 0.00001)) {
            break;
        }
    }
     return ((int)(nvNumero * 100 + 0.5)) / 100.0;
}

double pegaDouble() {
    double numero;
    while (1) {
        if (scanf("%lf", &numero) == 1) {
            return numero;
        } else {
            printf("Favor informar um número válido! ");

            while (getchar() != '\n');
        }
    }
}

double quadrado(double numero) {
    return numero * numero;
}

double distancia(double x1, double y1, double x2, double y2) {
    double distanciaX = x2 - x1;
    double distanciaY = y2 - y1;
    return met_babi(quadrado(distanciaX) + quadrado(distanciaY));
}

int main() {
    int opcao;
    double ladoA, ladoB, ladoC, x1, y1, x2, y2, x3, y3;

    printf("Digite 1 sera informado os lados do triangulo, \nou 2 se sera informado as coordenadas cartesianas: \n");
    while (1) {
        if (scanf("%d", &opcao) == 1 && (opcao == 1 || opcao == 2)) {
            break;
        }
        printf("Entrada invalida. Favor, insirir 1 ou 2: \n");
        
        while (getchar() != '\n');
    }

    if (opcao == 1) {
        printf("Digite o lado a: ");
        ladoA = pegaDouble();
        printf("Digite o lado b: ");
        ladoB = pegaDouble();
        printf("Digite o lado c: ");
        ladoC = pegaDouble();
        printf("Verificando o triangulo de  acordo com os lados. \n");
    } else {
        printf("Digite x1: ");
        x1 = pegaDouble();
        printf("Digite y1: ");
        y1 = pegaDouble();
        printf("Digite x2: ");
        x2 = pegaDouble();
        printf("Digite y2: ");
        y2 = pegaDouble();
        printf("Digite x3: ");
        x3 = pegaDouble();
        printf("Digite y3: ");
        y3 = pegaDouble();

        ladoA = distancia(x1, y1, x2, y2);
        ladoB = distancia(x2, y2, x3, y3);
        ladoC = distancia(x3, y3, x1, y1);
        printf("Verificando o triangulo de  acordo com as coordenadas. \n");
    }

    if ((ladoA + ladoB > ladoC) && (ladoB + ladoC > ladoA) && (ladoC + ladoA > ladoB)) {
        if (ladoA == ladoB && ladoB == ladoC) {
            printf("Triangulo: Equilatero.\n");
        } else if (ladoA == ladoB || ladoB == ladoC || ladoA == ladoC) {
            printf("Triangulo: Isosceles.\n");
        } else {
            printf("Triangulo: Escaleno.\n");
        }
    

        if (quadrado(ladoA) + quadrado(ladoB) == quadrado(ladoC) || 
            quadrado(ladoB) + quadrado(ladoC) == quadrado(ladoA) || 
            quadrado(ladoC) + quadrado(ladoA) == quadrado(ladoB)) {
            printf("O triangulo e retangulo.\n");
        } else {
            printf("O triangulo nao e retangulo.\n");
        }

    } else {
        printf("Os dados informados não formam um triandulo");
    }

    return 0;
}
