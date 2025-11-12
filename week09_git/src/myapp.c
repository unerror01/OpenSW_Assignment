#include <stdio.h>

double calulate(char* op, double a, double b){
    printf("Calculating.....\n");
}


int main(){

    double a,b;
    char op[3];

    printf("~~~ Welcome to my calulator ~~~\n\n");
    printf("Enter expression (e.g. 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);
    printf("Result: %.2lf\n", calulate(op, a, b));

    return 0;
}