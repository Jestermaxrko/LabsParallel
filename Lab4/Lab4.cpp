#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <Windows.h>

using namespace std;

void createArray(int *A, int n_elems) {
	

	std::cout << "Array: ";
	for (int i = 0; i < n_elems; i++) {
		A[i] = rand() % 100 + 1;
		std::cout << A[i] << " ";
	}
}

int main(int argc, char* argv[])
{	
	srand(time(NULL));
	int n_elems = 10;
	int *A =new int[n_elems];;
	createArray(A, n_elems);

	std::cout << "\n";
	int i, n, n_tr;

		for (n = 0; n < n_elems; n++) {
			if (n & 1) {
#pragma omp parallel for private(i) shared(A)
				
				for (i = 2; i < n_elems; i += 2)
					if (A[i - 1] > A[i]) {
						n_tr = omp_get_thread_num();
						cout << "Thread " << n_tr <<" Replace "<< A[i - 1] << " --> " << A[i]<< endl;
						swap(A[i - 1], A[i]);
					}
			}
			else {
#pragma omp parallel for private(i) shared(A)
				for (i = 1; i < n_elems; i += 2)
					if (A[i - 1] > A[i]) {
						n_tr = omp_get_thread_num();
						cout << "Thread " << n_tr << " Replace " << A[i - 1] << " --> " << A[i] << endl;
						swap(A[i - 1], A[i]);
					}
			}
		}

		std::cout << std::endl << "Sorted Array: ";
		for (int i = 0; i < n_elems; i++) {
			std::cout << A[i] << " ";
		}
		system("PAUSE");
		return 0;
		
}