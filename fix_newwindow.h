#ifndef FIX_NEWWINDOW_H
#define FIX_NEWWINDOW_H

#include <QDialog>
#include "addressbook_func.h"

namespace Ui {
class Fix_newWindow;
}

class Fix_newWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Fix_newWindow(AddressBook &phonebook, QWidget *parent = nullptr);
    ~Fix_newWindow();

signals:
    void addressEdited();

private slots:
    void on_pushButton_Enter_clicked();
    void on_pushButton_Edit_clicked();

private:
    Ui::Fix_newWindow *ui;
    AddressBook& m_phonebook;
    QString currentSearchName;
};

#endif // FIX_NEWWINDOW_H
