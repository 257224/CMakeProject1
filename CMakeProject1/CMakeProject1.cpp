#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5


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


void vyberKina() {
    printf("Vyberte film:\n");
    printf("1. Spider-man 3 \n");
    printf("2. Harry Potter \n");
    printf("3. 3 orisky pro popelku\n");
   
}


void rezervace(char seats[ROWS][COLS]) {
    int row, col;

    printf("Vyberte radek (1-%d): ", ROWS);
    scanf("%d", &row);

    printf("Vyberte cislo mista (1-%d): ", COLS);
    scanf("%d", &col);

    
    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS && seats[row - 1][col - 1] == 'O') {
        seats[row - 1][col - 1] = 'X';
        printf("Misto mate rezervovano!\n");
    } else {
        printf("Omlouvame se, misto uz je obsazeno.\n");
    }
}

int main() {
    char seats[ROWS][COLS]; 

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 'O'; 
        }
    }

    int choice;

    do {
        vyberKina(); 
        displaySedatek(seats); 
        rezervace(seats); 

        printf("Chcete pokracovat? (1 - Ano, 0 - Ne): ");
        scanf("%d", &choice);

    } while (choice != 0);

    printf("Dekujeme za navstevu!\n");

    return 0;
}
