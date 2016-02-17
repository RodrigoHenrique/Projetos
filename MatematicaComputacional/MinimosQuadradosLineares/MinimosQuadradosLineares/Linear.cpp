#include "Linear.h"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::vector;

Linear::Linear()
{
}

Linear::~Linear()
{
}

void Linear::getXY()
{

	int resp;
	cout << "Inserir ponto? 1 - sim : ";
	cin >> resp;
	if(resp == 1)
	{
		double elemX,elemY;
		
		cout << "Elemento de X, indice " << x.size() + 1 << ": ";
		cin >> elemX;
		x.push_back(elemX);
	
		cout << "Elemento de Y, indice " << y.size() + 1 << ": ";
		cin >> elemY;
		y.push_back(elemY);
		
		getXY();	
	}
	else
	{
		
	}
}

int Linear::getN()
{
	if(x.size() == y.size()) return x.size();
	else return -1;
}

double Linear::getSX()
{
	double soma=0;
	for(int i=0;i < x.size();i++)
	{
		soma+=x[i];
	}
	return soma;
}

double Linear::getSY()
{
	double soma=0;
	for(int i=0;i < y.size();i++)
	{
		soma+=y[i];
	}
	return soma;
}

double Linear::getSX2()
{
	double soma=0;
	for(int i=0;i < x.size();i++)
	{
		soma+=(x[i])*(x[i]);
	}
	return soma;
}

double Linear::getSXY()
{
	double soma=0;
	for(int i=0;i < x.size();i++)
	{
		soma+=(x[i])*(y[i]);
	}
	return soma;
}

double Linear::getDelta()
{
	return n*sX2 - sX*sX;
}

double Linear::getDeltab()
{
	return n*sXY - sX*sY;
}

double Linear::getB()
{
	return Db*(1/D);
}

double Linear::getA()
{
	return sY*(1/n) - b*sX*(1/n);
}

void Linear::getFuncao()
{
	this->sX = getSX();
	this->sY = getSY();
	if(n != -1)
	{
		this->sX2 = getSX2();
		this->sXY = getSXY();
		this->D = getDelta();
		this->Db = getDeltab();
		this->b = getB();
		this->a = getA();
	}
}

void Linear::imprimeFuncao() const
{
	if(n != -1)
	{
		cout << "A funcao resultante e: " << a << " + " << b << "x \n\n";
	}
	else
	{
		cout << "Deu erro.\n\n";
	}
}

