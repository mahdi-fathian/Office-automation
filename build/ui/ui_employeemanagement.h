/********************************************************************************
** Form generated from reading UI file 'employeemanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEMANAGEMENT_H
#define UI_EMPLOYEEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeManagement
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *searchWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *searchLabel;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QTableWidget *employeeTable;
    QGroupBox *inputGroupBox;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *positionLabel;
    QLineEdit *positionEdit;
    QLabel *departmentLabel;
    QComboBox *departmentCombo;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *EmployeeManagement)
    {
        if (EmployeeManagement->objectName().isEmpty())
            EmployeeManagement->setObjectName("EmployeeManagement");
        EmployeeManagement->resize(800, 600);
        EmployeeManagement->setLayoutDirection(Qt::RightToLeft);
        EmployeeManagement->setStyleSheet(QString::fromUtf8("QLineEdit, QComboBox {\n"
"  padding: 8px;\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"  background-color: white;\n"
"  min-height: 30px;\n"
"}\n"
"QTableWidget {\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"  alternate-background-color: #f5f8fa;\n"
"  gridline-color: #e1e4e8;\n"
"}\n"
"QHeaderView::section {\n"
"  background-color: #2c3e50;\n"
"  color: white;\n"
"  padding: 6px;\n"
"  border: none;\n"
"  font-weight: bold;\n"
"}\n"
"QPushButton {\n"
"  border-radius: 8px;\n"
"  padding: 8px 16px;\n"
"  font-weight: bold;\n"
"  min-height: 35px;\n"
"}\n"
"QPushButton#addButton {\n"
"  background-color: #2ecc71;\n"
"  color: white;\n"
"}\n"
"QPushButton#addButton:hover {\n"
"  background-color: #27ae60;\n"
"}\n"
"QPushButton#editButton {\n"
"  background-color: #f1c40f;\n"
"  color: white;\n"
"}\n"
"QPushButton#editButton:hover {\n"
"  background-color: #f39c12;\n"
"}\n"
"QPushButton#deleteButton {\n"
"  background-color: #e74c3c;\n"
"  color: white;\n"
"}\n"
"QPushButton#d"
                        "eleteButton:hover {\n"
"  background-color: #c0392b;\n"
"}\n"
"QPushButton#searchButton {\n"
"  background-color: #3498db;\n"
"  color: white;\n"
"}\n"
"QPushButton#searchButton:hover {\n"
"  background-color: #2980b9;\n"
"}"));
        verticalLayout = new QVBoxLayout(EmployeeManagement);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        searchWidget = new QWidget(EmployeeManagement);
        searchWidget->setObjectName("searchWidget");
        horizontalLayout = new QHBoxLayout(searchWidget);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        searchLabel = new QLabel(searchWidget);
        searchLabel->setObjectName("searchLabel");

        horizontalLayout->addWidget(searchLabel);

        searchEdit = new QLineEdit(searchWidget);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setMinimumSize(QSize(0, 35));

        horizontalLayout->addWidget(searchEdit);

        searchButton = new QPushButton(searchWidget);
        searchButton->setObjectName("searchButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/modern/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchButton->setIcon(icon);

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addWidget(searchWidget);

        employeeTable = new QTableWidget(EmployeeManagement);
        if (employeeTable->columnCount() < 4)
            employeeTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        employeeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        employeeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        employeeTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        employeeTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        employeeTable->setObjectName("employeeTable");
        employeeTable->setAlternatingRowColors(true);
        employeeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        employeeTable->setSortingEnabled(true);
        employeeTable->setCornerButtonEnabled(false);
        employeeTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(employeeTable);

        inputGroupBox = new QGroupBox(EmployeeManagement);
        inputGroupBox->setObjectName("inputGroupBox");
        gridLayout = new QGridLayout(inputGroupBox);
        gridLayout->setSpacing(15);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(15, 15, 15, 15);
        nameLabel = new QLabel(inputGroupBox);
        nameLabel->setObjectName("nameLabel");

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameEdit = new QLineEdit(inputGroupBox);
        nameEdit->setObjectName("nameEdit");

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        positionLabel = new QLabel(inputGroupBox);
        positionLabel->setObjectName("positionLabel");

        gridLayout->addWidget(positionLabel, 1, 0, 1, 1);

        positionEdit = new QLineEdit(inputGroupBox);
        positionEdit->setObjectName("positionEdit");

        gridLayout->addWidget(positionEdit, 1, 1, 1, 1);

        departmentLabel = new QLabel(inputGroupBox);
        departmentLabel->setObjectName("departmentLabel");

        gridLayout->addWidget(departmentLabel, 2, 0, 1, 1);

        departmentCombo = new QComboBox(inputGroupBox);
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->setObjectName("departmentCombo");
        departmentCombo->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(departmentCombo, 2, 1, 1, 1);


        verticalLayout->addWidget(inputGroupBox);

        buttonWidget = new QWidget(EmployeeManagement);
        buttonWidget->setObjectName("buttonWidget");
        horizontalLayout_3 = new QHBoxLayout(buttonWidget);
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(buttonWidget);
        addButton->setObjectName("addButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/modern/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addButton->setIcon(icon1);

        horizontalLayout_3->addWidget(addButton);

        editButton = new QPushButton(buttonWidget);
        editButton->setObjectName("editButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/modern/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editButton->setIcon(icon2);

        horizontalLayout_3->addWidget(editButton);

        deleteButton = new QPushButton(buttonWidget);
        deleteButton->setObjectName("deleteButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/modern/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deleteButton->setIcon(icon3);

        horizontalLayout_3->addWidget(deleteButton);


        verticalLayout->addWidget(buttonWidget);


        retranslateUi(EmployeeManagement);

        QMetaObject::connectSlotsByName(EmployeeManagement);
    } // setupUi

    void retranslateUi(QWidget *EmployeeManagement)
    {
        searchLabel->setText(QCoreApplication::translate("EmployeeManagement", "\330\254\330\263\330\252\330\254\331\210:", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("EmployeeManagement", "\330\254\330\263\330\252\330\254\331\210\333\214 \332\251\330\247\330\261\331\205\331\206\330\257\330\247\331\206...", nullptr));
        searchButton->setText(QCoreApplication::translate("EmployeeManagement", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem = employeeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EmployeeManagement", "\330\264\331\206\330\247\330\263\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = employeeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EmployeeManagement", "\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = employeeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EmployeeManagement", "\330\263\331\205\330\252", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = employeeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EmployeeManagement", "\330\250\330\256\330\264", nullptr));
        inputGroupBox->setTitle(QCoreApplication::translate("EmployeeManagement", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \332\251\330\247\330\261\331\205\331\206\330\257", nullptr));
        nameLabel->setText(QCoreApplication::translate("EmployeeManagement", "\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214:", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("EmployeeManagement", "\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214 \332\251\330\247\330\261\331\205\331\206\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        positionLabel->setText(QCoreApplication::translate("EmployeeManagement", "\330\263\331\205\330\252:", nullptr));
        positionEdit->setPlaceholderText(QCoreApplication::translate("EmployeeManagement", "\330\263\331\205\330\252 \332\251\330\247\330\261\331\205\331\206\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        departmentLabel->setText(QCoreApplication::translate("EmployeeManagement", "\330\250\330\256\330\264:", nullptr));
        departmentCombo->setItemText(0, QCoreApplication::translate("EmployeeManagement", "\331\201\331\206\330\247\331\210\330\261\333\214 \330\247\330\267\331\204\330\247\330\271\330\247\330\252", nullptr));
        departmentCombo->setItemText(1, QCoreApplication::translate("EmployeeManagement", "\331\205\331\206\330\247\330\250\330\271 \330\247\331\206\330\263\330\247\331\206\333\214", nullptr));
        departmentCombo->setItemText(2, QCoreApplication::translate("EmployeeManagement", "\331\205\330\247\331\204\333\214", nullptr));
        departmentCombo->setItemText(3, QCoreApplication::translate("EmployeeManagement", "\330\250\330\247\330\262\330\247\330\261\333\214\330\247\330\250\333\214", nullptr));
        departmentCombo->setItemText(4, QCoreApplication::translate("EmployeeManagement", "\330\271\331\205\331\204\333\214\330\247\330\252", nullptr));

        addButton->setText(QCoreApplication::translate("EmployeeManagement", "\330\247\331\201\330\262\331\210\330\257\331\206 \332\251\330\247\330\261\331\205\331\206\330\257", nullptr));
        editButton->setText(QCoreApplication::translate("EmployeeManagement", "\331\210\333\214\330\261\330\247\333\214\330\264 \332\251\330\247\330\261\331\205\331\206\330\257", nullptr));
        deleteButton->setText(QCoreApplication::translate("EmployeeManagement", "\330\255\330\260\331\201 \332\251\330\247\330\261\331\205\331\206\330\257", nullptr));
        (void)EmployeeManagement;
    } // retranslateUi

};

namespace Ui {
    class EmployeeManagement: public Ui_EmployeeManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEMANAGEMENT_H
