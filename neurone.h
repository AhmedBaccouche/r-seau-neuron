#ifndef NEURAL_NETWORK_H_INCLUDED
#define NEURAL_NETWORK_H_INCLUDED

#include <stdio.h>
#include <math.h>

struct neuron {
    double output ;
    double bias;
    double weight;
};
typedef struct neuron neuron;

struct layer {
    int n;
    neuron *t;
};
typedef struct layer layer;
