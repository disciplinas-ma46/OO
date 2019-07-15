#ifndef FORMAS_HPP
#define FORMAS_HPP

#include "campo.hpp"

//classe mãe Formas, no qual as classes Block, Glider etc. herdam suas características
class Formas {
private:
  int posX;
  int posY;
  int largura;
  int altura;
  char formaVivo;

public:
  Formas();
  ~Formas();

  //verifica se a forma cabe no campo, retorna 1 se sim, e 0 se não
  int cabeNoCampo(Campo *campo);

  int getPosX();
  int getPosY();
  void setPosX(int novaPosX);
  void setPosY(int novaPosY);

  int getLarguraForma();
  int getAlturaForma();
  void setLarguraForma(int largura);
  void setAlturaForma(int altura);

  void setFormaVivo(char formaVivo);
  char getFormaVivo();
};

#endif
