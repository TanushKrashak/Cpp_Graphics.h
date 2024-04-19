#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

// ========================================
//	Main Algorithm 
//=========================================

void FloodFill(int x, int y, int newColor, int oldColor) {
	if (getpixel(x, y) == oldColor) {
		putpixel(x, y, newColor);		
		FloodFill(x + 1, y, newColor, oldColor);
		FloodFill(x - 1, y, newColor, oldColor);
		FloodFill(x, y + 1, newColor, oldColor);
		FloodFill(x, y - 1, newColor, oldColor);
	}	
}

// ========================================
//	Main Algorithm End
//=========================================

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);
	
	// Draw a circle and fill it with color
	circle(200, 200, 20);
	Floodfill(200, 200, 4, 0);

	getch();
	closegraph();
	return 0;
}
