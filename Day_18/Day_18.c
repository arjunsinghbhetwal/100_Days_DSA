#include <stdio.h>

int main(){

    int n; //array size.
    printf("Enter array size: ");
    scanf("%d",&n);

    //array created.
    int arr[n];

    printf("Enter the elements: ");
    //Element insertion.
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    int k;
    printf("Enter pos: ");
    scanf("%d",&k);

    //k position rotation.
    for(int i = 0;i < k;i++){

        int last = arr[n-1];

        for(int j = n-1;j > 0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = last;
    }

    printf("Rotated Array: ");
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}