#include <iostream>
#include "polinomioGrau2.h"
using std::cout;
using std::cin;

int main(int argc, char **argv)
{
	int resp=0;
	do
	{
        cout << "Minimos Quadrados Polinomiais de Grau 2\n\n";
		cout << "Devemos encontrar uma funcao polinomial quadratica pra vc, com base nos pontos que vc vai informar? <1 - sim> : ";
		cin >> resp;
        if(resp == 1)
		{
			polinomioGrau2 f;
			f.imprimeFuncao();
		}
	}while(resp == 1);
    cout << "\n\n\n\nFinalizado o codigo de Minimos Quadrados Polinomiais de Grau 2.\n";
	return 0;
}
