#include <iostream>
#include "formas.hpp"
#include "campo.hpp"
#include "blinker.hpp"

Blinker::Blinker(int posX, int posY, char formaVivo) {
  setLarguraForma(1);
  setAlturaForma(3);
  setPosX(posX);
  setPosY(posY);
  setFormaVivo(formaVivo);
}

Blinker::Blinker(char formaVivo) {
  setLarguraForma(1);
  setAlturaForma(3);
  setPosX(2);
  setPosY(2);
  setFormaVivo(formaVivo);
}

Blinker::~Blinker() {}

int Blinker::inserirNoCampo(Campo *campo) {
  char formaVivo = getFormaVivo();
  int x = getPosX();
  int y = getPosY();

  if(!cabeNoCampo(campo))
    return 0;
  else {
    campo->setElemCampo(x + 0, y + 0, formaVivo);
    campo->setElemCampo(x + 1, y + 0, formaVivo);
    campo->setElemCampo(x + 2, y + 0, formaVivo);
    return 1;
  }
}
