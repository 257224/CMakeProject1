#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RADY 10
#define SLOUPCE 10

struct Film {
    char name[50];
    char seats[RADY][SLOUPCE];
};
void displaySedatek(char seats[RADY][SLOUPCE]) {
    printf("\n\nVolne mista:\n\n");

    for (int i = 0; i < RADY; i++) {
        for (int j = 0; j < SLOUPCE; j++) {
            printf("%c ", seats[i][j]);
        }
        printf("|"); 
        printf(" obrazovka \n");
    }
    printf("\n");
}
void vyberKina(struct Film *films, int count, int *choice) {
    printf("Vyberte film:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, films[i].name);
    }

    scanf("%d", choice);
    if (*choice < 1 || *choice > count) {
        printf("Neplatny vyber filmu.\n");
        *choice = 0;
    }
}
void rezervace(struct Film *film) {
    int row, col;

    printf("Vyberte radek (1-%d): ", RADY);
    scanf("%d", &row);

    printf("Vyberte cislo mista (1-%d): ", SLOUPCE);
    scanf("%d", &col);

    if (row >= 1 && row <= RADY && col >= 1 && col <= SLOUPCE && film->seats[row - 1][col - 1] == 'O') {
        film->seats[row - 1][col - 1] = 'X';
        printf("Misto mate rezervovano pro film \"%s\"!\n", film->name);
    } else {
        printf("Omlouvame se, misto uz je obsazeno nebo neplatny vyber filmu.\n");
    }
}
int main() {
    struct Film films[3];

    strcpy(films[0].name, "Spider-man 3");
    strcpy(films[1].name, "Harry Potter");
    strcpy(films[2].name, "3 orisky pro popelku");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < RADY; j++) {
            for (int k = 0; k < SLOUPCE; k++) {
                films[i].seats[j][k] = 'O';
            }
        }
    }
    int choice;
    do {
        vyberKina(films, 3, &choice);
        if (choice != 0) {
            displaySedatek(films[choice - 1].seats);
            rezervace(&films[choice - 1]);
        }
        printf("Chcete pokracovat? (1 - Ano, 0 - Ne): ");
        scanf("%d", &choice);
    } while (choice != 0);
    printf("Dekujeme za navstevu!\n");
    return 0;
}
