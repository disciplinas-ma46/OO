#include <iostream>
#include "formas.hpp"
#include "campo.hpp"
#include "gosperglidergun.hpp"

using namespace std;

GosperGliderGun::GosperGliderGun(int posX, int posY, char formaVivo) {
  setLarguraForma(36);
  setAlturaForma(9);
  setPosX(posX);
  setPosY(posY);
  setFormaVivo(formaVivo);
}

GosperGliderGun::GosperGliderGun(char formaVivo) {
  setLarguraForma(36);
  setAlturaForma(9);
  setPosX(1);
  setPosY(1);
  setFormaVivo(formaVivo);
}

GosperGliderGun::~GosperGliderGun() {}

int GosperGliderGun::inserirNoCampo(Campo *campo) {
  char formaVivo = getFormaVivo();
  int x = getPosX();
  int y = getPosY();

  if(!cabeNoCampo(campo))
    return 0;
  else {
    campo->setElemCampo(x + 4, y + 0, formaVivo);
    campo->setElemCampo(x + 4, y + 1, formaVivo);
    campo->setElemCampo(x + 5, y + 0, formaVivo);
    campo->setElemCampo(x + 5, y + 1, formaVivo);

    campo->setElemCampo(x + 4, y + 10, formaVivo);
    campo->setElemCampo(x + 5, y + 10, formaVivo);
    campo->setElemCampo(x + 6, y + 10, formaVivo);

    campo->setElemCampo(x + 3, y + 11, formaVivo);
    campo->setElemCampo(x + 7, y + 11, formaVivo);

    campo->setElemCampo(x + 2, y + 12, formaVivo);
    campo->setElemCampo(x + 2, y + 13, formaVivo);
    campo->setElemCampo(x + 8, y + 12, formaVivo);
    campo->setElemCampo(x + 8, y + 13, formaVivo);

    campo->setElemCampo(x + 5, y + 14, formaVivo);

    campo->setElemCampo(x + 3, y + 15, formaVivo);
    campo->setElemCampo(x + 7, y + 15, formaVivo);

    campo->setElemCampo(x + 4, y + 16, formaVivo);
    campo->setElemCampo(x + 5, y + 16, formaVivo);
    campo->setElemCampo(x + 6, y + 16, formaVivo);

    campo->setElemCampo(x + 5, y + 17, formaVivo);

    campo->setElemCampo(x + 2, y + 20, formaVivo);
    campo->setElemCampo(x + 3, y + 20, formaVivo);
    campo->setElemCampo(x + 4, y + 20, formaVivo);
    campo->setElemCampo(x + 2, y + 21, formaVivo);
    campo->setElemCampo(x + 3, y + 21, formaVivo);
    campo->setElemCampo(x + 4, y + 21, formaVivo);

    campo->setElemCampo(x + 1, y + 22, formaVivo);
    campo->setElemCampo(x + 5, y + 22, formaVivo);

    campo->setElemCampo(x + 0, y + 24, formaVivo);
    campo->setElemCampo(x + 1, y + 24, formaVivo);
    campo->setElemCampo(x + 5, y + 24, formaVivo);
    campo->setElemCampo(x + 6, y + 24, formaVivo);

    campo->setElemCampo(x + 2, y + 34, formaVivo);
    campo->setElemCampo(x + 2, y + 35, formaVivo);
    campo->setElemCampo(x + 3, y + 34, formaVivo);
    campo->setElemCampo(x + 3, y + 35, formaVivo);

    return 1;
  }
}
