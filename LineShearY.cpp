#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);

	// ========================================
	//	Main Algorithm 
	//=========================================
	
	int coords[6];
	cout << "Enter first point (X-lowest): ";
	cin >> coords[0] >> coords[1];
	cout << "Enter second point: ";
	cin >> coords[2] >> coords[3];
	cout << "Enter third point: ";
	cin >> coords[4] >> coords[5];
	int offsetX = 315, offsetY = 250;
	// Draw Original Line
	line(coords[0] + offsetX, coords[1] + offsetY, coords[2] + offsetX, coords[3] + offsetY);
	line(coords[0] + offsetX, coords[1] + offsetY, coords[4] + offsetX, coords[5] + offsetY);
	line(coords[4] + offsetX, coords[5] + offsetY, coords[2] + offsetX, coords[3] + offsetY);

	cout << "Enter shearing factor for X: ";
	int shear; cin >> shear;
	if (coords[1] != coords[3] && coords[1] != coords[5]) {
		line(coords[0] + offsetX, coords[1] + offsetY, coords[2] + offsetX + shear, coords[3] + offsetY);
		line(coords[0] + offsetX, coords[1] + offsetY, coords[4] + offsetX + shear, coords[5] + offsetY);
		line(coords[4] + offsetX + shear, coords[5] + offsetY, coords[2] + offsetX + shear, coords[3] + offsetY);
	}
	else if (coords[1] == coords[3]) {
		line(coords[0] + offsetX, coords[1] + offsetY, coords[2] + offsetX, coords[3] + offsetY);
		line(coords[0] + offsetX, coords[1] + offsetY, coords[4] + offsetX + shear, coords[5] + offsetY);
		line(coords[4] + offsetX + shear, coords[5] + offsetY, coords[2] + offsetX, coords[3] + offsetY);
	}
	else {
		line(coords[0] + offsetX, coords[1] + offsetY, coords[2] + offsetX + shear, coords[3] + offsetY);
		line(coords[0] + offsetX, coords[1] + offsetY, coords[4] + offsetX, coords[5] + offsetY);
		line(coords[4] + offsetX, coords[5] + offsetY, coords[2] + offsetX + shear, coords[3] + offsetY);
	}


	// ========================================
	//	Main Algorithm End
	//=========================================

	getch();
	closegraph();
	return 0;
}
