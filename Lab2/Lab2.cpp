#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <Windows.h>
int main(int argc, char* argv[])
{	
	int rows=5,cols=4;
	int** A = new int*[rows];
	for (int i = 0; i < rows; ++i)
		A[i] = new int[cols];
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			A[i][j] = rand() % 10+1;
			std::cout << A[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	

#pragma omp parallel shared(A,rows,cols)
	{
#pragma omp for
		for (int i = 0; i < rows; i++)
		{	
			int sum = 0;
			for(int j=0; j<cols;j++){
				if ((i + 1) % 2 != 0) {
					sum += A[i][j];
				}
			}
			if((i+1)%2!=0)
				std::cout << "sum of "<<i+1<<" row: " << sum<<std::endl;
		}
	}
	system("PAUSE");
	return 0;
}