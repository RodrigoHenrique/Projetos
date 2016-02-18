#include <iostream>
#include "Linear.h"
using std::cout;
using std::cin;

int main(int argc, char **argv)
{
	int resp=0;
	do
	{
        cout << "Minimos Quadrados Lineares\n\n";
		cout << "Devemos encontrar uma funcao linear pra vc, com base nos pontos que vc vai informar? <1 - sim> : ";
		cin >> resp;
        if(resp == 1)
		{
			Linear f;
			f.imprimeFuncao();
		}
	}while(resp == 1);
    cout << "\n\n\n\nFinalizado o codigo de Minimos Quadrados Lineares.\n";
	return 0;
}
