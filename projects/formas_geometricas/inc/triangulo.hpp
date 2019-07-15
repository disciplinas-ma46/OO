#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP

#include "formageometrica.hpp"

class Triangulo : public FormaGeometrica{
   public:
     Triangulo(float base, float altura);

     // Sobrescrita de Método
     float calculaArea();
     float calculaPerimetro();

}


#endif
