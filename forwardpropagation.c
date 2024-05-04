#include <stdio.h>
#include "structures.h"
#include "activation.h"
#include "forwardpropagation.h"

void forward_propagation(layer *input_layer, layer *output_layer) {
    neuron *input_neuron = input_layer->neuron;
    neuron *output_neuron = output_layer->neuron;

    while (output_neuron != NULL) {
        double weighted_sum = 0;
        neuron *input_neuron_ptr = input_layer->neuron;

        while (input_neuron_ptr != NULL) {
            weighted_sum += input_neuron_ptr->output * input_neuron_ptr->weight;
            input_neuron_ptr = input_neuron_ptr->next;
        }

        weighted_sum += output_neuron->bias;
        output_neuron->output = sigmoid(weighted_sum);

        output_neuron = output_neuron->next;
    }
}
