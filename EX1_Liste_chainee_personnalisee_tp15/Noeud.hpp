#ifndef NOEUD_HPP
#define NOEUD_HPP

class Noeud {
public:
	int valeur;
	Noeud *suivant;   // Pointeur vers le noeud suivant

	Noeud(int val) {
		valeur = val;
		suivant = nullptr;
	}
};

#endif
