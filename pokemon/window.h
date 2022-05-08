#include <string>

#ifndef WINDOW_H
#define WINDOW_H

#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

    protected:
        Window* itsParent;

    public:
        Window(Window* parent=nullptr);

};

#endif // WINDOW_H
