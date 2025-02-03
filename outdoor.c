#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LETTERS 20 // Número máximo de letras na palavra
#define LETTER_HEIGHT 5 // Altura das letras
#define LETTER_WIDTH 5  // Largura das letras

// Tabela de caracteres para letras de A a Z
const char LETTERS[26][LETTER_HEIGHT][LETTER_WIDTH + 1] = {
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

// Captura a ltra de acondo com o indice da tabela (A=0, B=1, ... Z=25)
int char_to_index(char c) {
    return toupper(c) - 'A';
}

// Imprimir a palavra usando a converção. 
void print_led_word(const char *word) {
    int length = strlen(word);
    for (int row = 0; row < LETTER_HEIGHT; row++) {
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
