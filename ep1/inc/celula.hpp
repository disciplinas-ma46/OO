#ifndef CELULA_HPP
#define CELULA_HPP

class Celula {
private:
  char estado;
  int posX;
  int posY;

public:
  Celula(int x, int y, char estadoInicial);
  ~Celula();

  void proxGeracaoCelula(Campo *terreno, char vivo, char morto);

  char getEstado();
  void setEstado(char novoEstado);

  int getPosX();
  int getPosY();
};

#endif
