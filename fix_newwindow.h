#ifndef FIX_NEWWINDOW_H
#define FIX_NEWWINDOW_H

#include <QDialog>
#include <qmainwindow.h>
#include "addressbook_func.h"
#include "address_factor.h"

namespace Ui {
class Fix_newWindow;
}

class Fix_newWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Fix_newWindow(QWidget *parent = nullptr);
    ~Fix_newWindow();

private:
    Ui::Fix_newWindow *ui;
};

#endif // FIX_NEWWINDOW_H
