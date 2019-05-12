#ifndef CRUZAMENTO_H
#define CRUZAMENTO_H
#include "Rua.h"
#include <random>

class Cruzamento{

private:
	enum SEMAFORO { ESQ, DIR, CIMA, BAIXO, QUANTIDADE};

	Rua *esq, *dir, *cima, *baixo;
    int                 semaforo; //       1,2,3,4/esq,dir,cima,baixo
    const static double tempoVerde;
    const static double tempoAmarelo;
    const static double tempoTransferencia;
	static mt19937 mt;

public:
    Cruzamento();
    double  getTempoTroca();
    double  getTempoTrans();
    int     getSemaforo();
    Rua *getRuaSemaforo();
    Rua *getRuaSemaforo(int r);
    //seta os ponteiros para as ruas.
    void setRuas(Rua& e, Rua& d, Rua& c, Rua& b);
    //muda o semaforo para o proximo.
    void mudaSemaforo();

    //Metodo responsavel pela transferencia dos veiculos no cruzamento.
    //Retorna true caso consiga transferir, false caso contrario.
    //Desenfila da rua em que o semaforo esta verde e enfila em outra
    //definida aleatoriamente.
    bool transfereVeiculos();

};


#endif
