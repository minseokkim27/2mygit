#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "address_factor.h"
#include "addressbook_func.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Address address1("Son", "M", "010-7777-7777", "1st, London, England");
    Address address2("Ryu", "M", "010-9999-9999", "2st, LA, America");
    Address address3("Amanda", "W", "010-1588-1588", "3st, Sao Paulo, Brazil");
    Address address4("Messi", "M", "010-1010-1010", "4st, Barcellona, Spain");
    Address address5("Kim", "M", "010-2929-2929", "5st, Incheon, Korea");
    m_phonebook.addAddress(address1);
    m_phonebook.addAddress(address2);
    m_phonebook.addAddress(address3);
    m_phonebook.addAddress(address4);
    m_phonebook.addAddress(address5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    
}

void MainWindow::on_pushButton_Add_clicked()
{
    
}

void MainWindow::on_pushButton_Delete_clicked()
{
    
}

void MainWindow::on_pushButton_Search_clicked()
{
    //m_phonebook.SearchAddressBook(searchName.toStdString());
    //ui->textEdit_mainWindow->setText(m_phonebook.SearchAddressBook().data());
    QString searchName = ui->lineEdit->text().trimmed(); 
    //m_phonebook.searchAddress(searchName.toStdString());
    //ui->textEdit_mainWindow->setText(m_phonebook.searchAddress(QString::fromStdString(searchName)));
    std::string str = m_phonebook.SearchAddressBook(searchName.toStdString());
    ui->textEdit_mainWindow->setText(QString::fromStdString(str));
}
void MainWindow::on_pushButton_Fix_clicked()
{

}

void MainWindow::on_pushButton_SaveLoad_clicked()
{

}

void MainWindow::on_pushButton_show_clicked()
{
    ui->textEdit_mainWindow->setText(m_phonebook.GetAddressBook().data());
}

void MainWindow::on_pushButton_CleanUp_clicked()
{
    ui->textEdit_mainWindow->setText("");
}

void MainWindow::on_pushButton_enter_clicked()
{    
    std::string str = ui->textEdit_mainWindow->toPlainText().toStdString();
    str += ui->lineEdit->text().toStdString()+ "\n";
    ui->textEdit_mainWindow->setText(str.data());
}
