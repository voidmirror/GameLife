#include <iostream>
#include <vector>
#include "Cell.h"

void Cell::changeStateNow(int s) {
	stateNow = s;
}

void Cell::changeStateFuture(int s) {
	stateFuture = s;
}

int Cell::getStateNow() {
	return stateNow;
}

void Cell::printState() {
	if (this->getStateNow() == 1) {
		cout << "O ";
	}
	else {
		cout << "  ";
	}
}

void Cell::updateCellClass(vector <vector <Cell*>> mat, int iMat, int jMat) {
	int counter = 0;
	for (int i = iMat - 1; i <= iMat + 1; i++) {
		for (int j = jMat - 1; j <= jMat + 1; j++) {
			counter += (*(mat[i][j])).getStateNow();
		}
	}

	if (stateNow == 1) {
		counter--;
	}

	if ((*(mat[iMat][jMat])).getStateNow() == 1) {
		if (counter < 2 || counter > 3) {
			(*(mat[iMat][jMat])).changeStateFuture(0);
		}
		else {
			(*(mat[iMat][jMat])).changeStateFuture(1);
		}
	}
	else {
		if (counter == 3) {
			(*(mat[iMat][jMat])).changeStateFuture(1);
		}
	}
}

void Cell::updateNextGeneration() {
	stateNow = stateFuture;
}

Cell::Cell()
{
	stateNow = 0;
	stateFuture = 0;
}