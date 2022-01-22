/*

XOR (^) Problems in Bit Manipulation

Properties of XOR:

    n ^ n = 0
    0 ^ n = n
    n ^ a ^ n = a


Q1:) Find the only non repeating element in array where every other element occurs twice

Q2:) Find the two non repeating elements in an array where every element repeats twice

Q3:) Find the only non repeating element in an array where every other element repeates thrice


------------------------------>>>>>> Q1 <<<<< -----------------------------------

    If we use brute force , our time complexity will be O(n^2)
    If we use hash table, our time complexity will be O(n) but space complexity : O(n)

    But it can do it in

    Time complexity: O(n), space complexity : O(1)

    using XOR

    Consider this array>

        [5, 4, 6, 3 , 6 ,4 ,5]

    So will say our

        res = 0;
        we will traverse into array and say
            res = res^element;

        so first, our res = 5 (0^5 = 5)
        second iteration, our res = 5 ^ 4 (some value we dont care)
        third iteration, our res = 5 ^ 4 ^ 6 (some value we dont care)
        fourth iteration, our res = 5 ^ 4 ^ 6 ^ 3(some value we dont care)
        fifth iteration, our res = 5 ^ 4 ^ 6 ^ 3 ^ 6 (value will be equal to 5^4^3)(see property 3 of XOR)
        sixth iteration, our res = 5 ^ 4 ^ 3 ^ 4 (value will be 5^3)
        seventh iteration, our res = 5 ^ 3 ^ 5 (value will be 3)

        as loops ends, our res = 3 will be the answer

------------------------------>>>>>> Q2 <<<<< -----------------------------------


    Let us see an example.
    arr[] = {2, 4, 7, 9, 2, 4}
    1) Get the XOR of all the elements. like we did in Q1
        xor = 2^4^7^9^2^4 = 14 (1110)
    2) Get a number which has only one set bit of the xor. (Getting the rightmost set bit)
    Since we can easily get the rightmost set bit, let us use it.
        set_bit_no = xor & ~(xor-1) = (1110) & ~(1101) = 0010

    Now set_bit_no will have only set as rightmost set bit of xor. (Now we divide 2 sets on basis of rightmost setbit)
    3) Now divide the elements in two sets and do xor of
    elements in each set and we get the non-repeating
    elements 7 and 9. Please see the implementation for this step.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    // --------------------------------------------Ans 1
    int arr1[] = {5, 4, 6, 3, 6, 4, 5};

    int xor_res = 0;
    for (int i = 0; i < 7; i++)
    {
        xor_res = xor_res ^ arr1[i];
    }
    printf("The Element is %d\n", xor_res);

    // ----------------------------------------------Ans 2

    int arr2[] = {2, 4, 7, 9, 2, 4};

    int *x = (int *)malloc(sizeof(int)); // can use simple integer also
    int *y = (int *)malloc(sizeof(int));

    *x = *y = 0;

    // getting the xor result
    int xor_res_2 = 0;
    for (int i = 0; i < 6; i++)
    {
        xor_res_2 = xor_res_2 ^ arr2[i];
    }

    // finding the rightmost set bit in our xor result
    int rightmost_set_bit = xor_res_2 & ~(xor_res_2 - 1);

    // diving the array into 2 half on basis of our rightmost set bit
    for (int i = 0; i < 6; i++)
    {

        /*Xor of first set */
        if (arr2[i] & rightmost_set_bit)
            *x = *x ^ arr2[i]; // using x as a pointer but can also use simple integer
        /*Xor of second set*/
        else
        {
            *y = *y ^ arr2[i];
        }
    }
    printf("The two non repeating elements are: %d   %d\n", *x, *y);

    return 0;
}