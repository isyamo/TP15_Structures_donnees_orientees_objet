#include <iostream>
#include <string>
#include "TableHachage.hpp"

int main() {
	// Création d'une table de hachage de taille 5
	TableHachage maTable(5);

	// Insertion
	maTable.inserer(5, "Pomme");
	maTable.inserer(10, "Banane");
	maTable.inserer(2, "Orange");
	maTable.inserer(7, "Fraise");

	std::cout << "\n <<< CONTENU DE LA TABLE DE HACHAGE >>> " << std::endl;
	maTable.afficher();

	// Recherche
	std::cout << "\n <<< RECHERCHE DE LA CLE 7 >>> " << std::endl;
	std::string resultat = maTable.rechercher(7);
	if (!resultat.empty()) {
		std::cout << "\n Trouvé ! Valeur : " << resultat << std::endl;
	} else {
		std::cout << "\n Non trouvé." << std::endl;
	}

	// Suppression
	std::cout << "\n <<< SUPPRESSION DE LA CLE 10 >>>" << std::endl;
	maTable.supprimer(10);

	std::cout << "\n <<< CONTENU APRES SUPPRESSION >>> " << std::endl;
	maTable.afficher();

	return 0;
}
