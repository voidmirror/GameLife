#ifndef Cell_H
#define Cell_H
using namespace std;
class Cell
{
public:
	void changeStateNow(int s);
	void changeStateFuture(int s);
	void printState();
	int getStateNow();
	void updateNextGeneration();
	void updateCellClass(vector <vector <Cell*>> mat, int iMat, int jMat);
	Cell(); 

private:
	int stateNow;
	int stateFuture;
};

#endif