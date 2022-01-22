/*

________________________Bit Manipulation (Theory)---------------------------------

Bit manipulation is used to increase calculation speed
as it directly works on binary
 so time used to convert decimal to binary is saved


 Consider a decimal number "n" 
 number of digits in its binary eqivalent will be equals = log n + 1


----------------------->>> 1. Addition in Binary Numbers >>>>---------------------


    Consider 2 numbers;
    5 (101) & 7(111)

                            1   0   1
                          + 1   1   1
                        ---------------
                        1   1    0    0
                        ---------------

    Here on the right side, when we started addition , (1 + 1 = 2) which is 10 in binary 
    so we write 0 and takes 1 as carry and will do the same with others

    and get our addition = 1100 which is 12 in Decimal

---------------------->>>> 2. Subtraction in Binary Numbers  >>>>>>-----------------


    consider 2 numbers
    12 (1100) & 5(101)

    If we want to subtract we can just say 12 - 5 Or we can say 12 + (-5)

    so to subtract 2 numbers we need to do  |  a + (inverse of b)

    Inverse of b means, -b (negative of b)

    So we will add the inverse of "b" in "a" 

        Q) How do we find inverse of a number in binary?
        Ans) Using 2's complement Method

        -------------------------- 2's complement method ------------------------

        Step 1)  Invert all bits
        Step 2)  Add 1

        For example, inverse of 5 (101), invert means (convert 1 to 0 and vice versa)

        after inverting all bits(101) we get 010

        now we add 1 to 010

                                0   1   0
                                    +   1
                                -----------
                                0    1    1
                                ------------


        Note: One more thing to remember when we perform inverse

        Our 5 in binary looks like this 101, but actually its like (32 bit integer)

            0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1

        And same is the case with 12 (1100)

            0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

        Now when we performed Step 1: on our 5(101)
        we not only inverted 101, but all the other 0's also, so now our 5 becomes

        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0

        now when we added 1 to it becomes

        1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1

Now we have our 12 (......1100) and inverse of 5 (.....011) or (.....1011)

Now we peform add operation on these 2

    ...0    0   0   0       1   1   0   0
    ...1    1   1   1       1   0   1   1
                        --------------------
            .....0    0    0    1    1    1     
            
            (we carried 1 till the 32th bit and our addition result came 0
            , cuz 1 + 1 = (10) i.e 0, and our 1 will carried on 
            to 33 bit which doesn't exist and hence will be lost)


It becomes 7 (111) or (...000 111)  whatever we call it                     

--------------------------------<<< Bitwise Operators >>>>>>> -----------------------


    & , | ,  ^ , << , >>, ~

    |   A    |   B     |    and(&)  |     OR(|)    |   XOR(^)  |
    |        |         |            |              |           |
    |   0    |   0     |    0       |      0       |     0     |   
    |   0    |   1     |    0       |      1       |     1     |   
    |   1    |   0     |    0       |      1       |     1     |   
    |   1    |   1     |    1       |      1       |     0     |   


    ~ "One's complement"  used to invert the bits

    >> "Shift right" used to shift "k" bits to the right (decreases the value)
    << "Shift left" used to shift "k" bits to the left  (increases the value)

    12 >> 2, will result to , 12 / 2^2 = 12/4 = 3

            1   1   0   0 >> 2
            0   0   1   1, which is equivalent to 3

    12 << 2, will result to, 12 * 2^2 = 12 * 4 = 48

                1   1   0   0 << 2
      1    1    0   0   0   0, which is equivalent to 48

    (Important Formulas, to know the new values after using these operators)

    n >> k 's new value will be = n / 2 power k || or we can say that "n" is divided by 2 raise to power k
    n << k 's new value will be = n * 2 power k || or we can say that "n" is multiplied by 2 raise to power k

    So in short if want to say that I want to divide "n" with 2
    n >> 1 will do it , but faster than n/2;

    Similarily, If I want to multiply "n" with 2
    n << 1 will do it, faster than n*2;



*/