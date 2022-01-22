/*

Find if a number is odd or even


Note: 
    Every even number's binary bits ends with 0
    Similarily every odd number's binary bit ends with 1

    2's binary is 1 0
    4's binary is 1 0 0
    6's binary is 1 1 0

    3's binary is 1 1
    5's binary is 1 0 1

So here's the logic to find the last bit;

    We will say n&1 (bitwise and) == 1 means the number is odd else even
    explanation

        consider number 5

                1   0   1
              & 0   0   1
              -----------
               0    0    1
               -----------

            So our answer is 1, hence 5 is odd 
        
        consider number 6

                1   1   0
            &   0   0   1
                -----------
                0   0   0
                ----------
            so our answer is 0, hence 6 is even

*/

#include<stdio.h>

int main(){

    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);
  
    if(n&1)
    {
        printf("%d is odd\n", n);
    }

    else
    {
        printf("%d is even\n", n);
    }

    return 0;
}