#include <X11/Xlib.h>


void size(int* width, int* height) {
    Display *display = XOpenDisplay(0);
    int screen_num = DefaultScreen(display);
    *width = DisplayWidth(display, screen_num);
    *height = DisplayHeight(display, screen_num);
}
