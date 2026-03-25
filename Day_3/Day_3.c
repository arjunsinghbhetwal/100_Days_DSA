#include <stdio.h>

int main(){

    //array size input.
    int num;
    printf("Enter array size: ");
    scanf("%d",&num);

    //array created.
    int arr[num];

    //Element insertion.
    for(int i = 0;i < num; i++){
        printf("Enter %d element: ",i+1);
        scanf("%d",&arr[i]);
    }

    //Temporary variable and flag.
    int temp;
    int found = 0;

    printf("Enter element to be searched: ");
    scanf("%d",&temp);

    //Linear search.
    for(int j = 0;j < num;j++){
        if(temp == arr[j]){
            printf("Element Found at index: %d",j);
            found = 1;
            break;
        }
    }

    if(found == 0){
        printf("Element Not FOUND!\n");
    }


    return 0;
}