#include "gerador.h"
#include "mainwindow.h"

Gerador::Gerador(MainWindow *m){
    carrosGerados=0;
    mw = m;
}

void Gerador::setRua(Rua& r, int p){this->r=&r;this->p=p;}

int Gerador::getCarrosGerados(){return carrosGerados;}

void Gerador::incrementaCarrosGerados(){carrosGerados++;}

bool Gerador::criaCarro(){
    uniform_int_distribution<int>dist(1,2);
   // int d = dist(mt);
    string nome;
    int tamanho;

    nome = "Carro"; tamanho = 12;
    ImagemCarro *aux = mw->novoCarroImagem();
    Veiculo v(nome,tamanho,0,0, aux);

   if(p==1){
       if(r->entraVeiculo1(v)){
           mw->setaCarro(aux);
       }
   }
   else if(p==2){
       if(r->entraVeiculo2(v)){
           mw->setaCarro(aux);
       }
   }
   return true;

}


mt19937 Gerador::mt((random_device())());

