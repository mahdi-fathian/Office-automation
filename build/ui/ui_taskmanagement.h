/********************************************************************************
** Form generated from reading UI file 'taskmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGEMENT_H
#define UI_TASKMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManagement
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tasksTab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *filterLayout;
    QLabel *filterLabel;
    QComboBox *statusFilterCombo;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QTableWidget *taskTable;
    QHBoxLayout *buttonLayout;
    QPushButton *completeButton;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QWidget *newTaskTab;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *titleLabel;
    QLineEdit *titleEdit;
    QLabel *descriptionLabel;
    QTextEdit *descriptionEdit;
    QLabel *assigneeLabel;
    QComboBox *assigneeCombo;
    QLabel *dueDateLabel;
    QDateEdit *dueDateEdit;
    QLabel *priorityLabel;
    QComboBox *priorityCombo;
    QLabel *statusLabel;
    QComboBox *statusCombo;
    QHBoxLayout *saveLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *TaskManagement)
    {
        if (TaskManagement->objectName().isEmpty())
            TaskManagement->setObjectName("TaskManagement");
        TaskManagement->resize(800, 600);
        TaskManagement->setLayoutDirection(Qt::RightToLeft);
        TaskManagement->setStyleSheet(QString::fromUtf8("QLineEdit, QTextEdit, QComboBox, QDateEdit {\n"
"  padding: 8px;\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"  background-color: white;\n"
"}\n"
"QLineEdit, QComboBox, QDateEdit {\n"
"  min-height: 30px;\n"
"}\n"
"QTextEdit {\n"
"  min-height: 120px;\n"
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
""
                        "}\n"
"QPushButton#deleteButton {\n"
"  background-color: #e74c3c;\n"
"  color: white;\n"
"}\n"
"QPushButton#deleteButton:hover {\n"
"  background-color: #c0392b;\n"
"}\n"
"QPushButton#searchButton, QPushButton#completeButton {\n"
"  background-color: #3498db;\n"
"  color: white;\n"
"}\n"
"QPushButton#searchButton:hover, QPushButton#completeButton:hover {\n"
"  background-color: #2980b9;\n"
"}\n"
"QTabWidget::pane {\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"}\n"
"QTabBar::tab {\n"
"  background-color: #ecf0f1;\n"
"  padding: 8px 16px;\n"
"  border-top-left-radius: 8px;\n"
"  border-top-right-radius: 8px;\n"
"  margin-right: 2px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"  background-color: #3498db;\n"
"  color: white;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"  margin-top: 2px;\n"
"}"));
        verticalLayout = new QVBoxLayout(TaskManagement);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        tabWidget = new QTabWidget(TaskManagement);
        tabWidget->setObjectName("tabWidget");
        tasksTab = new QWidget();
        tasksTab->setObjectName("tasksTab");
        verticalLayout_2 = new QVBoxLayout(tasksTab);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        filterLayout = new QHBoxLayout();
        filterLayout->setSpacing(15);
        filterLayout->setObjectName("filterLayout");
        filterLabel = new QLabel(tasksTab);
        filterLabel->setObjectName("filterLabel");

        filterLayout->addWidget(filterLabel);

        statusFilterCombo = new QComboBox(tasksTab);
        statusFilterCombo->addItem(QString());
        statusFilterCombo->addItem(QString());
        statusFilterCombo->addItem(QString());
        statusFilterCombo->addItem(QString());
        statusFilterCombo->setObjectName("statusFilterCombo");
        statusFilterCombo->setMinimumSize(QSize(150, 35));

        filterLayout->addWidget(statusFilterCombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        filterLayout->addItem(horizontalSpacer);

        searchEdit = new QLineEdit(tasksTab);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setMinimumSize(QSize(250, 35));

        filterLayout->addWidget(searchEdit);

        searchButton = new QPushButton(tasksTab);
        searchButton->setObjectName("searchButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/modern/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchButton->setIcon(icon);

        filterLayout->addWidget(searchButton);


        verticalLayout_2->addLayout(filterLayout);

        taskTable = new QTableWidget(tasksTab);
        if (taskTable->columnCount() < 5)
            taskTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        taskTable->setObjectName("taskTable");
        taskTable->setAlternatingRowColors(true);
        taskTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        taskTable->setSortingEnabled(true);
        taskTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(taskTable);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(15);
        buttonLayout->setObjectName("buttonLayout");
        completeButton = new QPushButton(tasksTab);
        completeButton->setObjectName("completeButton");

        buttonLayout->addWidget(completeButton);

        addButton = new QPushButton(tasksTab);
        addButton->setObjectName("addButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/modern/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addButton->setIcon(icon1);

        buttonLayout->addWidget(addButton);

        editButton = new QPushButton(tasksTab);
        editButton->setObjectName("editButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/modern/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editButton->setIcon(icon2);

        buttonLayout->addWidget(editButton);

        deleteButton = new QPushButton(tasksTab);
        deleteButton->setObjectName("deleteButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/modern/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deleteButton->setIcon(icon3);

        buttonLayout->addWidget(deleteButton);


        verticalLayout_2->addLayout(buttonLayout);

        tabWidget->addTab(tasksTab, QString());
        newTaskTab = new QWidget();
        newTaskTab->setObjectName("newTaskTab");
        verticalLayout_3 = new QVBoxLayout(newTaskTab);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(15, 15, 15, 15);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        titleLabel = new QLabel(newTaskTab);
        titleLabel->setObjectName("titleLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, titleLabel);

        titleEdit = new QLineEdit(newTaskTab);
        titleEdit->setObjectName("titleEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, titleEdit);

        descriptionLabel = new QLabel(newTaskTab);
        descriptionLabel->setObjectName("descriptionLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, descriptionLabel);

        descriptionEdit = new QTextEdit(newTaskTab);
        descriptionEdit->setObjectName("descriptionEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, descriptionEdit);

        assigneeLabel = new QLabel(newTaskTab);
        assigneeLabel->setObjectName("assigneeLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, assigneeLabel);

        assigneeCombo = new QComboBox(newTaskTab);
        assigneeCombo->setObjectName("assigneeCombo");
        assigneeCombo->setMinimumSize(QSize(0, 35));

        formLayout->setWidget(2, QFormLayout::FieldRole, assigneeCombo);

        dueDateLabel = new QLabel(newTaskTab);
        dueDateLabel->setObjectName("dueDateLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, dueDateLabel);

        dueDateEdit = new QDateEdit(newTaskTab);
        dueDateEdit->setObjectName("dueDateEdit");
        dueDateEdit->setMinimumSize(QSize(0, 35));
        dueDateEdit->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, dueDateEdit);

        priorityLabel = new QLabel(newTaskTab);
        priorityLabel->setObjectName("priorityLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, priorityLabel);

        priorityCombo = new QComboBox(newTaskTab);
        priorityCombo->addItem(QString());
        priorityCombo->addItem(QString());
        priorityCombo->addItem(QString());
        priorityCombo->addItem(QString());
        priorityCombo->setObjectName("priorityCombo");
        priorityCombo->setMinimumSize(QSize(0, 35));

        formLayout->setWidget(4, QFormLayout::FieldRole, priorityCombo);

        statusLabel = new QLabel(newTaskTab);
        statusLabel->setObjectName("statusLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, statusLabel);

        statusCombo = new QComboBox(newTaskTab);
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->setObjectName("statusCombo");
        statusCombo->setMinimumSize(QSize(0, 35));

        formLayout->setWidget(5, QFormLayout::FieldRole, statusCombo);


        verticalLayout_3->addLayout(formLayout);

        saveLayout = new QHBoxLayout();
        saveLayout->setSpacing(15);
        saveLayout->setObjectName("saveLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        saveLayout->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(newTaskTab);
        saveButton->setObjectName("saveButton");
        saveButton->setMinimumSize(QSize(150, 40));
        saveButton->setStyleSheet(QString::fromUtf8("background-color: #2ecc71;\n"
"color: white;"));

        saveLayout->addWidget(saveButton);

        cancelButton = new QPushButton(newTaskTab);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setMinimumSize(QSize(150, 40));
        cancelButton->setStyleSheet(QString::fromUtf8("background-color: #e74c3c;\n"
"color: white;"));

        saveLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(saveLayout);

        tabWidget->addTab(newTaskTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(TaskManagement);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TaskManagement);
    } // setupUi

    void retranslateUi(QWidget *TaskManagement)
    {
        filterLabel->setText(QCoreApplication::translate("TaskManagement", "\331\201\333\214\331\204\330\252\330\261 \330\250\330\261\330\247\330\263\330\247\330\263 \331\210\330\266\330\271\333\214\330\252:", nullptr));
        statusFilterCombo->setItemText(0, QCoreApplication::translate("TaskManagement", "\331\207\331\205\331\207", nullptr));
        statusFilterCombo->setItemText(1, QCoreApplication::translate("TaskManagement", "\330\257\330\261 \330\247\331\206\330\252\330\270\330\247\330\261", nullptr));
        statusFilterCombo->setItemText(2, QCoreApplication::translate("TaskManagement", "\330\257\330\261 \330\255\330\247\331\204 \330\247\331\206\330\254\330\247\331\205", nullptr));
        statusFilterCombo->setItemText(3, QCoreApplication::translate("TaskManagement", "\330\252\332\251\331\205\333\214\331\204 \330\264\330\257\331\207", nullptr));

        searchEdit->setPlaceholderText(QCoreApplication::translate("TaskManagement", "\330\254\330\263\330\252\330\254\331\210\333\214 \331\210\330\270\330\247\333\214\331\201...", nullptr));
        searchButton->setText(QCoreApplication::translate("TaskManagement", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem = taskTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TaskManagement", "\330\264\331\206\330\247\330\263\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = taskTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TaskManagement", "\330\271\331\206\331\210\330\247\331\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = taskTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TaskManagement", "\331\205\330\263\330\246\331\210\331\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = taskTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TaskManagement", "\331\205\331\207\331\204\330\252 \330\247\331\206\330\254\330\247\331\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = taskTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TaskManagement", "\331\210\330\266\330\271\333\214\330\252", nullptr));
        completeButton->setText(QCoreApplication::translate("TaskManagement", "\330\252\332\251\331\205\333\214\331\204 \331\210\330\270\333\214\331\201\331\207", nullptr));
        addButton->setText(QCoreApplication::translate("TaskManagement", "\330\247\331\201\330\262\331\210\330\257\331\206 \331\210\330\270\333\214\331\201\331\207", nullptr));
        editButton->setText(QCoreApplication::translate("TaskManagement", "\331\210\333\214\330\261\330\247\333\214\330\264 \331\210\330\270\333\214\331\201\331\207", nullptr));
        deleteButton->setText(QCoreApplication::translate("TaskManagement", "\330\255\330\260\331\201 \331\210\330\270\333\214\331\201\331\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tasksTab), QCoreApplication::translate("TaskManagement", "\331\204\333\214\330\263\330\252 \331\210\330\270\330\247\333\214\331\201", nullptr));
        titleLabel->setText(QCoreApplication::translate("TaskManagement", "\330\271\331\206\331\210\330\247\331\206:", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("TaskManagement", "\330\271\331\206\331\210\330\247\331\206 \331\210\330\270\333\214\331\201\331\207 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("TaskManagement", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252:", nullptr));
        descriptionEdit->setPlaceholderText(QCoreApplication::translate("TaskManagement", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 \331\210\330\270\333\214\331\201\331\207 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257...", nullptr));
        assigneeLabel->setText(QCoreApplication::translate("TaskManagement", "\331\205\330\263\330\246\331\210\331\204:", nullptr));
        dueDateLabel->setText(QCoreApplication::translate("TaskManagement", "\331\205\331\207\331\204\330\252 \330\247\331\206\330\254\330\247\331\205:", nullptr));
        priorityLabel->setText(QCoreApplication::translate("TaskManagement", "\330\247\331\210\331\204\331\210\333\214\330\252:", nullptr));
        priorityCombo->setItemText(0, QCoreApplication::translate("TaskManagement", "\332\251\331\205", nullptr));
        priorityCombo->setItemText(1, QCoreApplication::translate("TaskManagement", "\331\205\330\252\331\210\330\263\330\267", nullptr));
        priorityCombo->setItemText(2, QCoreApplication::translate("TaskManagement", "\330\262\333\214\330\247\330\257", nullptr));
        priorityCombo->setItemText(3, QCoreApplication::translate("TaskManagement", "\331\201\331\210\330\261\333\214", nullptr));

        statusLabel->setText(QCoreApplication::translate("TaskManagement", "\331\210\330\266\330\271\333\214\330\252:", nullptr));
        statusCombo->setItemText(0, QCoreApplication::translate("TaskManagement", "\330\257\330\261 \330\247\331\206\330\252\330\270\330\247\330\261", nullptr));
        statusCombo->setItemText(1, QCoreApplication::translate("TaskManagement", "\330\257\330\261 \330\255\330\247\331\204 \330\247\331\206\330\254\330\247\331\205", nullptr));
        statusCombo->setItemText(2, QCoreApplication::translate("TaskManagement", "\330\252\332\251\331\205\333\214\331\204 \330\264\330\257\331\207", nullptr));

        saveButton->setText(QCoreApplication::translate("TaskManagement", "\330\260\330\256\333\214\330\261\331\207 \331\210\330\270\333\214\331\201\331\207", nullptr));
        cancelButton->setText(QCoreApplication::translate("TaskManagement", "\330\247\331\206\330\265\330\261\330\247\331\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(newTaskTab), QCoreApplication::translate("TaskManagement", "\331\210\330\270\333\214\331\201\331\207 \330\254\330\257\333\214\330\257", nullptr));
        (void)TaskManagement;
    } // retranslateUi

};

namespace Ui {
    class TaskManagement: public Ui_TaskManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGEMENT_H
