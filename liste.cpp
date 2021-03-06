#include "liste.h"

Liste::Liste():tete(NULL), longueur(0), fini(false){}

Liste::~Liste()
{
  Cell* ptr=tete;
  while(!isnull(tete))
  {
    ptr=ptr->getSuiv();
    delete tete;
    tete=ptr;
  }
  longueur=0;
  fini=false;
}

bool Liste::isnull(Cell* p) const
{
  return !p;
}

Cell* Liste::getPremier() const
{
  return tete;
}

sint Liste::getLongueur() const
{
  return longueur;
}

bool Liste::getFini() const
{
  return fini;
}

void Liste::setFini(bool b)
{
  fini=b;
}
void Liste::add(sint v)
{
  if(isnull(tete))
  {
    tete=new Cell(v);
  }
  else
  {
    Cell* ptr=new Cell(v);
    ptr->setSuiv(tete);
    tete=ptr;
  }
  ++longueur;
}
void Liste::putFin(sint v)
{
  if(isnull(tete))
  {
    tete=new Cell(v);
  }
  else
  {
    Cell* ptr=tete;
    for(size_t j=1; j<longueur; j++)
    {
      ptr=ptr->getSuiv();
    }
    Cell* c=new Cell(v);
    ptr->setSuiv(c);
  }
  ++longueur;
}

sint Liste::cutHd()
{
  sint val=0;
  if(!isnull(tete))
  {
    val=tete->getVal();
    Cell* ptr=tete->getSuiv();
    delete tete;
    tete=ptr;
    --longueur;
  }
  return val;
}

sint Liste::somElem() const
{
    int som = 0;
    Cell* ptr=tete;
    while (!isnull(ptr))
      {
        som += ptr->getVal();
        ptr = ptr->getSuiv();
      }
    return som+longueur-1;
}

sint Liste::somCell() const
{
  sint som = 0;
  Cell* ptr=tete;
  while(!isnull(ptr))
  {
    som += ptr->getVal();
    ptr = ptr->getSuiv();
  }
  return som;
}

bool Liste::appartient(sint val) const
{
  Cell* ptr = tete;
  while (!isnull(ptr) && ptr->getVal() != val)
  {
    ptr = ptr->getSuiv();
  }
  return !isnull(ptr);
}

Liste& Liste::operator=(const Liste& c)
{
  if(!isnull(tete))
  {
    this->~Liste();
  }
  Cell *ptr=c.getPremier();
  while(!isnull(ptr))
  {
    this->putFin(ptr->getVal());
    ptr=ptr->getSuiv();
  }
  this->setFini(c.getFini());
  return *this;
}

Cell* Liste::operator()(sint i) const
{
  if(i>longueur)
  {
    exit(EXIT_FAILURE);
  }
  else
  {
    if(i<=1)
    {
      return tete;
    }
    else
    {
      Cell* ptr=tete;
      for(size_t j=1; j<i; j++)
      {
        ptr=ptr->getSuiv();
      }
      return ptr;
    }
  }
}

Liste* Liste::inverseL_cst() const
{
  Liste* Res=new Liste();
  Cell* ptr=tete;
  while(!isnull(ptr))
  {
    Res->add(ptr->getVal());
    ptr=ptr->getSuiv();
  }
  return Res;
}
void Liste::afficheL(std::ostream &os) const
{
  Cell* ptr=tete;
  std::string sep="";
  while(!isnull(ptr))
  {
    os << sep << ptr->getVal();
    ptr=ptr->getSuiv();
    sep="->";
  }
  os << std::endl;
}

std::string Liste::afficheListe() const
{
  std::stringstream ss;
  Cell* ptr=tete;
  std::string sep="";
  while(!isnull(ptr))
  {
    ss <<sep <<ptr->getVal();
    ptr=ptr->getSuiv();
    sep=" ";
  }
  return ss.str();
}

std::string Liste::afficheListeV() const
{
  std::stringstream ss;
  //  std::string str;
  Cell* ptr=tete;
  while(!isnull(ptr))
  {
    ss << ptr->getVal()<<std::endl;
    ptr=ptr->getSuiv();
  }
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Liste &L)
{
  L.afficheL(os);
  return os;
}
