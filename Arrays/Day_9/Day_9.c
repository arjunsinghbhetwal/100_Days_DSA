#include <stdio.h>
#include <string.h>

void rev(char str[], int i){
    if(i < 0)
    return;

    printf("%c",str[i]);
    rev(str, i - 1);
}

int main(){
    char str[100];
    scanf("%s", str);

    int len = strlen(str);
    rev(str, len - 1);
    
    return 0;
}