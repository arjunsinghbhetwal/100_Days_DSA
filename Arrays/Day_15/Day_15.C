#include <stdio.h>

int main(){

    int n; //size of array.
    printf("Enter array size: ");
    scanf("%d",&n);

    //Array created.
    int arr[n][n];

    //Elements Insertion.
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int sum = 0;

    //Diagonal Elements Addition.
    for(int i = 0;i < n;i++){
        sum += arr[i][i];
    }

    printf("Sum of Diagonal elements: %d",sum);

    return 0;
}