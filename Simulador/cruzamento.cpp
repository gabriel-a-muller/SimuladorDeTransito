#include <QDebug>
#include "Cruzamento.h"

Cruzamento::Cruzamento(){esq=NULL;dir=NULL;cima=NULL;baixo=NULL;semaforo=0;}

double Cruzamento::getTempoTroca() {return (tempoVerde+tempoAmarelo);}
double Cruzamento::getTempoTrans() {return tempoTransferencia;}

int Cruzamento::getSemaforo()
{
    return semaforo;
}

Rua *Cruzamento::getRuaSemaforo()
{
    Rua *aux = NULL;
    if     (semaforo == 1) aux = esq;
    else if(semaforo == 2) aux = dir;
    else if(semaforo == 3) aux = cima;
    else if(semaforo == 4) aux = baixo;
    return aux;
}

Rua *Cruzamento::getRuaSemaforo(int r)
{
    Rua *aux = NULL;
    if     (r == 1) aux = esq;
    else if(r == 2) aux = dir;
    else if(r == 3) aux = cima;
    else if(r == 4) aux = baixo;
    return aux;
}

void Cruzamento::setRuas(Rua& e, Rua& d, Rua& c, Rua& b){esq = &e; dir = &d; cima = &c; baixo = &b;}//verificar
void Cruzamento::mudaSemaforo(){
    semaforo++;
    if(semaforo==5) semaforo=1;

}


//VERIFICAR!
bool Cruzamento::transfereVeiculos(){
    //qDebug() << "teste";
    uniform_int_distribution<int>dist(1,4);
    Veiculo v;
    int de    = semaforo;
    int para  = dist(mt);
    while(de==para) para = dist(mt);

    if(de == 1){
        if(esq->carroFim2()){
           // qDebug() << "teste";
            v = esq->getVeiculo2();
            if(para == 2){
                if(!dir->ruaCheia2(v)){
                    esq->saiVeiculo2();
                    dir->entraVeiculo2(v);
                    return true;
                }
            }
            else if(para == 3){
                if(!cima->ruaCheia1(v)){
                    //rotacionar
                    esq->saiVeiculo2();
                    cima->entraVeiculo1(v);
                    return true;
                }
            }
            else if(para == 4){
                if(!baixo->ruaCheia2(v)){
                    //rotacionar
                    esq->saiVeiculo2();
                    baixo->entraVeiculo2(v);
                    return true;
                }
            }
        }
    }
    else if(de == 2){

        if(dir->carroFim1()){
            v = dir->getVeiculo1();
            if(para == 1){
                if(!esq->ruaCheia1(v)){
                    dir->saiVeiculo1();
                    esq->entraVeiculo1(v);
                    return true;
                }
            }
            else if(para == 3){
                if(!cima->ruaCheia1(v)){
                    //rotacionar
                    dir->saiVeiculo1();
                    cima->entraVeiculo1(v);
                    return true;
                }
            }
            else if(para == 4){
                if(!baixo->ruaCheia2(v)){

                    //rotacionar
                    dir->saiVeiculo1();
                    baixo->entraVeiculo2(v);
                    return true;
                }
            }
        }
    }
    else if(de == 3){
        if(cima->carroFim2()){
            v = cima->getVeiculo2();
            if(para == 1){
                if(!esq->ruaCheia1(v)){
                    cima->saiVeiculo2();
                    esq->entraVeiculo1(v);
                    return true;
                }
            }
            else if(para == 2){
                if(!dir->ruaCheia2(v)){
                    //rotacionar
                    cima->saiVeiculo2();
                    dir->entraVeiculo2(v);
                    return true;
                }
            }
            else if(para == 4){
                if(!baixo->ruaCheia2(v)){
                    //rotacionar
                    cima->saiVeiculo2();
                    baixo->entraVeiculo2(v);
                    return true;
                }
            }
        }
    }
    else if(de == 4){
        //qDebug() << "teste4";
        if(baixo->carroFim1()){
            v = baixo->getVeiculo1();
            if(para == 1){
                if(!esq->ruaCheia1(v)){
                    baixo->saiVeiculo1();
                    esq->entraVeiculo1(v);
                    return true;
                }
            }
            else if(para == 2){
                if(!dir->ruaCheia2(v)){
                    //rotacionar
                    baixo->saiVeiculo1();
                    dir->entraVeiculo2(v);
                    return true;
                }
            }
            else if(para == 3){
                if(!cima->ruaCheia1(v)){
                    //rotacionar
                    baixo->saiVeiculo1();
                    cima->entraVeiculo1(v);
                    return true;
                }
            }
        }
    }
    return false;
}

const double Cruzamento::tempoVerde = 15; //segundos;
const double Cruzamento::tempoAmarelo = 4;
const double Cruzamento::     tempoTransferencia = 3;
mt19937 Cruzamento::mt((random_device())());
