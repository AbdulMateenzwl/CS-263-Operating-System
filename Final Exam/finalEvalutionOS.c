#include <stdio.h>

int main()
{
    int X, G, L, F, M, R, T;

    printf("Enter the number of account holders: ");
    scanf("%d", &X);

    printf("Enter the total amount of money in their accounts: ");
    scanf("%d", &G);

    printf("Enter the amount of the car loan requested: ");
    scanf("%d", &L);

    printf("Enter the amount of fixed deposits: ");
    scanf("%d", &F);

    printf("Enter the amount of monthly income schemes: ");
    scanf("%d", &M);

    printf("Enter the amount of gold, etc. that the bank has: ");
    scanf("%d", &R);

    T = G + F + M + R;

    if (T - L >= G)
    {
        printf("The bank can give the car loan.\n");
    }
    else
    {
        printf("The bank cannot give the car loan.\n");
    }
    return 0;
}