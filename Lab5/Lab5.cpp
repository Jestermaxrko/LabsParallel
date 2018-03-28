#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <Windows.h>
#include <vector>
using namespace std;

void createMatrix(int **A, int n_elems) {
	std::cout << "Matrix: "<<endl;
	for (int i = 0; i < n_elems; i++) {
		A[i] = new int[n_elems];
	}

	for(int i =0;i <n_elems;i++){
		for (int j = 0; j < n_elems; j++) {
			A[i][j] = rand() % 2;
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{	
	srand(time(NULL));
	int n_elems = 5;
	int **A =new int*[n_elems];
	vector <int> acycles;
	createMatrix(A, n_elems);

#pragma omp parallel for shared(A, acycles,n_elems)
	for (int i = 0; i < n_elems; i++) {
		if (A[i][i] == 0) {
			acycles.push_back(i+1);
		}
	}


	cout << endl <<"Acyclic edges at the vertices: ";
	for (int i = 0; i < acycles.size(); i++) {
		cout << acycles[i] << " ";
	}

	cout << endl;
	system("PAUSE");
	return 0;
		
}