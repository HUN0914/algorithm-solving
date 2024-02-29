#include <stdio.h>


int main (void) {
    
    int input; 
    double sum;
    double max=0;
    
    scanf("%d", &input);
    
    double sc[input];
    
    for(int i=0; i<input; i++) {
        scanf("%lf ", sc+i);
        if (sc[i] > max) max = sc[i];
        }
    
    for(int i=0; i<input; i++) {
        sc[i] = (sc[i]/max)*100;
        sum += sc[i];
    }
    
    printf("%.2lf", sum/input);
    
}