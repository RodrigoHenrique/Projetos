#include <iostream>
#include "Linear.h"

using std::cout;
using std::cin;

int main(int argc, char **argv)
{
	cout << "Minimos quadrados lineares\n\n";
	int resp=0;
	do
	{
		cout << "Devemos encontrar uma funcao linear pra vc, com base nos pontos que vc vai informar? (1 - sim)";
		cin >> resp;
		if(resp==1)
		{
			Linear f;
			f.getSXY();
			f.getFuncao();
			f.imprimeFuncao();
		}
	}while(resp == 1);
	return 0;
}
