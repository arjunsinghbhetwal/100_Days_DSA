#include <stdio.h>

int main(){

    int num; //array size variable.
    printf("Enter array size: ");
    scanf("%d",&num);

    int arr[num]; //array creation.

    printf("Enter the elements(spaced): ");

    //Element Insertion.
    for(int i = 0;i < num;i++){
        scanf("%d",&arr[i]);
    }

    int i = 0;

    //Unique elements.
    for(int j = 1;j < num;j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }

    //Print Unique elements:
    printf("Unique Elements: ");
    for(int k = 0;k <= i;k++){
        printf("%d",arr[k]);
    }

    return 0;
}