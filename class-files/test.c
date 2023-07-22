#include <stdio.h>

void modifyValue(int num) {
    num = num * 2;
}

int main() {
    int value = 5;
    modifyValue(value);
    value++;
    printf("%d", value);
}