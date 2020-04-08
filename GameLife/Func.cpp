#include <iostream>
#include "Func.h"

using namespace std;

void printMatrix(vector<vector<int>> mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void gameField(vector<vector<int>> mat, int n) {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (mat[i][j] == 1) {
				cout << "O ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}

int updateCell(vector<vector<int>> mat, int iMat,int jMat) {
	int counter = 0;
	for (int i = iMat - 1; i <= iMat + 1; i++) {
		for (int j = jMat - 1; j <= jMat + 1; j++) {
			counter += mat[i][j];
		}
	}
	counter--;

	if (mat[iMat][jMat] == 1) {
		if (counter < 2 || counter > 3) {
			mat[iMat][jMat] = 0;
		}
	}
	else {
		if (counter == 3) {
			mat[iMat][jMat] = 1;
		}
	}

	return mat[iMat][jMat];
}

vector<vector<int>> updateField(vector<vector<int>> mat, int n) {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			
			mat[i][j] = updateCell(mat, i, j);

		}
	}

	return mat;
}

vector<vector<int>> updateEdge(vector<vector<int>> mat, int n) {
	for (int j = 1; j < n - 1; j++) {
		mat[0][j] = mat[n - 2][j];

		mat[n - 1][j] = mat[1][j];
	}

	for (int i = 1; i < n - 1; i++) {
		mat[i][0] = mat[i][n - 2];

		mat[i][n - 1] = mat[i][1];
	}

	mat[0][0] = mat[n - 2][n - 2];
	mat[0][n - 1] = mat[n - 1][1];
	mat[n - 1][0] = mat[1][n - 2];
	mat[n - 1][n - 1] = mat[1][1];

	return mat;
}

int checkLast(vector<vector<int>> mat, vector<vector<int>> copy, int n) {
	int check = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (copy[i][j] != mat[i][j]) {
				check = 0;
				return check;
			}
		}
	}

	return check;
}

vector<vector<Cell*>> updateFieldClass(vector<vector<Cell*>> mat, int n) {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {

			(*(mat[i][j])).updateCellClass(mat, i, j); // WARNING

		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {

			(*(mat[i][j])).updateNextGeneration();

		}
	}

	return mat;
}

vector<vector<Cell*>> updateEdgeClass(vector<vector<Cell*>> mat, int n) {
	for (int j = 1; j < n - 1; j++) {
		(*(mat[0][j])).changeStateNow((*(mat[n - 2][j])).getStateNow());

		(*(mat[n - 1][j])).changeStateNow((*(mat[1][j])).getStateNow());
	}

	for (int i = 1; i < n - 1; i++) {
		(*(mat[i][0])).changeStateNow((*(mat[i][n - 2])).getStateNow());

		(*(mat[i][n - 1])).changeStateNow((*(mat[i][1])).getStateNow());
	}

	(*(mat[0][0])).changeStateNow((*(mat[n - 2][n - 2])).getStateNow());
	(*(mat[0][n - 1])).changeStateNow((*(mat[n - 1][1])).getStateNow());
	(*(mat[n - 1][0])).changeStateNow((*(mat[1][n - 2])).getStateNow());
	(*(mat[n - 1][n - 1])).changeStateNow((*(mat[1][1])).getStateNow());

	return mat;
}

void gameFieldClass(vector<vector<Cell*>> mat, int n) {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			(*(mat[i][j])).printState();
			//cout << (*(mat[i][j])).getStateNow() << "";
		}
		//cout << "HEY";
		cout << endl;
	}
}

int checkLastClass(vector<vector<Cell*>> mat, vector<vector<Cell*>> copy, int n) {
	int check = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((*(copy[i][j])).getStateNow() != (*(mat[i][j])).getStateNow()) {
				check = 0;
				return check;
			}
		}
	}

	return check;
}