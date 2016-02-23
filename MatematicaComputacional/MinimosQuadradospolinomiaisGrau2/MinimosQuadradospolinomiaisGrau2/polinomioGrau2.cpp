#include "polinomioGrau2.h"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::fixed;

polinomioGrau2::polinomioGrau2()
{
    cout << "\nInserindo Pontos...\n\n";
    getXY();
    getN();
    setMatriz();
    setABC();
}

polinomioGrau2::~polinomioGrau2()
{
}

void polinomioGrau2::getXY()
{

	int resp;
	cout << "\n???Inserir ponto??? <1 - sim> : ";
	cin >> resp;
    cout << "\n";
	if(resp == 1)
	{
		double elemX,elemY;
		
		cout << "Elemento de X[" << x.size() + 1 << "]: ";
		cin >> elemX;
		x.push_back(elemX);
	
		cout << "Elemento de Y[" << y.size() + 1 << "]: ";
		cin >> elemY;
		y.push_back(elemY);
		
		getXY();	
	}
	else
	{
		
	}
}

void polinomioGrau2::getN()
{
	if(x.size() == y.size()) n = x.size();
	else n = -1;
}

double polinomioGrau2::getSX4()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=(x[i]*x[i]*x[i]*x[i]);
	}
	return soma;
}

double polinomioGrau2::getSX3()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=(x[i]*x[i]*x[i]);
	}
	return soma;
}

double polinomioGrau2::getSX2()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=(x[i]*x[i]);
	}
	return soma;
}

double polinomioGrau2::getSX()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=x[i];
	}
	return soma;
}

double polinomioGrau2::getSYX2()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=(x[i]*y[i]*y[i]);
	}
	return soma;
}

double polinomioGrau2::getSYX()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=(x[i]*y[i]);
	}
	return soma;
}

double polinomioGrau2::getSY()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=y[i];
	}
	return soma;
}

//Erros estranhos ao usar determinante. Favor usar escalonamento.

double polinomioGrau2::getA()
{
	return a;
}

double polinomioGrau2::getB()
{
	return this->b;
}

double polinomioGrau2::getC()
{
	return this->c;
}

void polinomioGrau2::setMatriz()
{
	this->sX = getSX();
	this->sY = getSY();
	if(n != -1)
	{
		this->sX4 = getSX4();
		this->sX3 = getSX3();
		this->sX2 = getSX2();
		this->sX = getSX();
		this->sYX2 = getSYX2();
		this->sYX = getSYX();
		this->sY = getSY();
		
		this->A[0][0] = sX4;
		this->A[0][1] = sX3;
		this->A[0][2] = sX2;
		this->A[0][3] = sYX2;
		this->A[1][0] = sX3;
		this->A[1][1] = sX2;
		this->A[1][2] = sX;
		this->A[1][3] = sYX;
		this->A[2][0] = sX2;
		this->A[2][1] = sX;
		this->A[2][2] = n;
		this->A[2][3] = sY;
	}
}

void polinomioGrau2::setABC()
{
	alpha = (float) A[0][0]/A[1][0];
	
	for(int i=0;i<4;i++)
	{
		A[1][i] = A[0][i] - alpha*A[1][i];
	}
	
	alpha = (float) A[0][0]/A[2][0];
	
	for(int i=0;i<4;i++)
	{
		A[2][i] = A[0][i] - alpha*A[2][i];
	}
	
	alpha = (float) A[1][1]/A[2][1];
	
	for(int i=1;i<4;i++)
	{
		A[2][i] = A[1][i] - alpha*A[2][i];
	}
	
	alpha = A[0][0];
	
	for(int i=0;i<4;i++)
	{
		A[0][i] = (float) A[0][i]/alpha;
	}
	
	alpha = A[1][1];
	
	for(int i=1;i<4;i++)
	{
		A[1][i] = (float) A[1][i]/alpha;
	}
	
	alpha = A[2][2];
	
	for(int i=2;i<4;i++)
	{
		A[2][i] = (float) A[2][i]/alpha;
	}
	
	this->c = A[2][3];
	this->b = A[1][3] - c*A[1][2];
	this->a = A[0][3] - b*A[0][1] - c*A[0][2];
}

void polinomioGrau2::imprimeFuncao() const
{
	if(n != -1)
	{
		
		cout << "A funcao resultante e: f(x) = " << fixed << this->a << "x^2 + " << fixed << this->b << "x + " << fixed << this->c << "\n\n";
	}
	else
	{
		cout << "Deu erro.\n\n";   //Para o inverossimil caso dos vetores de x e y nao terem o mesmo tamanho.
	}
}
