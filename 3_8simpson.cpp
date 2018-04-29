#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <math.h>



double funcao(double );
double (*func) (double) = funcao; //Ponteiro para a função
double tres_oito_simpson(double , double , int , double (*func)(double)); //Método 1/3 simpson

int main()
{
	//Pre-definindo o numero de iteracoes e os intervalos,
	//sem interacao com o usuario.
	int n = 100000; // numero de sub intervalos (tem que ser par)
	double a = -5;
	double b = 5;

	double result = tres_oito_simpson(a, b, n, func);

	std::cout << std::endl;
	std::cout << ">>Resultado aproximado da integral: ";
	std::cout << result << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "Para mais detalhes sobre a funcao integrada e o metodo  1/3 de Simpson, consultar o codigo." << std::endl;


	return 0;
}

double funcao(double x)
{
	return x * std::sin(x);
	//return std::pow(x,2);
}

double tres_oito_simpson(double a, double b, int n, double (*func)(double))
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
	
	double result = vet_y[0];
	for(int i = 1; i < n+1; ++i)
	{
		if(i%3 == 1)
		{
			result = result + 2 * vet_y[i];
		}
		else
		{
			result = result + 3 * vet_y[i];
		}
	}
	result = (3*h/8) * (result + vet_y[n+1]);
	return result;
	
}
