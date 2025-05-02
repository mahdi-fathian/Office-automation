#ifndef TASKMANAGEMENT_H
#define TASKMANAGEMENT_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QDateEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "database.h"

class TaskManagement : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManagement(QWidget *parent = nullptr);
    ~TaskManagement();

private slots:
    void onAddTaskClicked();
    void onEditTaskClicked();
    void onDeleteTaskClicked();
    void onSearchTaskClicked();
    void onStatusChanged();
    void refreshTaskList();

private:
    QTableWidget *taskTable;
    QLineEdit *titleEdit;
    QTextEdit *descriptionEdit;
    QDateEdit *dueDateEdit;
    QComboBox *assigneeCombo;
    QComboBox *statusCombo;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *searchButton;
    QLineEdit *searchEdit;
    Database *db;

    void setupUI();
    void loadTasks();
    void clearInputs();
    void loadAssignees();
};

#endif // TASKMANAGEMENT_H 