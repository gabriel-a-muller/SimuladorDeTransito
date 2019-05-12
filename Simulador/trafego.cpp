#include "Trafego.h"
#include "mainwindow.h"

Trafego::Trafego(MainWindow *mw) : g1(mw),g2(mw),g3(mw),g4(mw),g5(mw),g6(mw) {
    setRuas();
    setGeradores();
    setCruzamentos();
}

/*Trafego::Trafego(const Trafego &t) : {
    c1 = t.c1; c2 = t.c2;
    r1 = t.r1; r2 = t.r2; r3 = t.r3; r4 = t.r4; r5 = t.r5; r6 = t.r6; r7 = t.r7;
    g1 = t.g1; g2 = t.g2; g3 = t.g3; g4 = t.g4; g5 = t.g5; g6 = t.g6;
}*/

void Trafego::setRuas()
{
    r1.setCFSGE(0,  200,'h','e',230);
    r2.setCFSGE(260,460,'h','x',230);
    r3.setCFSGE(520,720,'h','d',230);
    r4.setCFSGE(0,  200,'v','e',230);
    r5.setCFSGE(260,460,'v','d',230);
    r6.setCFSGE(0,  200,'v','e',490);
    r7.setCFSGE(260,460,'v','d',490);
}

void Trafego::setGeradores(){
    g1.setRua(r1,2);
    g2.setRua(r4,2);
    g3.setRua(r6,2);
    g4.setRua(r3,1);
    g5.setRua(r7,1);
    g6.setRua(r5,1);
}

void Trafego::setCruzamentos(){
    c1.setRuas(r1,r2,r4,r5);
    c2.setRuas(r2,r3,r6,r7);
}

void Trafego::mudaSemaforos(){
    c1.mudaSemaforo();
    c2.mudaSemaforo();
    //qDebug() << c2.getSemaforo();
}

void Trafego::geraCarros2()
{
    g1.criaCarro();
    g2.criaCarro();
    g5.criaCarro();
}

void Trafego::geraCarros1()
{
    g3.criaCarro();
    g4.criaCarro();
    g6.criaCarro();
}

void Trafego::simulador(){
    c1.transfereVeiculos();
    c2.transfereVeiculos();
    r1.atualizaVeiculos();
    r2.atualizaVeiculos();
    r3.atualizaVeiculos();
    r4.atualizaVeiculos();
    r5.atualizaVeiculos();
    r6.atualizaVeiculos();
    r7.atualizaVeiculos();
    r1.carroFim1();
    r3.carroFim2();
    r4.carroFim1();
    r5.carroFim2();
    r6.carroFim1();
    r7.carroFim2();
}
