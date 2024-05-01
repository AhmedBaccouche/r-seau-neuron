#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Fonction qui génere un output de la neuronne d'entrée en fonction des output des neuronnes de la couche précédente
void  unitary_output(neuronne *neuron,double input[2])
{
    double output=0;
    for(i=0;i<2;i++)
    {
        output=output+neuron->weight[a]*input[2];
    }
    n->bias = (rand() / (double)RAND_MAX) * 2 - 1;
    n->output = 0;
}

//Fonction qui initialise le bias et weight à une valeur aléatoire, et l
void initialiser_neuronne(neuronne *neuron){
    srand(time(NULL));
    for (int i = 0; i < 2; i++)
    {
        neuron->weight[i] = (rand()/(double)RAND_MAX) * 2 - 1;
    }
    neuron->bias = (rand()/(double)RAND_MAX) * 2 - 1;
    neuron->output = 0;
