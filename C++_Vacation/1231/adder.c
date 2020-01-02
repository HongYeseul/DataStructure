#include <stdio.h>

int add(int a, int b){
    return a+b;
}

float addf(float a, float b){
    return a+b;
}

int main(void){
    
    int sum = add(10, 20);
    float sumf = addf(10.5, 10.487);
    printf("%d %f\n", sum, sumf);
    return 0;
}
