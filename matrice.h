#ifndef __MATRICE_H__
#define __MATRICE_H__
#include <string>
#include <iostream>

using namespace std;
//enum class Color  {?, rouge, noir};

class Matrice
{
  private:
    size_t nbl;
    size_t nbc;
    int** mat;

  public:
    Matrice(size_t nbl, size_t nbc);
    ~Matrice();

    int** getMat()const;
    size_t getNbc()const;
    size_t getNbl()const;
    void affiche_ter(std::ostream& f)const;
};
#endif
