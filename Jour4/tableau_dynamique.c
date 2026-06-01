#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    printf("Combien d'entiers voulez-vous stocker ? ");
    scanf("%d", &n);

    // Allocation dynamique
    int *tableau = (int *)malloc(n * sizeof(int));

    // Vérification de l'allocation
    if (tableau == NULL)
    {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    // Saisie des valeurs
    for (int i = 0; i < n; i++)
    {
        printf("Valeur %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    // Affichage des valeurs
    printf("\nValeurs saisies :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Calcul de la somme
    int somme = 0;
    for (int i = 0; i < n; i++)
    {
        somme += tableau[i];
    }

    // Calcul de la moyenne
    double moyenne = (double)somme / n;

    printf("Somme = %d\n", somme);
    printf("Moyenne = %.2f\n", moyenne);

    // Libération de la mémoire
    free(tableau);
    tableau = NULL;

    return 0;
}