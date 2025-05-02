/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer_1;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(450, 550);
        Login->setLayoutDirection(Qt::RightToLeft);
        Login->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f0f4f8;\n"
"}\n"
"QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"QLineEdit {\n"
"    padding: 12px;\n"
"    border: 2px solid #e1e4e8;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"    font-size: 14px;\n"
"    min-height: 40px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4a90e2;\n"
"}\n"
"QPushButton {\n"
"    padding: 12px;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    min-height: 45px;\n"
"}\n"
"QPushButton#loginButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"}\n"
"QPushButton#loginButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton#registerButton {\n"
"    background-color: #2ecc71;\n"
"    color: white;\n"
"}\n"
"QPushButton#registerButton:hover {\n"
"    background-color: #27ae60;\n"
"}"));
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        logoLabel = new QLabel(Login);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(120, 120));
        logoLabel->setMaximumSize(QSize(120, 120));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/modern/logo.png")));
        logoLabel->setScaledContents(true);
        logoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logoLabel);

        titleLabel = new QLabel(Login);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 26px; font-weight: bold; color: #2c3e50; margin-bottom: 20px;"));

        verticalLayout->addWidget(titleLabel);

        verticalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        usernameLabel = new QLabel(Login);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(Login);
        usernameEdit->setObjectName("usernameEdit");

        verticalLayout->addWidget(usernameEdit);

        passwordLabel = new QLabel(Login);
        passwordLabel->setObjectName("passwordLabel");

        verticalLayout->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(Login);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordEdit);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");

        verticalLayout->addWidget(loginButton);

        registerButton = new QPushButton(Login);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\330\263\333\214\330\263\330\252\331\205 \330\247\330\252\331\210\331\205\330\247\330\263\333\214\331\210\331\206 \330\247\330\257\330\247\330\261\333\214 - \331\210\330\261\331\210\330\257", nullptr));
        logoLabel->setText(QString());
        titleLabel->setText(QCoreApplication::translate("Login", "\330\263\333\214\330\263\330\252\331\205 \330\247\330\252\331\210\331\205\330\247\330\263\333\214\331\210\331\206 \330\247\330\257\330\247\330\261\333\214", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Login", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("Login", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 \330\256\331\210\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Login", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Login", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261 \330\256\331\210\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "\331\210\330\261\331\210\330\257", nullptr));
        registerButton->setText(QCoreApplication::translate("Login", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
