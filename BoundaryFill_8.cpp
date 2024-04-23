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
		delay(1);
		// Recursion for all 8 directions
		BoundaryFill(x + 1, y, newColor, boundaryColor);
		BoundaryFill(x - 1, y, newColor, boundaryColor);
		BoundaryFill(x, y + 1, newColor, boundaryColor);
		BoundaryFill(x, y - 1, newColor, boundaryColor);
		BoundaryFill(x + 1, y + 1, newColor, boundaryColor);
		BoundaryFill(x - 1, y + 1, newColor, boundaryColor);
		BoundaryFill(x + 1, y - 1, newColor, boundaryColor);
		BoundaryFill(x - 1, y - 1, newColor, boundaryColor);
	}
}

// =====================================
//	Main Algorithm End
//======================================

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);

	// Draw a thick circle so that it doesn't cross over while checking diagonally
	circle(200, 200, 20);
	circle(200, 200, 21);
	circle(200, 200, 22);
	
	BoundaryFill(200, 200, RED, WHITE);

	getch();
	closegraph();
	return 0;
}
