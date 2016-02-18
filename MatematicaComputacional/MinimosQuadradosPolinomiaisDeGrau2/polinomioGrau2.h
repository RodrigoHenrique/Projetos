#ifndef POLINOMIOGRAU2_H
#define POLINOMIOGRAU2_H
#include <vector>

class polinomioGrau2
{
public:
	polinomioGrau2();
	~polinomioGrau2();
	void getXY();
	void getN();
	void getSX4();
	void getSX3();
	void getSX2();
	void getSX();
	void getSYX2();
	void getSYX();
	void getSY();
	void getDelta();
	void getDeltaA();
	void getDeltaB();
	void getDeltaC();
	void getA();
	void getB();
	void getC();
	void getFuncao();
	void imprimeFuncao() const;
	
private:
	double a;
	double b;
	double c;
	int n;
	vector<double> x;
	vector<double> y;
	double sX,sY,sX4,sX3,sX2,sX,sXY2,sXY,sY;
	double delta,deltaA,deltaB,deltaC;
	
};

#endif // POLINOMIOGRAU2_H
