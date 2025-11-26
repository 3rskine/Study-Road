#include <stdio.h>
#include <string.h>

int main() {
    char t[1000];
    if (!fgets(t, sizeof(t), stdin)) return 0;
    int n = strlen(t);
    if (n > 0 && t[n-1] == '\n') t[--n] = '\0';
    int mostleft = 0, maxlen = 0;

    for (int i = 0; i < n; i++) {
        for (int iseven = 0; iseven <= 1; iseven++) {
            int L = i, R = i + iseven;
            while (L >= 0 && R < n && t[L] == t[R]) { 
                L--; R++; 
            }
            int start = L + 1;
            int end = R - 1;
            int len = end - start + 1;

            if (len > 0) {
                if (t[start] == ' ' && t[end] == ' ') {//Strip a pair of spaces
                    start++;end--;len -= 2;
                }
                if (len > 0 && (len > maxlen || (len == maxlen && start < mostleft))) {
                    maxlen = len;
                    mostleft = start;
                }
            }
        }
    }

    for (int i = mostleft; i < mostleft + maxlen; i++) putchar(t[i]);
    putchar('\n');
    return 0;
}