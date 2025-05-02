#ifndef FORGOTPASSWORDDIALOG_H
#define FORGOTPASSWORDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ForgotPasswordDialog : public QDialog {
    Q_OBJECT
public:
    explicit ForgotPasswordDialog(QWidget *parent = nullptr);
    QString getUsername() const;
    QString getNationalCode() const;
private:
    QLineEdit *usernameEdit;
    QLineEdit *nationalCodeEdit;
    QPushButton *sendCodeBtn;
    QPushButton *cancelBtn;
};

#endif // FORGOTPASSWORDDIALOG_H 