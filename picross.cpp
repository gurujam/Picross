#include "picross.h"

//constructeur
Picross::Picross(size_t nbl, size_t nbc):mat(nbl, nbc),lignes(nbl),colonnes(nbc)
{}
void Picross::remplirTabListe(std::ifstream& f)
{
  size_t val,i=0;
  while(i<lignes.getTaille())
  {
    while(f.peek()!='\n')
    {
      f>>val; //je lit l'indice
      lignes[i].putFin(val); //je le rajoute a la liste
    }
    f.ignore(); //le '\n'
    i++;  //on change de ligne
  }
  i=0;
  while(i<colonnes.getTaille())
  {
    while(f.peek()!='\n')
    {
      f>>val;
      colonnes[i].putFin(val);
    }
    f.ignore();
    i++;
  }
}
//accesseur
TabListe Picross::getLignes() const
{
  return lignes;
}
TabListe Picross::getColonnes() const
{
  return colonnes;
}
Matrice Picross::getMat() const
{
  return mat;
}
//Methode
int* Picross::tabGauche(size_t ind, bool b)
{
  switch(b)
  {
  case 0:
  {
    size_t taille=colonnes.getTaille();//on traite une ligne
    size_t nbcell=lignes[ind].getLongueur();
    int* tab=new int [taille];
    size_t j=0;//l'indice du tab
    size_t cpt=0;//boucle cases à noircir
    size_t v=1;//valeur de la case noircie pour l'identifier ensuite
    for(size_t i=1; i<=nbcell; i++)//pour chaque cellule de la liste
    {
      while(cpt<lignes[ind](i).getVal());//on remplit getVal cases
      {
        tab[j]=v;
        j++;
        cpt++;
      }
      ++j;//la case blanche
      ++v;
      cpt=0;
    }
    return tab;
  }
    break;
  case 1:
  {
    size_t taille=lignes.getTaille();
    int* tab=new int [taille];
    size_t nbcell=colonnes[ind].getLongueur();
    size_t cpt=0;
    size_t j=0;
    size_t v=1;
    for(size_t i=1; i<=nbcell; i++)
    {
      while(cpt<colonnes[ind](i).getVal());
      {
        tab[j]=v;
        j++;
        cpt++;
      }
      ++j;
      ++v;
      cpt=0;
    }
    return tab;
  }
    break;
  default:
    return NULL;
    break;
  }
}
int* Picross::tabDroite(size_t ind, bool b)
{
  switch(b)
  {
  case 0:
  {
    size_t taille=colonnes.getTaille();//on traite une ligne
    size_t nbcell=lignes[ind].getLongueur();
    int* tab=new int [taille];
    size_t j=taille;//l'indice du tab
    size_t cpt=0;//boucle cases à noircir
    while(nbcell>0)//pour chaque cellule de la liste
    {
      while(cpt<lignes[ind](nbcell).getVal());//on part de la fin
      {
        tab[j]=nbcell;
        j--;
        cpt++;
      }
      --j;//la case blanche
      --nbcell;
      cpt=0;
    }
    return tab;
  }
  break;
  case 1:
  {
    size_t taille=lignes.getTaille();
    int* tab=new int [taille];
    size_t nbcell=colonnes[ind].getLongueur();
    size_t j=taille;
    size_t cpt=0;
    while(nbcell>0)
    {
      while(cpt<colonnes[ind](nbcell).getVal());
      {
        tab[j]=nbcell;
        j--;
        cpt++;
      }
      --j;
      --nbcell;
      cpt=0;
    }
    return tab;
  }
  break;
  default:
    return NULL;
    break;
  }
}
int* Picross::mergeTab(int *T1, int *T2, int n)
{
  int* T=new int [n];

  for(int i=0; i<n; i++)
  {
    /* On à mis l'indice de la cellule dans la liste en valeur dans les T
    On passe sur les 0 qui s'entrecroisent,
    on ne peut les determiner par cette methode que pour les lignes pleines */
    if(T1[i]!=0 && T1[i]==T2[i])
    {
      T[i]=1;
    }
  }
  return T;
}
void Picross::remplirMat(size_t ind, int* T, bool b)
{
  switch(b)
  {
  case 0:
  {
    size_t taille=colonnes.getTaille();
    for(size_t i=0; i<taille; i++)
    {
      mat[ind][i]=T[i];
    }
    break;
  }
  case 1:
  {
    size_t taille=lignes.getTaille();
    for(size_t i=0; i<taille; i++)
    {
      mat[ind][i]=T[i];
    }
    break;
  }
  }
}
void Picross::afficheP(std::ostream &os) const
{
  os<<"Lignes : "<<std::endl;
  lignes.afficheT(os);
  os<<"Colonnes : "<<std::endl;
  colonnes.afficheT(os);
  os<<"Matrice : "<<std::endl;
  mat.afficheM(os);
}

//operateur d'affichage
std::ostream &operator<<(std::ostream& os, Picross &P)
{
  P.afficheP(os);
  return os;
}
