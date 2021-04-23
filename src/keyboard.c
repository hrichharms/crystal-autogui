#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>


void set_key(int key, Bool down) {
    Display *display = XOpenDisplay(0);
    XTestFakeKeyEvent(display, key, down, CurrentTime);
    XFlush(display);
}

void press(int key) {
    Display *display = XOpenDisplay(0);
    XTestFakeKeyEvent(display, key, True, CurrentTime);
    XFlush(display);
    XTestFakeKeyEvent(display, key, False, CurrentTime);
    XFlush(display);
}
