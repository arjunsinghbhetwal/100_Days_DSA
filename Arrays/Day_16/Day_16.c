#include <stdio.h>

int main(){

    int n; //array size
    printf("Enter array size: ");
    scanf("%d",&n);

    //Array creation.
    int arr[n][n];
    int visited[n];

    //Element Insertion.
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&arr[i][j]);
            visited[n] = 0;
        }
    }

    //Count.
    for(int i = 0;i < n;i++){

        if(visited[i] = 1)
            continue;

        int count = 1;

        for(int j = 0;j < n;j++){
            if(arr[i] == arr[j]){
                count++;
                visited[j] = 1;
            }
        }
        printf("%d:%d", arr[i],count);
    }

    return 0;
}