#ifndef Func_H
#define Func_H
#include <vector>
#include "Cell.h"
using namespace std;

void printMatrix(vector<vector<int>> mat, int n);
void gameField(vector<vector<int>> mat, int n);
int updateCell(vector<vector<int>> mat, int iMat, int jMat);
vector<vector<int>> updateField(vector<vector<int>> mat, int n);
vector<vector<int>> updateEdge(vector<vector<int>> mat, int n);
int checkLast(vector<vector<int>> mat, vector<vector<int>> copy, int n);
vector<vector<Cell*>> updateFieldClass(vector<vector<Cell*>> mat, int n);
vector<vector<Cell*>> updateEdgeClass(vector<vector<Cell*>> mat, int n);
void gameFieldClass(vector<vector<Cell*>> mat, int n);
int checkLastClass(vector<vector<Cell*>> mat, vector<vector<Cell*>> copy, int n);

#endif