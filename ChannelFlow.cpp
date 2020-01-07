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
	double grid[xPoints][yPoints] = {};

	// Rectagle Variables
	int xRectangle = 1;
	int yRectangle = 2;


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


	/* computation */
	for (int k =0 ; k < 100; k++) {	
		for (int i = 1 ; i <xLength/h;i++) {
			for (int j = 0;j < yLength/h; j++) {
				//Inside the rectangle
				if ((i*h) >= (xLength-xRectangle) && (j*h) <= (yRectangle)) {
					continue;
				}
				// At the wall or 0 axis
				if (j == 0 || j == yPoints-1) {
					continue;
				}

				grid[i][j] = 0.25*(grid[i-1][j] + grid[i+1][j] + (1 + (h/(2*j*h)) )*grid[i][j-1] + (1 - (h/(2*j*h)) )*grid[i][j+1]); 
			}
		}
	}



	// Print grid
	ofstream  myfile ("output.txt");
	if (myfile.is_open()) {
		for (int j = 0; j < yLength/h; j++ ) {
			for (int i=0; i< xLength/h; i++) {
				myfile << grid[i][j] << "\t";
			}
			myfile << "\n" ;
		}

		myfile.close();
	}
	else cout << "Didnt work";



	return 0;
}