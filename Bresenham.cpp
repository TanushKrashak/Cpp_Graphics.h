#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;


int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);

// =====================================
//			Main Algorithm
//======================================

	int x1 = 100, y1 = 100, x2 = 400, y2 = 300;
	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double m = dy / dx;
	double d = 2*dy - dx;
	int x = x1, y = y1;
	while (x <= x2 && y <= y2) {
		putpixel(x, y, WHITE);
		if (m < 1) {
			x++;
			if (d < 0)
				d += + 2*dy;
			else {
				y++;
				d += + 2*dy - 2*dx;
			}
		}
		else {
			y++;
			if (d < 0)
				d += + 2*dx;
			else {
				x++;
				d += + 2*dx - 2*dy;
			}
		}
	}

// =====================================
//		Main Algorithm End
//======================================

	getch();
	closegraph();
	return 0;
}
