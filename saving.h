#ifndef SAVINGWBL_H_
#define SAVINGWBL_H_
#include<stdio.h>
#include<stdlib.h>
void saveWeightBiasLoss(double**,double,double);
void read_matrix(char *filename, double (*T)[COLS]);
int trouver(char ch[],char *filename);
int trouver_bias(char ch[],char *filename);
int trouver_weight(char ch[],char *filename);
void afficher(char *filename);
void min(char *filename, double *minimum, char *ligne);
void affiche_min(char *filename,char *var,double m);
#endif
