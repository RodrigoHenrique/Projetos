#ifndef LINEAR_H
#define LINEAR_H
#include <vector>

using std::vector;

class Linear
{
public:
	Linear();
	~Linear();
	void getXY();
	int getN();
	double getSX();
	double getSY();
	double getSX2();
	double getSXY();
	double getDelta();
	double getDeltab();
	double getB();
	double getA();
	void getFuncao();
	void imprimeFuncao() const;

private:
	double a;
	double b;
	int n;
	vector<double> x;
	vector<double> y;
	double sX,sY,sX2,sXY;
	double D,Db;
	
};

#endif // LINEAR_H
