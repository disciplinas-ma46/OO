#include <iostream>
#include "campo.hpp"
#include "celula.hpp"

Celula::Celula(int x, int y, char estadoInicial) {
  posX = x;
  posY = y;
  estado = estadoInicial;
}

Celula::~Celula() {}

void Celula::proxGeracaoCelula(Campo *terreno, char vivo, char morto) {
  int i, j, nroVizinhosVivos = 0;

  //essa parte conta quantos vizinhos vivos tem
  for(i=-1; i<2; i++)
    for(j=-1; j<2; j++)
      if((i || j) && terreno->getElemCampo(posX+i, posY+j)==vivo)
        nroVizinhosVivos++;

  //nessa parte aplicam-se as regras
  if(estado == vivo) {
		if(nroVizinhosVivos < 2)
			setEstado(morto);
		else if(nroVizinhosVivos > 3)
			setEstado(morto);
	} else {
		if(nroVizinhosVivos == 3)
			setEstado(vivo);
	}
}

char Celula::getEstado() {
  return estado;
}

void Celula::setEstado(char novoEstado) {
  estado = novoEstado;
}

int Celula::getPosX() {
  return posX;
}

int Celula::getPosY() {
  return posY;
}
