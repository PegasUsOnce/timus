#include <stdio.h>
#include <math.h>

bool is_triangle_number(const unsigned long long number, double temp) {
    temp = sqrt(8 * number + 1);
    return (double)temp == (unsigned long long)temp;
}

int main() {
    unsigned int quantity;
    scanf("%d", &quantity);

    bool result[65535];
    unsigned long long num;
    double temp = 0;

    for (int i = 0; i < quantity; i++) {
        scanf("%d", &num);
        result[i] = is_triangle_number(num - 1, temp);
    }

    for (int i = 0; i < quantity; i++) {
        printf("%d ", result[i] == true ? 1 : 0);
    }

    return 0;
}

