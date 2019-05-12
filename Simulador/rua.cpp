//REFAZER ESTA CLASSE COM OUTRA CLASSE PISTA. PARA MELHOR ORGANIZAÇÃO!

#include "Rua.h"
#include <QDebug>
#include <iostream>

Rua::Rua(int vm){velocidadeMaxima = vm;qtdCarros=0;tamOcupado1=0;tamOcupado2=0;}
Rua::Rua(const Rua &r){
    f1 = r.f1; f2 = r.f2;
    qtdCarros		 = r.qtdCarros;
    velocidadeMaxima = r.velocidadeMaxima;
    tamOcupado1		 = r.tamOcupado1; tamOcupado2 = r.tamOcupado2;
}

QList<Veiculo>&	 Rua::getFila1(){return f1;} //verificar
QList<Veiculo> &Rua::getFila2(){return f2;} //verificar
int		  Rua::getQtdCarros(){return qtdCarros;}
int       Rua::getT1(){return tamOcupado1;}
int 	  Rua::getT2(){return tamOcupado2;}
int       Rua::getTamanho() const {return tamanho;}  //verificar

int	      Rua::getTamVeiculo(int i){
    if(i==1){
        Veiculo aux = f1.first();
        int tam = aux.getTamanho();
        return tam;
    }
    if(i==2){
        Veiculo aux = f2.first();
        int tam = aux.getTamanho();
        return tam;
    }
    return 0;
}

Veiculo   Rua::getVeiculo1(){return f1.first();}
Veiculo   Rua::getVeiculo2(){return f2.first();}

void	  Rua::setQtdCarros(int qtc){qtdCarros = qtc;}

bool	  Rua::entraVeiculo1(Veiculo v){
    if((tamOcupado1+v.getTamanho()>tamanho)) {
        return false;
    }
    if(sentido=='h'){
        v.setX(f);
        v.setY(eixo_fixo - 15);
    }
    else if(sentido=='v'){
        v.setX(eixo_fixo + 15);
        v.setY(f);
    }
    f1.append(v);
    tamOcupado1 += v.getTamanho();
    qtdCarros++;
    return true;
}

bool 	  Rua::entraVeiculo2(Veiculo v){
    if((tamOcupado2+v.getTamanho()>tamanho)) return false;
    //colocar o sentido e verificações, etc
    if(sentido=='h'){
        v.setX(c);
        v.setY(eixo_fixo + 15);
    }
    else if(sentido=='v'){
        v.setX(eixo_fixo - 15);
        v.setY(c);
    }
    f2.append(v);
    tamOcupado2 += v.getTamanho();
    qtdCarros++;
    return true;
}

Veiculo   Rua::saiVeiculo1(){
    if(tamOcupado1==0) throw(ExcecaoInvalida("Rua vazia!"));
    Veiculo aux;
    if(!f1.isEmpty())
        aux = f1.takeFirst();
    tamOcupado1 -= aux.getTamanho(); //verificar
    qtdCarros--;
    return aux;
}

Veiculo   Rua::saiVeiculo2(){
    if(tamOcupado2==0) throw(ExcecaoInvalida("Rua vazia!"));
    Veiculo aux;
    if(!f2.isEmpty())
    aux = f2.takeFirst();
    tamOcupado2 -= aux.getTamanho(); //verificar
    qtdCarros--;
    return aux;
}

bool Rua::ruaCheia1(Veiculo v){
    if (tamOcupado1>188) return true;
    else if( (tamOcupado1+v.getTamanho()) > 200 ) return true;
    else return false;
}
bool Rua::ruaCheia2(Veiculo v){
    if (tamOcupado2>188) return true;
    else if( (tamOcupado2+v.getTamanho()) > 200 ) return true;
    else return false;
}
bool Rua::ruaVazia1(){
    if (tamOcupado1==0) return true;
    else return false;
}
bool Rua::ruaVazia2(){
    if (tamOcupado2==0) return true;
    else return false;
}

void Rua::setCFSGE(int x1, int y1, char s, char g, int ef)
{
    c = x1; f = y1; sentido = s; gerador = g;
    eixo_fixo = ef;
}

int Rua::getC() const
{
    return c;
}

int Rua::getF() const
{
    return f;
}

char Rua::getG() const
{
    return gerador;
}

bool Rua::carroFim1()
{
   if(!f1.isEmpty()){
       int X = f1.first().getX();
       int Y = f1.first().getY();
       int aux = 0;
       if(sentido=='h'){
           aux = X;
       }
       else if(sentido=='v'){
           aux = Y;
       }
       if(aux==c){
           if(gerador=='e'){
               Veiculo aux = saiVeiculo1();
               aux.destroiImagem();
           }
           else{
               return true;
           }
       }
   }
       return false;

}

bool Rua::carroFim2()
{
    if(!f2.isEmpty()){
        int X = f2.first().getX();
        int Y = f2.first().getY();
        int aux = 0;
        if(sentido=='h'){
            aux = X;
        }
        else if(sentido=='v'){
            aux = Y;
        }
            if(aux==f){
                if(gerador=='d'){
                    Veiculo aux = saiVeiculo2();
                    aux.destroiImagem();
                }
                else{

                    return true;
                }
            }
   }
        return false;
}

void Rua::atualizaVeiculos()
{
    if(!f1.isEmpty()){
    //para pista 1;
    if(sentido=='h'){
        if(f1.first().getX()!=(c)){
                f1.first().setX(f1.first().getX()-1);//ou +2?
        }
        for(int i=1;i<f1.size();i++){ //crucial

            if(f1.at(i-1).sobraEspaco(f1.at(i).getX(),            f1.at(i-1).getX(),f1.at(i-1).getTamanho())){
                            f1[i].setX(f1.at(i).getX()-1);
            }

        }
     }
    else if(sentido=='v'){
        if(f1.first().getY()!=c){
                f1.first().setY(f1.first().getY()-1);//ou +2?
        }
        for(int i=1;i<f1.size();i++){ //crucial
            //*v2 = f1.at(i).;
            if(f1.at(i-1).sobraEspaco(f1.at(i).getY(),           f1.at(i-1).getY(),f1.at(i-1).getTamanho())){
                       f1[i].setY(f1.at(i).getY()-1);
            }
        }
    }
}

    if(!f2.isEmpty()){

    if(sentido=='h'){

        if(f2.first().getX()!=(f)){
            f2.first().setX(f2.first().getX()+1);//ou +2?
        }
        for(int i=1;i<f2.size();i++){ //crucial
            if(f2[i-1].sobraEspaco(f2.at(i-1).getX(), f2.at(i).getX(),f2.at(i-1).getTamanho())){
                f2[i].setX(f2.at(i).getX()+1);
            }
        }
     }
    else if(sentido=='v'){
        if(f2.first().getY()!=f){
                f2.first().setY(f2.first().getY()+1);//ou +2?
        }
        for(int i=1;i<f2.size();i++){ //crucial

            if(f2.at(i-1).sobraEspaco(f2.at(i-1).getY(),             f2.at(i).getY(),f2.at(i-1).getTamanho())){
                f2[i].setY( f2.at(i).getY()+1);
            }
        }
     }
    }
}

char Rua::getS()const
{
    return sentido;
}

const int Rua::tamanho = 200;
