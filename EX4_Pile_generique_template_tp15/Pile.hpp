#ifndef PILE_HPP
#define PILE_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

// Définir la classe template Pile
template<typename T>
class Pile {
private:
	std::vector<T> elements; // vecteur dynamique pour stocker les données

public:
	// Constructeur par défaut
	Pile() {
	}

	// Empiler un élément
	void empiler(T element) {
		elements.push_back(element);
	}

	// Dépiler l'élément
	T depiler() {
		if (estVide()) {
			throw std::runtime_error(
					"Exception : Impossible de depiler, la pile est vide !");
		}
		T sommetElement = elements.back();
		elements.pop_back(); // Retire le dernier élément
		return sommetElement;
	}

	// Retourner l'élément sans le retirer
	T sommet() const {
		if (estVide()) {
			throw std::runtime_error(
					"Exception : La pile est vide, aucun sommet disponible !");
		}
		return elements.back();
	}

	// Vérifier si la pile est vide
	bool estVide() const {
		return elements.empty();
	}

	// Inverser la pile
	void inverser() {
		std::reverse(elements.begin(), elements.end());
	}
};

#endif
