#include <stdio.h>

int main(int argc, char *argv[]) {
    int *a, *b, x, y;
    scanf("%d%d", &x, &y);
    a = &x;
    b = &y;
    swapInt(a, b);
    printf("After swapping, x is %d and y is %d", x, y);
}
void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
