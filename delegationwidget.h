#ifndef DELEGATIONWIDGET_H
#define DELEGATIONWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>

class DelegationWidget : public QWidget {
    Q_OBJECT
public:
    explicit DelegationWidget(QWidget *parent = nullptr);
private:
    QComboBox *userCombo;
    QDateEdit *fromDateEdit;
    QDateEdit *toDateEdit;
    QTimeEdit *fromTimeEdit;
    QTimeEdit *toTimeEdit;
    QCheckBox *detailsCheck;
    QList<QCheckBox*> accessChecks;
    QPushButton *saveBtn;
    QPushButton *cancelBtn;
};

#endif // DELEGATIONWIDGET_H 