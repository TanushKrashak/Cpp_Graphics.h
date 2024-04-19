#include <iostream>
#include <cmath>
#include "graphics.h"

using namespace std;

const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
const int x_max = 400, y_max = 300, x_min = 100, y_min = 100;

int calC(int x, int y) {
	int code = 0;
	if (x < x_min)
		code += LEFT;
	else if (x > x_max)
		code += RIGHT;
	if (y < y_min)
		code += BOTTOM;
	else if (y > y_max)
		code += TOP;
	return code;
}


// =====================================
//		Main Algorithm
//======================================

void CHS(int x1, int y1, int x2, int y2) {
	int code1 = calC(x1, y1);
	int code2 = calC(x2, y2);
	bool accept = false;
	while (true) {
		if (!(code1 || code2)) {
			accept = true;
			break;
		}
		else if (code1 & code2)
			break;
		else {
			int code_out = code1 ? code1 : code2;
			int x, y;
			if (code_out & TOP) {
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) {
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else {
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = calC(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = calC(x2, y2);
			}
		}
	}
	if (accept) {
		setcolor(YELLOW);
		line(x1, y1, x2, y2);
	}
}

// =====================================
//		Main Algorithm End
//======================================

int main() {
	int gd = DETECT, gm;
	initwindow(650, 500);
	rectangle(x_min, y_min, x_max, y_max);
	double x1, y1, x2, y2;
	cout << "Enter x1 and y1 : ";
	cin >> x1 >> y1;
	cout << "Enter x2 and y2 : ";
	cin >> x2 >> y2;
	CHS(x1, y1, x2, y2);

	getch();
	closegraph();
	return 0;
}
