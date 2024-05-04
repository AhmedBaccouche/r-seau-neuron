#include <stdio.h>
#include <math.h>
#include "loss.h"

double loss_function(double *y,double *prob_y,int n)
{
    double loss = 0;
    for (int i = 0; i < n; i++)
    {
        loss =loss + *(y+i) * log(*(prob_y+i)) + (1-*(y+i))*log(1-*(prob_y+i));
    }

    loss = -loss/n;
    return loss;
}
