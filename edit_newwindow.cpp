#include "edit_newwindow.h"
#include "ui_edit_newwindow.h"

Edit_newWindow::Edit_newWindow(AddressBook &phonebook, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_newWindow),
    m_phonebook(phonebook)
{
    ui->setupUi(this);
    connect(ui->lineEdit_SearchName, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Enter_clicked()));
    connect(ui->lineEdit_Address, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Edit_clicked()));
    ui->lineEdit->setText("수정을 원하는 사람의 이름을 최하단에 입력해주세요.");
}

Edit_newWindow::~Edit_newWindow()
{
    delete ui;
}

void Edit_newWindow::on_pushButton_Edit_clicked()
{
    QString newName = ui->lineEdit_Name->text().trimmed();
    QString newSex = ui->lineEdit_Sex->text().trimmed();
    QString newNumber = ui->lineEdit_Num->text().trimmed();
    QString newAddress = ui->lineEdit_Address->text().trimmed();

    std::string str = m_phonebook.editAddressBook(currentSearchName.toStdString(), newName.toStdString(), newSex.toStdString(), newNumber.toStdString(), newAddress.toStdString());

    emit addressEdited();
    accept();
}

void Edit_newWindow::on_pushButton_Enter_clicked()
{
    QString searchName = ui->lineEdit_SearchName->text().trimmed();
    std::string name, sex, number, address;
    std::string str = m_phonebook.SearchAddressBook(searchName.toStdString());
    
    if (str.find("주소록에 없습니다.") == std::string::npos)
    {
        ui->lineEdit_Name->setText(QString::fromStdString(name));
        ui->lineEdit_Sex->setText(QString::fromStdString(sex));
        ui->lineEdit_Num->setText(QString::fromStdString(number));
        ui->lineEdit_Address->setText(QString::fromStdString(address));
        currentSearchName = searchName;
        ui->lineEdit->setText("수정할 내용을 기입해주세요.");
    } 
    else
    {
        ui->lineEdit_Name->clear();
        ui->lineEdit_Sex->clear();
        ui->lineEdit_Num->clear();
        ui->lineEdit_Address->clear();
        currentSearchName.clear();
    }
    
}


