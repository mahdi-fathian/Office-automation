#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QCalendarWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "database.h"

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void onDateSelected(const QDate &date);
    void onAddEventClicked();
    void onEditEventClicked();
    void onDeleteEventClicked();
    void onEventSelected();
    void refreshEventList();

private:
    Database *db;
    QCalendarWidget *calendarWidget;
    QTableWidget *eventTable;
    QLineEdit *titleEdit;
    QDateTimeEdit *startTimeEdit;
    QDateTimeEdit *endTimeEdit;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;

    void setupUI();
    void loadEvents(const QDate &date);
    void clearInputs();
};

#endif // CALENDAR_H 