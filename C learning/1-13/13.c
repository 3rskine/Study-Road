#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b; scanf("%d %d", &a, &b);
    long long sum = 0;
    for (int n = a; n <= b; ++n) {
        int digit[5], t = n;

        for (int i = 4; i >= 0; --i) {
            digit[i] = t % 10; 
            t /= 10; 
        }

        if (!(digit[0] < digit[1] && digit[1] > digit[2] && digit[2] < digit[3] && digit[3] > digit[4])) continue;
        //A < B > C < D > E

        bool isqua = 1;
        for (int i = 0; i < 5 && isqua; ++i) for (int j = i+1; j < 5; ++j)
              if (digit[i] == digit[j]) { isqua = 0; break; }
              
        if (isqua) sum += n;
    }
    printf("%lld\n", sum);
    return 0;
} 