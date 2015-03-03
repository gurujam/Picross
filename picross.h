#ifndef __PICROSS_H__
#define __PICROSS_H__
#include "tabListe.h"
#include "matrice.h"
#include <fstream>

class Picross
{
 private:
  Matrice mat;
  TabListe lignes;
  TabListe colonnes;
 public:

  //constructeur
  Picross(size_t, size_t);
  //les lignes puis les colonnes
  void remplirTabListe(std::ifstream& f);
  //accesseur
  TabListe getLignes() const;
  TabListe getColonnes() const;
  void setLigneMat(size_t ind, int* Tab);
  int* getLigneMat(size_t ind)const;
  void setColonneMat(size_t ind, int* Tab);
  int* getColonneMat(size_t ind)const;
  Matrice getMat() const;
  /**
  * \fn tabGauche(size_t ind, bool b);
  * \param ind : l'indice de la liste; b : lignes ou colonnes
  * \return T rempli d'entiers identidiant leurs cellules
  */
  int* tabGauche(size_t ind, bool b);
  int* tabDroite(size_t ind, bool b);
  /**
  * \fn mergeTab(int *T1, int *T2, int n);
  * \param tabGauche, tabDroite, taille
  * \return T rempli de 1 là ou les id se chevauchent
  */
  int* mergeTab(int *T1, int *T2, size_t n);
  /**
  * \fn pushMat(size_t ind, int *T, bool b);
  * \brief copie le resultat de merge dans la matrice
  */
  void pushMat(size_t ind, int *T, bool b);
  /**
  * \fn remplirMat(bool b)
  * \brief 0>lignes, 1>colonnes
  */
  void solCasesSure(bool b);

  void afficheP(std::ostream&) const;
  int* solGauche(int* ligne, Liste L, size_t i);
  void solutionPaD(int* tab, int taille,int indice, bool lig);

};
std::ostream& operator<<(std::ostream&, Picross&);
#endif
