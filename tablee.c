#include <stdio.h>

int main(void) {
    int reponse;
    int resultat;
    printf("Nombre (0 pour quitter): ");
    scanf("%d", &reponse);


do {
    for (int i = 1; i <= 10; i++) {
        resultat = reponse * i;
        printf("%d * %d = %d\n", reponse, i, resultat);
    }
    printf("Nombre (0 pour quitter): ");
    scanf("%d", &reponse);
} while (reponse != 0);

}