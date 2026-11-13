#ifndef LISTECHAINEE_HPP
#define LISTECHAINEE_HPP

#include "Noeud.hpp"

class ListeChainee {
private:
	Noeud *tete; // Pointeur vers le premier élément de la liste

public:
	// Constructeur et Destructeur
	ListeChainee();
	~ListeChainee();

	// Méthodes
	void ajouterDebut(int valeur);
	void ajouterFin(int valeur);
	void supprimer(int valeur);
	void afficher() const;
	int taille() const;

	//  Itérateur personnalisé pour parcourir la liste
	class Iterator {
	private:
		Noeud *courant;
	public:
		Iterator(Noeud *ptr);
		bool operator!=(const Iterator &autre) const;
		Iterator& operator++();
		int& operator*();
	};

	Iterator begin();
	Iterator end();
};

#endif
