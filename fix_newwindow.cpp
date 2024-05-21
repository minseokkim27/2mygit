#include "fix_newwindow.h"
#include "ui_fix_newwindow.h"
#include "mainwindow.h"

Fix_newWindow::Fix_newWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fix_newWindow)
{
    ui->setupUi(this);
}

Fix_newWindow::~Fix_newWindow()
{
    delete ui;
}
