#ifndef __TABLISTE_H__
#define __TABLISTE_H__

/**
* \class TabListe
* \brief Classe représentant un tableau de listes de cellules
*/

#include "liste.h"

class TabListe
{
private:
	size_t taille;
	Liste* tab;

public:
	TabListe(size_t);
	//	~TabListe();
	size_t getTaille() const;
	/**
	* \fn error()
	* \brief Stratagème pour sortir du programme avec élégance
	* Affiche problèmes sur terminal en cas d'erreur
	*/
	void error() const;
	/**
	* \fn operator[](size_t)
	* \brief Sucre syntaxique évitant les seg. fault
	* \param i l'indice de la liste dans le tableau[O..taille-1]
	* \return tab[i]
	*/
	Liste &operator[](size_t) const;
	/**
	* \fn operator=()
	* \brief Surcharge opérateur
	*/
	void afficheT(std::ostream&) const;
};
/**
* \fn operator<<(&ostream, &TabListe)
* \brief Sucre syntaxique permettant l'affichage d'un tabListe
*/
std::ostream &operator<<(std::ostream&, const TabListe&);

#endif
