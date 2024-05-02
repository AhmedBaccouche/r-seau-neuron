_Simple Neural Network in C_

## Structure 

1. `neuron` :formé par
   - `output` 
   - `bias` 
   - `weight`
   - `next` : pointeur sur le neuron suivant dans la couche
   - `prev` : pointeur sur le neuron précédent dans la couche

2. `layer`:formé par
   - `neuron` : pointeur sur le premier neuron de la couche
   - `num_neurons` : Le nombre de neurones dans le layer

## IMLPLEMENTATION

l'implementation contient les fonctionnalités suivantes:
1. **Initialization**
2. **Activation Function**
