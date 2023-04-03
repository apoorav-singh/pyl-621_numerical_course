// Algorithm for Backward Difference Method
// Code By: Apoorav Singh Deo
// Roll No: v19036


#include<math.h>
#include<stdlib.h>
#include<stdio.h>

double difference_backward(double y1, double y2, double h)
{
    double res;
    // Diffrentiating using Backward Difference Method
    res = (y1-y2)/h;
    //printf("%lf\n", res);
    return res;
}
