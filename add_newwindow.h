#ifndef ADD_NEWWINDOW_H
#define ADD_NEWWINDOW_H

#include <QDialog>

namespace Ui {
class Add_newWindow;
}

class Add_newWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Add_newWindow(QWidget *parent = nullptr);
    ~Add_newWindow();

private:
    Ui::Add_newWindow *ui;
};

#endif // ADD_NEWWINDOW_H
