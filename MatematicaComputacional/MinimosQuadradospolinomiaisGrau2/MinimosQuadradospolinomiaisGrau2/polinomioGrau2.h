#ifndef POLINOMIOGRAU2_H
#define POLINOMIOGRAU2_H
#include <vector>

using std::vector;

class polinomioGrau2
{
public:
	polinomioGrau2();
	~polinomioGrau2();
	void getXY();
	void getN();
	double getSX4();
	double getSX3();
	double getSX2();
	double getSX();
	double getSYX2();
	double getSYX();
	double getSY();
	double getA();
	double getB();
	double getC();
	void setMatriz();
	void imprimeFuncao() const;
	void setABC();
	
private:
	double a;
	double b;
	double c;
	int n;
	vector<double> x;
	vector<double> y;
    double sX4;
    double sX3;
    double sX2;
    double sX;
    double sYX2;
    double sYX;
    double sY;
	double delta,deltaA,deltaB,deltaC;
	double A[3][4];
	double alpha;
	
};

#endif // POLINOMIOGRAU2_H
