#include <iostream>
#include <string>

class Etudiant
{
private:
    std::string nom;
    int age;
    double moyenne;

public:
    // Constructeur avec liste d'initialisation
    Etudiant(std::string n, int a, double m)
        : nom(n), age(a), moyenne(m)
    {
    }

    void ajouterNote(double note)
    {
        moyenne = (moyenne + note) / 2;
    }

    bool estMajeur() const
    {
        return age >= 18;
    }

    void afficher() const
    {
        std::cout << "Nom : " << nom << std::endl;
        std::cout << "Age : " << age << std::endl;
        std::cout << "Moyenne : " << moyenne << std::endl;
        std::cout << "Majeur : ";

        if (estMajeur())
        {
            std::cout << "Oui";
        }
        else
        {
            std::cout << "Non";
        }

        std::cout << std::endl;
    }

    std::string getNom() const
    {
        return nom;
    }

    double getMoyenne() const
    {
        return moyenne;
    }
};

int main()
{
    const int NB_ETUDIANTS = 5;

    std::string nom;
    int age;
    double moyenne;

    Etudiant* etudiants[NB_ETUDIANTS];

    // Saisie
    for (int i = 0; i < NB_ETUDIANTS; i++)
    {
        std::cout << "\nEtudiant " << i + 1 << std::endl;

        std::cout << "Nom : ";
        std::cin >> nom;

        std::cout << "Age : ";
        std::cin >> age;

        std::cout << "Moyenne : ";
        std::cin >> moyenne;

        etudiants[i] = new Etudiant(nom, age, moyenne);
    }

    // Affichage
    std::cout << "\n===== Liste des etudiants =====\n";

    for (int i = 0; i < NB_ETUDIANTS; i++)
    {
        etudiants[i]->afficher();
        std::cout << std::endl;
    }

    // Moyenne de la promotion
    double somme = 0;

    for (int i = 0; i < NB_ETUDIANTS; i++)
    {
        somme += etudiants[i]->getMoyenne();
    }

    double moyennePromotion = somme / NB_ETUDIANTS;

    std::cout << "Moyenne de la promotion : "
              << moyennePromotion << std::endl;

    // Meilleur étudiant
    int meilleurIndice = 0;

    for (int i = 1; i < NB_ETUDIANTS; i++)
    {
        if (etudiants[i]->getMoyenne() >
            etudiants[meilleurIndice]->getMoyenne())
        {
            meilleurIndice = i;
        }
    }

    std::cout << "\n===== Meilleur etudiant =====\n";
    std::cout << "Nom : "
              << etudiants[meilleurIndice]->getNom()
              << std::endl;

    std::cout << "Moyenne : "
              << etudiants[meilleurIndice]->getMoyenne()
              << std::endl;

    // Libération mémoire
    for (int i = 0; i < NB_ETUDIANTS; i++)
    {
        delete etudiants[i];
    }

    return 0;
}