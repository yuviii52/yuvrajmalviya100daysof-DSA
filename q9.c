#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j;
    char temp;

    printf("Enter the code name: ");
    scanf("%s", s);

    i = 0;
    j = strlen(s) - 1;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    printf("Mirrored code name: %s", s);

    return 0;
}
