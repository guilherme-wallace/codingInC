#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LETTERS 20
#define ALTURA_DA_LETRA 5
#define LARGURA_DA_LETRA 5

const char LETTERS[26][ALTURA_DA_LETRA][LARGURA_DA_LETRA + 1] = {
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

int char_to_index(char c) {
    return toupper(c) - 'A';
}

void print_led_word(const char *word) {
    int length = strlen(word);
    for (int row = 0; row < ALTURA_DA_LETRA; row++) {
        for (int i = 0; i < length; i++) {
            int index = char_to_index(word[i]);
            if (index < 0 || index >= 26) {
                printf("N/A");
            } else {
                printf("%s ", LETTERS[index][row]);
            }
        }
        printf("\n");
    }
}

int main() {
    char word[MAX_LETTERS + 1];
    int valid;
    do {
        valid = 1;
        printf("Digite uma palavra de no máximo %d letras, apenas de A-Z): ", MAX_LETTERS);
        scanf("%s", word);
        for (int i = 0; word[i] != '\0'; i++) {
            if (!isalpha(word[i])) {
                valid = 0;
                printf("Erro: A palavra deve conter apenas letras de A-Z.\n");
                break;
            }
        }
    } while (!valid);
    
    print_led_word(word);
    
    return 0;
}
