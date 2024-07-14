#include <stdio.h>

void print_F(char floor[3][4], int row, int col) {
    printf("Floor matrix:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            if (r == row && c == col) {
                printf("->VC<- ");
            } else {
                printf("%c ", floor[r][c]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void clean(char floor[3][4]) {
    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 4; j++) {
                if (floor[i][j] == 'd') {
                    floor[i][j] = 'c';
                }
                print_F(floor, i, j);
            }
        } else {
            for (int j = 3; j >= 0; j--) {
                if (floor[i][j] == 'd') {
                    floor[i][j] = 'c';
                }
                print_F(floor, i, j);
            }
        }
    }
}

int main() {
    char floor[3][4] = {{'d', 'c', 'c', 'd'}, {'c', 'd', 'd', 'o'}, {'o', 'c', 'c', 'd'}};
    clean(floor);
    return 0;
}

