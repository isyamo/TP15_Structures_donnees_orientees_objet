#ifndef FILE_HPP
#define FILE_HPP

#include <stdexcept>

class File {
private:
	int *tableau;
	int capacite;
	int debut;
	int fin;
	int tailleActuelle;

public:
	// Constructeur et Destructeur
	File(int tailleMax);
	~File();

	// Méthodes
	bool estVide() const;
	bool estPleine() const;
	void enfiler(int valeur);
	int defiler();
	void afficher() const;
};

#endif
