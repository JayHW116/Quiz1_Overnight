#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isLoShuMagicSquare(int square[3][3]) {
    int sum = square[0][0] + square[0][1] + square[0][2];

    for (int i = 0; i < 3; i++) {
        if (square[i][0] + square[i][1] + square[i][2] != sum ||
            square[0][i] + square[1][i] + square[2][i] != sum) {
            return 0;
        }
    }

    if ((square[0][0] + square[1][1] + square[2][2] != sum) ||
        (square[0][2] + square[1][1] + square[2][0] != sum)) {
        return 0;
    }

    return 1;
}

void generateLoShuMagicSquare() {
    int count = 0, square[3][3], used[10] = {0};
    
    srand(time(0));

    while (1) {
        count++;
        for (int i = 1; i <= 9; i++) used[i] = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num;
                do {
                    num = (rand() % 9) + 1;
                } while (used[num]);
                used[num] = 1;
                square[i][j] = num;
            }
        }

        if (isLoShuMagicSquare(square)) {
            printf("Lo Shu Magic Square found after %d attempts:\n", count);
            printf("[%d %d %d]\n[%d %d %d]\n[%d %d %d]\n",
          square[0][0], square[0][1], square[0][2],
          square[1][0], square[1][1], square[1][2],
          square[2][0], square[2][1], square[2][2]);
            break;
        }
    }
}

int main() {
    generateLoShuMagicSquare();
    return 0;
}
