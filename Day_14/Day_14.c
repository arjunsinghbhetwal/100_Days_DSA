#include <stdio.h>

int main(){

    int n;
    printf("Enter array size: ");
    scanf("%d",&n);

    //Array creation.
    int arr[n][n];

    printf("Enter the elements of the matrix: ");

    //Elements Insertion.
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    //flag created.
    int isidentity = 1;

    //check for Identity Matrix.
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                if(arr[i][j] != 1){
                    isidentity = 0;
                    break;
                }
            }else{
                if(arr[i][j] != 0){
                    isidentity = 0;
                    break;
                }
            }
        }if(isidentity == 0){
            break;
        }
    }

    //Conditional statement.
    if(isidentity == 1){
        printf("Identity Matrix");
    }
    else{
        printf("Not an Identity Matrix");
    }

    return 0;
}