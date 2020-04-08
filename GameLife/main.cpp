#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "Func.h"

using namespace std;

int main() {
	srand(time(0));
	int n = 22;

	// by class ----------------------------------------------------------------------

	// <comment>
	
	// <comment>

	vector <vector <Cell*>> mat;
	vector <vector <Cell*>> copy;
	mat.resize(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = new Cell();
		}
	}
	copy.resize(n);
	for (int i = 0; i < n; i++) {
		copy[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy[i][j] = new Cell();
		}
	}

	// RANDOM ------------------------------------------------------------------------

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*(mat[i][j])).changeStateNow(rand() % 2);
		}
	}

	//--------------------------------------------------------------------------------

	//// GLIDER ------------------------------------------------------------------------

	//(*(mat[4][6])).changeStateNow(1);
	//(*(mat[5][7])).changeStateNow(1);
	//(*(mat[5][8])).changeStateNow(1);
	//(*(mat[4][8])).changeStateNow(1);
	//(*(mat[3][8])).changeStateNow(1);

	//--------------------------------------------------------------------------------


	//// CROSS -------------------------------------------------------------------------

	//(*(mat[7][6])).changeStateNow(1);
	//(*(mat[7][7])).changeStateNow(1);
	//(*(mat[7][8])).changeStateNow(1);
	//(*(mat[7][9])).changeStateNow(1);

	//(*(mat[7][9])).changeStateNow(1);
	//(*(mat[8][9])).changeStateNow(1);
	//(*(mat[9][9])).changeStateNow(1);

	//(*(mat[8][6])).changeStateNow(1);
	//(*(mat[9][6])).changeStateNow(1);

	//(*(mat[9][5])).changeStateNow(1);
	//(*(mat[9][4])).changeStateNow(1);

	//(*(mat[10][4])).changeStateNow(1);
	//(*(mat[11][4])).changeStateNow(1);
	//(*(mat[12][4])).changeStateNow(1);

	//(*(mat[12][5])).changeStateNow(1);
	//(*(mat[12][6])).changeStateNow(1);

	//(*(mat[13][6])).changeStateNow(1);
	//(*(mat[14][6])).changeStateNow(1);

	//(*(mat[14][7])).changeStateNow(1);
	//(*(mat[14][8])).changeStateNow(1);
	//(*(mat[14][9])).changeStateNow(1);

	//(*(mat[13][9])).changeStateNow(1);
	//(*(mat[12][9])).changeStateNow(1);

	//(*(mat[12][10])).changeStateNow(1);
	//(*(mat[12][11])).changeStateNow(1);

	//(*(mat[11][11])).changeStateNow(1);
	//(*(mat[10][11])).changeStateNow(1);
	//(*(mat[9][11])).changeStateNow(1);

	//(*(mat[9][10])).changeStateNow(1);

	//--------------------------------------------------------------------------------


	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << (*(mat[i][j])).getStateNow() << " ";
	//	}
	//	cout << endl;
	//}
	//Sleep(2000);
	system("cls");
	gameFieldClass(mat, n);
	Sleep(5000);

	int counter = 1;
	int tempik = 0;
	while (counter != 0) {
		counter = 0;

		mat = updateEdgeClass(mat, n);
		mat = updateFieldClass(mat, n);
		system("cls");
		gameFieldClass(mat, n);
		Sleep(200);
		
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				counter += (*(mat[i][j])).getStateNow();
			}
		}

		/*if (checkLastClass(mat, copy, n) == 1) {
			break;
		}*/
		tempik++;
		if (tempik == 3) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					(*(copy[i][j])).changeStateNow((*(mat[i][j])).getStateNow());
				}
			}
			tempik = 0;
		}
		
	}

	cout << endl << "The End!" << endl;
	cout << endl << endl;


	// <comment>
	
	// <comment>

	
	// by matrix ---------------------------------------------------------------------

	// <comment>
	/*
	// <comment>
	vector <vector <int>> mat;
	vector <vector <int>> copy;
	mat.resize(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(n);
	}
	copy.resize(n);
	for (int i = 0; i < n; i++) {
		copy[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = rand() % 2;
		}
	}
	
	mat[4][6]++;
	mat[5][7]++;
	mat[6][7]++;
	mat[6][6]++;
	mat[6][5]++;

	gameField(mat, n);
	Sleep(5000);

	int counter = 1;
	int tempik = 0;
	while (counter != 0) {
		counter = 0;

		mat = updateEdge(mat, n);
		mat = updateField(mat, n);
		system("cls");
		gameField(mat, n);
		Sleep(200);

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				counter += mat[i][j];
			}
		}

		if (checkLast(mat, copy, n) == 1) {
			break;
		}
		tempik++;
		if (tempik == 3) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					copy[i][j] = mat[i][j];
				}
			}
			tempik = 0;
		}
	}

	cout << endl << "The End!" << endl;
	//cout << endl << endl;
	//printMatrix(mat, n);

	// <comment>
	*/
	// <comment>
	

	cout << "End";
}