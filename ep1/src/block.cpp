#include <iostream>
#include "formas.hpp"
#include "campo.hpp"
#include "block.hpp"

Block::Block(int posX, int posY, char formaVivo) {
  setLarguraForma(2);
  setAlturaForma(2);
  setPosX(posX);
  setPosY(posY);
  setFormaVivo(formaVivo);
}

Block::Block(char formaVivo) {
  setLarguraForma(2);
  setAlturaForma(2);
  setPosX(3);
  setPosY(3);
  setFormaVivo(formaVivo);
}

Block::~Block() {}

int Block::inserirNoCampo(Campo *campo) {
  char formaVivo = getFormaVivo();
  int x = getPosX();
  int y = getPosY();

  if(!cabeNoCampo(campo))
    return 0;
  else {
    campo->setElemCampo(x + 0, y + 0, formaVivo);
    campo->setElemCampo(x + 0, y + 1, formaVivo);
    campo->setElemCampo(x + 1, y + 0, formaVivo);
    campo->setElemCampo(x + 1, y + 1, formaVivo);
    return 1;
  }
}
