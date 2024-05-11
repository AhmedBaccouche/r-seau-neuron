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





void read_matrix(char *filename, double (*T)[COLS]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    char line[1024]; // Assuming a maximum line length of 1024 characters
    int row = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), fp) && row < LINE) {
        char *token;
        int col = 0;

        // Parse the line using strtok
        token = strtok(line, ";");
        while (token != NULL && col < COLS) {
            // Convert token to float and store in the matrix
            T[row][col++]  = atof(token);
            token = strtok(NULL, ";");
        }

        row++; // Move to the next row
    }

    fclose(fp);
}






int trouver(char ch[],char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    int k=-1;
    for (int i=0;i<strlen(ch)-3;i++){
        if(ch[i]=='l' && ch[i+1]=='o' && ch[i+2]=='s' && ch[i+3]=='s'){
            k=i+5;
        }
    }
    fclose(fp);
    return k;
}
int trouver_bias(char ch[],char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    int k=-1;
    for (int i=0;i<strlen(ch)-3;i++){
        if(ch[i]=='b' && ch[i+1]=='i' && ch[i+2]=='a' && ch[i+3]=='s'){
            k=i+5;
        }
    }
    fclose(fp);
    return k;
}
int trouver_weight(char ch[],char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    int k=-1;
    for (int i=0;i<strlen(ch)-3;i++){
        if(ch[i]=='w' && ch[i+1]=='e' && ch[i+2]=='i' && ch[i+3]=='g' && ch[i+4]=='h' && ch[i+5]=='t'){
            k=i+8;
        }
    }
    fclose(fp);
    return k;
}
void afficher(char *filename)
{
FILE *fp;
fp = fopen(filename, "r");
if (fp == NULL)
{
    printf("Erreur lors de l'ouverture du fichier\n");
    return;
}
char var[101];
while(!feof(fp))
{
    while(fgets(var,100,fp))
    {
        printf("%s\n",var);
    }
}
fclose(fp);
}


void min(char *filename, double *minimum, char *ligne)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    char min[15]; // Temporary buffer to store the minimum value as string
    char var[101]; // Buffer to read each line from the file
    int i = 0;
    int k = 0;
    double mi;
    double m;
    int li = 0;
    char *y = NULL; // Pointer to dynamically allocated memory for storing the line
    size_t y_size = 0;

    while (fgets(var, 100, fp)) {
        i = trouver(var,filename);
        for (int j =i ; j < strlen(var) - 1; j++) {
            min[k] = var[j];
            k++;
        }
        min[k] = '\0';
        m = atof(min);
        k = 0;

        if (li == 0 || mi > m) {
            mi = m;
            if (y) {
                free(y); // Free previously allocated memory
            }
            y_size = strlen(var) + 1; // Include space for null terminator
            y = malloc(y_size); // Allocate memory for the line
            if (y == NULL) {
                // Handle memory allocation failure
                printf("Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strcpy(y, var);
        }
        li++;
    }

    *minimum = mi;
    if (y != NULL) {
        strcpy(ligne, y); // Copy the line to ligne
        free(y); // Free allocated memory
    } else {
        ligne[0] = '\0'; // Set ligne to empty string if y is NULL
    }
    fclose(fp);
}






void affiche_min(char *filename,char *var,double m)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    int j=0;
    int k=0;
    char biass[20];
    char w[20];
    char loss[20];
    j=trouver_bias(var,filename);
    while ((isdigit(var[j]) || var[j] == '.' || var[j] == '-' || var[j] == ',') && var[j] != '\0')
    {
        biass[k] = var[j];
        k++;
        j++;
    }
    j=trouver_weight(var,filename);
    k=0;
    while ((isdigit(var[j]) || var[j] == '.' || var[j] == '-' || var[j] == ',') && var[j] != '\0')
    {
        w[k] = var[j];
        k++;
        j++;
    }
    printf("w1,w2 = ");
    puts(w);
    printf("bias = ");
    puts(biass);
    printf("Loss = %f",m);
    fclose(fp);
}







