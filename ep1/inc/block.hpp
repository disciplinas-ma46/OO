#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "formas.hpp"
#include "campo.hpp"

class Block : public Formas {
public:
  Block(int posX, int posY, char formaVivo);
  Block(char formaVivo);

  ~Block();

  int inserirNoCampo(Campo *campo);

};

#endif
