#include <stdio.h>

int main(void)
{
    char a[4], b[4];
    scanf("%s %s",a,b);
    for(int i=2; i>=0; i--){
        if(a[i]<b[i]){
            for(int j=2; j>=0; j--){
                printf("%c",b[j]);
            }
            break;
        }
        else if(b[i]<a[i]){
            for(int j=2; j>=0; j--){
                printf("%c",a[j]);
            }
            break;
        }
    }
    printf("\n");
    return 0;
}