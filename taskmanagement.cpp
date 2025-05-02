#include "taskmanagement.h"

TaskManagement::TaskManagement(QWidget *parent) : QWidget(parent)
{
    db = new Database(this);
    setupUI();
    loadTasks();
    loadAssignees();
}

TaskManagement::~TaskManagement()
{
}

void TaskManagement::setupUI()
{
    // Create main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Create search section
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchEdit = new QLineEdit(this);
    searchEdit->setPlaceholderText("Search tasks...");
    searchEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    searchButton = new QPushButton("Search", this);
    searchButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; padding: 8px; border-radius: 4px; }"
                              "QPushButton:hover { background-color: #2980b9; }");
    
    searchLayout->addWidget(searchEdit);
    searchLayout->addWidget(searchButton);
    mainLayout->addLayout(searchLayout);

    // Create task table
    taskTable = new QTableWidget(this);
    taskTable->setColumnCount(6);
    taskTable->setHorizontalHeaderLabels({"ID", "Title", "Description", "Assignee", "Due Date", "Status"});
    taskTable->setStyleSheet("QTableWidget { border: 1px solid #bdc3c7; border-radius: 4px; }"
                           "QHeaderView::section { background-color: #2c3e50; color: white; padding: 8px; }");
    taskTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    taskTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(taskTable);

    // Create input section
    QVBoxLayout *inputLayout = new QVBoxLayout();
    
    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("Task Title");
    titleEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    descriptionEdit = new QTextEdit(this);
    descriptionEdit->setPlaceholderText("Task Description");
    descriptionEdit->setStyleSheet("QTextEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    QHBoxLayout *taskDetailsLayout = new QHBoxLayout();
    
    dueDateEdit = new QDateEdit(this);
    dueDateEdit->setCalendarPopup(true);
    dueDateEdit->setDate(QDate::currentDate());
    dueDateEdit->setStyleSheet("QDateEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    assigneeCombo = new QComboBox(this);
    assigneeCombo->setStyleSheet("QComboBox { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    statusCombo = new QComboBox(this);
    statusCombo->addItems({"Pending", "In Progress", "Completed", "Cancelled"});
    statusCombo->setStyleSheet("QComboBox { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    taskDetailsLayout->addWidget(new QLabel("Due Date:"));
    taskDetailsLayout->addWidget(dueDateEdit);
    taskDetailsLayout->addWidget(new QLabel("Assignee:"));
    taskDetailsLayout->addWidget(assigneeCombo);
    taskDetailsLayout->addWidget(new QLabel("Status:"));
    taskDetailsLayout->addWidget(statusCombo);
    
    inputLayout->addWidget(titleEdit);
    inputLayout->addWidget(descriptionEdit);
    inputLayout->addLayout(taskDetailsLayout);
    mainLayout->addLayout(inputLayout);

    // Create button section
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    addButton = new QPushButton("Add Task", this);
    editButton = new QPushButton("Edit Task", this);
    deleteButton = new QPushButton("Delete Task", this);
    
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
    connect(addButton, &QPushButton::clicked, this, &TaskManagement::onAddTaskClicked);
    connect(editButton, &QPushButton::clicked, this, &TaskManagement::onEditTaskClicked);
    connect(deleteButton, &QPushButton::clicked, this, &TaskManagement::onDeleteTaskClicked);
    connect(searchButton, &QPushButton::clicked, this, &TaskManagement::onSearchTaskClicked);
    connect(statusCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TaskManagement::onStatusChanged);
}

void TaskManagement::loadTasks()
{
    QSqlQuery query;
    query.exec("SELECT * FROM tasks");
    
    taskTable->setRowCount(0);
    while (query.next()) {
        int row = taskTable->rowCount();
        taskTable->insertRow(row);
        
        taskTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        taskTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        taskTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        taskTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        taskTable->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        taskTable->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
    }
}

void TaskManagement::loadAssignees()
{
    QSqlQuery query;
    query.exec("SELECT name FROM employees");
    
    assigneeCombo->clear();
    while (query.next()) {
        assigneeCombo->addItem(query.value(0).toString());
    }
}

void TaskManagement::onAddTaskClicked()
{
    QString title = titleEdit->text();
    QString description = descriptionEdit->toPlainText();
    QString assignee = assigneeCombo->currentText();
    QDate dueDate = dueDateEdit->date();
    QString status = statusCombo->currentText();

    if (title.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields!");
        return;
    }

    // Get assignee ID from database
    QSqlQuery query;
    query.prepare("SELECT id FROM employees WHERE name = ?");
    query.addBindValue(assignee);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Error", "Invalid assignee selected!");
        return;
    }
    int assigneeId = query.value(0).toInt();

    // Get current user ID (assuming it's stored in a member variable)
    int creatorId = 1; // TODO: Replace with actual current user ID

    if (db->addTask(title, description, assigneeId, creatorId, dueDate, "Medium")) {
        QMessageBox::information(this, "Success", "Task added successfully!");
        clearInputs();
        loadTasks();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add task!");
    }
}

void TaskManagement::onEditTaskClicked()
{
    QList<QTableWidgetItem*> selectedItems = taskTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a task to edit!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = taskTable->item(row, 0)->text();
    QString title = titleEdit->text();
    QString description = descriptionEdit->toPlainText();
    QString assignee = assigneeCombo->currentText();
    QDate dueDate = dueDateEdit->date();
    QString status = statusCombo->currentText();

    if (title.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields!");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE tasks SET title = ?, description = ?, assignee = ?, due_date = ?, status = ? WHERE id = ?");
    query.addBindValue(title);
    query.addBindValue(description);
    query.addBindValue(assignee);
    query.addBindValue(dueDate);
    query.addBindValue(status);
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Task updated successfully!");
        clearInputs();
        loadTasks();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update task!");
    }
}

void TaskManagement::onDeleteTaskClicked()
{
    QList<QTableWidgetItem*> selectedItems = taskTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a task to delete!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = taskTable->item(row, 0)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
        "Are you sure you want to delete this task?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM tasks WHERE id = ?");
        query.addBindValue(id);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Task deleted successfully!");
            loadTasks();
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete task!");
        }
    }
}

void TaskManagement::onSearchTaskClicked()
{
    QString searchText = searchEdit->text();
    if (searchText.isEmpty()) {
        loadTasks();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM tasks WHERE title LIKE ? OR description LIKE ? OR assignee LIKE ?");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");

    if (query.exec()) {
        taskTable->setRowCount(0);
        while (query.next()) {
            int row = taskTable->rowCount();
            taskTable->insertRow(row);
            
            taskTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            taskTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            taskTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            taskTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            taskTable->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            taskTable->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        }
    }
}

void TaskManagement::onStatusChanged()
{
    QList<QTableWidgetItem*> selectedItems = taskTable->selectedItems();
    if (selectedItems.isEmpty()) {
        return;
    }

    int row = selectedItems.first()->row();
    QString id = taskTable->item(row, 0)->text();
    QString status = statusCombo->currentText();

    QSqlQuery query;
    query.prepare("UPDATE tasks SET status = ? WHERE id = ?");
    query.addBindValue(status);
    query.addBindValue(id);

    if (query.exec()) {
        loadTasks();
    }
}

void TaskManagement::clearInputs()
{
    titleEdit->clear();
    descriptionEdit->clear();
    dueDateEdit->setDate(QDate::currentDate());
    statusCombo->setCurrentIndex(0);
}

void TaskManagement::refreshTaskList()
{
    taskTable->setRowCount(0);
    loadTasks();
} 