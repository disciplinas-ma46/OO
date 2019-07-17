#include <iostream>
#include "formas.hpp"
#include "campo.hpp"
#include "glider.hpp"

Glider::Glider(int posX, int posY, char formaVivo) {
  setLarguraForma(3);
  setAlturaForma(3);
  setPosX(posX);
  setPosY(posY);
  setFormaVivo(formaVivo);
}

Glider::Glider(char formaVivo) {
  setLarguraForma(3);
  setAlturaForma(3);
  setPosX(1);
  setPosY(1);
  setFormaVivo(formaVivo);
}

Glider::~Glider() {}

int Glider::inserirNoCampo(Campo *campo) {
  char formaVivo = getFormaVivo();
  int x = getPosX();
  int y = getPosY();

  if(!cabeNoCampo(campo))
    return 0;
  else {
    campo->setElemCampo(x + 0, y + 1, formaVivo);
    campo->setElemCampo(x + 1, y + 2, formaVivo);
    campo->setElemCampo(x + 2, y + 0, formaVivo);
    campo->setElemCampo(x + 2, y + 1, formaVivo);
    campo->setElemCampo(x + 2, y + 2, formaVivo);

    return 1;
  }
}
