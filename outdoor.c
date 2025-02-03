#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LETRAS 20
#define ALTURA_LETRA 5
#define LARGURA_LETRA 5

const char LETRAS[26][ALTURA_LETRA][LARGURA_LETRA + 1] = {
    {"  #  ", " # # ", "#####", "#   #", "#   #"}, // A
    {"#### ", "#   #", "#### ", "#   #", "#### "}, // B
    {" ####", "#    ", "#    ", "#    ", " ####"}, // C
    {"#### ", "#   #", "#   #", "#   #", "#### "}, // D
    {"#####", "#    ", "#####", "#    ", "#####"}, // E
    {"#####", "#    ", "#####", "#    ", "#    "}, // F
    {" ####", "#    ", "#  ##", "#   #", " ####"}, // G
    {"#   #", "#   #", "#####", "#   #", "#   #"}, // H
    {" ### ", "  #  ", "  #  ", "  #  ", " ### "}, // I
    {"    #", "    #", "    #", "#   #", " ### "}, // J
    {"#   #", "#  # ", "###  ", "#  # ", "#   #"}, // K
    {"#    ", "#    ", "#    ", "#    ", "#####"}, // L
    {"#   #", "## ##", "# # #", "#   #", "#   #"}, // M
    {"#   #", "##  #", "# # #", "#  ##", "#   #"}, // N
    {" ### ", "#   #", "#   #", "#   #", " ### "}, // O
    {"#### ", "#   #", "#### ", "#    ", "#    "}, // P
    {" ### ", "#   #", "# # #", "#  ##", " ####"}, // Q
    {"#### ", "#   #", "#### ", "#  # ", "#   #"}, // R
    {" ####", "#    ", " ### ", "    #", "#### "}, // S
    {"#####", "  #  ", "  #  ", "  #  ", "  #  "}, // T
    {"#   #", "#   #", "#   #", "#   #", " ### "}, // U
    {"#   #", "#   #", "#   #", " # # ", "  #  "}, // V
    {"#   #", "#   #", "# # #", "## ##", "#   #"}, // W
    {"#   #", " # # ", "  #  ", " # # ", "#   #"}, // X
    {"#   #", " # # ", "  #  ", "  #  ", "  #  "}, // Y
    {"#####", "   # ", "  #  ", " #   ", "#####"}  // Z
};

int caractere_para_indice(char c) {
    return toupper(c) - 'A';
}

void exibir_palavra_led(const char *palavra) {
    int tamanho = strlen(palavra);
    for (int linha = 0; linha < ALTURA_LETRA; linha++) {
        for (int i = 0; i < tamanho; i++) {
            int indice = caractere_para_indice(palavra[i]);
            if (indice < 0 || indice >= 26) {
                printf("N/A");
            } else {
                printf("%s ", LETRAS[indice][linha]);
            }
        }
        printf("\n");
    }
}

int main() {
    char palavra[MAX_LETRAS + 1];
    int valido;
    do {
        valido = 1;
        printf("Digite uma palavra de no máximo %d letras, apenas de A-Z: ", MAX_LETRAS);
        scanf("%s", palavra);
        for (int i = 0; palavra[i] != '\0'; i++) {
            if (!isalpha(palavra[i])) {
                valido = 0;
                printf("Erro: A palavra deve conter apenas letras de A-Z.\n");
                break;
            }
        }
    } while (!valido);
    
    exibir_palavra_led(palavra);
    
    return 0;
}
