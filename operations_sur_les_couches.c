#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "structures.c"
#include "operations_sur_les_couches.h"

#define COLS 3
#define LINE 100

layer *creer_couche(int nombre_neuronnes)
{
    layer *layer1=(layer*)malloc(sizeof(layer));
    neuron *current_neuron=NULL;
    if (layer1==NULL)
    {
        printf("erreur d'allocation !");
        return;
    }

    layer1->neuron=(neuron*)malloc(sizeof(neuron));
    if (layer1->neuron==NULL)
    {
        printf("erreur d'allocation !");
        return;
    }
    initialiser_neuronne(layer1->neuron);
    layer1->neuron->prev=NULL;
    current_neuron=layer1->neuron;

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




void read_matrix(char *filename, double (*T)[LINE][COLS])
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    char line[1024]; // Assuming a maximum line length of 1024 characters
    int row = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), fp)) {
        char *token;
        int col = 0;

        // Parse the line using strtok
        token = strtok(line, ",");
        while (token != NULL && col < COLS) {

            double a= atof(token); // Convert token to integer and store in the matrix
            strcpy(T[row][col++],token);
            token = strtok(NULL, ",");
        }

        row++; // Move to the next row
    }

    fclose(fp);
}

