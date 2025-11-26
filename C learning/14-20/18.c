#include <stdio.h>
int main(){
    char hay[501] , needle[501];
    fgets(hay , sizeof(hay) , stdin);
    fgets(needle , sizeof(needle) , stdin);

    int index = -1;
    for (int i = 0; hay[i] != '\0' && index == -1; i++)
    {
        int gotcha = 0;
        while (needle[gotcha] != '\0' && hay[i + gotcha] == needle[gotcha])gotcha++;
        if (needle[gotcha] == '\0'){
        index = i;
        break;
        }
    }
    printf("%d",index);
}