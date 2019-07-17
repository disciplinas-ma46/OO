#ifndef GLIDER_HPP
#define GLIDER_HPP

#include "formas.hpp"
#include "campo.hpp"

class Glider : public Formas {
public:
  Glider(int posX, int posY, char formaVivo);
	Glider(char formaVivo);

  ~Glider();

  int inserirNoCampo(Campo *campo);

};

#endif
