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
    getFuncao();
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
		soma+=x[i]*x[i]*x[i]*x[i];
	}
	return soma;
}

double polinomioGrau2::getSX3()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=x[i]*x[i]*x[i];
	}
	return soma;
}

double polinomioGrau2::getSX2()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=x[i]*x[i];
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
		soma+=x[i]*y[i]*y[i];
	}
	return soma;
}

double polinomioGrau2::getSYX()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=x[i]*y[i];
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

double polinomioGrau2::getDelta()
{
	return sX4*sX2*n - sX2*sX2;
}

double polinomioGrau2::getDeltaA()
{
	return sYX2*sX2*n + sX3*sX*sY + sX2*sYX*sX - sX2*sX2*sY - sY*sX*sYX2 - n*sX3*sYX;
}

double polinomioGrau2::getDeltaB()
{
	return sX4*sYX*n + sYX2*sX*sX2 + sX2*sX3*sY - sX2*sYX*sX2 - sX*sY*sX4 - n*sYX2*sX3;
}

double polinomioGrau2::getDeltaC()
{
	return sX4*sX2*sY + sX3*sYX*sX2 + sYX2*sX3*sX - sYX2*sX2*sX2 - sYX*sX*sX4 - sY*sX3*sX3;
}

double polinomioGrau2::getA()
{
	return deltaA/delta;
}

double polinomioGrau2::getB()
{
	return deltaB/delta;
}

double polinomioGrau2::getC()
{
	return deltaC/delta;
}

void polinomioGrau2::getFuncao()
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
		this->delta = getDelta();
		this->deltaA = getDeltaA();
		this->deltaB = getDeltaB();
		this->deltaC = getDeltaC();
		this->a = getA();
		this->b = getB();
		this->c = getC();
	}
}

void polinomioGrau2::imprimeFuncao() const
{
	if(n != -1)
	{
		cout << "A funcao resultante e: f(x) = " << fixed << a << "x^2 + " << fixed << b << "x + " << fixed << c << "\n\n";
	}
	else
	{
		cout << "Deu erro.\n\n";   //Para o inverossimil caso dos vetores de x e y nao terem o mesmo tamanho.
	}
}