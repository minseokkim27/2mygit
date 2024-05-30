#ifndef ADD_NEWWINDOW_H
#define ADD_NEWWINDOW_H

#include <QDialog>
#include "addressbook_func.h"

namespace Ui {
class Add_newWindow;
}

class Add_newWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Add_newWindow(AddressBook &addressBook, QWidget *parent = nullptr);
    ~Add_newWindow();

signals:
    void addressAdded(bool nameCheck);

private slots:
    void on_pushButton_Address_clicked();

private:
    Ui::Add_newWindow *ui;
    AddressBook& m_addressBook;
};

#endif // ADD_NEWWINDOW_H

