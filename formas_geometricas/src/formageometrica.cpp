#include "formageometrica.hpp"

FormaGeometrica::FormaGeometrica(){
   tipo = "Generico";
   lados = 4;
   base = 10.0;
   altura = 5.0;
}
FormaGeometrica::FormaGeometrica(string tipo, int lados, float base, float altura) {
   this->tipo = tipo;
   this->lados = lados;
   this->base = base;
   this->altura = altura;
}

string FormaGeometrica::getTipo(){
   return tipo;
}
void FormaGeometrica::setTipo(sting tipo){
   this->tipo = tipo;
}
int FormaGeometrica::getLados(){
   return lados;
}
void FormaGeometrica::setLados(int lados){
   this->lados = lados;
}
float FormaGeometrica::getBase(){
   return base;
}
void FormaGeometrica::setBase(float base){
   this->base = base;
}
float FormaGeometrica::getAltura(){
   return altura;
}
void FormaGeometrica::setAltura(float altura){
   this->altura = altura;
}

float FormaGeometrica::calculaArea(){
   return base*altura;
}
float FormaGeometrica::calculaPerimetro(){
   return 2*(base+altura);
}






