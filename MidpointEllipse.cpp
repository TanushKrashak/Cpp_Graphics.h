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
	
	int offX = 300, offY = 250; // Offset for centering the ellipse
	float rx = 50, ry = 80, x = 0, y = ry; // Radius along x and y axis and initial point

	// Part 1
	float p = pow(ry, 2) - ry*pow(rx, 2) + pow(rx, 2)/4; // Initial decision parameter
	do {
		putpixel( x + offX,  y + offY, WHITE);
		putpixel(-x + offX,  y + offY, WHITE);
		putpixel( x + offX, -y + offY, WHITE);
		putpixel(-x + offX, -y + offY, WHITE);
		x++;
		if (p < 0)
			p += 2*x*pow(ry, 2) + pow(ry, 2);
		else {
			y--;
			p += 2*x*pow(ry, 2) - 2*y*pow(rx, 2) + pow(ry, 2);
		}		
	} while (2*x*pow(ry, 2) < 2*y*pow(rx, 2));

	// Part 2
	p = pow(ry, 2)*pow(x+0.5, 2) + pow(rx, 2)*pow(y-1, 2) - pow(rx, 2)*pow(ry, 2);
	do {
		putpixel( x + offX,  y + offY, WHITE);
		putpixel(-x + offX,  y + offY, WHITE);
		putpixel( x + offX, -y + offY, WHITE);
		putpixel(-x + offX, -y + offY, WHITE);
		y--;
		if (p > 0)
			p -= 2*y*pow(rx, 2) + pow(rx, 2);
		else {
			x++;
			p += 2*x*pow(ry, 2) - 2*y*pow(rx, 2) + pow(rx, 2);
		}
	} while (y >= 0);
	
// ========================================
//	Main Algorithm End
//=========================================
	
	getch();
	closegraph();
	return 0;
}
