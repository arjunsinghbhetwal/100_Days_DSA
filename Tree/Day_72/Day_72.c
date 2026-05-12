#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);

    int visited[26] = {0};

    for (int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a';

        if (visited[index] == 1) {
            printf("%c", str[i]);
            return 0;
        }

        visited[index] = 1;
    }

    printf("-1");
    return 0;
}