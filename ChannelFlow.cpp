#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// Set up variables
	// Grid Variables
	int xLength = 6;
	int yLength = 4;
	double h = 0.25;
	int xPoints = xLength/h;
	int yPoints = yLength/h;
	//cout << xPoints << " " << yPoints;
	double grid[xPoints][yPoints] = {};

	// Rectagle Variables
	//int xRectangle = 1;
	//int yRectangle = 2;


	/* IC */
	// AFED Phi = 0
	// A->B Flow
	for (int j = 0; j < (yLength/h); j++) {
		grid[0][j] = ((j)*h)/4;
	}

	//B-> C Wall
	for (int i = 0; i <xLength/h;i++) {
		grid[i][yPoints-1] = 1;
	}

	/*

	for (int i = 0; i < (xLength-xRectangle)/h; i++  ) {
		grid[i][0] = 0;
	}

	// Rectangle
	for (int i = (xLength-xRectangle)/h; i<xLength/h; i++) {
		for (int j = 0; j < (xRectangle/h); j++) {
			grid[i][j] = 0; 
		}
	} 
	*/

	// Print grid
	ofstream  myfile ("output.txt");
	if (myfile.is_open()) {
		for (int j = 0; j < yLength/h; j++ ) {
			for (int i=0; i< xLength/h; i++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n" ;
		}

		myfile.close();
	}
	else cout << "Didnt work";



	return 0;
}