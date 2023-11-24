#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Функция для отображения текущего состояния мест в зале
void displaySeats(char seats[ROWS][COLS]) {
    printf("\n\nМеста в зале:\n\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Функция для выбора фильма
void chooseMovie() {
    printf("Выберите фильм:\n");
    printf("1. Фильм 1\n");
    printf("2. Фильм 2\n");
    // Добавьте другие фильмы при необходимости
}

// Функция для резервации места
void reserveSeat(char seats[ROWS][COLS]) {
    int row, col;

    printf("Введите номер ряда (1-%d): ", ROWS);
    scanf("%d", &row);

    printf("Введите номер места (1-%d): ", COLS);
    scanf("%d", &col);

    // Проверка наличия места и его резервация
    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS && seats[row - 1][col - 1] == 'O') {
        seats[row - 1][col - 1] = 'X';
        printf("Место успешно зарезервировано!\n");
    } else {
        printf("Извините, это место уже занято или недопустимый выбор. Пожалуйста, выберите другое место.\n");
    }
}

int main() {
    char seats[ROWS][COLS]; // Массив для хранения состояния мест в зале

    // Инициализация мест в зале (предполагается, что все места свободны в начале)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 'O'; // 'O' представляет свободное место
        }
    }

    int choice;

    do {
        chooseMovie(); // Пользователь выбирает фильм
        displaySeats(seats); // Отображается текущее состояние мест в зале
        reserveSeat(seats); // Пользователь резервирует место

        printf("Желаете продолжить? (1 - Да, 0 - Нет): ");
        scanf("%d", &choice);

    } while (choice != 0);

    printf("Спасибо за визит в наш кинотеатр!\n");

    return 0;
}
