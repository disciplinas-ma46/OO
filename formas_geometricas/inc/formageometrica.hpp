#ifndef FORMAGEOMETRICA_HPP
#define FORMAGEOMETRICA_HPP

#include <string>

using namespace std;

class FormaGeometrica {
   protected:
   //private:
      string tipo;
      int lados;
      float base;
      float altura;
   public:
      FormaGeometrica();
      FormaGeometrica(string tipo, int lados, float base, float altura);
      string getTipo();
      void setTipo(string tipo);
      int getLados();
      void setLados(int lados);
      float getBase();
      void setBase(float base);
      float getAltura();
      void setAltura(float altura);

      float calculaArea();
      float calculaPerimetro();

}

#endif
