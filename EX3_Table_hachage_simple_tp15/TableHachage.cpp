#include <iostream>
#include "TableHachage.hpp"

TableHachage::TableHachage(int taille) {
	tailleTable = taille;
	table = new Noeud*[tailleTable];
	for (int i = 0; i < tailleTable; i++) {
		table[i] = nullptr;
	}
}

TableHachage::~TableHachage() {
	for (int i = 0; i < tailleTable; i++) {
		Noeud *actuel = table[i];
		while (actuel != nullptr) {
			Noeud *suivantSauve = actuel->suivant;
			delete actuel;
			actuel = suivantSauve;
		}
	}
	delete[] table;
}

// Insertion d'elet
void TableHachage::inserer(int cle, std::string valeur) {
	int index = hacher(cle);

	//  Verification de l'existance de la cle
	Noeud *actuel = table[index];
	while (actuel != nullptr) {
		if (actuel->cle == cle) {
			actuel->valeur = valeur;
			return;
		}
		actuel = actuel->suivant;
	}

	// Ajout d'un nouveau noeud
	Noeud *nouveau = new Noeud(cle, valeur);
	nouveau->suivant = table[index];
	table[index] = nouveau;
}

// Rechercher une valeur par la clé
std::string TableHachage::rechercher(int cle) const {
	int index = hacher(cle);
	Noeud *actuel = table[index];

	while (actuel != nullptr) {
		if (actuel->cle == cle) {
			return actuel->valeur;
		}
		actuel = actuel->suivant;
	}
	return "";
}

// Suppression d'un élément par sa clé
void TableHachage::supprimer(int cle) {
	int index = hacher(cle);
	Noeud *actuel = table[index];
	Noeud *precedent = nullptr;

	while (actuel != nullptr) {
		if (actuel->cle == cle) {
			if (precedent == nullptr) {
				table[index] = actuel->suivant;
			} else {
				precedent->suivant = actuel->suivant;
			}
			delete actuel;
			std::cout << "\n Clé " << cle << "\n supprimée avec succès.\n";
			return;
		}
		precedent = actuel;
		actuel = actuel->suivant;
	}
	std::cout << "\n Clé " << cle << " introuvable.\n";
}

// Affichage du contenu de chaque case avec les collisions
void TableHachage::afficher() const {
	for (int i = 0; i < tailleTable; i++) {
		std::cout << "\n Case " << i << " : ";
		Noeud *actuel = table[i];
		if (actuel == nullptr) {
			std::cout << "Vide";
		} else {
			while (actuel != nullptr) {
				std::cout << " [Clé: " << actuel->cle << ", Valeur: "
						<< actuel->valeur << "] -> ";
				actuel = actuel->suivant;
			}
			std::cout << "NULL";
		}
		std::cout << std::endl;
	}
}
