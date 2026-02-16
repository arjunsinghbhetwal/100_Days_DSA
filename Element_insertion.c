#include <stdio.h>

int main() {

//User input for the number of elements.
    int num;
    printf("Enter number of elements: ");
    scanf("%d",&num);

//creates the array with user defined no. of elements.
    int arr[num];

//Looping statement for element input.
    for(int i=0;i<num;i++){
        printf("Enter %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n");

//User input position and value input.
    int pos,val;
    printf("Enter the position and element: ");
    scanf("%d%d",&pos,&val);

//Loop statement for right shift.
    for(int k=num;k>=pos;k--){
        arr[k]=arr[k-1];
    }

//condition to add element at particular position.
    arr[pos-1]=val;

//Increases array size.
    num++;

//Looping statement for element output.
    for(int j=0;j<num;j++){
        printf("Element %d: %d\n",j+1,arr[j]);
    }
    printf("\n");

    return 0;
}