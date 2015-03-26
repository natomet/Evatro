
#include <stdio.h>

unsigned long next_fibonacci()
{
    static unsigned long a = 0;
    static unsigned long b = 1;
    unsigned long nf = a + b;

    a = b;
    b = nf;

    return nf;
}


int is_prime(unsigned long tested)
{
    unsigned long divisor;

    for (divisor = (tested / 2); divisor > 1; divisor--)
        if ((tested % divisor) == 0)
            return 0;

    return 1;
}




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
