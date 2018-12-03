#ifndef WINDOW_H
#define WINDOW_H
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long fill;
  int width, height;

 public:
  Xwindow(int width=500, int height=500);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.
  Xwindow(const Xwindow&) = delete;
  Xwindow &operator=(const Xwindow&) = delete;

  enum {White=0, Black, Red, Green, Blue}; // Available colours.

  // Sets the fill colour
  // - hex should be of the form XXXXXX where X is some hex value from 1 - f
  // - Nothing happens if hex is of the wrong form
  // - The first pair of digits is for red, second pair is for green and last pair for blue
  // - All rectangles and lines drawn after the fill is set will be of that colour
  void setFill(std::string hex);

  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=Black);

  // Draws a string
  void drawString(int x, int y, std::string msg);

  // Draws a line
  void drawLine(int x1, int y1, int x2, int y2, int colour=Black);

  // get dimensions
  int getWidth();

  int getHeight();

};

#endif
