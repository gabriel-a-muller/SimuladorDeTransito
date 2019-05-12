#ifndef RUA_H
#define RUA_H
#include <QList>
#include "Veiculo.h"

class Rua{

private:
	//pista um e dois.
    QList<Veiculo> 	f1,f2;
	//Quantidade de carros nas duas pistas.
	int		qtdCarros;
	//O espaço ocupado pelos carros de cada pista.
    int     tamOcupado1;
    int		tamOcupado2;
    int     velocidadeMaxima;
    int     c,f,eixo_fixo; //comeco e fim
    char    sentido;
    char    gerador;
    const static int tamanho;

public:
    Rua(int vm = 50);
    Rua(const Rua &r);
    QList<Veiculo>&	  getFila1();
    QList<Veiculo>&	  getFila2();
    int		  getQtdCarros();
    int       getT1();
    int 	  getT2();
    int       getTamanho() const;
    int	      getTamVeiculo(int i);

    Veiculo   getVeiculo1();
    Veiculo   getVeiculo2();

    void	  setQtdCarros(int qtc);

    //metodos de entradas e saidas de veiculos.
    bool	  entraVeiculo1(Veiculo v);
    bool 	  entraVeiculo2(Veiculo v);
    Veiculo   saiVeiculo1();
    Veiculo   saiVeiculo2();

    bool ruaCheia1(Veiculo v);
    bool ruaCheia2(Veiculo v);
    bool ruaVazia1();
    bool ruaVazia2();

    void setCFSGE(int x1, int y1, char s, char g, int ef);
    char getS() const;
    int  getC() const;
    int  getF() const;
    char getG() const;

    //verifica se o veiculo se encontra no fim da rua;
    bool carroFim1();
    bool carroFim2();

    //atualiza a posicao dos veiculos em uma unidade de distancia.
    void atualizaVeiculos();
};

#endif






