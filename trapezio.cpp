#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <math.h>

double funcao(double );
double (*func) (double) = funcao; //Ponteiro para a função
double trapezio(double , double , int , double (*func)(double)); //Método Trapézio

int main()
{
	//Pre-definindo o numero de iteracoes e os intervalos,
	//sem interacao com o usuario.
	int n = 6; // numero de sub intervalos (tem que ser par)
	double a = -5;
	double b = 5;

	double result = trapezio(a, b, n, func);

	std::cout << std::endl;
	std::cout << ">>Resultado aproximado da integral: ";
	std::cout << result << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "Para mais detalhes sobre a funcao integrada e o metodo  do trapezio, consultar o codigo." << std::endl;


	return 0;
}

double funcao(double x)
{
	return x * std::sin(x);
	//return std::pow(x,2); //debug
}

double trapezio(double a, double b, int n, double (*func)(double))
{
	double h = (b-a)/n;
	double vet_x[n+1];
	double vet_y[n+1];

	double width = (std::abs(a) + std::abs(b))/n;

	vet_x[0] = a;
	vet_y[0] = func(vet_x[0]);
	for(int i = 1; i < n+1; ++i)
	{
		vet_x[i] = vet_x[i-1] + width;
		vet_y[i] = func(vet_x[i]);
	}
	
	//ex: Regra do trapézio composta para 7 pontos: (aplicada 6 vezes)
	//h[f(x0)/2 + f(x1) + f(x2) + f(x3) + f(x4) + f(x5) + f(x6)/2 ]

	double result = vet_y[0]/2 + vet_y[n]/2; //f(x0)/2 + f(xn)/2

	for(int i = 1; i < n; ++i) //Restante dos valores são somados
	{
		result = result + vet_y[i];
	}
	result = h * result;
	return result;
}
