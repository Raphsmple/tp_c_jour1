#include <stdio.h>
#include <string.h>
#include "bibliotheque.h"

void ajouterLivre(Livre livres[], int *nbLivres)
{
    if (*nbLivres >= MAX_LIVRES)
    {
        printf("Bibliotheque pleine.\n");
        return;
    }

    printf("Titre : ");
    scanf(" %[^\n]", livres[*nbLivres].titre);

    printf("Auteur : ");
    scanf(" %[^\n]", livres[*nbLivres].auteur);

    printf("Annee de publication : ");
    scanf("%d", &livres[*nbLivres].annee);

    livres[*nbLivres].disponible = 1;

    (*nbLivres)++;

    printf("Livre ajoute avec succes.\n");
}

void afficherLivres(Livre livres[], int nbLivres)
{
    if (nbLivres == 0)
    {
        printf("Aucun livre dans la bibliotheque.\n");
        return;
    }

    printf("\n===== LISTE DES LIVRES =====\n");

    for (int i = 0; i < nbLivres; i++)
    {
        printf("\nLivre %d\n", i + 1);
        printf("Titre : %s\n", livres[i].titre);
        printf("Auteur : %s\n", livres[i].auteur);
        printf("Annee : %d\n", livres[i].annee);
        printf("Statut : %s\n",
               livres[i].disponible ? "Disponible" : "Emprunte");
    }
}

void rechercherLivre(Livre livres[], int nbLivres)
{
    char recherche[100];
    int trouve = 0;

    printf("Titre ou auteur a rechercher : ");
    scanf(" %[^\n]", recherche);

    for (int i = 0; i < nbLivres; i++)
    {
        if (strstr(livres[i].titre, recherche) != NULL ||
            strstr(livres[i].auteur, recherche) != NULL)
        {
            printf("\nTitre : %s\n", livres[i].titre);
            printf("Auteur : %s\n", livres[i].auteur);
            printf("Annee : %d\n", livres[i].annee);
            printf("Statut : %s\n",
                   livres[i].disponible ? "Disponible" : "Emprunte");

            trouve = 1;
        }
    }

    if (!trouve)
    {
        printf("Aucun livre trouve.\n");
    }
}

void emprunterRendreLivre(Livre livres[], int nbLivres)
{
    int numero;

    if (nbLivres == 0)
    {
        printf("Aucun livre disponible.\n");
        return;
    }

    afficherLivres(livres, nbLivres);

    printf("\nNumero du livre : ");
    scanf("%d", &numero);

    if (numero < 1 || numero > nbLivres)
    {
        printf("Numero invalide.\n");
        return;
    }

    livres[numero - 1].disponible =
        !livres[numero - 1].disponible;

    printf("Statut modifie.\n");
}

void supprimerLivre(Livre livres[], int *nbLivres)
{
    int numero;

    if (*nbLivres == 0)
    {
        printf("Aucun livre a supprimer.\n");
        return;
    }

    afficherLivres(livres, *nbLivres);

    printf("\nNumero du livre a supprimer : ");
    scanf("%d", &numero);

    if (numero < 1 || numero > *nbLivres)
    {
        printf("Numero invalide.\n");
        return;
    }

    for (int i = numero - 1; i < *nbLivres - 1; i++)
    {
        livres[i] = livres[i + 1];
    }

    (*nbLivres)--;

    printf("Livre supprime.\n");
}

void sauvegarderLivres(Livre livres[], int nbLivres)
{
    FILE *f = fopen("livres.txt", "w");

    if (f == NULL)
    {
        printf("Erreur lors de la sauvegarde.\n");
        return;
    }

    for (int i = 0; i < nbLivres; i++)
    {
        fprintf(f,
                "%s;%s;%d;%d\n",
                livres[i].titre,
                livres[i].auteur,
                livres[i].annee,
                livres[i].disponible);
    }

    fclose(f);
}

void chargerLivres(Livre livres[], int *nbLivres)
{
    FILE *f = fopen("livres.txt", "r");

    if (f == NULL)
    {
        return;
    }

    *nbLivres = 0;

    while (fscanf(f,
                  "%99[^;];%99[^;];%d;%d\n",
                  livres[*nbLivres].titre,
                  livres[*nbLivres].auteur,
                  &livres[*nbLivres].annee,
                  &livres[*nbLivres].disponible) == 4)
    {
        (*nbLivres)++;

        if (*nbLivres >= MAX_LIVRES)
        {
            break;
        }
    }

    fclose(f);
}