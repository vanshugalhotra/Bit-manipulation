/*

-----------------------------------------Bit Masking---------------------

1. Find ith bit
2. Set ith bit
3. Clear ith bit

Q). Find number of bits to change to convert a to b


----------------------->> 1. Find ith bit >> --------------------------------------

    consider a number "n" in binary
        ---------------------------------
        1   0   0   1   1   0   1   0   1
        ----------------------------------
    pos 8   7   6   5   4   3   2   1   0

    To find 5th bit

    So we will do this
    1 << 5 (1 left shift 5)

        ---------------------------------
    n = 1   0   0   1   1   0   1   0   1
        ----------------------------------

    After shifting, our "n" or we can say "mask" becomes
            ---------------------------------
    mask =   0   0   0   1   0   0   0   0   0
            ----------------------------------

    So if, n & mask == any non-zero, then our 5th bit is 1 else 0

    Logic:

        mask = 1<<i;


----------------------->> 2. Set ith bit >> --------------------------------------


    consider a number "n" in binary
        ---------------------------------
        1   0   0   1   1   0   1   0   1
        ----------------------------------
    pos 8   7   6   5   4   3   2   1   0

    To set 3th bit (set means 1)

    So we will do this
    1 << 3 (1 left shift 3)

        ---------------------------------
    n = 1   0   0   1   1   0   1   0   1
        ----------------------------------

    After shifting, our "n" or we can say "mask" becomes
            ---------------------------------
    mask =   0   0   0   0   0   1   0   0   0
            ----------------------------------

    n = n | mask will do the job;

    now our n, becomes

        ---------------------------------
    n = 1   0   0   1   1   1   1   0   1
        ----------------------------------

    Logic:
        mask = 1<<i
        n = n|mask;


----------------------->> 3. Clear ith bit >> --------------------------------------

    consider a number "n" in binary
        ---------------------------------
        1   0   0   1   1   0   1   0   1
        ----------------------------------
    pos 8   7   6   5   4   3   2   1   0

    To clear 4th bit (clear means set to 0)

    So we will do this
    1 << 4 (1 left shift 4)

        ---------------------------------
    n = 1   0   0   1   1   0   1   0   1
        ----------------------------------

    After shifting,| our "n" or we can say "mask" becomes
            ---------------------------------
    mask =   0   0   0   0   1   0   0   0   0
            ----------------------------------

    Now we will invert the mask (invert means set 1 to 0 and 0 to 1)

            ---------------------------------
    ~mask =  1   1   1   1   0   1   1   1   1
            ----------------------------------

    n = n & mask will do the job; (here mask is the inverted one)

    now our n, becomes

        ---------------------------------
    n = 1   0   0   1   0   0   1   0   1
        ----------------------------------

    logic:
        mask = 1<<i;
        mask = ~mask;
        n = n&mask;

-----------Q). Find number of bits to change to convert a to b---------------------


    Lets say, 
        -------------------
    a = 1   0   1   1   0
        -------------------

        -------------------
    b = 1   1   0   1   1
        -------------------

    Or we need to find how many bits are different, 

    Like on position 0, 2, 3 bits are not same in a and b
    so we will say 

    mask = a^b; (a XOR b) 

            ------------------
    mask =  0   1   1   0   1
            ------------------

    Now we just need to count the occurence of 1

        1.) Method 1:  Time complexity: worst case O(log n), best case O(log n) i.e number of bits in "n";

            we will say shift "n" right by 1, and check if its last bit is 1 or 0
            if 1 then counts++, else skip

            so it will take us log n + 1, shifts as number of bits are log n + 1
            we will do this till our "n" is zero

            (while n > 0)
            {
                n>>1;
                if(n&1) // it will return 1, if last bit is 1
                {
                    count++;
                }
            }

        2.)Method 2: Time Complexity: worst case O(log n), best case O(1),
                    basically,  time complexity we can say that O( number of 1 bits) or number of set bits

            we will do 
                n & (n - 1);
                this will clear our least significant set bit (1), means recent 1

                consider following;

                    1   0   1
                
                performing; n & (n - 1), will clear the 0th 1

                    1   0   0
                
                after performing again
                    0   0   0

            So basically we are clearing our number bit by bit;

            while(n > 0)
            {
                n = n & (n - 1)
                count++; // counting how many times we need to perform our clearing operations
            }


            --------------------->>>> Working of n & (n-1) <<<<< ------------------

            It just clear the recent 1 bit

            say, our number =   1   1   0   1

            so (n-1) will be,   1   1   0   0

            now n & (n-1)

                            1   1   0   1
                        &   1   1   0   0
                        -------------------
                            1   1   0   0
                        -------------------

            See after performing 1 time our recent 1 is cleared to 0

            Now lets perform it again on n, now our n = 12, n-1 = 11 (1011)

                1   1   0   0
            &   1   0   1   1
            ------------------
                1   0   0   0
            -----------------

            So our recent 1 at pos=2 is cleared   

*/