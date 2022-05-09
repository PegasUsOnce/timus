#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double proection_length(const double a, const double b) {
    return a - b;
}

double line_length(const Point point1, const Point point2) {
    double len1 = proection_length(point1.x, point2.x);
    double len2 = proection_length(point1.y, point2.y);
    return sqrt(len1 * len1 + len2 * len2);
}

int main() {
    unsigned short quantity;
    double radius;

    scanf("%d %lf", &quantity, &radius);

    Point dots[16];

    double result = 2 * 3.14 * radius;

    for (int i = 0; i < quantity; i++) {
        scanf("%lf %lf", &(dots[i].x), &(dots[i].y));
    }

    if (quantity > 1) {
        result += line_length(dots[0], dots[quantity - 1]);

        for (int i = 1; i < quantity; i++) {
            result += line_length(dots[i - 1], dots[i]);
        }
    }

    printf("%.2lf", (double)(round(100 * result) / 100));

    return 0;
}

