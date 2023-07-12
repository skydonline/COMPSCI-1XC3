#include <stdio.h>
// Global constant variable
const int MAX_VALUE = 100;

// Global non-constant variable
int globalVariable = 50;

void function1()
{
    // Access the global constant variable 
    printf("Max value: %d\n", MAX_VALUE);

    // Access the global non-constant variable
    printf("Global variable: %d\n", globalVariable);

    // Modify the global non-constant variable
    globalVariable = 75;
}
void function2()
{
    // Access the modified global variable from function1 
    printf("Updated global variable: %d\n", globalVariable);
}
int main()
{
    function1();
    function2();
}