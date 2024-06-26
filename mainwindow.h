#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addressbook_func.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);
    void on_pushButton_Add_clicked();    
    void on_pushButton_Delete_clicked();
    void on_pushButton_Search_clicked();    
    void on_pushButton_Edit_clicked();
    void on_pushButton_Save_clicked();
    void on_pushButton_Load_clicked();
    void on_pushButton_show_clicked();
    void on_pushButton_CleanUp_clicked();
    void disconnection();
    
    
    
    void text_AddressAdded(bool nameCheck);
    void text_AddressEdited();
    
private:
    Ui::MainWindow *ui;
    AddressBook m_phonebook;
};

#endif // MAINWINDOW_H
