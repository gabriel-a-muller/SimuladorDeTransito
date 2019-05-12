#ifndef TRAFEGO_H
#define TRAFEGO_H
#include "Cruzamento.h"
#include "gerador.h"

//classe responsabilizida por organizar os metodos
//e logicas de simulacao;
class Trafego{
private:
    Cruzamento  c1,c2;
    Rua         r1, r2, r3, r4, r5, r6, r7;
    Gerador     g1, g2, g3, g4, g5, g6;


public:
    Trafego(MainWindow* mw);
    //Trafego(const Trafego &t);
    void setRuas();
    void setGeradores();
    void setCruzamentos();

    void mudaSemaforos();
    void geraCarros1();
    void geraCarros2();
    void simulador();
};
#endif
