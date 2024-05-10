#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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








