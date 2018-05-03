#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <math.h>

double funcao(double );
double (*func) (double) = funcao; //Ponteiro para a função
double tres_oito_simpson(double , double , int , double (*func)(double)); //Método 3/8 simpson

int main()
{
	//Pre-definindo o numero de iteracoes e os intervalos,
	//sem interacao com o usuario.
	int n = 6; // numero de sub intervalos (tem que ser par)
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
	
	//Ex de 3/8 Simpson composta para 7 pontos(Ou seja, aplicada duas vezes):
	//3h/8 * [ f(x0) + 3*f(x1) + 3*f(x2) + 2*f(x3) + 3*f(x4) + 3*f(x5) + f(x6) ]

	double result = vet_y[0] + vet_y[n];
	for(int i = 1; i < n; ++i)
	{
		if(i%3 == 0) //Se o índice é multiplo de 3, multiplica f[i] por 2
		{
			result = result + 2 * vet_y[i];
		}
		else //Se não, multiplica por 3
		{
			result = result + 3 * vet_y[i];
		}
	}
	result = (3*h/8) * result;
	return result;
}
