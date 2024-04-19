#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace st;

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);

// =====================================
//			Main Algorithm
//======================================
	
	cout << " Enter center coordinates : ";
	int midX, midY; cin >> midX >> midY;
	cout<< " Enter Radius: ";
	int r; cin >> r;
	int p = 1-r; // Initial Decision Parameter
	int x = 0, y = r; // Initial Points
	while (x <= y) {
		putpixel( x + midX,  y + midY, WHITE);
		putpixel( y + midY,  x + midX, WHITE);
		putpixel(-x + midX,  y + midY, WHITE);
		putpixel( y + midY, -x + midX, WHITE);
		putpixel( x + midX, -y + midY, WHITE);
		putpixel(-y + midY,  x + midX, WHITE);
		putpixel(-x + midX, -y + midY, WHITE);
		putpixel(-y + midY, -x + midX, WHITE);
		x++;
		p += 2*x + 1;
		if (p >= 0) {
			y--;
			p -= 2 * y;
		}
	}

// =====================================
//		Main Algorithm End
//======================================

	getch();
	closegraph();
	return 0;
}