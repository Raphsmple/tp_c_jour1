#include <stdio.h>

int main(void) {

    float a = 17;
    int b = 5;

    float som = a + b;
    float sous = a - b;
    float mul = a * b;
    float div = a / b;

    int res = (int)a % b;

    printf("a = %.0f, b = %d\n", a, b);

    printf("somme: %f \n", som);
    printf("soustraction: %f \n", sous);
    printf("multiplication: %f \n", mul);
    printf("division: %f \n", div);

    printf("reste: %d \n", res);

    return 0;
}