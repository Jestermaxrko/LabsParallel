#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <Windows.h>
int main(int argc, char* argv[])
{
	double prod = 1;
#pragma omp parallel shared(prod)
	{
#pragma omp for
		for (int i = 2; i < 10; ++i){
			prod *= log(i)/(pow(i,2));
		}
	}
	std::cout << "Result = " << prod << std::endl;
	system("PAUSE");
	return 0;
}