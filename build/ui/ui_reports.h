/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTS_H
#define UI_REPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *employeeReportTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *filterGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *departmentLabel;
    QComboBox *departmentCombo;
    QSpacerItem *horizontalSpacer;
    QPushButton *generateButton;
    QTableWidget *employeeTable;
    QHBoxLayout *actionLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exportButton;
    QPushButton *printButton;
    QWidget *documentReportTab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *docFilterGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dateFromLabel;
    QDateEdit *dateFromEdit;
    QLabel *dateToLabel;
    QDateEdit *dateToEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *generateDocButton;
    QTableWidget *documentTable;
    QHBoxLayout *docActionLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *exportDocButton;
    QPushButton *printDocButton;
    QWidget *taskReportTab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *taskFilterGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *statusLabel;
    QComboBox *statusCombo;
    QLabel *assigneeLabel;
    QComboBox *assigneeCombo;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *generateTaskButton;
    QTableWidget *taskTable;
    QHBoxLayout *taskActionLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *exportTaskButton;
    QPushButton *printTaskButton;

    void setupUi(QWidget *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName("Reports");
        Reports->resize(800, 600);
        Reports->setLayoutDirection(Qt::RightToLeft);
        Reports->setStyleSheet(QString::fromUtf8("QComboBox, QDateEdit {\n"
"  padding: 8px;\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"  background-color: white;\n"
"  min-height: 35px;\n"
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
"QPushButton#e"
                        "xportButton, QPushButton#printButton {\n"
"  background-color: #3498db;\n"
"  color: white;\n"
"}\n"
"QPushButton#exportButton:hover, QPushButton#printButton:hover {\n"
"  background-color: #2980b9;\n"
"}\n"
"QLabel {\n"
"  font-size: 14px;\n"
"  color: #2c3e50;\n"
"}\n"
"QGroupBox {\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"  margin-top: 20px;\n"
"  font-size: 14px;\n"
"  font-weight: bold;\n"
"}\n"
"QGroupBox::title {\n"
"  subcontrol-origin: margin;\n"
"  subcontrol-position: top center;\n"
"  padding: 0 8px;\n"
"  color: #2c3e50;\n"
"}\n"
"QSplitter::handle {\n"
"  background-color: #e1e4e8;\n"
"}\n"
"QSplitter::handle:horizontal {\n"
"  width: 1px;\n"
"}\n"
"QSplitter::handle:vertical {\n"
"  height: 1px;\n"
"}"));
        verticalLayout = new QVBoxLayout(Reports);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        tabWidget = new QTabWidget(Reports);
        tabWidget->setObjectName("tabWidget");
        employeeReportTab = new QWidget();
        employeeReportTab->setObjectName("employeeReportTab");
        verticalLayout_2 = new QVBoxLayout(employeeReportTab);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        filterGroupBox = new QGroupBox(employeeReportTab);
        filterGroupBox->setObjectName("filterGroupBox");
        horizontalLayout = new QHBoxLayout(filterGroupBox);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(15, 20, 15, 15);
        departmentLabel = new QLabel(filterGroupBox);
        departmentLabel->setObjectName("departmentLabel");

        horizontalLayout->addWidget(departmentLabel);

        departmentCombo = new QComboBox(filterGroupBox);
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->addItem(QString());
        departmentCombo->setObjectName("departmentCombo");

        horizontalLayout->addWidget(departmentCombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        generateButton = new QPushButton(filterGroupBox);
        generateButton->setObjectName("generateButton");
        generateButton->setStyleSheet(QString::fromUtf8("background-color: #2ecc71;\n"
"color: white;"));

        horizontalLayout->addWidget(generateButton);


        verticalLayout_2->addWidget(filterGroupBox);

        employeeTable = new QTableWidget(employeeReportTab);
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
        employeeTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(employeeTable);

        actionLayout = new QHBoxLayout();
        actionLayout->setSpacing(15);
        actionLayout->setObjectName("actionLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionLayout->addItem(horizontalSpacer_2);

        exportButton = new QPushButton(employeeReportTab);
        exportButton->setObjectName("exportButton");

        actionLayout->addWidget(exportButton);

        printButton = new QPushButton(employeeReportTab);
        printButton->setObjectName("printButton");

        actionLayout->addWidget(printButton);


        verticalLayout_2->addLayout(actionLayout);

        tabWidget->addTab(employeeReportTab, QString());
        documentReportTab = new QWidget();
        documentReportTab->setObjectName("documentReportTab");
        verticalLayout_3 = new QVBoxLayout(documentReportTab);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(15, 15, 15, 15);
        docFilterGroupBox = new QGroupBox(documentReportTab);
        docFilterGroupBox->setObjectName("docFilterGroupBox");
        horizontalLayout_2 = new QHBoxLayout(docFilterGroupBox);
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(15, 20, 15, 15);
        dateFromLabel = new QLabel(docFilterGroupBox);
        dateFromLabel->setObjectName("dateFromLabel");

        horizontalLayout_2->addWidget(dateFromLabel);

        dateFromEdit = new QDateEdit(docFilterGroupBox);
        dateFromEdit->setObjectName("dateFromEdit");
        dateFromEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateFromEdit);

        dateToLabel = new QLabel(docFilterGroupBox);
        dateToLabel->setObjectName("dateToLabel");

        horizontalLayout_2->addWidget(dateToLabel);

        dateToEdit = new QDateEdit(docFilterGroupBox);
        dateToEdit->setObjectName("dateToEdit");
        dateToEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateToEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        generateDocButton = new QPushButton(docFilterGroupBox);
        generateDocButton->setObjectName("generateDocButton");
        generateDocButton->setStyleSheet(QString::fromUtf8("background-color: #2ecc71;\n"
"color: white;"));

        horizontalLayout_2->addWidget(generateDocButton);


        verticalLayout_3->addWidget(docFilterGroupBox);

        documentTable = new QTableWidget(documentReportTab);
        if (documentTable->columnCount() < 4)
            documentTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        documentTable->setObjectName("documentTable");
        documentTable->setAlternatingRowColors(true);
        documentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        documentTable->setSortingEnabled(true);
        documentTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(documentTable);

        docActionLayout = new QHBoxLayout();
        docActionLayout->setSpacing(15);
        docActionLayout->setObjectName("docActionLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        docActionLayout->addItem(horizontalSpacer_4);

        exportDocButton = new QPushButton(documentReportTab);
        exportDocButton->setObjectName("exportDocButton");

        docActionLayout->addWidget(exportDocButton);

        printDocButton = new QPushButton(documentReportTab);
        printDocButton->setObjectName("printDocButton");

        docActionLayout->addWidget(printDocButton);


        verticalLayout_3->addLayout(docActionLayout);

        tabWidget->addTab(documentReportTab, QString());
        taskReportTab = new QWidget();
        taskReportTab->setObjectName("taskReportTab");
        verticalLayout_4 = new QVBoxLayout(taskReportTab);
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(15, 15, 15, 15);
        taskFilterGroupBox = new QGroupBox(taskReportTab);
        taskFilterGroupBox->setObjectName("taskFilterGroupBox");
        horizontalLayout_3 = new QHBoxLayout(taskFilterGroupBox);
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(15, 20, 15, 15);
        statusLabel = new QLabel(taskFilterGroupBox);
        statusLabel->setObjectName("statusLabel");

        horizontalLayout_3->addWidget(statusLabel);

        statusCombo = new QComboBox(taskFilterGroupBox);
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->setObjectName("statusCombo");

        horizontalLayout_3->addWidget(statusCombo);

        assigneeLabel = new QLabel(taskFilterGroupBox);
        assigneeLabel->setObjectName("assigneeLabel");

        horizontalLayout_3->addWidget(assigneeLabel);

        assigneeCombo = new QComboBox(taskFilterGroupBox);
        assigneeCombo->addItem(QString());
        assigneeCombo->setObjectName("assigneeCombo");

        horizontalLayout_3->addWidget(assigneeCombo);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        generateTaskButton = new QPushButton(taskFilterGroupBox);
        generateTaskButton->setObjectName("generateTaskButton");
        generateTaskButton->setStyleSheet(QString::fromUtf8("background-color: #2ecc71;\n"
"color: white;"));

        horizontalLayout_3->addWidget(generateTaskButton);


        verticalLayout_4->addWidget(taskFilterGroupBox);

        taskTable = new QTableWidget(taskReportTab);
        if (taskTable->columnCount() < 5)
            taskTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        taskTable->setObjectName("taskTable");
        taskTable->setAlternatingRowColors(true);
        taskTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        taskTable->setSortingEnabled(true);
        taskTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(taskTable);

        taskActionLayout = new QHBoxLayout();
        taskActionLayout->setSpacing(15);
        taskActionLayout->setObjectName("taskActionLayout");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        taskActionLayout->addItem(horizontalSpacer_6);

        exportTaskButton = new QPushButton(taskReportTab);
        exportTaskButton->setObjectName("exportTaskButton");

        taskActionLayout->addWidget(exportTaskButton);

        printTaskButton = new QPushButton(taskReportTab);
        printTaskButton->setObjectName("printTaskButton");

        taskActionLayout->addWidget(printTaskButton);


        verticalLayout_4->addLayout(taskActionLayout);

        tabWidget->addTab(taskReportTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Reports);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Reports);
    } // setupUi

    void retranslateUi(QWidget *Reports)
    {
        filterGroupBox->setTitle(QCoreApplication::translate("Reports", "\331\201\333\214\331\204\330\252\330\261\331\207\330\247", nullptr));
        departmentLabel->setText(QCoreApplication::translate("Reports", "\330\250\330\256\330\264:", nullptr));
        departmentCombo->setItemText(0, QCoreApplication::translate("Reports", "\331\207\331\205\331\207", nullptr));
        departmentCombo->setItemText(1, QCoreApplication::translate("Reports", "\331\201\331\206\330\247\331\210\330\261\333\214 \330\247\330\267\331\204\330\247\330\271\330\247\330\252", nullptr));
        departmentCombo->setItemText(2, QCoreApplication::translate("Reports", "\331\205\331\206\330\247\330\250\330\271 \330\247\331\206\330\263\330\247\331\206\333\214", nullptr));
        departmentCombo->setItemText(3, QCoreApplication::translate("Reports", "\331\205\330\247\331\204\333\214", nullptr));
        departmentCombo->setItemText(4, QCoreApplication::translate("Reports", "\330\250\330\247\330\262\330\247\330\261\333\214\330\247\330\250\333\214", nullptr));

        generateButton->setText(QCoreApplication::translate("Reports", "\331\206\331\205\330\247\333\214\330\264 \332\257\330\262\330\247\330\261\330\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = employeeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Reports", "\330\264\331\206\330\247\330\263\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = employeeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Reports", "\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = employeeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Reports", "\330\263\331\205\330\252", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = employeeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Reports", "\330\250\330\256\330\264", nullptr));
        exportButton->setText(QCoreApplication::translate("Reports", "\330\256\330\261\331\210\330\254\333\214 \330\247\332\251\330\263\331\204", nullptr));
        printButton->setText(QCoreApplication::translate("Reports", "\332\206\330\247\331\276 \332\257\330\262\330\247\330\261\330\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(employeeReportTab), QCoreApplication::translate("Reports", "\332\257\330\262\330\247\330\261\330\264 \332\251\330\247\330\261\331\205\331\206\330\257\330\247\331\206", nullptr));
        docFilterGroupBox->setTitle(QCoreApplication::translate("Reports", "\331\201\333\214\331\204\330\252\330\261\331\207\330\247", nullptr));
        dateFromLabel->setText(QCoreApplication::translate("Reports", "\330\247\330\262 \330\252\330\247\330\261\333\214\330\256:", nullptr));
        dateToLabel->setText(QCoreApplication::translate("Reports", "\330\252\330\247 \330\252\330\247\330\261\333\214\330\256:", nullptr));
        generateDocButton->setText(QCoreApplication::translate("Reports", "\331\206\331\205\330\247\333\214\330\264 \332\257\330\262\330\247\330\261\330\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = documentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Reports", "\330\264\331\206\330\247\330\263\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = documentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Reports", "\330\271\331\206\331\210\330\247\331\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = documentTable->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Reports", "\331\206\331\210\333\214\330\263\331\206\330\257\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = documentTable->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Reports", "\330\252\330\247\330\261\333\214\330\256 \330\247\333\214\330\254\330\247\330\257", nullptr));
        exportDocButton->setText(QCoreApplication::translate("Reports", "\330\256\330\261\331\210\330\254\333\214 \330\247\332\251\330\263\331\204", nullptr));
        printDocButton->setText(QCoreApplication::translate("Reports", "\332\206\330\247\331\276 \332\257\330\262\330\247\330\261\330\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(documentReportTab), QCoreApplication::translate("Reports", "\332\257\330\262\330\247\330\261\330\264 \330\247\330\263\331\206\330\247\330\257", nullptr));
        taskFilterGroupBox->setTitle(QCoreApplication::translate("Reports", "\331\201\333\214\331\204\330\252\330\261\331\207\330\247", nullptr));
        statusLabel->setText(QCoreApplication::translate("Reports", "\331\210\330\266\330\271\333\214\330\252:", nullptr));
        statusCombo->setItemText(0, QCoreApplication::translate("Reports", "\331\207\331\205\331\207", nullptr));
        statusCombo->setItemText(1, QCoreApplication::translate("Reports", "\330\257\330\261 \330\247\331\206\330\252\330\270\330\247\330\261", nullptr));
        statusCombo->setItemText(2, QCoreApplication::translate("Reports", "\330\257\330\261 \330\255\330\247\331\204 \330\247\331\206\330\254\330\247\331\205", nullptr));
        statusCombo->setItemText(3, QCoreApplication::translate("Reports", "\330\252\332\251\331\205\333\214\331\204 \330\264\330\257\331\207", nullptr));

        assigneeLabel->setText(QCoreApplication::translate("Reports", "\331\205\330\263\330\246\331\210\331\204:", nullptr));
        assigneeCombo->setItemText(0, QCoreApplication::translate("Reports", "\331\207\331\205\331\207", nullptr));

        generateTaskButton->setText(QCoreApplication::translate("Reports", "\331\206\331\205\330\247\333\214\330\264 \332\257\330\262\330\247\330\261\330\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = taskTable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Reports", "\330\264\331\206\330\247\330\263\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = taskTable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Reports", "\330\271\331\206\331\210\330\247\331\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = taskTable->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Reports", "\331\205\330\263\330\246\331\210\331\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = taskTable->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Reports", "\331\205\331\207\331\204\330\252 \330\247\331\206\330\254\330\247\331\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = taskTable->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Reports", "\331\210\330\266\330\271\333\214\330\252", nullptr));
        exportTaskButton->setText(QCoreApplication::translate("Reports", "\330\256\330\261\331\210\330\254\333\214 \330\247\332\251\330\263\331\204", nullptr));
        printTaskButton->setText(QCoreApplication::translate("Reports", "\332\206\330\247\331\276 \332\257\330\262\330\247\330\261\330\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(taskReportTab), QCoreApplication::translate("Reports", "\332\257\330\262\330\247\330\261\330\264 \331\210\330\270\330\247\333\214\331\201", nullptr));
        (void)Reports;
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
