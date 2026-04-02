#include <stdio.h>

int main(){

    int n; //size of array.
    printf("Enter array size: ");
    scanf("%d",&n);

    //array created.
    int arr[n];

    //Element Insertion.
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    //Element Assigning.
    for(int i = 1;i < n;i++){
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    printf("Max and Min: %d:%d",max,min);

    return 0;
}