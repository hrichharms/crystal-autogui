#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>


void position(int* x, int* y) {
    Display *display = XOpenDisplay(0);
    int win_x, win_y, root_x, root_y = 0;
    unsigned int mask = 0;
    Window child_win, root_win;
    XQueryPointer(display, XRootWindow(display, DefaultScreen(display)), &child_win, &root_win, &root_x, &root_y, &win_x, &win_y, &mask);
    *x = win_x;
    *y = win_y;
}


void move_to(int x, int y) {
    Display *display = XOpenDisplay(0);
    XTestFakeMotionEvent(display, -1, x, y, CurrentTime);
    XFlush(display);
}


void set_mouse(int button, Bool down) {
    Display *display = XOpenDisplay(0);
    XTestFakeButtonEvent(display, button, down, CurrentTime);
    XFlush(display);
}


void click(int button) {
    Display *display = XOpenDisplay(0);
    XTestFakeButtonEvent(display, button, True, CurrentTime);
    XFlush(display);
    XTestFakeButtonEvent(display, button, False, CurrentTime);
    XFlush(display);
}
