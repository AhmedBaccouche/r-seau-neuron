#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "activation.h"

double sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}


//unité de rectification linéaire
double Relu(double x)
{
    if (x>0){
        return x;
    }
    else{
        return 0;
    }
}

double tanh (double x)
{
    return (exp(2*x)-1)/(exp(2*x)+1);
}

//max{min{x,1},-1}
double hard_tanh (double x)
{
    double y;
    if(x>1)
    {
        y=1;
    }
    else
    {
        y=x;
    }
    if(y>-1)
    {
        return y;
    }
    else
    {
        return -1;
    }
}

