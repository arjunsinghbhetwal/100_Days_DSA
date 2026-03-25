#include <stdio.h>

int main(){

    int num; //variable for aray size.
    printf("Enter array size: ");
    scanf("%d",&num);

    int arr[num]; //array created.
    printf("Enter %d elements(spaced): ",num);

    //Elements Insertion.
    for(int i = 0;i < num;i++){
        scanf("%d",&arr[i]);
    }

    //Reverse using two pointers.
    int i = 0;
    int j = num - 1;

    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }

    //Reversed Array.
    printf("Reversed Array: ");
    for(int k = 0;k < num;k++)
    {
        printf("%d ",arr[k]);
    }

    return 0;
}