#include <iostream>
#include <string>
#include "Pile.hpp"

int main() {
    // Test avec des entiers
    std::cout << "\n  <<< TEST AVEC DES ENTIERS >>> " << std::endl;
    Pile<int> pileInt;

    pileInt.empiler(10);
    pileInt.empiler(20);
    pileInt.empiler(30);

    std::cout << "\n Sommet actuel : " << pileInt.sommet() << std::endl;
    std::cout << "\n Element depile : " << pileInt.depiler() << std::endl;
    std::cout << "\n Nouveau sommet apres depilage : " << pileInt.sommet() << std::endl;

    std::cout << "\n Inversion de la pile d'entiers " << std::endl;
    pileInt.inverser();
    std::cout << "\n Nouveau sommet apres inversion : " << pileInt.sommet() << std::endl;
    std::cout << std::endl;


    // Test Avec des chaînes de caractères
    std::cout << "\n <<< TEST AVEC DES CHAINES >>> " << std::endl;
    Pile<std::string> pileString;

    pileString.empiler("Bonjour");
    pileString.empiler("C++");
    pileString.empiler("Monde");

    std::cout << "\n Sommet string : " << pileString.sommet() << std::endl;
    pileString.depiler();
    std::cout << "\n Sommet string apres un retrait : " << pileString.sommet() << std::endl;
    std::cout << std::endl;


    // Test Avec des doubles et Gestion d'exception
    std::cout << "\n <<< TEST AVEC DES DOUBLES ET EXCEPTION >>> " << std::endl;
    Pile<double> pileDouble;

    pileDouble.empiler(3.14);
    pileDouble.empiler(9.81);

    std::cout << "\n Element depile : " << pileDouble.depiler() << std::endl;
    std::cout << "\n Element depile : " << pileDouble.depiler() << std::endl;

    // Exception déclencher lorsqu'on dépile une pile vide
    try {
        std::cout << "\n Tentative de depiler sur une pile vide " << std::endl;
        pileDouble.depiler();
    } catch (const std::exception& e) {
        std::cout << "\n Exception attrapee avec succes -> " << e.what() << std::endl;
    }

    return 0;
}
