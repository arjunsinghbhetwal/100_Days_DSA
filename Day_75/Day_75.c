#include <stdio.h>

#define MAX 1000

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = 8;

    int sum = 0;
    int maxLen = 0;

    int hash[2000]; // for storing index
    for (int i = 0; i < 2000; i++)
        hash[i] = -1;

    int offset = 1000; // handle negative sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        if (hash[sum + offset] != -1) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + offset] = i;
        }
    }

    printf("Length: %d", maxLen);
    return 0;
}