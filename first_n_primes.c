//Print Prime numbers from 2 to the number using SOE[Optimised Algorithm]. i.e Time Complexity : O(log n)
#include <stdio.h>
#include<conio.h>
void main()
{
    int number,i,j;
    clrscr();
    printf("Enter the number\n");
    scanf("%d",&number);

    int primes[number+1];

    for(i = 2; i<=number; i++)
        primes[i] = i;

    i = 2;
    while ((i*i) <= number)
    {
        if (primes[i] != 0)
        {
            for(j=2; j<number; j++)
            {
                if (primes[i]*j > number)
                    break;
                else
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }

    for(i = 2; i<=number; i++)
    {
        if (primes[i]!=0)
            printf("%d\n",primes[i]);
    }
  getch();
}