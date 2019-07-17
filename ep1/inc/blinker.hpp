#ifndef BLINKER_HPP
#define BLINKER_HPP

#include "formas.hpp"
#include "campo.hpp"

class Blinker : public Formas {
public:
  Blinker(int posX, int posY, char formaVivo);
  Blinker(char formaVivo);

  ~Blinker();

  int inserirNoCampo(Campo *campo);

};

#endif
