/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *calendarLayout;
    QCalendarWidget *calendarWidget;
    QGroupBox *eventDetailsGroupBox;
    QFormLayout *formLayout;
    QLabel *titleLabel;
    QLineEdit *titleEdit;
    QLabel *startTimeLabel;
    QTimeEdit *startTimeEdit;
    QLabel *endTimeLabel;
    QTimeEdit *endTimeEdit;
    QLabel *descriptionLabel;
    QTextEdit *descriptionEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QVBoxLayout *eventsLayout;
    QLabel *dayEventsLabel;
    QLabel *selectedDateLabel;
    QListWidget *eventListWidget;

    void setupUi(QWidget *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName("Calendar");
        Calendar->resize(800, 600);
        Calendar->setLayoutDirection(Qt::RightToLeft);
        Calendar->setStyleSheet(QString::fromUtf8("QCalendarWidget {\n"
"  background-color: white;\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 10px;\n"
"}\n"
"QCalendarWidget QToolButton {\n"
"  color: #2c3e50;\n"
"  padding: 5px;\n"
"  font-size: 14px;\n"
"  font-weight: bold;\n"
"}\n"
"QCalendarWidget QMenu {\n"
"  background-color: white;\n"
"  padding: 5px;\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 5px;\n"
"}\n"
"QCalendarWidget QAbstractItemView:enabled {\n"
"  color: #2c3e50;\n"
"  selection-background-color: #3498db;\n"
"  selection-color: white;\n"
"}\n"
"QCalendarWidget QToolButton::menu-indicator {\n"
"  image: none;\n"
"}\n"
"QCalendarWidget #qt_calendar_navigationbar {\n"
"  background-color: #ecf0f1;\n"
"  border-top-left-radius: 10px;\n"
"  border-top-right-radius: 10px;\n"
"  padding: 2px;\n"
"}\n"
"QCalendarWidget #qt_calendar_prevmonth, QCalendarWidget #qt_calendar_nextmonth {\n"
"  border: none;\n"
"  color: #3498db;\n"
"  qproperty-icon: none;\n"
"  background-color: transparent;\n"
"}\n"
"QCalendarWidget #qt_calendar_"
                        "prevmonth:hover, QCalendarWidget #qt_calendar_nextmonth:hover {\n"
"  background-color: rgba(52, 152, 219, 0.2);\n"
"  border-radius: 4px;\n"
"}\n"
"QLabel {\n"
"  font-size: 14px;\n"
"  color: #2c3e50;\n"
"}\n"
"QLineEdit, QTextEdit, QTimeEdit, QDateEdit {\n"
"  padding: 8px;\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"  background-color: white;\n"
"  min-height: 30px;\n"
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
"QPushButton {\n"
"  border-radius: 8px;\n"
"  padding: 8px 16px;\n"
"  font-weight: bold;\n"
"  min-height: 35px;\n"
"}\n"
"QPushButton#addButton, QPushButton#saveButton {\n"
"  background-color: #2ecc71;\n"
"  color: white;\n"
"}\n"
"QPushButton#addButton:hover, QPushButton#saveButton:hover {\n"
"  background-color: #27ae6"
                        "0;\n"
"}\n"
"QPushButton#cancelButton, QPushButton#deleteButton {\n"
"  background-color: #e74c3c;\n"
"  color: white;\n"
"}\n"
"QPushButton#cancelButton:hover, QPushButton#deleteButton:hover {\n"
"  background-color: #c0392b;\n"
"}\n"
"QPushButton#editButton {\n"
"  background-color: #f1c40f;\n"
"  color: white;\n"
"}\n"
"QPushButton#editButton:hover {\n"
"  background-color: #f39c12;\n"
"}\n"
"QListWidget {\n"
"  border: 1px solid #e1e4e8;\n"
"  border-radius: 8px;\n"
"  background-color: white;\n"
"  alternate-background-color: #f5f8fa;\n"
"}"));
        verticalLayout = new QVBoxLayout(Calendar);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(20);
        mainLayout->setObjectName("mainLayout");
        calendarLayout = new QVBoxLayout();
        calendarLayout->setSpacing(15);
        calendarLayout->setObjectName("calendarLayout");
        calendarWidget = new QCalendarWidget(Calendar);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setMinimumSize(QSize(0, 300));
        calendarWidget->setFirstDayOfWeek(Qt::Saturday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        calendarLayout->addWidget(calendarWidget);

        eventDetailsGroupBox = new QGroupBox(Calendar);
        eventDetailsGroupBox->setObjectName("eventDetailsGroupBox");
        formLayout = new QFormLayout(eventDetailsGroupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(15, 20, 15, 15);
        titleLabel = new QLabel(eventDetailsGroupBox);
        titleLabel->setObjectName("titleLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, titleLabel);

        titleEdit = new QLineEdit(eventDetailsGroupBox);
        titleEdit->setObjectName("titleEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, titleEdit);

        startTimeLabel = new QLabel(eventDetailsGroupBox);
        startTimeLabel->setObjectName("startTimeLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, startTimeLabel);

        startTimeEdit = new QTimeEdit(eventDetailsGroupBox);
        startTimeEdit->setObjectName("startTimeEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, startTimeEdit);

        endTimeLabel = new QLabel(eventDetailsGroupBox);
        endTimeLabel->setObjectName("endTimeLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, endTimeLabel);

        endTimeEdit = new QTimeEdit(eventDetailsGroupBox);
        endTimeEdit->setObjectName("endTimeEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, endTimeEdit);

        descriptionLabel = new QLabel(eventDetailsGroupBox);
        descriptionLabel->setObjectName("descriptionLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, descriptionLabel);

        descriptionEdit = new QTextEdit(eventDetailsGroupBox);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setMaximumSize(QSize(16777215, 80));

        formLayout->setWidget(3, QFormLayout::FieldRole, descriptionEdit);


        calendarLayout->addWidget(eventDetailsGroupBox);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(10);
        buttonLayout->setObjectName("buttonLayout");
        addButton = new QPushButton(Calendar);
        addButton->setObjectName("addButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/modern/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addButton->setIcon(icon);

        buttonLayout->addWidget(addButton);

        editButton = new QPushButton(Calendar);
        editButton->setObjectName("editButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/modern/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editButton->setIcon(icon1);

        buttonLayout->addWidget(editButton);

        deleteButton = new QPushButton(Calendar);
        deleteButton->setObjectName("deleteButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/modern/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deleteButton->setIcon(icon2);

        buttonLayout->addWidget(deleteButton);


        calendarLayout->addLayout(buttonLayout);


        mainLayout->addLayout(calendarLayout);

        eventsLayout = new QVBoxLayout();
        eventsLayout->setSpacing(10);
        eventsLayout->setObjectName("eventsLayout");
        dayEventsLabel = new QLabel(Calendar);
        dayEventsLabel->setObjectName("dayEventsLabel");
        dayEventsLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #2c3e50;"));
        dayEventsLabel->setAlignment(Qt::AlignCenter);

        eventsLayout->addWidget(dayEventsLabel);

        selectedDateLabel = new QLabel(Calendar);
        selectedDateLabel->setObjectName("selectedDateLabel");
        selectedDateLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #3498db;"));
        selectedDateLabel->setAlignment(Qt::AlignCenter);

        eventsLayout->addWidget(selectedDateLabel);

        eventListWidget = new QListWidget(Calendar);
        eventListWidget->setObjectName("eventListWidget");
        eventListWidget->setAlternatingRowColors(true);

        eventsLayout->addWidget(eventListWidget);


        mainLayout->addLayout(eventsLayout);

        mainLayout->setStretch(0, 2);
        mainLayout->setStretch(1, 1);

        verticalLayout->addLayout(mainLayout);


        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QWidget *Calendar)
    {
        eventDetailsGroupBox->setTitle(QCoreApplication::translate("Calendar", "\330\254\330\262\330\246\333\214\330\247\330\252 \330\261\331\210\333\214\330\257\330\247\330\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("Calendar", "\330\271\331\206\331\210\330\247\331\206:", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("Calendar", "\330\271\331\206\331\210\330\247\331\206 \330\261\331\210\333\214\330\257\330\247\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257", nullptr));
        startTimeLabel->setText(QCoreApplication::translate("Calendar", "\330\262\331\205\330\247\331\206 \330\264\330\261\331\210\330\271:", nullptr));
        startTimeEdit->setDisplayFormat(QCoreApplication::translate("Calendar", "hh:mm", nullptr));
        endTimeLabel->setText(QCoreApplication::translate("Calendar", "\330\262\331\205\330\247\331\206 \331\276\330\247\333\214\330\247\331\206:", nullptr));
        endTimeEdit->setDisplayFormat(QCoreApplication::translate("Calendar", "hh:mm", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("Calendar", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252:", nullptr));
        descriptionEdit->setPlaceholderText(QCoreApplication::translate("Calendar", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252 \330\261\331\210\333\214\330\257\330\247\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257...", nullptr));
        addButton->setText(QCoreApplication::translate("Calendar", "\330\247\331\201\330\262\331\210\330\257\331\206 \330\261\331\210\333\214\330\257\330\247\330\257", nullptr));
        editButton->setText(QCoreApplication::translate("Calendar", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\261\331\210\333\214\330\257\330\247\330\257", nullptr));
        deleteButton->setText(QCoreApplication::translate("Calendar", "\330\255\330\260\331\201 \330\261\331\210\333\214\330\257\330\247\330\257", nullptr));
        dayEventsLabel->setText(QCoreApplication::translate("Calendar", "\330\261\331\210\333\214\330\257\330\247\330\257\331\207\330\247\333\214 \330\261\331\210\330\262", nullptr));
        selectedDateLabel->setText(QCoreApplication::translate("Calendar", "\330\252\330\247\330\261\333\214\330\256 \330\247\331\206\330\252\330\256\330\247\330\250 \330\264\330\257\331\207: ", nullptr));
        (void)Calendar;
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
