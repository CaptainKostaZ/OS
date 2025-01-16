#include <stdio.h>

void add(int a, int b, int c, int *result) {
    *result = a + b + c;
}

int main() {
    int a = 5, b = 10, c = 15, result;
    add(a, b, c, &result);
    printf("The sum of %d, %d, and %d is %d\n", a, b, c, result);
    return 0;
}
