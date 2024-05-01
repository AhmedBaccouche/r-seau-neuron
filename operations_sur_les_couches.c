#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structures.c"


layer *creer_couche(int nombre_neuronnes)
{
    layer *layer1=(layer*)malloc(sizeof(layer));
    neuron *current_neuron=NULL;
    if (layer1==NULL)
    {
        printf("erreur d'allocation !");
        return;
    }

    layer1->neuronne=(neuron*)malloc(sizeof(neuron));
    if (layer1->neuronne==NULL)
    {
        printf("erreur d'allocation !");
        return;
    }
    initialiser_neuronne(layer1->neuronne);
    layer1->neuronne->prev=NULL;
    current_neuron=layer1->neuronne;

    for(i=0;i<nombre_neuronnes-1;i++)
    {
        current_neuron->next=(neuron*)malloc(sizeof(neuron));
        if (current_neuron->next==NULL)
        {
            printf("erreur d'allocation !");
            return;
        }
        initialiser_neuronne(current_neuron);
        current_neuron->next->prev=current_neuron;
        current_neuron=current_neuron->next;
        }
    }
}

