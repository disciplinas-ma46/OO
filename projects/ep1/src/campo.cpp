#include "campo.hpp"
#include "celula.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define LIMPAR "clear"

using namespace std;

Campo::Campo(int altura, int largura, char vivo, char morto) {
  alturaCampo = altura;
  larguraCampo = largura;
  formaVivo = vivo;
  formaMorto = morto;

  elementosDoCampo = (char*)calloc(largura*altura, sizeof(char));
  if(elementosDoCampo == NULL) {
    throw 1;
  }
  preencherCampo(morto);
}

Campo::~Campo() {
  free(elementosDoCampo);
}

void Campo::printarCampo() {
  int i, j;

  system(LIMPAR);
  printf("\n");
  for(i=0; i<larguraCampo; i++)
    printf("--");
  printf("--");
  for(i=0; i<alturaCampo; i++) {
    printf("\n|");
    for(j=0; j<larguraCampo; j++)
      cout << *(elementosDoCampo + i*larguraCampo + j) << ' ';
    printf("|");
  }
  printf("\n");
  for(i=0; i<larguraCampo; i++)
    printf("--");
  printf("--\n");
}

void Campo::aplicaRegras(Campo *campo) {
	int i, j;
	int altura = campo->getAlturaCampo();
	int largura = campo->getLarguraCampo();

	Celula *celulas[altura][largura];
  //vetor de células recebe célula do campo, e avança uma geração
  for(i=0; i<altura; i++)
    for(j=0; j<largura; j++) {
      celulas[i][j] = new Celula(i, j, campo->getElemCampo(i,j));
      celulas[i][j]->proxGeracaoCelula(campo, formaVivo, formaMorto);
    }
  //campo recebe novas células
  for(i=1; i<altura-1; i++)
  	for(j=1; j<largura-1; j++)
   		campo->setElemCampo(i, j, celulas[i][j]->getEstado());
  //liberação da memória alocada de celulas
  for(i=0; i<altura; i++)
    for(j=0; j<largura; j++)
      free(celulas[i][j]);
}

void Campo::preencherCampo(char estado) {
  int i, j;

  for(i=0; i<alturaCampo; i++)
    for(j=0; j<larguraCampo; j++)
      *(elementosDoCampo + i*larguraCampo + j) = estado;
}

char Campo::getElemCampo(int x, int y) {
  return *(elementosDoCampo + x*larguraCampo + y);
}

void Campo::setElemCampo(int x, int y, char novoEstado) {
  *(elementosDoCampo + x*larguraCampo + y) = novoEstado;
}


int Campo::getLarguraCampo() {
  return larguraCampo;
}

int Campo::getAlturaCampo() {
  return alturaCampo;
}
