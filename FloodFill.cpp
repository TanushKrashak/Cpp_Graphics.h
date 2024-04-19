#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

// ========================================
//	Main Algorithm 
//=========================================

void FloodFill(int x, int y, int newcolor, int oldcolor) {
	if (getpixel(x, y) == oldcolor) {
		putpixel(x, y, newcolor);		
		FloodFill(x + 1, y, newcolor, oldcolor);
		FloodFill(x - 1, y, newcolor, oldcolor);
		FloodFill(x, y + 1, newcolor, oldcolor);
		FloodFill(x, y - 1, newcolor, oldcolor);
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
