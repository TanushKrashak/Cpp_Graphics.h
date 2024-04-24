#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);

// =====================================
//	Main Algorithm
//======================================
	
	cout << " Enter center coordinates : ";
	int midX, midY; cin >> midX >> midY;
	cout<< " Enter Radius: ";
	int r; cin >> r; // Radius
	int p = 1-r; // Initial Decision Parameter
	int x = 0, y = r; // Initial Points
	while (x <= y) {
		// Printing All 8 points using 8-way Symmetry
		putpixel( x + midX,  y + midY, WHITE);
		putpixel( y + midY,  x + midX, WHITE);
		putpixel(-x + midX,  y + midY, WHITE);
		putpixel( y + midY, -x + midX, WHITE);
		putpixel( x + midX, -y + midY, WHITE);
		putpixel(-y + midY,  x + midX, WHITE);
		putpixel(-x + midX, -y + midY, WHITE);
		putpixel(-y + midY, -x + midX, WHITE);
		x++;		
		if (p < 0) 
			p += 2*x + 1; // Increasing Decision Param
		else {
			y--;
			p += 2*x - 2*y + 1; // Decreasing Decision Param
		}
	}

// =====================================
//	\Main Algorithm End
//======================================

	getch();
	closegraph();
	return 0;
}
