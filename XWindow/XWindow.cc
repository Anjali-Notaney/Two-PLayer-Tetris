#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "XWindow.h"
#include "sstream"

using namespace std;

Xwindow::Xwindow(int width, int height): width{width}, height{height}{

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;

  cmap=DefaultColormap(d,DefaultScreen(d));
  XParseColor(d,cmap,"rgb:00/00/00",&xcolour);
  XAllocColor(d,cmap,&xcolour);

  fill = xcolour.pixel;
  XSetForeground(d,gc,xcolour.pixel); // initial fill is black

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::setFill(std::string hex){
	std::string colour = "rgb:";
	std::istringstream ss(hex); // make a stream of hex

	for(int i = 0; i < 3; i++){ // get three two-character hex portions
		char first, second;
		ss >> first >> second;

		// Checks for improper format
		if(ss.fail()){ // exit since hex is not in the correct format
			return;
		}else if(!(('0' <= first && first <= '9') || ('a' <= first && first <= 'f')) ||
			!(('0' <= second && second <= '9') || ('a' <= second && second <= 'f'))){ // check that we receive valid hex values
			return;
		}

		colour += first;
		colour += second;
		if(i != 2){
			colour += '/';
		}
	}

	// set the fill to the appropriate colour
	XColor xcolour;
	XParseColor(this->d,DefaultColormap(this->d,DefaultScreen(this->d)),colour.c_str(),&xcolour);
    XAllocColor(this->d,DefaultColormap(this->d,DefaultScreen(this->d)),&xcolour);
    this->fill = xcolour.pixel;
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, this->fill);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, this->fill);
}

void Xwindow::drawString(int x, int y, string msg) {
	XDrawString(this->d, this->w, DefaultGC(this->d, s), x, y, msg.c_str(), msg.length());
}

void Xwindow::drawLine(int x1, int y1, int x2, int y2, int colour) {
  XSetForeground(d, gc, this->fill);
  XDrawLine(d, w, gc, x1, y1, x2, y2);
  XSetForeground(d, gc, this->fill);
}

int Xwindow::getWidth(){
  return this->width;
}

int Xwindow::getHeight(){
  return this->height;
}


