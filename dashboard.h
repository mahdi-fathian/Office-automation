#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include <QStyle>
#include <QApplication>
#include <QTabWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QMessageBox>
#include "database.h"
#include "employeemanagement.h"
#include "documentmanagement.h"
#include "taskmanagement.h"
#include "calendar.h"
#include "reports.h"
#include "cartablewidget.h"
#include "delegationwidget.h"
#include "emailwidget.h"
#include "archivewidget.h"
#include "searchwidget.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

signals:
    void logoutRequested();

private slots:
    void onEmployeeManagementClicked();
    void onDocumentManagementClicked();
    void onTaskManagementClicked();
    void onCalendarClicked();
    void onReportsClicked();
    void onDashboardClicked();
    void onLogoutClicked();
    void onSettingsClicked();

private:
    Ui::Dashboard *ui;
    Database *db;
    
    // Main widgets
    QStackedWidget *stackedWidget;
    
    // User Profile Widgets
    QLabel *userNameLabel;
    QLabel *userRoleLabel;
    QPushButton *profileLogoutBtn;

    // Navigation buttons
    QPushButton *dashboardBtn;
    QPushButton *employeeManagementBtn;
    QPushButton *documentManagementBtn;
    QPushButton *taskManagementBtn;
    QPushButton *calendarBtn;
    QPushButton *reportsBtn;
    QPushButton *settingsBtn;
    QPushButton *automationBtn;
    QPushButton *cartableBtn;
    QPushButton *storageBtn;
    QPushButton *ePostBtn;
    
    // Dashboard widgets
    // QTableWidget *recentDocumentsTable;
    // QTableWidget *pendingTasksTable;
    // QTableWidget *upcomingEventsTable;
    
    // Page widgets
    EmployeeManagement *employeeManagementPage;
    DocumentManagement *documentManagementPage;
    TaskManagement *taskManagementPage;
    Calendar *calendarPage;
    Reports *reportsPage;
    QWidget *settingsPage;
    // Add these for navigation pages
    CartableWidget *cartablePage = nullptr;
    DelegationWidget *delegationPage = nullptr;
    EmailWidget *emailPage = nullptr;
    ArchiveWidget *archivePage = nullptr;
    SearchWidget *searchPage = nullptr;
    
    // Employee management widgets
    QTableWidget *employeeTable;
    QLineEdit *employeeSearchEdit;
    QPushButton *addEmployeeBtn;
    QPushButton *editEmployeeBtn;
    QPushButton *deleteEmployeeBtn;
    
    // Document management widgets
    QTableWidget *documentTable;
    QLineEdit *documentSearchEdit;
    QComboBox *documentTypeFilter;
    QDateEdit *documentDateFilter;
    QPushButton *addDocumentBtn;
    QPushButton *editDocumentBtn;
    QPushButton *deleteDocumentBtn;
    QPushButton *viewDocumentBtn;
    
    // Task management widgets
    QTableWidget *taskTable;
    QLineEdit *taskSearchEdit;
    QComboBox *taskStatusFilter;
    QDateEdit *taskDateFilter;
    QPushButton *addTaskBtn;
    QPushButton *editTaskBtn;
    QPushButton *deleteTaskBtn;
    QPushButton *completeTaskBtn;
    
    // Calendar widgets
    QTableWidget *eventTable;
    QDateEdit *eventDateFilter;
    QPushButton *addEventBtn;
    QPushButton *editEventBtn;
    QPushButton *deleteEventBtn;
    
    // Reports widgets
    QComboBox *reportTypeCombo;
    QDateEdit *reportStartDate;
    QDateEdit *reportEndDate;
    QPushButton *generateReportBtn;
    QPushButton *exportReportBtn;
    
    // Settings widgets
    QLineEdit *userFullNameEdit;
    QLineEdit *userEmailEdit;
    QLineEdit *userPhoneEdit;
    QLineEdit *userDepartmentEdit;
    QPushButton *saveSettingsBtn;
    QPushButton *changePasswordBtn;
    
    void setupUI();
    void setupConnections();
    QWidget* createDashboardPage();
    void loadDashboardData();
    void loadEmployeeData();
    void loadDocumentData();
    void loadTaskData();
    void loadEventData();
    void loadReportData();
    void loadSettingsData();
    void resetButtonStyles();
    void setActiveButton(QPushButton* button);
    QPushButton* createNavButton(const QString &text, const QString &iconPath);
};

#endif // DASHBOARD_H 