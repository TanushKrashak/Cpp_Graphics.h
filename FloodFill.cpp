#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

// ========================================
//	Main Algorithm 
//=========================================

void floodfill(int x, int y, int newcolor, int oldcolor) {
	if (getpixel(x, y) == oldcolor) {
		putpixel(x, y, newcolor);		
		floodfill(x + 1, y, newcolor, oldcolor);
		floodfill(x - 1, y, newcolor, oldcolor);
		floodfill(x, y + 1, newcolor, oldcolor);
		floodfill(x, y - 1, newcolor, oldcolor);
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
	floodfill(200, 200, 4, 0);

	getch();
	closegraph();
	return 0;
}
