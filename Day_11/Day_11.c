#include <stdio.h>

int main(){

    int row, col;
    printf("Enter row and column: ");
    scanf("%d%d",&row,&col);

    int arr[row][col];
    printf("Enter 1st matrix elements: ");

    //To insert elements into the array.
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int arr1[row][col];
    printf("Enter 2nd Matrix elements: ");
   
    //To insert the elements into the 2nd matrix.
    for(int i = 0; i < row;i++){
        for(int j = 0;j < col;j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    int arr2[row][col];
    arr2[row][col] = arr[row][col] + arr1[row][col];

    //Addition of the Matrix.
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            arr2[i][j] = arr[i][j] + arr1[i][j];
        }
    }

    //Resultant Matrix.
    printf("\nResultant Matrix:\n");
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            printf("    %d  ",arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}