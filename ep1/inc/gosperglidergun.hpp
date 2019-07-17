#ifndef GOSPER_HPP
#define GOSPER_HPP

#include "formas.hpp"
#include "campo.hpp"

class GosperGliderGun : public Formas {
public:
  GosperGliderGun(int posX, int posY, char formaVivo);
  GosperGliderGun(char formaVivo);
  ~GosperGliderGun();

  int inserirNoCampo(Campo *campo);

};

#endif
