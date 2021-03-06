#include "tabListe.h"

TabListe::TabListe(sint v) : taille(v), tab(new Liste [taille]){}

TabListe::~TabListe()
{
  if(tab)
  {
    delete [] tab;
    taille=0;
  }
}

sint TabListe::getTaille() const
{
  return taille;
}

void TabListe::error() const
{
  std::cerr << "Attention i>taille" << std::endl;
  this->~TabListe();
  exit(EXIT_FAILURE);
}

Liste& TabListe::operator[](sint i) const
{
  if(i>taille)
  {
    error();
  }
  return tab[i];
}

void TabListe::afficheT(std::ostream &os) const
{
  for(size_t i=0; i<taille; i++)
  {
    os << "tab[" << i << "] : ";
    this->tab[i].afficheL(os);
  }
}

std::ostream &operator<<(std::ostream &os, const TabListe &T)
{
  T.afficheT(os);
  return os;
}
