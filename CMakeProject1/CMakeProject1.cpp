#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

struct Film {
    char name[50];
    char seats[ROWS][COLS];
};

void displaySedatek(char seats[ROWS][COLS]) {
    printf("\n\nVolne mista:\n\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void vyberKina(struct Film *film) {
    printf("Vyberte film:\n");
    printf("1. Spider-man 3 \n");
    printf("2. Harry Potter \n");
    printf("3. 3 orisky pro popelku\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(film->name, "Spider-man 3");
            break;
        case 2:
            strcpy(film->name, "Harry Potter");
            break;
        case 3:
            strcpy(film->name, "3 orisky pro popelku");
            break;
        default:
            printf("Neplatny vyber filmu.\n");
            break;
    }
}

void rezervace(struct Film *film) {
    int row, col;

    printf("Vyberte radek (1-%d): ", ROWS);
    scanf("%d", &row);

    printf("Vyberte cislo mista (1-%d): ", COLS);
    scanf("%d", &col);

    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS && film->seats[row - 1][col - 1] == 'O') {
        film->seats[row - 1][col - 1] = 'X';
        printf("Misto mate rezervovano pro film \"%s\"!\n", film->name);
    } else {
        printf("Omlouvame se, misto uz je obsazeno nebo neplatny vyber filmu.\n");
    }
}

int main() {
    struct Film film;
    strcpy(film.name, "");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            film.seats[i][j] = 'O';
        }
    }

    int choice;

    do {
        vyberKina(&film);
        displaySedatek(film.seats);
        rezervace(&film);

        printf("Chcete pokracovat? (1 - Ano, 0 - Ne): ");
        scanf("%d", &choice);

    } while (choice != 0);

    printf("Dekujeme za navstevu!\n");

    return 0;
}
