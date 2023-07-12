#include <stdio.h>

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    // Create the main array
    int array[length][1];

    // Initialize the array with the predetermined value (0)
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            array[i][j] = i;
        }
    }

    // Print the array
    printf("Array elements:\n");
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < 1; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
