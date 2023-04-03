// Algorithm for Central Difference Method
// Code By: Apoorav Singh Deo
// Roll No: v19036

#include<math.h>
#include<stdlib.h>
#include<stdio.h>

double difference_centeral(double y1, double y2, double h)
{
    double res;
    // Diffrentiating using Central Difference Method
    res = (y2-y1)/(2*h);
    //printf("%lf\n", res);
    return res;
}
