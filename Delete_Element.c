#include <stdio.h>

int main() {

//variables and array creation.
    int n,pos;
    int arr[100];

//user input.
    printf("Enter no. of elements and pos: ");
    scanf("%d%d",&n,&pos);

//validation.
    if(pos < 1 || pos > n){
        printf("Invalid posiiton!\n");
        return 0;
    }

//Loop to input the elements.
    for(int k=0;k<n;k++){
        printf("Enter %d element: ",k+1);
        scanf("%d",&arr[k]);
    }

//Loop statement for the left shift.
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    printf("\nUpdated Arrray\n");

//Loop statement for elements printing.
    n--; //decrements the size of the array useful after the left shift.
    for(int j=0;j<n;j++){
        printf("%d",arr[j]);
        if (j<n-1) printf(" "); //prints space before the last index only.
    }
    
    return 0;
}