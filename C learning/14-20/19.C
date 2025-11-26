#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char a[100];
    fgets(a, sizeof(a), stdin);

    int len = strlen(a);
    (len > 0 && a[len - 1] == '\n') ? a[--len] = '\0' : 0;

    int PASS = 1;
    (len == 9) ? 0 : (PASS = 0);
    (a[0] == 'D') ? 0 : (PASS = 0);
    (a[1] == '1' || a[1] == '2' || a[1] == '3') ? 0 : (PASS = 0);
    (isdigit(a[2]) && isdigit(a[3])) ? 0 : (PASS = 0);
    (isupper(a[4]) && isupper(a[5])) ? 0 : (PASS = 0);
    (isdigit(a[6]) && isdigit(a[7]) && isdigit(a[8])) ? 0 : (PASS = 0);

    printf(PASS ? "Valid" : "Invalid");
    return 0;
}
