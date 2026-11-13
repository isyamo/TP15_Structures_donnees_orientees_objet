#include <iostream>
#include "ListeChainee.hpp"

int main() {
	ListeChainee maListe;

	maListe.ajouterFin(10);
	maListe.ajouterFin(20);
	maListe.ajouterDebut(5);
	maListe.ajouterDebut(2);

	std::cout << "\n Liste initiale : ";
	maListe.afficher();

	std::cout << "\n Taille de la liste : " << maListe.taille() << std::endl;

	maListe.supprimer(10);
	std::cout << "\n Apres suppression de 10 : ";
	maListe.afficher();

	std::cout << "\n Parcours avec l'iterateur : ";
	for (int val : maListe) {
		std::cout << val << " -> ";
	}
	std::cout << std::endl;

	return 0;
}
