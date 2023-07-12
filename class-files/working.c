#include <stdio.h>       
// Global variable
int globalVariable = 50; 
// Using #define
#define CONSTANT_VALUE "writing"

void function1()
{
    globalVariable = 75; // Modify the global variable
}
void function2()
{
    printf("Global variable: %d\n", globalVariable);
    printf("Constant value: %s\n", CONSTANT_VALUE);
}
int main()
{
    function1();
    function2();
}