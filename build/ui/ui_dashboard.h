/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *sidebarWidget;
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QWidget *userInfoWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *userAvatar;
    QLabel *usernameLabel;
    QLabel *roleLabel;
    QFrame *line;
    QPushButton *dashboardButton;
    QPushButton *employeeButton;
    QPushButton *documentButton;
    QPushButton *taskButton;
    QPushButton *calendarButton;
    QPushButton *reportsButton;
    QSpacerItem *verticalSpacer;
    QPushButton *logoutButton;
    QVBoxLayout *contentLayout;
    QWidget *headerWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pageTitle;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchEdit;
    QStackedWidget *stackedWidget;
    QWidget *dashboardPage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *cardLayout;
    QHBoxLayout *chartLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1280, 800);
        Dashboard->setLayoutDirection(Qt::RightToLeft);
        Dashboard->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"  background-color: #f0f4f8;\n"
"}\n"
"QWidget {\n"
"  font-size: 12pt;\n"
"}\n"
"QPushButton {\n"
"  background-color: #3498db;\n"
"  color: white;\n"
"  border-radius: 8px;\n"
"  padding: 8px 16px;\n"
"  font-weight: bold;\n"
"  min-height: 40px;\n"
"}\n"
"QPushButton:hover {\n"
"  background-color: #2980b9;\n"
"}\n"
"QPushButton:checked {\n"
"  background-color: #16a085;\n"
"}\n"
"QStackedWidget {\n"
"  background-color: white;\n"
"  border-radius: 10px;\n"
"}\n"
"#sidebarWidget {\n"
"  background-color: #2c3e50;\n"
"  border-radius: 0px;\n"
"  padding: 10px;\n"
"}\n"
"#headerWidget {\n"
"  background-color: white;\n"
"  border-bottom: 1px solid #e1e4e8;\n"
"}\n"
"#userInfoWidget {\n"
"  background-color: #34495e;\n"
"  border-radius: 8px;\n"
"  padding: 10px;\n"
"  margin: 10px;\n"
"}\n"
"QLabel#usernameLabel {\n"
"  color: white;\n"
"  font-weight: bold;\n"
"}\n"
"QLabel#roleLabel {\n"
"  color: #bdc3c7;\n"
"}\n"
"QLabel#logoLabel {\n"
"  color: white;\n"
"  font-size: 18pt;\n"
"  font-w"
                        "eight: bold;\n"
"}\n"
"QPushButton#navButton {\n"
"  background-color: transparent;\n"
"  color: #ecf0f1;\n"
"  text-align: right;\n"
"  border-radius: 8px;\n"
"  padding: 12px;\n"
"  font-weight: normal;\n"
"}\n"
"QPushButton#navButton:hover {\n"
"  background-color: #34495e;\n"
"}\n"
"QPushButton#navButton:checked {\n"
"  background-color: #3498db;\n"
"  font-weight: bold;\n"
"}\n"
"QLineEdit {\n"
"  padding: 8px;\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 6px;\n"
"  background-color: white;\n"
"}"));
        centralwidget = new QWidget(Dashboard);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebarWidget = new QWidget(centralwidget);
        sidebarWidget->setObjectName("sidebarWidget");
        sidebarWidget->setMinimumSize(QSize(240, 0));
        sidebarWidget->setMaximumSize(QSize(240, 16777215));
        verticalLayout = new QVBoxLayout(sidebarWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        logoLabel = new QLabel(sidebarWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logoLabel);

        userInfoWidget = new QWidget(sidebarWidget);
        userInfoWidget->setObjectName("userInfoWidget");
        verticalLayout_3 = new QVBoxLayout(userInfoWidget);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        userAvatar = new QLabel(userInfoWidget);
        userAvatar->setObjectName("userAvatar");
        userAvatar->setMinimumSize(QSize(64, 64));
        userAvatar->setMaximumSize(QSize(64, 64));
        userAvatar->setPixmap(QPixmap(QString::fromUtf8(":/icons/modern/user.png")));
        userAvatar->setScaledContents(true);
        userAvatar->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(userAvatar);

        usernameLabel = new QLabel(userInfoWidget);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(usernameLabel);

        roleLabel = new QLabel(userInfoWidget);
        roleLabel->setObjectName("roleLabel");
        roleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(roleLabel);


        verticalLayout->addWidget(userInfoWidget);

        line = new QFrame(sidebarWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        dashboardButton = new QPushButton(sidebarWidget);
        dashboardButton->setObjectName("dashboardButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/modern/dashboard.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dashboardButton->setIcon(icon);
        dashboardButton->setIconSize(QSize(24, 24));
        dashboardButton->setCheckable(true);
        dashboardButton->setChecked(true);

        verticalLayout->addWidget(dashboardButton);

        employeeButton = new QPushButton(sidebarWidget);
        employeeButton->setObjectName("employeeButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/modern/employee.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        employeeButton->setIcon(icon1);
        employeeButton->setIconSize(QSize(24, 24));
        employeeButton->setCheckable(true);

        verticalLayout->addWidget(employeeButton);

        documentButton = new QPushButton(sidebarWidget);
        documentButton->setObjectName("documentButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/modern/document.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        documentButton->setIcon(icon2);
        documentButton->setIconSize(QSize(24, 24));
        documentButton->setCheckable(true);

        verticalLayout->addWidget(documentButton);

        taskButton = new QPushButton(sidebarWidget);
        taskButton->setObjectName("taskButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/modern/task.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        taskButton->setIcon(icon3);
        taskButton->setIconSize(QSize(24, 24));
        taskButton->setCheckable(true);

        verticalLayout->addWidget(taskButton);

        calendarButton = new QPushButton(sidebarWidget);
        calendarButton->setObjectName("calendarButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/modern/calendar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        calendarButton->setIcon(icon4);
        calendarButton->setIconSize(QSize(24, 24));
        calendarButton->setCheckable(true);

        verticalLayout->addWidget(calendarButton);

        reportsButton = new QPushButton(sidebarWidget);
        reportsButton->setObjectName("reportsButton");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/modern/report.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        reportsButton->setIcon(icon5);
        reportsButton->setIconSize(QSize(24, 24));
        reportsButton->setCheckable(true);

        verticalLayout->addWidget(reportsButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        logoutButton = new QPushButton(sidebarWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("background-color: #e74c3c;"));

        verticalLayout->addWidget(logoutButton);


        horizontalLayout->addWidget(sidebarWidget);

        contentLayout = new QVBoxLayout();
        contentLayout->setSpacing(0);
        contentLayout->setObjectName("contentLayout");
        headerWidget = new QWidget(centralwidget);
        headerWidget->setObjectName("headerWidget");
        headerWidget->setMinimumSize(QSize(0, 70));
        headerWidget->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_2 = new QHBoxLayout(headerWidget);
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(20, 10, 20, 10);
        pageTitle = new QLabel(headerWidget);
        pageTitle->setObjectName("pageTitle");
        pageTitle->setStyleSheet(QString::fromUtf8("font-size: 18pt; font-weight: bold; color: #2c3e50;"));

        horizontalLayout_2->addWidget(pageTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        searchEdit = new QLineEdit(headerWidget);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setMinimumSize(QSize(250, 0));

        horizontalLayout_2->addWidget(searchEdit);


        contentLayout->addWidget(headerWidget);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        dashboardPage = new QWidget();
        dashboardPage->setObjectName("dashboardPage");
        verticalLayout_2 = new QVBoxLayout(dashboardPage);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        cardLayout = new QHBoxLayout();
        cardLayout->setSpacing(20);
        cardLayout->setObjectName("cardLayout");

        verticalLayout_2->addLayout(cardLayout);

        chartLayout = new QHBoxLayout();
        chartLayout->setSpacing(20);
        chartLayout->setObjectName("chartLayout");

        verticalLayout_2->addLayout(chartLayout);

        stackedWidget->addWidget(dashboardPage);

        contentLayout->addWidget(stackedWidget);


        horizontalLayout->addLayout(contentLayout);

        horizontalLayout->setStretch(1, 1);
        Dashboard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dashboard);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        Dashboard->setMenuBar(menubar);
        statusbar = new QStatusBar(Dashboard);
        statusbar->setObjectName("statusbar");
        Dashboard->setStatusBar(statusbar);

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "\330\263\333\214\330\263\330\252\331\205 \330\247\330\252\331\210\331\205\330\247\330\263\333\214\331\210\331\206 \330\247\330\257\330\247\330\261\333\214", nullptr));
        logoLabel->setText(QCoreApplication::translate("Dashboard", "\330\247\330\252\331\210\331\205\330\247\330\263\333\214\331\210\331\206 \330\247\330\257\330\247\330\261\333\214", nullptr));
        userAvatar->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        roleLabel->setText(QCoreApplication::translate("Dashboard", "\331\206\331\202\330\264: \331\205\330\257\333\214\330\261", nullptr));
        dashboardButton->setText(QCoreApplication::translate("Dashboard", "\330\257\330\247\330\264\330\250\331\210\330\261\330\257", nullptr));
        dashboardButton->setObjectName(QCoreApplication::translate("Dashboard", "navButton", nullptr));
        employeeButton->setText(QCoreApplication::translate("Dashboard", "\331\205\330\257\333\214\330\261\333\214\330\252 \332\251\330\247\330\261\332\251\331\206\330\247\331\206", nullptr));
        employeeButton->setObjectName(QCoreApplication::translate("Dashboard", "navButton", nullptr));
        documentButton->setText(QCoreApplication::translate("Dashboard", "\331\205\330\257\333\214\330\261\333\214\330\252 \330\247\330\263\331\206\330\247\330\257", nullptr));
        documentButton->setObjectName(QCoreApplication::translate("Dashboard", "navButton", nullptr));
        taskButton->setText(QCoreApplication::translate("Dashboard", "\331\205\330\257\333\214\330\261\333\214\330\252 \331\210\330\270\330\247\333\214\331\201", nullptr));
        taskButton->setObjectName(QCoreApplication::translate("Dashboard", "navButton", nullptr));
        calendarButton->setText(QCoreApplication::translate("Dashboard", "\330\252\331\202\331\210\333\214\331\205", nullptr));
        calendarButton->setObjectName(QCoreApplication::translate("Dashboard", "navButton", nullptr));
        reportsButton->setText(QCoreApplication::translate("Dashboard", "\332\257\330\262\330\247\330\261\330\264\330\247\330\252", nullptr));
        reportsButton->setObjectName(QCoreApplication::translate("Dashboard", "navButton", nullptr));
        logoutButton->setText(QCoreApplication::translate("Dashboard", "\330\256\330\261\331\210\330\254", nullptr));
        pageTitle->setText(QCoreApplication::translate("Dashboard", "\330\257\330\247\330\264\330\250\331\210\330\261\330\257", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("Dashboard", "\330\254\330\263\330\252\330\254\331\210...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
