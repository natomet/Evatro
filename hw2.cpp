
#include <stdio.h>



// get next fibonaci number each time when requested
unsigned long next_fibonacci()    
{ 
    
    static unsigned long a = 0;
    static unsigned long b = 1;
    unsigned long nf = a + b;

    a = b;
    b = nf;

    return nf;
}

// testing for prime
int is_prime(unsigned long tested)
{
    unsigned long divisor;

    for (divisor = (tested / 2); divisor > 1; divisor--)
        if ((tested % divisor) == 0)
            return 0;

    return 1;
}



// get next prime number each time when requested
unsigned long next_prime()
{
    static unsigned long prime = 0;
    unsigned long tested = prime + 1;

    while (1) {
        if (is_prime(tested)) {
            prime = tested;
            return prime;
        } else {
            tested++;
        }
    }
}




// We are given number and by  using two functions above each time we request for prime number and compare it with given minimum
// so we find first fibonacci prime number greater than given minimum
// for not same prime factors sum;everytime we get prime numbers starting from 2 with the function "next_prime" and we check if it is divisor of X,
// and if yes we divide X with that prime number until it is not divisible anymore, we store it for sum and in next step we get next prime number and do the same checking
int main(void)
{
    unsigned long given_minimum;
    unsigned long X;

printf("Enter the minimum :" );

scanf("%lu",&given_minimum);



    while ((X = next_fibonacci()) < given_minimum)
        ;

    while (!is_prime(X))
        X = next_fibonacci();

printf("first prime fibonacci number larger than a given minimum %lu\n", X);   
 X += 1;

    int np = next_prime(); // 1

    int challenge2 = 0;

    while (X != 1) {
        np = next_prime();

        if ((X % np) == 0) {
            while ((X % np) == 0)
                X = X / np;
            challenge2 += np;
        }
    }

    printf("Sum of factors %d\n", challenge2);
}
