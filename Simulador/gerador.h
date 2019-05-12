#ifndef GERADOR_H
#define GERADOR_H
#include <random>
#include "Veiculo.h"
#include "Rua.h"

class MainWindow;

class Gerador{
private:
    Rua *r;
    int carrosGerados;
    //inteiro para informar onde os carros gerados sao enfileirados.
    int p;
    static mt19937 mt;
    MainWindow *mw;
public:
    //construtor; recebe um ponteiro para MainWindow como parametro.
    Gerador(MainWindow *mw);
    void setRua(Rua& r,int p);
    int getCarrosGerados();
    void incrementaCarrosGerados();
    //cria um carro e enfila na rua recebida como atributo da classe.
    //retorna true caso o carro for criado e enfileirado com sucesso;
    //false caso contrario.
    bool criaCarro();


};
#endif // GERADOR_H
