#ifndef NEURAL_NETWORK_H_INCLUDED
#define NEURAL_NETWORK_H_INCLUDED

#include <stdio.h>
#include <math.h>

struct neuron {
    double output;
    double bias;
    double weight[2];
    struct neuron *next;
    struct neuron *prev;
};
typedef struct neuron neuron;

struct layer {
    int num_neurons;
    neuron *neuron;
};
typedef struct layer layer;
