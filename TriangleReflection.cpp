#include <iostream>
#include "graphics.h"
#include <cmath>

using namespace std;

int main() {
  int gd = DETECT, gm;
  initwindow(650, 500);
  
  // ========================================
  //	Main Algorithm 
  //=========================================
  
  int coords[6];
  cout << "Enter first point: ";
  cin >> coords[0] >> coords[1];
  cout << "Enter second point: ";
  cin >> coords[2] >> coords[3];
  cout << "Enter third point: ";
  cin >> coords[4] >> coords[5];
  int offsetX = 315, offsetY = 250;
  // Original Triangle
  line(coords[0] + offsetX, coords[1] + offsetY, coords[2] + offsetX, coords[3] + offsetY);
  line(coords[0] + offsetX, coords[1] + offsetY, coords[4] + offsetX, coords[5] + offsetY);
  line(coords[2] + offsetX, coords[3] + offsetY, coords[4] + offsetX, coords[5] + offsetY);
  //Reflection X-axis
  line(coords[0] + offsetX, -coords[1] + offsetY, coords[2] + offsetX, -coords[3] + offsetY);
  line(coords[0] + offsetX, -coords[1] + offsetY, coords[4] + offsetX, -coords[5] + offsetY);
  line(coords[2] + offsetX, -coords[3] + offsetY, coords[4] + offsetX, -coords[5] + offsetY);
  //Reflection Y-axis
  line(-coords[0] + offsetX, coords[1] + offsetY, -coords[2] + offsetX, coords[3] + offsetY);
  line(-coords[0] + offsetX, coords[1] + offsetY, -coords[4] + offsetX, coords[5] + offsetY);
  line(-coords[2] + offsetX, coords[3] + offsetY, -coords[4] + offsetX, coords[5] + offsetY);
  //Reflection around origin
  line(-coords[0] + offsetX, -coords[1] + offsetY, -coords[2] + offsetX, -coords[3] + offsetY);
  line(-coords[0] + offsetX, -coords[1] + offsetY, -coords[4] + offsetX, -coords[5] + offsetY);
  line(-coords[2] + offsetX, -coords[3] + offsetY, -coords[4] + offsetX, -coords[5] + offsetY);

  // ========================================
  //	Main Algorithm End
  //=========================================
  
  getch();
  closegraph();
  return 0;
}
