#include <stdio.h>
#include "structures.h"
#include "forwardpropagation.h"
#include "backpropagation.h"

void train_network(layer *input_layer, layer *output_layer, double learning_rate, int epochs, double expected_output) {
    for (int i = 0; i < epochs; i++) {
        forward_propagation(input_layer, output_layer);
        backward_propagation(input_layer, output_layer, learning_rate, expected_output);
    }
}
