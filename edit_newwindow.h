#ifndef EDIT_NEWWINDOW_H
#define EDIT_NEWWINDOW_H

#include <QDialog>
#include "addressbook_func.h"

namespace Ui {
class Edit_newWindow;
}

class Edit_newWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_newWindow(AddressBook &phonebook, QWidget *parent = nullptr);
    ~Edit_newWindow();

signals:
    void addressEdited();

private slots:
    void on_pushButton_Enter_clicked();
    void on_pushButton_Edit_clicked();

private:
    Ui::Edit_newWindow *ui;
    AddressBook& m_phonebook;
    QString currentSearchName;
};

#endif // EDIT_NEWWINDOW_H
