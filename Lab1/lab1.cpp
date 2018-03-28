#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <Windows.h>
int main(int argc, char* argv[])
{	
	#pragma omp parallel
	{	
		int var = 26;
		std::cout << pow(2, (var + 100))<<"\n"<<std::endl;
	}
	system("pause");
	return 0;
}
