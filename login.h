#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "database.h"

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void onLoginClicked();
    void onForgotPasswordClicked();
    // void onForgotPasswordClicked(); // Add if implementing this slot

private:
    Database *db;
    
    // Login form
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    // QPushButton *forgotPasswordButton; // Add if connecting the slot
};

#endif // LOGIN_H 