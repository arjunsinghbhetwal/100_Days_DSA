#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    int marks;
};

// Display
void display(struct Student s[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d %s %d\n", s[i].roll, s[i].name, s[i].marks);
    }
}

// Swap
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(struct Student s[], int n, int *comp) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            (*comp)++;
            if(s[j].marks > s[j+1].marks)
                swap(&s[j], &s[j+1]);
        }
    }
}

// Insertion Sort
void insertionSort(struct Student s[], int n, int *comp) {
    for(int i = 1; i < n; i++) {
        struct Student key = s[i];
        int j = i-1;

        while(j >= 0 && (++(*comp) && s[j].marks > key.marks)) {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
}

// Selection Sort
void selectionSort(struct Student s[], int n, int *comp) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            (*comp)++;
            if(s[j].marks < s[min].marks)
                min = j;
        }
        swap(&s[i], &s[min]);
    }
}

// Merge
void merge(struct Student s[], int l, int m, int r, int *comp) {
    int n1 = m-l+1, n2 = r-m;
    struct Student L[n1], R[n2];

    for(int i=0;i<n1;i++) L[i]=s[l+i];
    for(int j=0;j<n2;j++) R[j]=s[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2) {
        (*comp)++;
        if(L[i].marks <= R[j].marks)
            s[k++] = L[i++];
        else
            s[k++] = R[j++];
    }

    while(i<n1) s[k++] = L[i++];
    while(j<n2) s[k++] = R[j++];
}

// Merge Sort
void mergeSort(struct Student s[], int l, int r, int *comp) {
    if(l < r) {
        int m = (l+r)/2;
        mergeSort(s,l,m,comp);
        mergeSort(s,m+1,r,comp);
        merge(s,l,m,r,comp);
    }
}

// Partition
int partition(struct Student s[], int low, int high, int *comp) {
    int pivot = s[high].marks;
    int i = low-1;

    for(int j=low;j<high;j++) {
        (*comp)++;
        if(s[j].marks < pivot) {
            i++;
            swap(&s[i], &s[j]);
        }
    }
    swap(&s[i+1], &s[high]);
    return i+1;
}

// Quick Sort
void quickSort(struct Student s[], int low, int high, int *comp) {
    if(low < high) {
        int pi = partition(s,low,high,comp);
        quickSort(s,low,pi-1,comp);
        quickSort(s,pi+1,high,comp);
    }
}

// Linear Search
int linearSearch(struct Student s[], int n, int key) {
    for(int i=0;i<n;i++)
        if(s[i].roll == key)
            return i;
    return -1;
}

// Binary Search
int binarySearch(struct Student s[], int n, int key) {
    int low=0, high=n-1;

    while(low<=high) {
        int mid=(low+high)/2;
        if(s[mid].roll==key) return mid;
        else if(s[mid].roll<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

// Sort by Roll
void sortByRoll(struct Student s[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(s[j].roll > s[j+1].roll)
                swap(&s[j], &s[j+1]);
        }
    }
}

int main() {
    int n;
    struct Student s[MAX], temp[MAX];

    printf("Enter number of students: ");
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++) {
        printf("Enter Roll: ");
        scanf("%d",&s[i].roll);
        getchar();

        printf("Enter Name: ");
        fgets(s[i].name,50,stdin);
        s[i].name[strcspn(s[i].name,"\n")] = 0;

        printf("Enter Marks: ");
        scanf("%d",&s[i].marks);
        getchar();
    }

    printf("\n--- ORIGINAL DATA ---\n");
    display(s,n);

    int bubble=0,insertion=0,selection=0,mergeC=0,quick=0;

    memcpy(temp,s,sizeof(s));
    bubbleSort(temp,n,&bubble);

    memcpy(temp,s,sizeof(s));
    insertionSort(temp,n,&insertion);

    memcpy(temp,s,sizeof(s));
    selectionSort(temp,n,&selection);

    memcpy(temp,s,sizeof(s));
    mergeSort(temp,0,n-1,&mergeC);

    memcpy(temp,s,sizeof(s));
    quickSort(temp,0,n-1,&quick);

    printf("\nComparisons:\nBubble:%d Insertion:%d Selection:%d Merge:%d Quick:%d\n",
           bubble,insertion,selection,mergeC,quick);

    // Search
    int key;
    printf("\nEnter SAP ID to search: ");
    scanf("%d",&key);

    int idx = linearSearch(s,n,key);
    printf("Linear Search: %s\n",(idx!=-1)?"FOUND":"NOT FOUND");

    sortByRoll(s,n);

    idx = binarySearch(s,n,key);
    printf("Binary Search: %s\n",(idx!=-1)?"FOUND":"NOT FOUND");

    return 0;
}