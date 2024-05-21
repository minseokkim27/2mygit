#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "address_factor.h"
#include "addressbook_func.h"
#include "add_newwindow.h"
#include "fix_newwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(returnPressed()), this,  SLOT(on_pushButton_Search_Enter_clicked()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this,  SLOT(on_pushButton_Delete_Enter_clicked()));
    

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


//exec 와 show() 차이에 대해서 공부하기
void MainWindow::on_pushButton_Add_clicked()
{
    Add_newWindow *addWindow = new Add_newWindow(m_phonebook, this);
    connect(addWindow, &Add_newWindow::addressAdded, this, &MainWindow::text_AddressAdded);
    addWindow->exec();

    /*mAdd_newWindow.m_name;
    mAdd_newWindow.m_sex;
    mAdd_newWindow.m_number;
    mAdd_newWindow.m_address;*/
}

void MainWindow::on_pushButton_Delete_clicked()
{
    ui->textEdit_mainWindow->setText("<주소록 삭제>\n\n 삭제하실 주소록 이름을 적고 'Delete Enter'를 눌러주세요 \n");
}

void MainWindow::on_pushButton_Delete_Enter_clicked()
{
    QString searchName = ui->lineEdit->text().trimmed();
    std::string str = m_phonebook.DeleteAddressBook(searchName.toStdString());
    ui->textEdit_mainWindow->setText(QString::fromStdString(str));
}

void MainWindow::on_pushButton_Search_clicked()
{
    ui->textEdit_mainWindow->setText("<주소록 검색>\n\n 검색하실 주소록 이름을 적고 'Search Enter'를 눌러주세요. \n");
}

void MainWindow::on_pushButton_Search_Enter_clicked()
{
    QString searchName = ui->lineEdit->text().trimmed();
    std::string str = m_phonebook.SearchAddressBook(searchName.toStdString());
    ui->textEdit_mainWindow->setText(QString::fromStdString(str));
}

void MainWindow::on_pushButton_Fix_clicked()
{
    Fix_newWindow mFix_newWindow;
    mFix_newWindow.exec();
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

void MainWindow::text_AddressAdded()
{
    ui->textEdit_mainWindow->setText("주소가 추가되었습니다.");
}