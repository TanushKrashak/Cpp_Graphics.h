#include <iostream>
#include "graphics.h"
#include <cmath>
using namespace std;
int main() {
  int gd = DETECT, gm;
  initwindow(650, 500);
  
  // ========================================
  //	Main Algorithm End
  //=========================================
  
  double x1, y1, x2, y2;
  cout << "Enter x1 and y1 : ";
  cin >> x1 >> y1;
  cout << "Enter x2 and y2 : ";
  cin >> x2 >> y2;
  line(x1, y1, x2, y2); // Draw Original Line
  cout << "Enter translation values: ";
  int tx, ty; cin >> tx >> ty; // Translation Coords  
  line(x1 + tx, y1 + ty, x2 + tx, y2 + ty); // Translated Line

  // Scaling From 1st End Point (for Scaling from Origin, multiply both endpoints with scaling factor)  
  cout << "Enter scaling multipliers: ";
  int sx, sy; cin >> sx >> sy; // Scaling Values
  line(x1, y1, x1 + (x2 - x1) * sx, y1 + (y2 - y1) * sy);  

  cout << "Enter rotation angle: ";
  float r; cin >> r; // Rotation Value
  r *= 22.0 / (7.0 * 180);

  // Rotation From Origin
  line(x1 * cos(r) - y1 * sin(r), x1 * sin(r) + y1 * cos(r), x2 * cos(r) - y2 * sin(r), x2 * sin(r) + y2 *
  cos(r));

  // Convert to 2 decimal places
  float C = cos(r);
  C *= 100;
  C = int(C);
  C = C / 100;
  float S = sin(r);
  S *= 100;
  S = int(S);
  S = S / 100;

  //Rotation From Offset Origin 
  line(x1 * C - y1 * S + 315, x1 * S + y1 * C + 225, x2 * C - y2 * S + 315, x2 * S + y2 * C + 225);
  
  // ========================================
  //	Main Algorithm End
  //=========================================
  
  getch();
  closegraph();
  return 0;
}
