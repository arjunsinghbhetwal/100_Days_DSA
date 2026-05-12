#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);

    int freq[26] = {0};

    // Step 1: count frequency
    for (int i = 0; i < strlen(str); i++) {
        freq[str[i] - 'a']++;
    }

    // Step 2: find first non-repeating
    for (int i = 0; i < strlen(str); i++) {
        if (freq[str[i] - 'a'] == 1) {
            printf("%c", str[i]);
            return 0;
        }
    }

    printf("$");
    return 0;
}