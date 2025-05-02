#include "employeemanagement.h"

EmployeeManagement::EmployeeManagement(QWidget *parent) : QWidget(parent)
{
    db = new Database(this);
    setupUI();
    loadEmployees();
}

EmployeeManagement::~EmployeeManagement()
{
}

void EmployeeManagement::setupUI()
{
    // Create main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Create search section
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchEdit = new QLineEdit(this);
    searchEdit->setPlaceholderText("Search employees...");
    searchEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    searchButton = new QPushButton("Search", this);
    searchButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; padding: 8px; border-radius: 4px; }"
                              "QPushButton:hover { background-color: #2980b9; }");
    
    searchLayout->addWidget(searchEdit);
    searchLayout->addWidget(searchButton);
    mainLayout->addLayout(searchLayout);

    // Create employee table
    employeeTable = new QTableWidget(this);
    employeeTable->setColumnCount(4);
    employeeTable->setHorizontalHeaderLabels({"ID", "Name", "Position", "Department"});
    employeeTable->setStyleSheet("QTableWidget { border: 1px solid #bdc3c7; border-radius: 4px; }"
                               "QHeaderView::section { background-color: #2c3e50; color: white; padding: 8px; }");
    employeeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    employeeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(employeeTable);

    // Create input section
    QHBoxLayout *inputLayout = new QHBoxLayout();
    
    nameEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("Employee Name");
    nameEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    positionEdit = new QLineEdit(this);
    positionEdit->setPlaceholderText("Position");
    positionEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    departmentCombo = new QComboBox(this);
    departmentCombo->addItems({"IT", "HR", "Finance", "Marketing", "Operations"});
    departmentCombo->setStyleSheet("QComboBox { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    inputLayout->addWidget(nameEdit);
    inputLayout->addWidget(positionEdit);
    inputLayout->addWidget(departmentCombo);
    mainLayout->addLayout(inputLayout);

    // Create button section
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    addButton = new QPushButton("Add Employee", this);
    editButton = new QPushButton("Edit Employee", this);
    deleteButton = new QPushButton("Delete Employee", this);
    
    QString buttonStyle = "QPushButton { padding: 8px; border-radius: 4px; }";
    addButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #2ecc71; color: white; }"
                           "QPushButton:hover { background-color: #27ae60; }");
    editButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #f1c40f; color: white; }"
                            "QPushButton:hover { background-color: #f39c12; }");
    deleteButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #e74c3c; color: white; }"
                              "QPushButton:hover { background-color: #c0392b; }");
    
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);
    mainLayout->addLayout(buttonLayout);

    // Connect signals
    connect(addButton, &QPushButton::clicked, this, &EmployeeManagement::onAddEmployeeClicked);
    connect(editButton, &QPushButton::clicked, this, &EmployeeManagement::onEditEmployeeClicked);
    connect(deleteButton, &QPushButton::clicked, this, &EmployeeManagement::onDeleteEmployeeClicked);
    connect(searchButton, &QPushButton::clicked, this, &EmployeeManagement::onSearchEmployeeClicked);
}

void EmployeeManagement::loadEmployees()
{
    QSqlQuery query;
    query.exec("SELECT * FROM employees");
    
    employeeTable->setRowCount(0);
    while (query.next()) {
        int row = employeeTable->rowCount();
        employeeTable->insertRow(row);
        
        employeeTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        employeeTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        employeeTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        employeeTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
    }
}

void EmployeeManagement::onAddEmployeeClicked()
{
    QString name = nameEdit->text();
    QString position = positionEdit->text();
    QString department = departmentCombo->currentText();

    if (name.isEmpty() || position.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields!");
        return;
    }

    // Generate employee code (you might want to implement a more sophisticated method)
    QString employeeCode = "EMP" + QString::number(QDateTime::currentDateTime().toSecsSinceEpoch());
    
    // Set default values for required fields
    QDate hireDate = QDate::currentDate();
    double salary = 0.0; // TODO: Add salary input field

    if (db->addEmployee(employeeCode, name, position, department, hireDate, salary)) {
        QMessageBox::information(this, "Success", "Employee added successfully!");
        clearInputs();
        loadEmployees();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add employee!");
    }
}

void EmployeeManagement::onEditEmployeeClicked()
{
    QList<QTableWidgetItem*> selectedItems = employeeTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select an employee to edit!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = employeeTable->item(row, 0)->text();
    QString name = nameEdit->text();
    QString position = positionEdit->text();
    QString department = departmentCombo->currentText();

    if (name.isEmpty() || position.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields!");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE employees SET name = ?, position = ?, department = ? WHERE id = ?");
    query.addBindValue(name);
    query.addBindValue(position);
    query.addBindValue(department);
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Employee updated successfully!");
        clearInputs();
        loadEmployees();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update employee!");
    }
}

void EmployeeManagement::onDeleteEmployeeClicked()
{
    QList<QTableWidgetItem*> selectedItems = employeeTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select an employee to delete!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = employeeTable->item(row, 0)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
        "Are you sure you want to delete this employee?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM employees WHERE id = ?");
        query.addBindValue(id);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Employee deleted successfully!");
            loadEmployees();
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete employee!");
        }
    }
}

void EmployeeManagement::onSearchEmployeeClicked()
{
    QString searchText = searchEdit->text();
    if (searchText.isEmpty()) {
        loadEmployees();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM employees WHERE name LIKE ? OR position LIKE ? OR department LIKE ?");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");

    if (query.exec()) {
        employeeTable->setRowCount(0);
        while (query.next()) {
            int row = employeeTable->rowCount();
            employeeTable->insertRow(row);
            
            employeeTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            employeeTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            employeeTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            employeeTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        }
    }
}

void EmployeeManagement::clearInputs()
{
    nameEdit->clear();
    positionEdit->clear();
    departmentCombo->setCurrentIndex(0);
}

void EmployeeManagement::refreshEmployeeList()
{
    employeeTable->setRowCount(0);
    loadEmployees();
} 