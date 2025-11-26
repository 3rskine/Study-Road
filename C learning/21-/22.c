#include <stdio.h>
#include <string.h>
int main(){
    char a[102], b[102], res[102];
    scanf("%s" , a);
    scanf("%s" , b);
    
    int lena = strlen(a); int lenb = strlen(b);

    int inda = lena - 1; int indb = lenb - 1;
    int resind = 0 , carry = 0;

    while (inda >= 0 || indb >= 0 || carry >0)
    {
        int cura = (inda >= 0) ? (a[inda] - '0') : 0;
        int curb = (indb >= 0) ? (b[indb] - '0') : 0;

        int digitsum = cura + curb + carry;
        res[resind++] = (digitsum % 10) + '0';
        carry = digitsum / 10;
        
        inda--; indb--;
    }

    for (int i = resind - 1; i >= 0; i--)
    {
        putchar(res[i]);
    }
    putchar('\n');
}