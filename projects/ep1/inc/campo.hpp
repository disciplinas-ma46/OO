#ifndef CAMPO_HPP
#define CAMPO_HPP

class Campo {
private:
  int larguraCampo;
  int alturaCampo;

  char *elementosDoCampo;
  char formaVivo;
  char formaMorto;

public:
  Campo(int altura, int largura, char vivo, char morto);
  ~Campo();

  void preencherCampo(char estado);
  void printarCampo();

  // faz as células do campo avançarem uma geração
  void aplicaRegras(Campo *campo);

  // obtém estado de um elemento do campo
  char getElemCampo(int x, int y);

  // muda estado de um elemento do campo
  void setElemCampo(int x, int y, char novoEstado);

  int getLarguraCampo();
  int getAlturaCampo();
};


#endif
