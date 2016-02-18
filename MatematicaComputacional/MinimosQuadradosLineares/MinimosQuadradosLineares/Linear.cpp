#include "Linear.h"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::fixed;

Linear::Linear()
{
    cout << "\nInserindo Pontos...\n\n";
    getXY();
    getN();
    getFuncao();
}

Linear::~Linear()
{
}

void Linear::getXY()
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

void Linear::getN()
{
	if(x.size() == y.size()) n = x.size();
	else n = -1;
}

double Linear::getSX()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=x[i];
	}
	return soma;
}

double Linear::getSY()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=y[i];
	}
	return soma;
}

double Linear::getSX2()
{
	double soma=0;
	for(int i=0;i < n;i++)
	{
		soma+=(x[i])*(x[i]);
	}
	return soma;
}

double Linear::getSXY()
{
	double soma=0;
	for(int i=0;i < n;i++)
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
	return Db/D;
}

double Linear::getA()
{
	return sY/n - (b*sX)/n;
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
		cout << "A funcao resultante e: f(x) = " << fixed << a << " + " << fixed << b << "x \n\n";
	}
	else
	{
		cout << "Deu erro.\n\n";   //Para o inverossimil caso dos vetores de x e y nao terem o mesmo tamanho.
	}
}

