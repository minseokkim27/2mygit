#include "add_newwindow.h"
#include "ui_add_newwindow.h"

Add_newWindow::Add_newWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_newWindow)
{
    ui->setupUi(this);
}

Add_newWindow::~Add_newWindow()
{
    delete ui;
}
