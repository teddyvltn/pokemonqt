#include "window.h"

#include <iostream>

Window::Window(Window *parent) : QWidget(parent)
{
    itsParent = parent;
}





