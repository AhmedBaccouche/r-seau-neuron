#include <stdio.h>
#include "structures.h"
#include "activation.h"

void backward_propagation(layer *input_layer, layer *output_layer, double learning_rate, double expected_output) {
    neuron *input_neuron = input_layer->neuron;
    neuron *output_neuron = output_layer->neuron;

    while (output_neuron != NULL) {
        double error = (expected_output - output_neuron->output) * derivative_sigmoid(output_neuron->output);
        neuron *input_neuron_ptr = input_layer->neuron;

        while (input_neuron_ptr != NULL) {
            input_neuron_ptr->weight += learning_rate * error * input_neuron_ptr->output;
            input_neuron_ptr = input_neuron_ptr->next;
        }

        output_neuron->bias += learning_rate * error;
        output_neuron = output_neuron->next;
    }
}
