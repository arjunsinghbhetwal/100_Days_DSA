#include <stdio.h>

// Lower Bound
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Upper Bound
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Main
int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 7};
    int n = 7;
    int x = 4;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d", lb, ub);

    return 0;
}