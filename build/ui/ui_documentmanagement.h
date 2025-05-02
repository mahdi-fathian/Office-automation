/********************************************************************************
** Form generated from reading UI file 'documentmanagement.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTMANAGEMENT_H
#define UI_DOCUMENTMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_DocumentManagement
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *documentsTab;
    QVBoxLayout *verticalLayout_2;
    QWidget *searchWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *searchLabel;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QTableWidget *documentTable;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *viewButton;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QWidget *createDocumentTab;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *titleLabel;
    QLineEdit *titleEdit;
    QLabel *categoryLabel;
    QComboBox *categoryCombo;
    QLabel *contentLabel;
    QTextEdit *contentEdit;
    QLabel *uploadLabel;
    QHBoxLayout *attachmentLayout;
    QLineEdit *attachmentEdit;
    QPushButton *uploadButton;
    QHBoxLayout *saveLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *DocumentManagement)
    {
        if (DocumentManagement->objectName().isEmpty())
            DocumentManagement->setObjectName("DocumentManagement");
        DocumentManagement->resize(800, 600);
        DocumentManagement->setLayoutDirection(Qt::RightToLeft);
        DocumentManagement->setStyleSheet(QString::fromUtf8("QLineEdit, QTextEdit, QComboBox, QDateEdit {\n"
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
"QPushButton#searchButton, QPushButton#uploadButton, QPushButton#viewButton {\n"
"  background-color: #3498db;\n"
"  color: white;\n"
"}\n"
"QPushButton#searchButton:hover, QPushButton#uploadButton:hover, QPushButton#viewButton:hover {\n"
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
        verticalLayout = new QVBoxLayout(DocumentManagement);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        tabWidget = new QTabWidget(DocumentManagement);
        tabWidget->setObjectName("tabWidget");
        documentsTab = new QWidget();
        documentsTab->setObjectName("documentsTab");
        verticalLayout_2 = new QVBoxLayout(documentsTab);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        searchWidget = new QWidget(documentsTab);
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


        verticalLayout_2->addWidget(searchWidget);

        documentTable = new QTableWidget(documentsTab);
        if (documentTable->columnCount() < 4)
            documentTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        documentTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        documentTable->setObjectName("documentTable");
        documentTable->setAlternatingRowColors(true);
        documentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        documentTable->setSortingEnabled(true);
        documentTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(documentTable);

        buttonWidget = new QWidget(documentsTab);
        buttonWidget->setObjectName("buttonWidget");
        horizontalLayout_3 = new QHBoxLayout(buttonWidget);
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        viewButton = new QPushButton(buttonWidget);
        viewButton->setObjectName("viewButton");

        horizontalLayout_3->addWidget(viewButton);

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


        verticalLayout_2->addWidget(buttonWidget);

        tabWidget->addTab(documentsTab, QString());
        createDocumentTab = new QWidget();
        createDocumentTab->setObjectName("createDocumentTab");
        verticalLayout_3 = new QVBoxLayout(createDocumentTab);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(15, 15, 15, 15);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        titleLabel = new QLabel(createDocumentTab);
        titleLabel->setObjectName("titleLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, titleLabel);

        titleEdit = new QLineEdit(createDocumentTab);
        titleEdit->setObjectName("titleEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, titleEdit);

        categoryLabel = new QLabel(createDocumentTab);
        categoryLabel->setObjectName("categoryLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, categoryLabel);

        categoryCombo = new QComboBox(createDocumentTab);
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->addItem(QString());
        categoryCombo->setObjectName("categoryCombo");
        categoryCombo->setMinimumSize(QSize(0, 35));

        formLayout->setWidget(1, QFormLayout::FieldRole, categoryCombo);

        contentLabel = new QLabel(createDocumentTab);
        contentLabel->setObjectName("contentLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, contentLabel);

        contentEdit = new QTextEdit(createDocumentTab);
        contentEdit->setObjectName("contentEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, contentEdit);

        uploadLabel = new QLabel(createDocumentTab);
        uploadLabel->setObjectName("uploadLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, uploadLabel);

        attachmentLayout = new QHBoxLayout();
        attachmentLayout->setSpacing(10);
        attachmentLayout->setObjectName("attachmentLayout");
        attachmentEdit = new QLineEdit(createDocumentTab);
        attachmentEdit->setObjectName("attachmentEdit");
        attachmentEdit->setReadOnly(true);

        attachmentLayout->addWidget(attachmentEdit);

        uploadButton = new QPushButton(createDocumentTab);
        uploadButton->setObjectName("uploadButton");

        attachmentLayout->addWidget(uploadButton);


        formLayout->setLayout(3, QFormLayout::FieldRole, attachmentLayout);


        verticalLayout_3->addLayout(formLayout);

        saveLayout = new QHBoxLayout();
        saveLayout->setSpacing(15);
        saveLayout->setObjectName("saveLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        saveLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(createDocumentTab);
        saveButton->setObjectName("saveButton");
        saveButton->setMinimumSize(QSize(150, 40));
        saveButton->setStyleSheet(QString::fromUtf8("background-color: #2ecc71;\n"
"color: white;"));

        saveLayout->addWidget(saveButton);

        cancelButton = new QPushButton(createDocumentTab);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setMinimumSize(QSize(150, 40));
        cancelButton->setStyleSheet(QString::fromUtf8("background-color: #e74c3c;\n"
"color: white;"));

        saveLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(saveLayout);

        tabWidget->addTab(createDocumentTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(DocumentManagement);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DocumentManagement);
    } // setupUi

    void retranslateUi(QWidget *DocumentManagement)
    {
        searchLabel->setText(QCoreApplication::translate("DocumentManagement", "\330\254\330\263\330\252\330\254\331\210:", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("DocumentManagement", "\330\254\330\263\330\252\330\254\331\210\333\214 \330\247\330\263\331\206\330\247\330\257...", nullptr));
        searchButton->setText(QCoreApplication::translate("DocumentManagement", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem = documentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DocumentManagement", "\330\264\331\206\330\247\330\263\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = documentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DocumentManagement", "\330\271\331\206\331\210\330\247\331\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = documentTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DocumentManagement", "\331\206\331\210\333\214\330\263\331\206\330\257\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = documentTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DocumentManagement", "\330\252\330\247\330\261\333\214\330\256 \330\247\333\214\330\254\330\247\330\257", nullptr));
        viewButton->setText(QCoreApplication::translate("DocumentManagement", "\331\205\330\264\330\247\331\207\330\257\331\207 \330\263\331\206\330\257", nullptr));
        addButton->setText(QCoreApplication::translate("DocumentManagement", "\330\247\331\201\330\262\331\210\330\257\331\206 \330\263\331\206\330\257", nullptr));
        editButton->setText(QCoreApplication::translate("DocumentManagement", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\263\331\206\330\257", nullptr));
        deleteButton->setText(QCoreApplication::translate("DocumentManagement", "\330\255\330\260\331\201 \330\263\331\206\330\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(documentsTab), QCoreApplication::translate("DocumentManagement", "\331\205\330\257\333\214\330\261\333\214\330\252 \330\247\330\263\331\206\330\247\330\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("DocumentManagement", "\330\271\331\206\331\210\330\247\331\206:", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("DocumentManagement", "\330\271\331\206\331\210\330\247\331\206 \330\263\331\206\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        categoryLabel->setText(QCoreApplication::translate("DocumentManagement", "\330\257\330\263\330\252\331\207\342\200\214\330\250\331\206\330\257\333\214:", nullptr));
        categoryCombo->setItemText(0, QCoreApplication::translate("DocumentManagement", "\330\261\330\263\331\205\333\214", nullptr));
        categoryCombo->setItemText(1, QCoreApplication::translate("DocumentManagement", "\330\257\330\247\330\256\331\204\333\214", nullptr));
        categoryCombo->setItemText(2, QCoreApplication::translate("DocumentManagement", "\330\247\330\257\330\247\330\261\333\214", nullptr));
        categoryCombo->setItemText(3, QCoreApplication::translate("DocumentManagement", "\331\205\330\247\331\204\333\214", nullptr));
        categoryCombo->setItemText(4, QCoreApplication::translate("DocumentManagement", "\330\263\330\247\333\214\330\261", nullptr));

        contentLabel->setText(QCoreApplication::translate("DocumentManagement", "\331\205\330\255\330\252\331\210\330\247:", nullptr));
        contentEdit->setPlaceholderText(QCoreApplication::translate("DocumentManagement", "\331\205\330\255\330\252\331\210\330\247\333\214 \330\263\331\206\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257...", nullptr));
        uploadLabel->setText(QCoreApplication::translate("DocumentManagement", "\331\276\333\214\331\210\330\263\330\252:", nullptr));
        attachmentEdit->setPlaceholderText(QCoreApplication::translate("DocumentManagement", "\331\201\330\247\333\214\331\204\333\214 \330\247\331\206\330\252\330\256\330\247\330\250 \331\206\330\264\330\257\331\207 \330\247\330\263\330\252", nullptr));
        uploadButton->setText(QCoreApplication::translate("DocumentManagement", "\330\247\331\206\330\252\330\256\330\247\330\250 \331\201\330\247\333\214\331\204", nullptr));
        saveButton->setText(QCoreApplication::translate("DocumentManagement", "\330\260\330\256\333\214\330\261\331\207 \330\263\331\206\330\257", nullptr));
        cancelButton->setText(QCoreApplication::translate("DocumentManagement", "\330\247\331\206\330\265\330\261\330\247\331\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(createDocumentTab), QCoreApplication::translate("DocumentManagement", "\330\247\333\214\330\254\330\247\330\257 \330\263\331\206\330\257 \330\254\330\257\333\214\330\257", nullptr));
        (void)DocumentManagement;
    } // retranslateUi

};

namespace Ui {
    class DocumentManagement: public Ui_DocumentManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTMANAGEMENT_H
