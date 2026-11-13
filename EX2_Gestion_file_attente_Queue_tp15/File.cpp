#include <iostream>
#include "File.hpp"

// Constructeur
File::File(int tailleMax) {
	capacite = tailleMax;
	tableau = new int[capacite];
	debut = 0;
	fin = -1;
	tailleActuelle = 0;
}

// Destructeur
File::~File() {
	delete[] tableau;
}

// Vérifie si la file est vide
bool File::estVide() const {
	return tailleActuelle == 0;
}

// Vérifie si la file est pleine
bool File::estPleine() const {
	return tailleActuelle == capacite;
}

// Ajouter un élément à la fin de la file
void File::enfiler(int valeur) {
	if (estPleine()) {
		std::cout << "\n Erreur : La file est pleine ! Impossible d'enfiler "
				<< valeur << ".\n";
		return;
	}
	// Gestion circulaire de l'indice de fin
	fin = (fin + 1) % capacite;
	tableau[fin] = valeur;
	tailleActuelle++;
	std::cout << "\n Succès : " << valeur << " a été enfilé.\n";
}

// Retirer un élément du début de la file
int File::defiler() {
	// exeption pour le cas de la pile vide
	if (estVide()) {
		throw std::runtime_error(
				" Exception : Impossible de défiler, la file est vide !");
	}
	int valeurRetiree = tableau[debut];
	// Gestion  de l'indice de début
	debut = (debut + 1) % capacite;
	tailleActuelle--;
	return valeurRetiree;
}

// Afficher les éléments de la file
void File::afficher() const {
	if (estVide()) {
		std::cout << "\n La file est actuellement vide.\n";
		return;
	}
	std::cout << "\n Contenu de la file  : ";
	for (int i = 0; i < tailleActuelle; i++) {
		int index = (debut + i) % capacite;
		std::cout << tableau[index] << " ";
	}
	std::cout << std::endl;
}
