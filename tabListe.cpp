#include "tabListe.h"


TabListe::TabListe(size_t v) : taille(v), tab(new Liste [taille]){}

TabListe::~TabListe()
{
  if(taille != 0)
  {
    delete [] tab;
  }
}

size_t TabListe::getTaille() const
{
  return taille;
}

void TabListe::afficheT() const
{
  for(size_t i=0; i<taille; i++)
  {
    std::cout <<"tab[" << i << "] : ";
    this->tab[i].afficheL();
  }
}

Liste& TabListe::operator[](size_t i)
{
  if(i>taille)
  {
    error();
  }
  return tab[i];
}

void TabListe::error() const{
  std::cerr<<"Attention i>taille"<<std::endl;
  exit(EXIT_FAILURE);
}
