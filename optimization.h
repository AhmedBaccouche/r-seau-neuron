#ifndef OPTIMIZATION_H_
#define OPTIMIZATION_H_

double derivative_sigmoid(double a);
double derivative_loss(double y,double a);
double derivative_logLoss(double y,double a,double x);
double vect(double* w,double* x);
#endif
