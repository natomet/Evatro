

#include<stdio.h>
#include<math.h>

/* Input param */
/* Input param */
//int g_set[] = { 3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78, 81, 92, 95, 97, 99 };
int g_set[] = {1,2,3,4,6 };

int g_setlen = sizeof(g_set) / sizeof(int);

int is_membership(int v)
{
    int i;

    for (i = 0; i < g_setlen; i++)
        if (g_set[i] == v) {
            return 1;
        }

    return 0;
}

int is_onebit(int v)
{
    int i;
    for (i = 0; i < g_setlen; i++)
        if (v == (pow(2, i)))
            return 1;
    return 0;
}

int main(void)
{
    int mask;
    int m;
    int aux;
    int pos;
    unsigned int N = pow(2, g_setlen);
    int challenge3 = 0;

    for (mask = 1; mask < N; mask++)
    {
        if (is_onebit(mask))
            continue;

        aux = mask;
        pos = 0;
        m = 0;
        while (aux != 0) {
            if (aux & 0x01)
                m += g_set[pos];
            aux = aux >> 1;
            pos++;
        }

        if (is_membership(m))
            challenge3++;
    }

    printf("Solution to challenge 3 is %d\n", challenge3);
}
