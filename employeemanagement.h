#ifndef EMPLOYEEMANAGEMENT_H
#define EMPLOYEEMANAGEMENT_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "database.h"

class EmployeeManagement : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeManagement(QWidget *parent = nullptr);
    ~EmployeeManagement();

private slots:
    void onAddEmployeeClicked();
    void onEditEmployeeClicked();
    void onDeleteEmployeeClicked();
    void onSearchEmployeeClicked();
    void refreshEmployeeList();

private:
    QTableWidget *employeeTable;
    QLineEdit *nameEdit;
    QLineEdit *positionEdit;
    QComboBox *departmentCombo;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *searchButton;
    QLineEdit *searchEdit;
    Database *db;

    void setupUI();
    void loadEmployees();
    void clearInputs();
};

#endif // EMPLOYEEMANAGEMENT_H 