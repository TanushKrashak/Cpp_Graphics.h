#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

// =====================================
//	Main Algorithm
//======================================

void BoundaryFill(int x, int y, int newColor, int boundaryColor) {
	// Current Pixel should not be boundary color or new color
	if (getpixel(x, y) != boundaryColor && getpixel(x, y) != newColor) { 
		putpixel(x, y, newColor);		
		// Recursion for all 4 directions
		BoundaryFill(x + 1, y, newColor, boundaryColor);
		BoundaryFill(x - 1, y, newColor, boundaryColor);
		BoundaryFill(x, y + 1, newColor, boundaryColor);
		BoundaryFill(x, y - 1, newColor, boundaryColor);
	}	
}

// =====================================
//	Main Algorithm End
//======================================

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);

	// Draw a circle and fill it with color
	circle(200, 200, 20);
	BoundaryFill(200, 200, RED, WHITE);

	getch();
	closegraph();
	return 0;
}
