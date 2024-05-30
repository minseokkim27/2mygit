#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "address_factor.h"
#include "addressbook_func.h"
#include "add_newwindow.h"
#include "edit_newwindow.h"

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
    disconnection();
    Add_newWindow *addWindow = new Add_newWindow(m_phonebook, this);
    connect(addWindow, &Add_newWindow::addressAdded, this, &MainWindow::text_AddressAdded);
    addWindow->exec();
}

void MainWindow::text_AddressAdded(bool nameCheck)
{
    if (nameCheck)
    {
        ui->textEdit_mainWindow->setText("주소가 추가되었습니다.");
    }
    else
    {
        ui->textEdit_mainWindow->setText("이미 같은 이름이 있습니다.");
    }
}

void MainWindow::on_pushButton_Delete_clicked()
{
    disconnection();
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Delete_clicked()));
    //ui->lineEdit->setText("");
    QString searchName = ui->lineEdit->text().trimmed();
    if (searchName.isEmpty())
    {
        ui->textEdit_mainWindow->setText("<주소록 삭제>\n\n 삭제하실 주소록 이름을 적고 'Delete'를 눌러주세요 \n");
    }
    else
    {
        std::string str = m_phonebook.DeleteAddressBook(searchName.toStdString());
        ui->textEdit_mainWindow->setText(QString::fromStdString(str));
    }
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_Search_clicked()
{
    disconnection();
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Search_clicked()));

    QString searchName = ui->lineEdit->text().trimmed();
    if (searchName.isEmpty())
    {
        ui->textEdit_mainWindow->setText("<주소록 검색>\n\n 검색하실 주소록 이름을 적고 'Enter'를 눌러주세요 \n");
    }
    else
    {
        std::string str = m_phonebook.SearchAddressBook(searchName.toStdString());
        ui->textEdit_mainWindow->setText(QString::fromStdString(str));
    }
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_Edit_clicked()
{
    disconnection();
    Edit_newWindow *editWindow = new Edit_newWindow(m_phonebook, this);
    connect(editWindow, &Edit_newWindow::addressEdited, this, &MainWindow::text_AddressEdited);
    editWindow->exec();
}

void MainWindow::text_AddressEdited()
{
    ui->textEdit_mainWindow->setText("주소가 수정되었습니다.\n");
}

void MainWindow::on_pushButton_Save_clicked()
{
    disconnection();
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Save_clicked()));

    QString fileName = ui->lineEdit->text().trimmed();
    if (fileName.isEmpty())
    {
        ui->textEdit_mainWindow->setText("<JSON 저장>\n\n 저장하실 Json파일 이름을 .json까지 적고 'save' 버튼을 눌러주세요 \n");
    }
    else
    {
        std::string str = m_phonebook.saveToJson(fileName.toStdString());
        ui->textEdit_mainWindow->setText(QString::fromStdString(str));
    }
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_Load_clicked()
{
    disconnection();
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Load_clicked()));

    QString fileName = ui->lineEdit->text().trimmed();
    if (fileName.isEmpty())
    {
        ui->textEdit_mainWindow->setText("<JSON 저장>\n\n 불러오실 Json파일 이름을 .json까지 적고 'load' 버튼을 눌러주세요 \n");
    }
    else
    {
        std::string str = m_phonebook.loadFromJson(fileName.toStdString());
        ui->textEdit_mainWindow->setText(QString::fromStdString(str));
    }
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_show_clicked()
{
    disconnection();
    ui->textEdit_mainWindow->setText(m_phonebook.GetAddressBook().data());
}

void MainWindow::on_pushButton_CleanUp_clicked()
{
    disconnection();
    ui->textEdit_mainWindow->setText("");
}

void MainWindow::disconnection()
{
    disconnect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Delete_clicked()));
    disconnect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Search_clicked()));
    disconnect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Save_clicked()));
    disconnect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Load_clicked()));
}
