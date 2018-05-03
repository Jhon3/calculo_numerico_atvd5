#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <math.h>

double funcao(double );
double (*func) (double) = funcao; //Ponteiro para a função
double um_tres_simpson(double , double , int , double (*func)(double)); //Método 1/3 simpson

int main()
{
	//Pre-definindo o numero de iteracoes e os intervalos,
	//sem interacao com o usuario.
	int n = 6; // numero de sub intervalos (tem que ser par)
	double a = -5;
	double b = 5;

	double result = um_tres_simpson(a, b, n, func);

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

double um_tres_simpson(double a, double b, int n, double (*func)(double))
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
	
	//Ex da 1_3 Simpson composta para 7 pontos (Ou seja, aplicada 3 vezes):
	//h/3*[ f(x0) + 4*f(x1) + 2*f(x2) + 4*f(x3) + 2*f(x4) + 4*f(x5) + f(x6) ]; 

	double result = vet_y[0] + vet_y[n]; //f(x0) + f(xn)
	for(int i = 1; i < n; ++i)
	{
		if(i%2 != 0) //Valor em posição ímpar, multiplica por 4
		{
			result = result + 4 * vet_y[i];
		}
		else //Valor em posição par, multiplica por 2
		{
			result = result + 2* vet_y[i];
		}
	}
	result = (h/3) * result;
	return result;
}
