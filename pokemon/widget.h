#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ui_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QStackedWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::StackedWidget *ui;
};
#endif // WIDGET_H
