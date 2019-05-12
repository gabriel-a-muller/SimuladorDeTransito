#ifndef VEICULO_H
#define VEICULO_H
#include "imagemcarro.h"
#include "ExcecaoInvalida.h"
#include <iostream>
#include <string>
#include <QDebug>
using namespace std;


class Veiculo{

private:
	string 	tipo;
	int 	tamanho;
    int     x,y;
    ImagemCarro *item;

public:
    Veiculo(){}
    Veiculo(string tp, int t, int X, int Y, ImagemCarro* ic)
    {
        tipo = tp; tamanho = t;  x = X; y = Y;
        item = ic;
    }
    Veiculo(const Veiculo &vc){tipo = vc.tipo; tamanho = vc.tamanho; x = vc.x; y = vc.y;item = vc.item;}

    void destroiImagem(){
        delete item;
    }

    ImagemCarro* getICarro(){return item;}

    string 	getTipo(){return tipo;}
    int 	getTamanho()const{return tamanho;}

    void	setTipo(string tp){tipo = tp;}
    void	setTamanho(int t){tamanho = t;}


    int getX() const{return x;}
    void setX(int value){
       x = value;
       item->setX(x/2);
    }
    int getY() const{return y;}
    void setY(int value){
        y = value;
        item->setY(y/2);
    }

    //tam eh o tamanho do carro da frente.
    //p1 e p2 sao as posicoes dos carro.
    //p1 sempre deve ser maior que p2.
    //retorna true caso haja espaco sobrando entre carros;
    //false caso contrario
    bool sobraEspaco(int p1, int p2, int tam)const{ //p1  sempre maior que p2;
        //if(p2>p1) return false;
        int s = p1 - p2;
        if(s == tam || s < 0) return false;
        return true;
    }
};

#endif
