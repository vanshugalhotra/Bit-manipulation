/*

Swap 2 numbers

    Basically if we want to swap 2 variables we do this in decimal, 

    we use a third variable, or we do addition/subtraction whatever in these 2 to swap them


    // Now to do above  steps we can use ^ (XOR) operator something like....

    a = a^b;
    b = a^b;
    a = a^b;

    // Explanation

    Consider a = 5 (1 0 1) and b = 7 (1 1 1)

    now, first line says, a = a^b; 
                          a = 5^7 

                        1   0   1
                    ^   1   1   1
                    -----------------
                        0    1    0     = 2 in decimal
                    ----------------

    now our a = 2 ( 1 0 ) and b = 7 (1 1 1)
    now, second line says, b = a^b;
                           b = 2^7;

                        0   1   0  
                    ^   1   1   1
                    -----------------
                        1   0   1       = 5 in decimal
                    ------------------

    now our a = 2 (1 0) and b = 5(1 0 1)
    now, third line says, a = a^b;
                          a = 2^5;

                        0   1   0
                    ^   1   0   1
                    -----------------
                        1   1   1          = 7 in decimal
                    -----------------  
 
                
*/

#include <stdio.h>

int main()
{

    int a, b;

    a = 5;
    b = 7;

    printf("Before Swapping\n");
    printf("A: %d \t B: %d\n", a, b);

    a = a^b;
    b = a^b;
    a = a^b;

    printf("After Swapping\n");
    printf("A: %d \t B: %d\n", a, b);

    return 0;
}