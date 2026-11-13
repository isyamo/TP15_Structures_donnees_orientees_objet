#ifndef TABLEHACHAGE_HPP
#define TABLEHACHAGE_HPP

#include <string>

class TableHachage {
private:
	// Structure interne pour un élément de la liste chaînée
	struct Noeud {
		int cle;
		std::string valeur;
		Noeud *suivant;

		Noeud(int c, std::string v) {
			cle = c;
			valeur = v;
			suivant = nullptr;
		}
	};

	int tailleTable;
	Noeud **table; // Tableau de pointeurs vers des listes chaînées

	// Fonction de hachage simple
	int hacher(int cle) const {
		return (cle % tailleTable + tailleTable) % tailleTable;
	}

public:
	// Constructeur et Destructeur
	TableHachage(int taille);
	~TableHachage();

	// Méthodes
	void inserer(int cle, std::string valeur);
	std::string rechercher(int cle) const;
	void supprimer(int cle);
	void afficher() const;
};

#endif
