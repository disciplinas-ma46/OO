// Aluno: Marcelo Araújo dos Santos
// Matrícula: 16/0035481
// Orientação a Objetos. Prof: Renato Sampaio
// UnB Campus do Gama. Data: 21/09/17

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "campo.hpp"
#include "celula.hpp"
#include "glider.hpp"
#include "block.hpp"
#include "blinker.hpp"
#include "gosperglidergun.hpp"
#include "formas.hpp"

#define LIMPAR "clear" //no Windows, trocar clear por clr
#define VIVO 'O'
#define MORTO ' '
#define NRO_CICLOS 100
#define VELOCIDADE 100000.0
#define TEMPO 10
#define MAX_CICLOS 5000
#define MAX_TEMPO 1200
#define ALTURA 20
#define LARGURA 40
#define MAX_ALTURA 30
#define MAX_LARGURA 70

using namespace std;

// protótipos de funções
void imprimirMenu();
void demonstrarForma(char qualForma, int ciclos, double velocidade, Campo *terreno);
void configurar(int *ciclos, double *velocidade, int *altura, int *largura, Campo *terreno);
void desenhar(int ciclos, double velocidade, Campo *terreno);

int main() {
  char controle = 's';
  int altura = 20;
  int largura = 40;
  int ciclos = NRO_CICLOS;
  double velocidade = VELOCIDADE;

  Campo *terreno;

  try {
    terreno = new Campo(altura, largura, VIVO, MORTO);
  }
  catch(...) {
    cout << "\n\nNão foi possível criar campo!!!\n\n";
  }

  while(controle != '0') {
	  //terreno->printarCampo();
    imprimirMenu();
    cin >> controle;

    switch (controle) {
      case '1':
        demonstrarForma(controle, ciclos, velocidade, terreno); //GosperGliderGun
        break;
      case '2':
        demonstrarForma(controle, ciclos, velocidade, terreno); //Glider
        break;
      case '3':
        demonstrarForma(controle, ciclos, velocidade, terreno); //Blinker
        break;
      case '4':
        demonstrarForma(controle, ciclos, velocidade, terreno); //Block
        break;
      case '5':
        desenhar(ciclos, velocidade, terreno);
        break;
      case '6':
        configurar(&ciclos, &velocidade, &altura, &largura, terreno);
        break;
      case '0':
        cout << "\n\nSaindo do jogo...\n\n";
        break;
      default:
        cout << "\nOpção inválida! Digite uma das opções listadas\n";
        sleep(2.5);
    }
  }
  //delete(gun);
  delete(terreno);
  return 0;
}

//=================  SUBPROGRAMAS =================

void imprimirMenu() {
  system(LIMPAR);
  cout << "\t>>> Bem vindo ao jogo da vida de Conway (Conway's Game of Life) <<<" << endl;
  cout << "\n\nDigite o valor da opção e aperte ENTER\n\n";
  cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
  cout << "* 1: Gosper glider gun (atira gliders)          *" << endl;
  cout << "* 2: Glider (nave espacial)                     *" << endl;
  cout << "* 3: Blinker (oscilador)                        *" << endl;
  cout << "* 4: Block (figura estática)                    *" << endl;
  cout << "* 5: Desenhar próprio campo                     *" << endl;
  cout << "* 6: Configurações                              *" << endl;
  cout << "*                                               *" << endl;
  cout << "* 0: Sair                                       *" << endl;
  cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
  cout << "\n(Obs: Maximize o terminal para campos maiores)\n\n" << endl << endl;
}

void desenhar(int ciclos, double velocidade, Campo *terreno) {
  GosperGliderGun *gun = new GosperGliderGun(VIVO);
  Glider *glider = new Glider(VIVO);
  Blinker *blincker = new Blinker(VIVO);
  Block *bloco = new Block(VIVO);
  terreno->preencherCampo(MORTO);
  int x, y;
  char continuar;

  do{
    system(LIMPAR);
    cout << "Escolha uma forma para Inserir ou 'c' para iniciar: \n";
    cout << "* 1: Gosper glider gun" << endl;
    cout << "* 2: Glider (nave espacial)" << endl;
    cout << "* 3: Blinker (oscilador)" << endl;
    cout << "* 4: Block (figura estática)" << endl;
    cout << "* c: iniciar" << endl;
    cin >> continuar;
    system(LIMPAR);
    if(continuar != 'c') {
      cout << "\nDigite a posição x da forma: ";
      cin >> x;
      cout << "\nDigite a posição y da forma: ";
      cin >> y;
    }


    switch (continuar) {
      case '1': //GosperGliderGun
        gun->setPosX(x);
        gun->setPosY(y);
        gun->inserirNoCampo(terreno);
        break;
      case '2': //Glider
        glider->setPosX(x);
        glider->setPosY(y);
        glider->inserirNoCampo(terreno);
        break;
      case '3': //Blinker
        blincker->setPosX(x);
        blincker->setPosY(y);
        blincker->inserirNoCampo(terreno);
        break;
      case '4': //Block
        bloco->setPosX(x);
        bloco->setPosY(y);
        bloco->inserirNoCampo(terreno);
        break;
      case 'c':
        cout << "\n\nIniciando...";
        sleep(1);
        break;
    }

  }while(continuar != 'c');

  for(int i = 0; i<=ciclos; i++) {
    terreno->printarCampo();
    terreno->aplicaRegras(terreno);
    cout << "\ngeração: " << i;
    usleep(velocidade);
  }
  terreno->preencherCampo(MORTO);
  system(LIMPAR);

  delete(gun);
  delete(glider);
  delete(blincker);
  delete(bloco);

  cout << "\nFinalizado! Foram mostradas " << ciclos << " gerações.";
  cout << "\nDigite alguma coisa e pressione ENTER para voltar ao menu: ";
  cin >> continuar;
}

void configurar(int *ciclos, double *velocidade, int *altura, int *largura, Campo *terreno) {
  char opcao;
  int tempo;
  tempo = (int)(((*ciclos) * (*velocidade)) / 1000000);
  do{
    system(LIMPAR);

    cout << "\tDigite o valor da opção que deseja configurar e aperte ENTER\n\n";
    cout << " 1: N° de ciclos (valor atual: " << *ciclos << ")" << endl;
    cout << " 2: Tempo de execução (tempo aprox.: " << tempo << " segundos)" << endl;
    cout << " 3: Largura do Campo (valor atual: " << *largura << ")" << endl;
    cout << " 4: Altura do Campo (valor atual: " << *altura << ")" << endl;
    cout << " 5: Voltar às configurações padrão" << endl;
    cout << "\n";
    cout << " 0: Sair das configurações\n\n";

    cin >> opcao;
    system(LIMPAR);

    switch (opcao) {
      case '1':
        cout << "Digite o n° de ciclos (min 2 e máx " << MAX_CICLOS << "): ";
        cin >> *ciclos;
        while (*ciclos < 2 || *ciclos > MAX_CICLOS) {
          cout << "\n\nValor inválido! Digite novamente: ";
          cin >> *ciclos;
        }
        break;
      case '2':
        cout << "Digite o tempo de execução (min 1 seg. e máx " << MAX_TEMPO << " segunos): ";
        cin >> tempo;
        while (tempo < 1 || tempo > MAX_TEMPO) {
          cout << "\n\nValor inválido! Digite novamente: ";
          cin >> tempo;
        }
        break;
      case '3':
        cout << "Digite a largura: ";
        cin >> *largura;
        while (*largura < 5 || *largura > MAX_LARGURA) {
          cout << "\n\nValor inválido! Digite novamente:  (min 5 e máx " << MAX_LARGURA << "): ";
          cin >> *largura;
        }
        break;
      case '4':
        cout << "Digite a altura: ";
        cin >> *altura;
        while (*altura < 5 || *altura > MAX_ALTURA) {
          cout << "\n\nValor inválido! Digite novamente:  (min 5 e máx " << MAX_ALTURA << "): ";
          cin >> *altura;
        }
        break;
      case '5':
      *ciclos = NRO_CICLOS;
      tempo = TEMPO;
      *altura = ALTURA;
      *largura = LARGURA;
        break;
      case '0':
        delete(terreno);
        terreno = new Campo(*altura, *largura, VIVO, MORTO);
        *velocidade = (double)((tempo*1000000)/(*ciclos));
        cout << "\n\nSaindo... ";
        sleep(1.5);
        system(LIMPAR);
        break;
      default:
        cout << "\n\nOpção desconhecida!";
        sleep(2);
    }
  }while(opcao != '0');

}





void demonstrarForma(char qualForma, int ciclos, double velocidade, Campo *terreno) {
  GosperGliderGun *gun = new GosperGliderGun(VIVO);
  Glider *glider = new Glider(VIVO);
  Blinker *blincker = new Blinker(VIVO);
  Block *bloco = new Block(VIVO);
  char continuar;
  int inseriuNoCampo;

  do{
    system(LIMPAR);
    switch (qualForma) {
      case '1': //GosperGliderGun
        inseriuNoCampo = gun->inserirNoCampo(terreno);
        break;
      case '2': //Glider
        inseriuNoCampo = glider->inserirNoCampo(terreno);
        break;
      case '3': //Blinker
        inseriuNoCampo = blincker->inserirNoCampo(terreno);
        break;
      case '4': //Block
        inseriuNoCampo = bloco->inserirNoCampo(terreno);
        break;
    }
    if(inseriuNoCampo) {
      for(int i = 0; i<=ciclos; i++) {
        terreno->printarCampo();
        terreno->aplicaRegras(terreno);
        cout << "\ngeração: " << i;
        usleep(velocidade);
      }
      terreno->preencherCampo(MORTO);
      system(LIMPAR);
      cout << "\nDemonstração terminada. Foram mostradas " << ciclos << " gerações.";
      cout << "\nDigite 'c' e ENTER para repetir ou outra coisa para voltar ao menu: ";
      cin >> continuar;
    }
    else
      continuar = '-';


  }while(continuar == 'c');

  delete(gun);
  delete(glider);
  delete(blincker);
  delete(bloco);
}
