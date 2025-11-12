#include "advanced_ops.h"

double mypow(double base, double n){
    double result = 1.0;
    for(int i = 0; i < (int)n; i++){
        result *= base;
    }
    return result;
}