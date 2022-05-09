#include <stdio.h>

int main() {
    int a;
    long sum = 0;
    scanf("%d", &a);

    // 0
    if (a == 1) {
        printf("%d", 1);
        return 0;
    }

    if (a > 1) {
        for (int i = 1; i <= a; i++)
            sum += i;
    } else {
        for (int i = 1; i >= a; i--)
            sum += i;
    }

    printf("%d", sum);

    return 0;
}
