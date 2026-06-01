#include <iostream>
#include <string>

int main()
{
    std::string prenom;
    int age;
    float moyenne;

    std::cout << "Quel est ton prenom ? ";
    std::cin >> prenom;

    std::cout << "Quel est ton âge ? ";
    std::cin >> age;

    std::cout << "Quel est ta moyenne ? ";
    std::cin >> moyenne;



    std::cout << "Prenom : " << prenom << std::endl;
    std::cout << "age : " << age << std::endl;
    std::cout << "moyenne : " << moyenne << std::endl;


    return 0;
}