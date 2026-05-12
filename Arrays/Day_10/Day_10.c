#include <stdio.h>
#include <string.h>

int main(){

    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int i = 0;
    int j = strlen(str) - 1;
    int flag = 1;

    while(i < j){
        if(str[i] != str[j]){
        flag = 0;
        break;
    }
    i++;
    j--;
}
    
    if(flag)
    printf("Yes\n");
    else
    printf("No\n");


    return 0;
}