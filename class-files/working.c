#include <stdio.h> 
int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printf("Accessing elements within the valid range:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    printf("\nAccessing elements out of the valid range:\n");
    printf("numbers[6] = %d\n", numbers[6]); // Accessing element outside the valid range
}