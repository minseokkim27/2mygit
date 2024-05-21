#include "add_newwindow.h"
#include "ui_add_newwindow.h"
#include "mainwindow.h"

Add_newWindow::Add_newWindow(AddressBook &addressBook, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_newWindow),
    m_addressBook(addressBook)
{
    ui->setupUi(this);
    connect(ui->lineEdit_Address, SIGNAL(returnPressed()), this,  SLOT(on_pushButton_Address_clicked()));
}

Add_newWindow::~Add_newWindow()
{
    delete ui;
}

void Add_newWindow::on_pushButton_Address_clicked()
{
    QString name = ui->lineEdit_Name->text().trimmed();
    QString sex = ui->lineEdit_Sex->text().trimmed();
    QString number = ui->lineEdit_Number->text().trimmed();
    QString address = ui->lineEdit_Address->text().trimmed();

    Address newAddress(name.toStdString(), sex.toStdString(), number.toStdString(), address.toStdString());
    m_addressBook.addAddress(newAddress);

    emit addressAdded();
    accept();
}