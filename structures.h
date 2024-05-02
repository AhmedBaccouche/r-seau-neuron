#ifndef STRUCTURES
#define STRUCTURES

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
