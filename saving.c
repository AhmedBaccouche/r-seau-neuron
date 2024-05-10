#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 3
#define LINE 100


void saveWeightBiasLoss(double weight[],double bias,double loss){
    FILE*fp;
    fp=fopen("weightsbiasloss.txt","a");
    fprintf(fp,"weights=%lf,%lf-bias=%lf-loss=%lf\n",weight[0],weight[1],bias,loss) ;
    fclose(fp);
}
int main(){
    double weight[]={1,2};
    saveWeightBiasLoss(weight,2.2,3.2);
    return 0;
}





void read_matrix(char *filename, double (*T)[COLS])
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    char line[1024]; // Assuming a maximum line length of 1024 characters
    int row = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), fp) && row < LINE)
    {
        char *token;
        int col = 0;

        // Parse the line using strtok
        token = strtok(line, ";");
        double value =  strtod(token, NULL); // Convert token to double
        T[row][col++] = value; // Store in the matrix
        token = strtok(NULL, ";");
        value =  strtod(token, NULL); // Convert token to double
        T[row][col++] = value; // Store in the matrix
        token = strtok(NULL, ";");
        value =  strtod(token, NULL);// Convert token to double
        T[row][col++] = value; // Store in the matrix

        row++; // Move to the next row
    }
    fclose(fp);
}







