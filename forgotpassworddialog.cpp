#include "forgotpassworddialog.h"

ForgotPasswordDialog::ForgotPasswordDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("بازیابی رمز عبور");
    setFixedSize(350, 200);
    setStyleSheet("QDialog { background-color: white; }"
                  "QLineEdit { padding: 8px; border: 1px solid #ccc; border-radius: 4px; }"
                  "QPushButton { padding: 10px; border-radius: 4px; color: white; background-color: #4a5568; }"
                  "QPushButton:hover { background-color: #2d3748; }");

    QLabel *logoLabel = new QLabel("<b>سازمان الکترونیک پیوست</b>\nPAYVAST ELECTRONIC ORGANIZATION");
    logoLabel->setAlignment(Qt::AlignCenter);

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("نام کاربری");
    nationalCodeEdit = new QLineEdit(this);
    nationalCodeEdit->setPlaceholderText("کد ملی");

    QHBoxLayout *btnLayout = new QHBoxLayout();
    sendCodeBtn = new QPushButton("ارسال کد", this);
    cancelBtn = new QPushButton("انصراف", this);
    btnLayout->addWidget(sendCodeBtn);
    btnLayout->addWidget(cancelBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(logoLabel);
    mainLayout->addWidget(usernameEdit);
    mainLayout->addWidget(nationalCodeEdit);
    mainLayout->addLayout(btnLayout);

    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);
    connect(sendCodeBtn, &QPushButton::clicked, this, &QDialog::accept);
}

QString ForgotPasswordDialog::getUsername() const {
    return usernameEdit->text();
}

QString ForgotPasswordDialog::getNationalCode() const {
    return nationalCodeEdit->text();
} 