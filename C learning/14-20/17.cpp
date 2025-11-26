#include <stdio.h>
int main(){
    char c[501];
    fgets(c , sizeof(c) , stdin);
    int longest = 0;
    int curlength = 0;
    for (int i = 0; c[i] != '\0' ; i++){
        char achar = c[i];
        if (isalpha(achar)) {
            curlength++;
        } else {
            if (curlength > longest)longest = curlength;
            curlength = 0;
        }
    }
    if (curlength > longest)longest = curlength;  
    printf("Longest Word Length: %d\n" , longest);
    return 0;
}