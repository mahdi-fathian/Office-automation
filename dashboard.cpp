#include "dashboard.h"
#include "ui_dashboard.h"
#include "employeemanagement.h"
#include "documentmanagement.h"
#include "documents.h"
#include "taskmanagement.h"
#include "calendar.h"
#include "reports.h"
#include "delegationwidget.h"
#include "cartablewidget.h"
#include <QStyle>
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QTableWidget>
#include <QGroupBox>
#include <QLabel>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QToolBar>
#include <QListWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSettings>
#include "emailwidget.h"
#include "archivewidget.h"
#include "searchwidget.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    
    // Initialize settings
    settings = new QSettings("OfficeAutomation", "Dashboard", this);
    
    // Initialize database
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "خطا",
            "خطا در راه‌اندازی برنامه. لطفاً برنامه را مجدداً اجرا کنید.");
        return;
    }
    
    // Initialize page pointers
    employeeManagementPage = nullptr;
    documentManagementPage = nullptr;
    taskManagementPage = nullptr;
    calendarPage = nullptr;
    reportsPage = nullptr;
    settingsPage = nullptr;
    
    setupUI();
    setupConnections();
    loadUserPreferences();
    loadDashboardData();
}

Dashboard::~Dashboard()
{
    saveUserPreferences();
    delete ui;
}

void Dashboard::setupUI()
{
    // Set window properties
    setWindowTitle("اتوماسیون اداری - داشبورد");
    setMinimumSize(1024, 768); // Adjust size as needed
    setStyleSheet("QMainWindow { background-color: #e5e7eb; }" // Light gray background
                  "QFrame#navPanel { background-color: #1f2937; }" // Dark blue/gray for nav panel
                  "QPushButton#navButton { background-color: transparent; color: white; padding: 12px; "
                  "border: none; text-align: right; font-size: 14px; }"
                  "QPushButton#navButton:hover { background-color: #374151; }"
                  "QPushButton#navButton:checked { background-color: #4b5563; }" // Style for active button
                  "QFrame#mainContent { background-color: #f9fafb; border-radius: 8px; }" // Background for content area
                  "QFrame#userProfilePanel { background-color: #4b5563; border-radius: 8px; }" // User profile panel style
                  "QLabel#userNameLabel { color: white; font-size: 16px; font-weight: bold; }"
                  "QLabel#userRoleLabel { color: #d1d5db; font-size: 12px; }"
                  "QPushButton#profileButton { background-color: transparent; color: #d1d5db; border: none; text-align: right; }"
                  "QPushButton#profileButton:hover { color: white; }"
                  "QPushButton.tileButton { background-color: #3b82f6; color: white; border: none; border-radius: 8px; padding: 20px; font-size: 14px; text-align: center; }" // Tile button style
                  "QPushButton.tileButton:hover { background-color: #2563eb; }"
                 );

    // Create main layout (Central Widget)
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // --- Main Content Area (Left) ---
    QFrame *mainContentArea = new QFrame(this);
    mainContentArea->setObjectName("mainContent");
    QVBoxLayout *contentLayout = new QVBoxLayout(mainContentArea);
    contentLayout->setContentsMargins(20, 20, 20, 20);
    contentLayout->setSpacing(15);

    // Placeholder Label for Content Area
    QLabel *titleLabel = new QLabel("سازمان الکترونیک پیوست", mainContentArea);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #1f2937;");
    titleLabel->setAlignment(Qt::AlignCenter);

    // Stacked widget for pages (will replace the placeholder later)
    stackedWidget = new QStackedWidget(mainContentArea);
    // Add dashboard page with tiles initially
    QWidget *dashboardPage = createDashboardPage();
    stackedWidget->addWidget(dashboardPage);
    // TODO: Add other pages (EmployeeManagement, DocumentManagement, etc.) to stackedWidget

    contentLayout->addWidget(titleLabel);
    contentLayout->addWidget(stackedWidget);
    contentLayout->addStretch();

    // --- Navigation Panel (Right) ---
    QFrame *navPanel = new QFrame(this);
    navPanel->setObjectName("navPanel");
    navPanel->setFixedWidth(220); // Adjust width as needed
    QVBoxLayout *navLayout = new QVBoxLayout(navPanel);
    navLayout->setContentsMargins(10, 10, 10, 10);
    navLayout->setSpacing(5);

    // User Profile Section
    QFrame *userProfilePanel = new QFrame(navPanel);
    userProfilePanel->setObjectName("userProfilePanel");
    userProfilePanel->setFixedHeight(120); // Adjust height
    QVBoxLayout *userProfileLayout = new QVBoxLayout(userProfilePanel);
    // Add User profile widgets (Image Placeholder, Name, Role, Buttons)
    QHBoxLayout *userInfoLayout = new QHBoxLayout();
    QLabel *userImageLabel = new QLabel("[img]"); // Placeholder for user image
    userImageLabel->setFixedSize(50, 50);
    userImageLabel->setStyleSheet("border: 1px solid white; border-radius: 25px; background-color: white;"); // Circular placeholder
    userImageLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *userNameRoleLayout = new QVBoxLayout();
    userNameLabel = new QLabel("امیر احمدی"); // Placeholder
    userNameLabel->setObjectName("userNameLabel");
    userRoleLabel = new QLabel("مدیر سیستم"); // Placeholder
    userRoleLabel->setObjectName("userRoleLabel");
    userNameRoleLayout->addWidget(userNameLabel);
    userNameRoleLayout->addWidget(userRoleLabel);
    userNameRoleLayout->setSpacing(2);

    userInfoLayout->addWidget(userImageLabel);
    userInfoLayout->addSpacing(10);
    userInfoLayout->addLayout(userNameRoleLayout);
    userInfoLayout->addStretch();

    QPushButton *changePasswordBtn = new QPushButton("تغییر کلمه عبور", userProfilePanel);
    changePasswordBtn->setObjectName("profileButton");
    changePasswordBtn->setCursor(Qt::PointingHandCursor);

    QPushButton *profileLogoutBtn = new QPushButton("خروج", userProfilePanel); // Renamed to avoid conflict
    profileLogoutBtn->setObjectName("profileButton");
    profileLogoutBtn->setCursor(Qt::PointingHandCursor);

    userProfileLayout->addLayout(userInfoLayout);
    userProfileLayout->addStretch();
    userProfileLayout->addWidget(changePasswordBtn);
    userProfileLayout->addWidget(profileLogoutBtn);

    // Navigation Buttons
    dashboardBtn = createNavButton("داشبورد", ":/icons/modern/dashboard.png");
    employeeManagementBtn = createNavButton("دفتر تلفن", ":/icons/modern/phone.png"); // Changed text/icon based on image
    documentManagementBtn = createNavButton("یادداشت", ":/icons/modern/notes.png"); // Changed text/icon
    taskManagementBtn = createNavButton("تقویم", ":/icons/modern/calendar.png"); // Changed text/icon
    calendarBtn = createNavButton("تابلو اعلانات", ":/icons/modern/announcements.png"); // Changed text/icon
    reportsBtn = createNavButton("دبیرخانه", ":/icons/modern/archive.png"); // Changed text/icon
    QPushButton *automationBtn = createNavButton("اتوماسیون اداری", ":/icons/modern/automation.png"); // New button from image
    settingsBtn = createNavButton("لیست کارها", ":/icons/modern/tasks.png"); // Changed text/icon
    QPushButton *cartableBtn = createNavButton("کارتابل", ":/icons/modern/cartable.png");
    QPushButton *storageBtn = createNavButton("بایگانی اسناد", ":/icons/modern/storage.png"); // New button from image
    QPushButton *ePostBtn = createNavButton("پست الکترونیک", ":/icons/modern/email.png"); // New button from image
    QPushButton *delegationBtn = createNavButton("تفویض", ":/icons/modern/delegation.png");
    QPushButton *emailBtn = createNavButton("پست الکترونیک", ":/icons/modern/email.png");
    QPushButton *archiveBtn = createNavButton("آرشیو اسناد", ":/icons/modern/archive.png");
    QPushButton *searchBtn = createNavButton("جستجو", ":/icons/modern/search.png");

    // Add buttons to navigation panel
    navLayout->addWidget(userProfilePanel);
    navLayout->addSpacing(20);
    navLayout->addWidget(dashboardBtn);
    navLayout->addWidget(employeeManagementBtn);
    navLayout->addWidget(documentManagementBtn);
    navLayout->addWidget(taskManagementBtn);
    navLayout->addWidget(calendarBtn);
    navLayout->addWidget(reportsBtn);
    navLayout->addWidget(automationBtn);
    navLayout->addWidget(settingsBtn);
    navLayout->addWidget(cartableBtn);
    navLayout->addWidget(storageBtn);
    navLayout->addWidget(ePostBtn);
    navLayout->addWidget(delegationBtn);
    navLayout->addWidget(emailBtn);
    navLayout->addWidget(archiveBtn);
    navLayout->addWidget(searchBtn);
    navLayout->addStretch();
    // navLayout->addWidget(logoutBtn); // Logout is now in profile panel

    // Add content area and nav panel to main layout
    mainLayout->addWidget(mainContentArea, 1); // Content takes more space
    mainLayout->addWidget(navPanel);        // Nav panel on the right

    setCentralWidget(centralWidget);

    // Connect signals
    connect(profileLogoutBtn, &QPushButton::clicked, this, &Dashboard::onLogoutClicked); // Connect the correct logout button
    // TODO: Connect other nav buttons to slots that switch stackedWidget pages
    connect(dashboardBtn, &QPushButton::clicked, this, &Dashboard::onDashboardClicked);
    // connect(employeeManagementBtn, &QPushButton::clicked, this, &Dashboard::onPhoneBookClicked); // Example new slot
    // ... connect other buttons

    // Set initial state
    dashboardBtn->setChecked(true); // Set dashboard as active initially
    loadDashboardData(); // Load initial data for the dashboard page
}

// Helper function to create navigation buttons (slightly modified)
QPushButton* Dashboard::createNavButton(const QString &text, const QString &iconPath)
{
    QPushButton *button = new QPushButton(text);
    button->setObjectName("navButton"); // Assign object name for styling
    if (!iconPath.isEmpty())
    {
      button->setIcon(QIcon(iconPath));
      button->setIconSize(QSize(20, 20)); // Adjust icon size
      button->setLayoutDirection(Qt::RightToLeft); // Icon on the left for RTL
    }
    button->setCheckable(true); // Make buttons checkable for active state
    button->setAutoExclusive(true); // Ensure only one button is checked at a time (within a group)
    button->setCursor(Qt::PointingHandCursor);
    return button;
}

// Helper function to create the initial dashboard page with tiles
QWidget* Dashboard::createDashboardPage()
{
    QWidget *page = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(page);
    gridLayout->setSpacing(20);
    gridLayout->setContentsMargins(20, 20, 20, 20);

    // Create tile buttons based on the navigation panel (example)
    QPushButton *tile1 = new QPushButton("دفتر تلفن");
    QPushButton *tile2 = new QPushButton("یادداشت");
    QPushButton *tile3 = new QPushButton("تقویم");
    QPushButton *tile4 = new QPushButton("تابلو اعلانات");
    QPushButton *tile5 = new QPushButton("دبیرخانه");
    QPushButton *tile6 = new QPushButton("اتوماسیون اداری\n5 نامه جدید\n4 یادداشت اداری جدید\n9 فرد جدید");
    QPushButton *tile7 = new QPushButton("لیست کارها");
    QPushButton *tile8 = new QPushButton("مدیریت پیش نویس");
    QPushButton *tile9 = new QPushButton("بایگانی اسناد");
    QPushButton *tile10 = new QPushButton("پست الکترونیک");

    // Apply common style
    QString tileStyle = "QPushButton { background-color: #86efac; color: #1f2937; border: none; border-radius: 8px; padding: 20px; font-size: 14px; text-align: center; } QPushButton:hover { background-color: #4ade80; }";
    tile1->setStyleSheet("background-color: #fdba74;" + tileStyle); // Orange
    tile2->setStyleSheet("background-color: #fcd34d;" + tileStyle); // Yellow
    tile3->setStyleSheet("background-color: #c4b5fd;" + tileStyle); // Purple
    tile4->setStyleSheet("background-color: #34d399;" + tileStyle); // Green
    tile5->setStyleSheet("background-color: #67e8f9;" + tileStyle); // Cyan
    tile6->setStyleSheet("background-color: #60a5fa;" + tileStyle); // Blue
    tile7->setStyleSheet("background-color: #a78bfa;" + tileStyle); // Violet
    tile8->setStyleSheet("background-color: #34d399;" + tileStyle); // Green
    tile9->setStyleSheet("background-color: #a3e635;" + tileStyle); // Lime
    tile10->setStyleSheet("background-color: #67e8f9;" + tileStyle); // Cyan

    tile1->setCursor(Qt::PointingHandCursor);
    tile2->setCursor(Qt::PointingHandCursor);
    tile3->setCursor(Qt::PointingHandCursor);
    tile4->setCursor(Qt::PointingHandCursor);
    tile5->setCursor(Qt::PointingHandCursor);
    tile6->setCursor(Qt::PointingHandCursor);
    tile7->setCursor(Qt::PointingHandCursor);
    tile8->setCursor(Qt::PointingHandCursor);
    tile9->setCursor(Qt::PointingHandCursor);
    tile10->setCursor(Qt::PointingHandCursor);

    // Arrange tiles in a grid
    gridLayout->addWidget(tile1, 0, 0);
    gridLayout->addWidget(tile2, 0, 1);
    gridLayout->addWidget(tile3, 0, 2);
    gridLayout->addWidget(tile4, 0, 3);

    gridLayout->addWidget(tile5, 1, 0);
    gridLayout->addWidget(tile6, 1, 1);
    gridLayout->addWidget(tile7, 1, 2);
    gridLayout->addWidget(tile8, 1, 3);

    gridLayout->addWidget(tile9, 2, 0);
    gridLayout->addWidget(tile10, 2, 1);

    // Add stretch to fill remaining space
    gridLayout->setRowStretch(3, 1);
    gridLayout->setColumnStretch(4, 1);

    // TODO: Connect tile buttons to appropriate slots/actions
    // connect(tile1, &QPushButton::clicked, ...);

    return page;
}

// Update setupConnections to connect new buttons
void Dashboard::setupConnections()
{
    // Connect profile buttons
    // connect(changePasswordBtn, &QPushButton::clicked, this, &Dashboard::onChangePasswordClicked);
    connect(profileLogoutBtn, &QPushButton::clicked, this, &Dashboard::onLogoutClicked);

    // Connect navigation buttons
    connect(dashboardBtn, &QPushButton::clicked, this, &Dashboard::onDashboardClicked);
    connect(employeeManagementBtn, &QPushButton::clicked, this, &Dashboard::onEmployeeManagementClicked);
    connect(documentManagementBtn, &QPushButton::clicked, this, &Dashboard::onDocumentManagementClicked);
    connect(taskManagementBtn, &QPushButton::clicked, this, &Dashboard::onTaskManagementClicked);
    connect(calendarBtn, &QPushButton::clicked, this, &Dashboard::onCalendarClicked);
    connect(reportsBtn, &QPushButton::clicked, this, &Dashboard::onReportsClicked);
    connect(settingsBtn, &QPushButton::clicked, this, &Dashboard::onSettingsClicked);

    // Cartable
    connect(cartableBtn, &QPushButton::clicked, [this]() {
        if (!cartablePage) {
            cartablePage = new CartableWidget(db, this);
            stackedWidget->addWidget(cartablePage);
        }
        stackedWidget->setCurrentWidget(cartablePage);
    });
    // Delegation
    connect(delegationBtn, &QPushButton::clicked, [this]() {
        if (!delegationPage) {
            delegationPage = new DelegationWidget(this);
            stackedWidget->addWidget(delegationPage);
        }
        stackedWidget->setCurrentWidget(delegationPage);
    });
    // Email
    connect(ePostBtn, &QPushButton::clicked, [this]() {
        if (!emailPage) {
            emailPage = new EmailWidget(this);
            stackedWidget->addWidget(emailPage);
        }
        stackedWidget->setCurrentWidget(emailPage);
    });
    // Archive
    connect(archiveBtn, &QPushButton::clicked, [this]() {
        if (!archivePage) {
            archivePage = new ArchiveWidget(this);
            stackedWidget->addWidget(archivePage);
        }
        stackedWidget->setCurrentWidget(archivePage);
    });
    // Search
    connect(searchBtn, &QPushButton::clicked, [this]() {
        if (!searchPage) {
            searchPage = new SearchWidget(this);
            stackedWidget->addWidget(searchPage);
        }
        stackedWidget->setCurrentWidget(searchPage);
    });
}

// Modify loadDashboardData to load data for the new dashboard page if necessary
// (Currently, the tiles are static)
void Dashboard::loadDashboardData()
{
    try {
        // Assuming stackedWidget index 0 is the tile dashboard page
        stackedWidget->setCurrentIndex(0);
        
        // Load user data from database
        QSqlQuery query;
        query.prepare("SELECT full_name, role FROM users WHERE id = ?");
        query.addBindValue(settings->value("user/id").toInt());
        
        if (query.exec() && query.next()) {
            userNameLabel->setText(query.value(0).toString());
            userRoleLabel->setText(query.value(1).toString());
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "خطا",
            "خطا در بارگذاری اطلاعات داشبورد: " + QString(e.what()));
    }
}

void Dashboard::onDashboardClicked()
{
    stackedWidget->setCurrentIndex(0); // Assuming index 0 is the tile dashboard
    // No need to call setActiveButton if using autoExclusive buttons
    // loadDashboardData(); // Data is static for now
}

// Implement slots for new navigation buttons (Example)
/*
void Dashboard::onPhoneBookClicked()
{
    // if (!phoneBookPage) { phoneBookPage = new PhoneBookWidget(); stackedWidget->addWidget(phoneBookPage); }
    // stackedWidget->setCurrentWidget(phoneBookPage);
    // loadPhoneBookData();
}
*/

// Remove old setActiveButton and resetButtonStyles logic if using checkable buttons
void Dashboard::setActiveButton(QPushButton* button)
{
    // This might not be needed if QButtonGroup or autoExclusive is used
    button->setChecked(true);
}

void Dashboard::resetButtonStyles()
{
    // This might not be needed if QButtonGroup or autoExclusive is used
    // Iterate through buttons and set default style
}

// ... Rest of the Dashboard implementation ...
// Make sure loadEmployeeData, loadDocumentData etc. create and switch to the correct pages in the stackedWidget

void Dashboard::onEmployeeManagementClicked()
{
    stackedWidget->setCurrentIndex(1);
    setActiveButton(employeeManagementBtn);
    loadEmployeeData();
}

void Dashboard::onDocumentManagementClicked()
{
    stackedWidget->setCurrentIndex(2);
    setActiveButton(documentManagementBtn);
    loadDocumentData();
}

void Dashboard::onTaskManagementClicked()
{
    stackedWidget->setCurrentIndex(3);
    setActiveButton(taskManagementBtn);
    loadTaskData();
}

void Dashboard::onCalendarClicked()
{
    stackedWidget->setCurrentIndex(4);
    setActiveButton(calendarBtn);
    loadEventData();
}

void Dashboard::onReportsClicked()
{
    stackedWidget->setCurrentIndex(5);
    setActiveButton(reportsBtn);
    loadReportData();
}

void Dashboard::onSettingsClicked()
{
    stackedWidget->setCurrentIndex(6);
    setActiveButton(settingsBtn);
    loadSettingsData();
}

void Dashboard::onLogoutClicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "تایید خروج",
        "آیا از خروج از سیستم اطمینان دارید؟",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        emit logoutRequested();
        close();
    }
}

void Dashboard::loadEmployeeData()
{
    // Create employee management page if not exists
    if (!employeeManagementPage) {
        employeeManagementPage = new EmployeeManagement(this);
        stackedWidget->addWidget(employeeManagementPage);
    }
}

void Dashboard::loadDocumentData()
{
    // Create document management page if not exists
    if (!documentManagementPage) {
        documentManagementPage = new DocumentManagement(this);
        stackedWidget->addWidget(documentManagementPage);
    }
}

void Dashboard::loadTaskData()
{
    // Create task management page if not exists
    if (!taskManagementPage) {
        taskManagementPage = new TaskManagement(this);
        stackedWidget->addWidget(taskManagementPage);
    }
}

void Dashboard::loadEventData()
{
    // Create calendar page if not exists
    if (!calendarPage) {
        calendarPage = new Calendar(this);
        stackedWidget->addWidget(calendarPage);
    }
}

void Dashboard::loadReportData()
{
    // Create reports page if not exists
    if (!reportsPage) {
        reportsPage = new Reports(this);
        stackedWidget->addWidget(reportsPage);
    }
}

void Dashboard::loadSettingsData()
{
    // Create settings page if not exists
    if (!settingsPage) {
        settingsPage = new QWidget();
        QVBoxLayout *settingsLayout = new QVBoxLayout(settingsPage);
        
        // Add settings widgets here
        QLabel *settingsLabel = new QLabel("تنظیمات سیستم");
        settingsLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
        settingsLayout->addWidget(settingsLabel);
        
        // Add more settings widgets as needed
        
        stackedWidget->addWidget(settingsPage);
    }
}

bool Dashboard::initializeDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("office_automation.db");
    
    if (!db.open()) {
        QMessageBox::critical(this, "خطا در اتصال به پایگاه داده",
            "خطا در اتصال به پایگاه داده: " + db.lastError().text());
        return false;
    }
    
    // Create necessary tables if they don't exist
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "username TEXT UNIQUE NOT NULL,"
               "password TEXT NOT NULL,"
               "full_name TEXT NOT NULL,"
               "role TEXT NOT NULL)");
               
    query.exec("CREATE TABLE IF NOT EXISTS documents ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "title TEXT NOT NULL,"
               "content TEXT,"
               "created_date DATETIME DEFAULT CURRENT_TIMESTAMP,"
               "modified_date DATETIME DEFAULT CURRENT_TIMESTAMP)");
               
    query.exec("CREATE TABLE IF NOT EXISTS tasks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "title TEXT NOT NULL,"
               "description TEXT,"
               "due_date DATETIME,"
               "status TEXT DEFAULT 'pending')");
               
    return true;
}

void Dashboard::saveUserPreferences()
{
    settings->setValue("window/geometry", saveGeometry());
    settings->setValue("window/state", saveState());
    settings->setValue("user/name", userNameLabel->text());
    settings->setValue("user/role", userRoleLabel->text());
}

void Dashboard::loadUserPreferences()
{
    restoreGeometry(settings->value("window/geometry").toByteArray());
    restoreState(settings->value("window/state").toByteArray());
    userNameLabel->setText(settings->value("user/name", "کاربر").toString());
    userRoleLabel->setText(settings->value("user/role", "کاربر").toString());
}

void Dashboard::on_documentManagementButton_clicked()
{
    try {
        if (!documentManagementPage) {
            documentManagementPage = new DocumentManagementPage(this);
            stackedWidget->addWidget(documentManagementPage);
        }
        stackedWidget->setCurrentWidget(documentManagementPage);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در باز کردن صفحه مدیریت اسناد: " + QString(e.what()));
    }
}

void Dashboard::on_newDocumentButton_clicked()
{
    try {
        QSqlQuery query;
        query.prepare("INSERT INTO documents (title, content) VALUES (?, ?)");
        query.addBindValue("سند جدید");
        query.addBindValue("");
        
        if (!query.exec()) {
            throw std::runtime_error("خطا در ایجاد سند جدید: " + 
                query.lastError().text().toStdString());
        }
        
        // Refresh document list
        if (documentManagementPage) {
            documentManagementPage->refreshDocuments();
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در ایجاد سند جدید: " + QString(e.what()));
    }
}

void Dashboard::on_deleteDocumentButton_clicked()
{
    try {
        QListWidgetItem* currentItem = documentListWidget->currentItem();
        if (!currentItem) {
            QMessageBox::warning(this, "هشدار",
                "لطفاً یک سند را برای حذف انتخاب کنید.");
            return;
        }
        
        int documentId = currentItem->data(Qt::UserRole).toInt();
        
        QSqlQuery query;
        query.prepare("DELETE FROM documents WHERE id = ?");
        query.addBindValue(documentId);
        
        if (!query.exec()) {
            throw std::runtime_error("خطا در حذف سند: " + 
                query.lastError().text().toStdString());
        }
        
        // Refresh document list
        if (documentManagementPage) {
            documentManagementPage->refreshDocuments();
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در حذف سند: " + QString(e.what()));
    }
}

void Dashboard::on_taskManagementButton_clicked()
{
    try {
        if (!taskManagementPage) {
            taskManagementPage = new TaskManagementPage(this);
            stackedWidget->addWidget(taskManagementPage);
        }
        stackedWidget->setCurrentWidget(taskManagementPage);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در باز کردن صفحه مدیریت وظایف: " + QString(e.what()));
    }
}

void Dashboard::on_newTaskButton_clicked()
{
    try {
        QSqlQuery query;
        query.prepare("INSERT INTO tasks (title, description, status) VALUES (?, ?, ?)");
        query.addBindValue("وظیفه جدید");
        query.addBindValue("");
        query.addBindValue("در انتظار");
        
        if (!query.exec()) {
            throw std::runtime_error("خطا در ایجاد وظیفه جدید: " + 
                query.lastError().text().toStdString());
        }
        
        // Refresh task list
        if (taskManagementPage) {
            taskManagementPage->refreshTasks();
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در ایجاد وظیفه جدید: " + QString(e.what()));
    }
}

void Dashboard::on_deleteTaskButton_clicked()
{
    try {
        QListWidgetItem* currentItem = taskListWidget->currentItem();
        if (!currentItem) {
            QMessageBox::warning(this, "هشدار",
                "لطفاً یک وظیفه را برای حذف انتخاب کنید.");
            return;
        }
        
        int taskId = currentItem->data(Qt::UserRole).toInt();
        
        QSqlQuery query;
        query.prepare("DELETE FROM tasks WHERE id = ?");
        query.addBindValue(taskId);
        
        if (!query.exec()) {
            throw std::runtime_error("خطا در حذف وظیفه: " + 
                query.lastError().text().toStdString());
        }
        
        // Refresh task list
        if (taskManagementPage) {
            taskManagementPage->refreshTasks();
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در حذف وظیفه: " + QString(e.what()));
    }
}

void Dashboard::on_calendarButton_clicked()
{
    try {
        if (!calendarPage) {
            calendarPage = new CalendarPage(this);
            stackedWidget->addWidget(calendarPage);
        }
        stackedWidget->setCurrentWidget(calendarPage);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در باز کردن صفحه تقویم: " + QString(e.what()));
    }
}

void Dashboard::on_newEventButton_clicked()
{
    try {
        QSqlQuery query;
        query.prepare("INSERT INTO events (title, description, start_date, end_date) VALUES (?, ?, ?, ?)");
        query.addBindValue("رویداد جدید");
        query.addBindValue("");
        query.addBindValue(QDateTime::currentDateTime());
        query.addBindValue(QDateTime::currentDateTime().addSecs(3600)); // 1 hour later
        
        if (!query.exec()) {
            throw std::runtime_error("خطا در ایجاد رویداد جدید: " + 
                query.lastError().text().toStdString());
        }
        
        // Refresh calendar
        if (calendarPage) {
            calendarPage->refreshEvents();
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در ایجاد رویداد جدید: " + QString(e.what()));
    }
}

void Dashboard::on_deleteEventButton_clicked()
{
    try {
        QListWidgetItem* currentItem = eventListWidget->currentItem();
        if (!currentItem) {
            QMessageBox::warning(this, "هشدار",
                "لطفاً یک رویداد را برای حذف انتخاب کنید.");
            return;
        }
        
        int eventId = currentItem->data(Qt::UserRole).toInt();
        
        QSqlQuery query;
        query.prepare("DELETE FROM events WHERE id = ?");
        query.addBindValue(eventId);
        
        if (!query.exec()) {
            throw std::runtime_error("خطا در حذف رویداد: " + 
                query.lastError().text().toStdString());
        }
        
        // Refresh calendar
        if (calendarPage) {
            calendarPage->refreshEvents();
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در حذف رویداد: " + QString(e.what()));
    }
}

void Dashboard::on_reportsButton_clicked()
{
    try {
        if (!reportsPage) {
            reportsPage = new ReportsPage(this);
            stackedWidget->addWidget(reportsPage);
        }
        stackedWidget->setCurrentWidget(reportsPage);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در باز کردن صفحه گزارشات: " + QString(e.what()));
    }
}

void Dashboard::on_generateReportButton_clicked()
{
    try {
        QString reportType = reportTypeComboBox->currentText();
        QDate startDate = startDateEdit->date();
        QDate endDate = endDateEdit->date();
        
        if (startDate > endDate) {
            QMessageBox::warning(this, "هشدار",
                "تاریخ شروع نمی‌تواند بعد از تاریخ پایان باشد.");
            return;
        }
        
        QSqlQuery query;
        query.prepare("SELECT * FROM " + reportType + " WHERE date BETWEEN ? AND ?");
        query.addBindValue(startDate);
        query.addBindValue(endDate);
        
        if (!query.exec()) {
            throw std::runtime_error("خطا در تولید گزارش: " + 
                query.lastError().text().toStdString());
        }
        
        // Process and display report data
        if (reportsPage) {
            reportsPage->displayReport(query);
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در تولید گزارش: " + QString(e.what()));
    }
}

void Dashboard::on_exportReportButton_clicked()
{
    try {
        QString fileName = QFileDialog::getSaveFileName(this,
            "ذخیره گزارش", "", "فایل‌های PDF (*.pdf);;فایل‌های Excel (*.xlsx)");
            
        if (fileName.isEmpty()) {
            return;
        }
        
        if (fileName.endsWith(".pdf")) {
            exportToPDF(fileName);
        } else if (fileName.endsWith(".xlsx")) {
            exportToExcel(fileName);
        } else {
            throw std::runtime_error("فرمت فایل پشتیبانی نمی‌شود.");
        }
        
        QMessageBox::information(this, "موفقیت",
            "گزارش با موفقیت ذخیره شد.");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "خطا",
            "خطا در ذخیره گزارش: " + QString(e.what()));
    }
} 