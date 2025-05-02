#include "calendar.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Calendar::Calendar(QWidget *parent) : QWidget(parent)
{
    db = new Database(this);
    setupUI();
    loadEvents(QDate::currentDate());
}

Calendar::~Calendar()
{
}

void Calendar::setupUI()
{
    // Create main layout
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Create calendar widget
    QVBoxLayout *calendarLayout = new QVBoxLayout();
    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setStyleSheet("QCalendarWidget { background-color: white; }"
                                "QCalendarWidget QToolButton { color: #2c3e50; }"
                                "QCalendarWidget QMenu { background-color: white; }"
                                "QCalendarWidget QSpinBox { background-color: white; }");
    calendarLayout->addWidget(calendarWidget);
    mainLayout->addLayout(calendarLayout);

    // Create event section
    QVBoxLayout *eventLayout = new QVBoxLayout();
    
    // Create event table
    eventTable = new QTableWidget(this);
    eventTable->setColumnCount(4);
    eventTable->setHorizontalHeaderLabels({"ID", "Title", "Start Time", "End Time"});
    eventTable->setStyleSheet("QTableWidget { border: 1px solid #bdc3c7; border-radius: 4px; }"
                            "QHeaderView::section { background-color: #2c3e50; color: white; padding: 8px; }");
    eventTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    eventTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    eventLayout->addWidget(eventTable);

    // Create input section
    QVBoxLayout *inputLayout = new QVBoxLayout();
    
    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("Event Title");
    titleEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    QHBoxLayout *timeLayout = new QHBoxLayout();
    
    startTimeEdit = new QDateTimeEdit(this);
    startTimeEdit->setCalendarPopup(true);
    startTimeEdit->setDateTime(QDateTime::currentDateTime());
    startTimeEdit->setStyleSheet("QDateTimeEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    endTimeEdit = new QDateTimeEdit(this);
    endTimeEdit->setCalendarPopup(true);
    endTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(3600));
    endTimeEdit->setStyleSheet("QDateTimeEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    timeLayout->addWidget(new QLabel("Start:"));
    timeLayout->addWidget(startTimeEdit);
    timeLayout->addWidget(new QLabel("End:"));
    timeLayout->addWidget(endTimeEdit);
    
    inputLayout->addWidget(titleEdit);
    inputLayout->addLayout(timeLayout);
    eventLayout->addLayout(inputLayout);

    // Create button section
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    addButton = new QPushButton("Add Event", this);
    editButton = new QPushButton("Edit Event", this);
    deleteButton = new QPushButton("Delete Event", this);
    
    QString buttonStyle = "QPushButton { padding: 8px; border-radius: 4px; }";
    addButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #2ecc71; color: white; }"
                           "QPushButton:hover { background-color: #27ae60; }");
    editButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #f1c40f; color: white; }"
                            "QPushButton:hover { background-color: #f39c12; }");
    deleteButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #e74c3c; color: white; }"
                              "QPushButton:hover { background-color: #c0392b; }");
    
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);
    eventLayout->addLayout(buttonLayout);

    mainLayout->addLayout(eventLayout);

    // Connect signals
    connect(calendarWidget, &QCalendarWidget::clicked, this, &Calendar::onDateSelected);
    connect(addButton, &QPushButton::clicked, this, &Calendar::onAddEventClicked);
    connect(editButton, &QPushButton::clicked, this, &Calendar::onEditEventClicked);
    connect(deleteButton, &QPushButton::clicked, this, &Calendar::onDeleteEventClicked);
}

void Calendar::loadEvents(const QDate &date)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM events WHERE DATE(start_time) = ?");
    query.addBindValue(date.toString("yyyy-MM-dd"));
    
    if (query.exec()) {
        eventTable->setRowCount(0);
        while (query.next()) {
            int row = eventTable->rowCount();
            eventTable->insertRow(row);
            
            eventTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            eventTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            eventTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            eventTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        }
    }
}

void Calendar::onAddEventClicked()
{
    QString title = titleEdit->text();
    QDateTime startTime = startTimeEdit->dateTime();
    QDateTime endTime = endTimeEdit->dateTime();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter an event title!");
        return;
    }

    if (startTime >= endTime) {
        QMessageBox::warning(this, "Error", "End time must be after start time!");
        return;
    }

    // Get current user ID (assuming it's stored in a member variable)
    int creatorId = 1; // TODO: Replace with actual current user ID
    QString description = ""; // TODO: Add description field
    QString eventType = "General"; // TODO: Add event type selection

    if (db->addEvent(title, description, creatorId, startTime, endTime, eventType)) {
        QMessageBox::information(this, "Success", "Event added successfully!");
        clearInputs();
        loadEvents(calendarWidget->selectedDate());
    } else {
        QMessageBox::critical(this, "Error", "Failed to add event!");
    }
}

void Calendar::onEditEventClicked()
{
    QList<QTableWidgetItem*> selectedItems = eventTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select an event to edit!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = eventTable->item(row, 0)->text();
    QString title = titleEdit->text();
    QDateTime startTime = startTimeEdit->dateTime();
    QDateTime endTime = endTimeEdit->dateTime();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter an event title!");
        return;
    }

    if (startTime >= endTime) {
        QMessageBox::warning(this, "Error", "End time must be after start time!");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE events SET title = ?, start_time = ?, end_time = ? WHERE id = ?");
    query.addBindValue(title);
    query.addBindValue(startTime);
    query.addBindValue(endTime);
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Event updated successfully!");
        clearInputs();
        loadEvents(calendarWidget->selectedDate());
    } else {
        QMessageBox::critical(this, "Error", "Failed to update event!");
    }
}

void Calendar::onDeleteEventClicked()
{
    QList<QTableWidgetItem*> selectedItems = eventTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select an event to delete!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = eventTable->item(row, 0)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
        "Are you sure you want to delete this event?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM events WHERE id = ?");
        query.addBindValue(id);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Event deleted successfully!");
            loadEvents(calendarWidget->selectedDate());
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete event!");
        }
    }
}

void Calendar::onDateSelected(const QDate &date)
{
    loadEvents(date);
}

void Calendar::onEventSelected()
{
    QList<QTableWidgetItem*> selectedItems = eventTable->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        titleEdit->setText(eventTable->item(row, 1)->text());
        startTimeEdit->setDateTime(QDateTime::fromString(eventTable->item(row, 2)->text()));
        endTimeEdit->setDateTime(QDateTime::fromString(eventTable->item(row, 3)->text()));
    }
}

void Calendar::clearInputs()
{
    titleEdit->clear();
    startTimeEdit->setDateTime(QDateTime::currentDateTime());
    endTimeEdit->setDateTime(QDateTime::currentDateTime().addSecs(3600));
}

void Calendar::refreshEventList()
{
    eventTable->setRowCount(0);
    loadEvents(calendarWidget->selectedDate());
} 