#include <iostream>
#include "ListeChainee.hpp"

// Constructeur
ListeChainee::ListeChainee() {
	tete = nullptr;
}

// Destructeur
ListeChainee::~ListeChainee() {
	Noeud *actuel = tete;
	while (actuel != nullptr) {
		Noeud *suivantSauve = actuel->suivant;
		delete actuel;
		actuel = suivantSauve;
	}
}

// Ajouter un élément au début
void ListeChainee::ajouterDebut(int valeur) {
	Noeud *nouveau = new Noeud(valeur);
	nouveau->suivant = tete;
	tete = nouveau;
}

//  Ajouter un élément à la fin
void ListeChainee::ajouterFin(int valeur) {
	Noeud *nouveau = new Noeud(valeur);
	if (tete == nullptr) {
		tete = nouveau;
		return;
	}

	Noeud *actuel = tete;
	while (actuel->suivant != nullptr) {
		actuel = actuel->suivant;
	}
	actuel->suivant = nouveau;
}

// Supprimer un élément par sa valeur
void ListeChainee::supprimer(int valeur) {
	if (tete == nullptr)
		return;

	//  suppression en tête
	if (tete->valeur == valeur) {
		Noeud *temp = tete;
		tete = tete->suivant;
		delete temp;
		return;
	}

	// Recherche dans le reste de la liste
	Noeud *actuel = tete;
	while (actuel->suivant != nullptr && actuel->suivant->valeur != valeur) {
		actuel = actuel->suivant;
	}

	if (actuel->suivant != nullptr) {
		Noeud *temp = actuel->suivant;
		actuel->suivant = actuel->suivant->suivant;
		delete temp;
	}
}

// Afficher tous les éléments de la liste
void ListeChainee::afficher() const {
	Noeud *actuel = tete;
	while (actuel != nullptr) {
		std::cout << actuel->valeur << " -> ";
		actuel = actuel->suivant;
	}
	std::cout << "NULL" << std::endl;
}

// Retourner le nombre d'éléments
int ListeChainee::taille() const {
	int compteur = 0;
	Noeud *actuel = tete;
	while (actuel != nullptr) {
		compteur++;
		actuel = actuel->suivant;
	}
	return compteur;
}

// Implémentation de l'Itérateur
ListeChainee::Iterator::Iterator(Noeud *ptr) :
		courant(ptr) {
}

bool ListeChainee::Iterator::operator!=(const Iterator &autre) const {
	return courant != autre.courant;
}

ListeChainee::Iterator& ListeChainee::Iterator::operator++() {
	if (courant != nullptr) {
		courant = courant->suivant;
	}
	return *this;
}

int& ListeChainee::Iterator::operator*() {
	return courant->valeur;
}

ListeChainee::Iterator ListeChainee::begin() {
	return Iterator(tete);
}

ListeChainee::Iterator ListeChainee::end() {
	return Iterator(nullptr);
}
