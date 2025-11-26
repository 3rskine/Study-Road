#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int i, j;
    for (i = 0 ; i <= N / 2 ; i++) {

        for (j = 0; j < N / 2 - i; j++)printf(" ");
        for (j = 0; j < 2 * i + 1; j++)printf("*");

        printf("\n");
    }

    for (i = N / 2 - 1 ; i >= 0 ; i--) {

        for (j = 0; j < N / 2 - i; j++)printf(" ");
        for (j = 0; j < 2 * i + 1; j++)printf("*");

        printf("\n");
    }

    return 0;
}
