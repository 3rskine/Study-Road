#include<stdio.h>
int main(){
    int t; scanf("%d" , &t);
    int arr[t] = {};
    long long curlen = 0, maxl = 0;
    for (int i = 0; i < t; i++){
        scanf("%d" , &arr[i]);
        curlen += arr[i];
        if (curlen < 0) curlen = 0;
        if (curlen > maxl) maxl = curlen;
    }
    printf("%lld\n", maxl);
}
