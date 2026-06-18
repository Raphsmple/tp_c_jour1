#include <stdio.h>
#include "bibliotheque.h"

int main()
{
    Livre livres[MAX_LIVRES];
    int nbLivres = 0;
    int choix;

    chargerLivres(livres, &nbLivres);

    do
    {
        printf("\n=== BIBLIOTHEQUE ===\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher\n");
        printf("4. Emprunter / Rendre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Sauvegarder et quitter\n");

        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix)
        {
            case 1:
                ajouterLivre(livres, &nbLivres);
                break;

            case 2:
                afficherLivres(livres, nbLivres);
                break;

            case 3:
                rechercherLivre(livres, nbLivres);
                break;

            case 4:
                emprunterRendreLivre(livres, nbLivres);
                break;

            case 5:
                supprimerLivre(livres, &nbLivres);
                break;

            case 6:
                sauvegarderLivres(livres, nbLivres);
                printf("Bibliotheque sauvegardee.\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while(choix != 6);

    return 0;
}