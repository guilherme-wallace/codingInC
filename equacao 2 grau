#include <stdio.h>

double met_babi(double numero) {
    if (numero == 0) {
        return 0;
    }
    double nvNumero = numero / 2.0;
    double aux;
    while (1) {
        aux = nvNumero;
        nvNumero = (nvNumero + numero / nvNumero) / 2.0;

        if ((aux - nvNumero < 0.00001) && (nvNumero - aux < 0.00001)) {
            break;
        }
    }
    return ((int)(nvNumero * 1000 + 0.5)) / 1000.0;
}

double pegaDouble() {
    double numero;
    while (1) {
        if (scanf("%lf", &numero) == 1) {
            return numero;
        } else {
            printf("Favor informar um numero valido! ");
            
            while (getchar() != '\n');
        }
    }
}

int main() {
    double a, b, c, delta, x1, x2;
    printf("Equacao do 2 grau. \n --  ax^2 + bx + c = 0  -- \n\n");
    
    printf("Informe o valor a: ");
    a = pegaDouble();
    while (a == 0) {
        printf("a Tem que ser diferente de 0.\n");
        printf("Informe novamente o valor de a: ");
        a = pegaDouble();
    }
    
    printf("Informe o valor de b: ");
    b = pegaDouble();
    
    printf("Informe o valor de c: ");
    c = pegaDouble();
    
    delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("A equacao nao possui raizes reais.\n");
    } else {
        double deltaFim = met_babi(delta);
        x1 = (-b + deltaFim) / (2 * a);
        x2 = (-b - deltaFim) / (2 * a);

        printf("As raizes da equacao são:\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }

    return 0;
}
