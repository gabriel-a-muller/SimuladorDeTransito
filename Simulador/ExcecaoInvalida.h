#ifndef EXC_INVALIDA_H
#define EXC_INVALIDA_H
#include <string>
using namespace std;

//Classe para tratamento de excecao.
class ExcecaoInvalida {
private:
	string erro;
public:
	ExcecaoInvalida(string errotxt = ""){erro=errotxt;}
	string consultaErro()const{return erro;}
};
#endif
