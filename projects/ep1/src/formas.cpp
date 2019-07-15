#include "formas.hpp"
#include "campo.hpp"

#include <iostream>

using namespace std;

Formas::Formas() {
  posX = 2;
  posY = 2;
  largura = 2;
  altura = 2;
}

Formas::~Formas() {}

int Formas::cabeNoCampo(Campo *campo) {
  char aux;
  int naoCabe = 0;

  if(getPosY() + getLarguraForma() >= campo->getLarguraCampo())
    naoCabe = 1;
  else
    if(getPosX() + getAlturaForma() >= campo->getAlturaCampo())
      naoCabe = 1;

  if(naoCabe) {
    cout << "\nEssa forma não cabe no campo!!! Digite algo para continuar" << '\n';
    cin >> aux;
    return 0;
  }
  else
    return 1;
}

int Formas::getPosX() {
  return posX;
}

int Formas::getPosY() {
  return posY;
}

void Formas::setPosX(int novaPosX) {
  while (novaPosX < 1) {
    cout << "\n\nDigite Valor maior que 0 para posição X: ";
    cin >> novaPosX;
  }
  posX = novaPosX;
}

void Formas::setPosY(int novaPosY) {
  while (novaPosY < 1) {
    cout << "\n\nDigite Valor maior que 0 para posição Y: ";
    cin >> novaPosY;
  }
  posY = novaPosY;
}


int Formas::getLarguraForma() {
  return largura;
}

int Formas::getAlturaForma() {
  return altura;
}

void Formas::setLarguraForma(int largura) {
  this->largura = largura;
}

void Formas::setAlturaForma(int altura) {
  this->altura = altura;
}

void Formas::setFormaVivo(char formaVivo) {
  this->formaVivo = formaVivo;
}

char Formas::getFormaVivo() {
  return formaVivo;
}
