#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

// Function to return sign of a number
int sign(int n) {
	if (n < 0)
		return -1;
	else if (n > 0)
		return 1;
	return 0;
}

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);

// =====================================
//	Main Algorithm
//======================================
		
	cout << "Enter starting coordinates: ";
	int x1, y1; cin >> x1 >> y1;
	cout << "Enter ending coordinates: ";
	int x2, y2; cin >> x2 >> y2;
	double dx = abs(x2 - x1);
	double dy = abs(y2 - y1);
	int l = (dx > dy) ? dx : dy; // Length of line
	dx = (x2 - x1) / (double)l; // New Change in x
	dy = (y2 - y1) / (double)l; // New Change in y
	double x = x1 + 0.5 * sign(dx); // Initial x
	double y = y1 + 0.5 * sign(dy); // Initial y
	for (int i = 0; i < l; i++) {
		// For Dotted Line
		if (i % 5 == 0)
			putpixel(int(x), int(y), WHITE);
		x += dx;
		y += dy;
	}

// =====================================
//	Main Algorithm End
//======================================

	getch();
	closegraph();
	return 0;
}
