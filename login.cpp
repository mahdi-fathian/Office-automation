#include "login.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QFrame>
#include <QSpacerItem>
#include <QPixmap>
#include "forgotpassworddialog.h"

Login::Login(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("اتوماسیون اداری - ورود به سیستم");
    setMinimumSize(800, 500);
    setStyleSheet("QDialog { background-color: white; }"
                  "QLineEdit { padding: 8px; border: 1px solid #ccc; border-radius: 4px; }"
                  "QPushButton { padding: 10px; border-radius: 4px; color: white; background-color: #4a5568; }"
                  "QPushButton:hover { background-color: #2d3748; }"
                  "QLabel#logoPlaceholder { border: 1px dashed grey; }"
                  "QLabel#sidePanelPlaceholder { background-color: #4a5568; color: white; border: 1px dashed grey; }"
                  "QPushButton#forgotPasswordButton { background-color: transparent; color: red; border: 1px solid red; }"
                  "QPushButton#forgotPasswordButton:hover { background-color: #fee2e2; }");

    db = new Database(this);
    if (!db->initDatabase()) {
        QMessageBox::critical(this, "خطا", "خطا در اتصال به پایگاه داده!");
        return;
    }

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QLabel *sidePanel = new QLabel("ویژگی های سامانه الکترونیک پیوست\n\n# مدیریت چرخه کامل فرآیندهای سازمانی براساس فرآتر الکترونیک\n# مرورگر کرومی کار و سادیکسفاک امر سیستم");
    sidePanel->setObjectName("sidePanelPlaceholder");
    sidePanel->setWordWrap(true);
    sidePanel->setAlignment(Qt::AlignCenter);
    sidePanel->setMinimumWidth(300);
    sidePanel->setStyleSheet("background-color: #4a5568; color: white; padding: 20px; font-size: 14px;");

    QFrame *loginArea = new QFrame(this);
    loginArea->setFrameShape(QFrame::NoFrame);
    QVBoxLayout *loginLayout = new QVBoxLayout(loginArea);
    loginLayout->setContentsMargins(50, 50, 50, 50);
    loginLayout->setAlignment(Qt::AlignCenter);

    QLabel *logoLabel = new QLabel();
    logoLabel->setObjectName("logoPlaceholder");
    QPixmap logoPixmap(":/icons/logo.png");
    if (logoPixmap.isNull()) {
        logoLabel->setText("PAYVAST ELECTRONIC ORGANIZATION\n [Logo]");
        logoLabel->setMinimumSize(300, 80);
        logoLabel->setAlignment(Qt::AlignCenter);
    } else {
         logoLabel->setPixmap(logoPixmap.scaled(300, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
         logoLabel->setAlignment(Qt::AlignCenter);
    }

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("نام کاربری");

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("کلمه عبور");
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("ورود", this);

    QPushButton *forgotPasswordButton = new QPushButton("رمز عبور را فراموش کرده ام", this);
    forgotPasswordButton->setObjectName("forgotPasswordButton");
    forgotPasswordButton->setFlat(true);
    forgotPasswordButton->setCursor(Qt::PointingHandCursor);

    loginLayout->addWidget(logoLabel, 0, Qt::AlignCenter);
    loginLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    loginLayout->addWidget(usernameEdit);
    loginLayout->addWidget(passwordEdit);
    loginLayout->addSpacing(10);
    loginLayout->addWidget(loginButton);
    loginLayout->addSpacing(5);
    loginLayout->addWidget(forgotPasswordButton, 0, Qt::AlignCenter);
    loginLayout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    mainLayout->addWidget(loginArea, 2);
    mainLayout->addWidget(sidePanel, 1);

    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginClicked);
    connect(forgotPasswordButton, &QPushButton::clicked, this, &Login::onForgotPasswordClicked);

    usernameEdit->setFocus();
}

Login::~Login()
{
}

void Login::onLoginClicked()
{
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً نام کاربری و رمز عبور را وارد کنید!");
        return;
    }

    if (db->authenticateUser(username, password)) {
        Dashboard *dashboard = new Dashboard(/* username, */ this);
        dashboard->setAttribute(Qt::WA_DeleteOnClose);
        accept();
        dashboard->show();
    } else {
        QMessageBox::critical(this, "خطا", "نام کاربری یا رمز عبور اشتباه است!");
    }
}

void Login::onForgotPasswordClicked()
{
    ForgotPasswordDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        // TODO: ارسال کد بازیابی به کاربر (در صورت نیاز)
        QMessageBox::information(this, "ارسال کد", "کد بازیابی به کاربر ارسال شد (نمایشی)");
    }
}

// TODO: Implement onForgotPasswordClicked() slot if needed
// void Login::onForgotPasswordClicked()
// {
//     QMessageBox::information(this, "فراموشی رمز عبور", "لطفاً با مدیر سیستم تماس بگیرید.");
// }

// Remove onRegisterClicked() as registration is removed from UI
// void Login::onRegisterClicked() { ... }

// Remove unused member variable declarations if any were related to registration
// For example, remove regUsernameEdit, regPasswordEdit, etc. from login.h if they exist

// Remove unused member variable declarations if any were related to registration
// For example, remove regUsernameEdit, regPasswordEdit, etc. from login.h if they exist 