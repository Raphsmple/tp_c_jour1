#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#define MAX_LIVRES 100

typedef struct
{
    char titre[100];
    char auteur[100];
    int annee;
    int disponible; // 1 = disponible, 0 = emprunté
} Livre;

void ajouterLivre(Livre livres[], int *nbLivres);
void afficherLivres(Livre livres[], int nbLivres);
void rechercherLivre(Livre livres[], int nbLivres);
void emprunterRendreLivre(Livre livres[], int nbLivres);
void supprimerLivre(Livre livres[], int *nbLivres);
void sauvegarderLivres(Livre livres[], int nbLivres);
void chargerLivres(Livre livres[], int *nbLivres);

#endif