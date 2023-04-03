// Program to convert binary to decimal 

#include<stdio.h>
#include<math.h>
int d_b(long long n);

void main()
{   
    // n would be storing the number
    long long n;
    printf("Enter the binary number: ");
    scanf("%lld", &n);
    printf("%lld in binary = %d in decimal.\n", n,b_d(n));
}

int b_d(long long n)
{   
    // dec is the return value
    // i would define the index 
    // rem would store the index
    int dec=0, i=0, rem; 
    while(n!=0)
    {
        rem = n%10;
        n=n/10; // also be written as n/=10;
        dec += rem*pow(2,i);
        i+=1; 
    }
    // point when n=0 means number has shrinked to 
    // decimal regime
    return dec;
}

