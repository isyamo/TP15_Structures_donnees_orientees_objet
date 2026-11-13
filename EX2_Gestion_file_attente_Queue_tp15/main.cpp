#include <iostream>
#include <stdexcept>
#include "File.hpp"

int main() {
	// Création d'une file
	File maFile(5);

	std::cout << "\n <<< TEST DE L'ETAT INITIAL >>> " << std::endl;
	if (maFile.estVide()) {
		std::cout << "\n La file est initialement vide.\n" << std::endl;
	}

	std::cout << "\n <<< AJOUT D'ELEMENTS >>> " << std::endl;
	maFile.enfiler(10);
	maFile.enfiler(20);
	maFile.enfiler(30);
	maFile.afficher();
	std::cout << std::endl;

	std::cout << "\n <<< RETRAIT D'UN ELEMENT >>> " << std::endl;
	try {
		int elementRetire = maFile.defiler();
		std::cout << "\n Element retire : " << elementRetire << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	maFile.afficher();
	std::cout << std::endl;

	std::cout << "\n <<< TEST DU TABLEAU CIRCULAIRE ET FILE PLEINE >>> "
			<< std::endl;

	maFile.enfiler(40);
	maFile.enfiler(50);
	maFile.enfiler(60);
	maFile.afficher();

	if (maFile.estPleine()) {
		std::cout << "\n La file est maintenant pleine !\n" << std::endl;
	}

	std::cout << "\n <<< TEST DE LA GESTION D'EXCEPTION de FILE VIDE >>> "
			<< std::endl;
	// Vider la file
	while (!maFile.estVide()) {
		maFile.defiler();
	}
	maFile.afficher();

	// Défiler la file vide pour déclenche l'exception
	try {
		std::cout << "\n Tentative de defiler sur une file vide "
				<< std::endl;
		maFile.defiler();
	} catch (const std::exception &e) {
		std::cout << "\n Exception attrapee avec succes -> " << e.what()
				<< std::endl;
	}

	return 0;
}
