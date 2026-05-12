#include <stdio.h>

int main(){

    int row,col;
    printf("Enter row and column: ");
    scanf("%d%d",&row,&col);

    //square check
    if(row != col){
        printf("Not Symmetric!");
        return 0;
    }

    int arr[row][col];

    //Element insertion.
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    //Check for symmetric.
    int issymmetric = 1;

    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            if(arr[i][j] != arr[j][i]){
                issymmetric = 0;
                break;
            }
        }
        if(issymmetric == 0)
        break;
    }

    if(issymmetric == 1){
        printf("The Matrix is Symmetric");
    }else{
        printf("Not Symmetric");
    }

    return 0;
}