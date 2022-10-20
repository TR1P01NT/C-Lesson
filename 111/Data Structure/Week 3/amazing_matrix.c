#include <stdio.h>
#include <stdbool.h>

int matrix[10][10];
int rotation[10][10];

bool checkMagicSquare(int size);
bool checkSymmetry(int size);
bool checkAsymmetry(int size);
bool rotateMatrix(int size);

int main(void) {
    int n = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool magicsquare = checkMagicSquare(n);
    bool symmetric = checkSymmetry(n);
    bool asymmetric = rotateMatrix(n);

    if(magicsquare) {
        printf("Magic Square\n");
    }
    else if(symmetric && asymmetric) {
        printf("Symmetric Asymmetric\n");
    }
    else if(symmetric) {
        printf("Symmetric\n");
    }
    else if(asymmetric) {
        printf("Asymmetric\n");
    }
    else {
        printf("NOTHING\n");
    }
}

bool checkMagicSquare(int size) {
    int sum = 0;
    int sum2 = 0;
    int max = size * size;

    for (int i = 1; i <= max; i++) {
        sum += i;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum2 += matrix[i][j];
        }
    }

    if (sum != sum2) {
        return false;
    }

    int diagonal_sum1 = 0;
    int diagonal_sum2 = 0;

    for (int i = 0; i < size; i++) {
        diagonal_sum1 += matrix[i][i];
        diagonal_sum2 += matrix[i][size - 1 - i];
    }

    if (diagonal_sum1 != diagonal_sum2) {
        return false;
    }

    int row_sum = 0;
    int col_sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            row_sum += matrix[i][j];
            col_sum += matrix[j][i];
        }

        if (row_sum != diagonal_sum1 || col_sum != diagonal_sum1 || row_sum != col_sum) {
            return false;
        }

        row_sum = 0;
        col_sum = 0;
    }

    return true;
}

bool checkSymmetry(int size) {
    int transpose[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != transpose[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool checkAsymmetry(int size) {
    int transpose[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transpose[i][j] = rotation[j][i];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rotation[i][j] != transpose[i][j]) {
                return false;
            }
        }
    }

    // printf("Transpose:\n");
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         printf("%d ", transpose[i][j]);
    //     }
    //     printf("\n");
    // }

    return true;
}

bool rotateMatrix(int size) {
    int a = 0;
    int b = 0;

    for (int i = size - 1; i >= 0; i--, a++) {
        for (int j = 0; j < size; j++, b++) {
            rotation[a][b] = matrix[j][i];
        }
        b = 0;
    }

    // printf("Rotation:\n");

    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         printf("%d ", rotation[i][j]);
    //     }
    //     printf("\n");
    // }

    bool symmetric = checkAsymmetry(size);

    if (symmetric) {
        return true;
    }
    else {
        return false;
    }
}