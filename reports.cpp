#include "reports.h"

Reports::Reports(QWidget *parent) : QWidget(parent)
{
    db = new Database(this);
    setupUI();
}

Reports::~Reports()
{
}

void Reports::setupUI()
{
    // Create main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Create report type selection
    QHBoxLayout *typeLayout = new QHBoxLayout();
    reportTypeCombo = new QComboBox(this);
    reportTypeCombo->addItems({"Employee Report", "Task Report", "Document Report", "Event Report"});
    reportTypeCombo->setStyleSheet("QComboBox { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    typeLayout->addWidget(new QLabel("Report Type:"));
    typeLayout->addWidget(reportTypeCombo);
    mainLayout->addLayout(typeLayout);

    // Create date range selection
    QHBoxLayout *dateLayout = new QHBoxLayout();
    startDateEdit = new QDateEdit(this);
    startDateEdit->setCalendarPopup(true);
    startDateEdit->setDate(QDate::currentDate().addMonths(-1));
    startDateEdit->setStyleSheet("QDateEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    endDateEdit = new QDateEdit(this);
    endDateEdit->setCalendarPopup(true);
    endDateEdit->setDate(QDate::currentDate());
    endDateEdit->setStyleSheet("QDateEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    dateLayout->addWidget(new QLabel("Start Date:"));
    dateLayout->addWidget(startDateEdit);
    dateLayout->addWidget(new QLabel("End Date:"));
    dateLayout->addWidget(endDateEdit);
    mainLayout->addLayout(dateLayout);

    // Create report table
    reportTable = new QTableWidget(this);
    reportTable->setStyleSheet("QTableWidget { border: 1px solid #bdc3c7; border-radius: 4px; }"
                             "QHeaderView::section { background-color: #2c3e50; color: white; padding: 8px; }");
    reportTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    reportTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(reportTable);

    // Create button section
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    generateButton = new QPushButton("Generate Report", this);
    exportButton = new QPushButton("Export to CSV", this);
    
    QString buttonStyle = "QPushButton { padding: 8px; border-radius: 4px; }";
    generateButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #3498db; color: white; }"
                                "QPushButton:hover { background-color: #2980b9; }");
    exportButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #2ecc71; color: white; }"
                              "QPushButton:hover { background-color: #27ae60; }");
    
    buttonLayout->addWidget(generateButton);
    buttonLayout->addWidget(exportButton);
    mainLayout->addLayout(buttonLayout);

    // Connect signals
    connect(generateButton, &QPushButton::clicked, this, &Reports::onGenerateReportClicked);
    connect(exportButton, &QPushButton::clicked, this, &Reports::onExportReportClicked);
    connect(reportTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Reports::onReportTypeChanged);
}

void Reports::onGenerateReportClicked()
{
    switch (reportTypeCombo->currentIndex()) {
        case 0:
            generateEmployeeReport();
            break;
        case 1:
            generateTaskReport();
            break;
        case 2:
            generateDocumentReport();
            break;
        case 3:
            generateEventReport();
            break;
    }
}

void Reports::onExportReportClicked()
{
    if (reportTable->rowCount() == 0) {
        QMessageBox::warning(this, "Error", "No data to export!");
        return;
    }
    exportToCSV();
}

void Reports::onReportTypeChanged(int /*index*/)
{
    // Implementation will be added later
    updateReportView();
}

void Reports::generateEmployeeReport()
{
    reportTable->setColumnCount(4);
    reportTable->setHorizontalHeaderLabels({"ID", "Name", "Position", "Department"});
    
    QSqlQuery query;
    query.exec("SELECT * FROM employees");
    
    reportTable->setRowCount(0);
    while (query.next()) {
        int row = reportTable->rowCount();
        reportTable->insertRow(row);
        
        reportTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        reportTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        reportTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        reportTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
    }
}

void Reports::generateTaskReport()
{
    reportTable->setColumnCount(6);
    reportTable->setHorizontalHeaderLabels({"ID", "Title", "Description", "Assignee", "Due Date", "Status"});
    
    QSqlQuery query;
    query.prepare("SELECT * FROM tasks WHERE due_date BETWEEN ? AND ?");
    query.addBindValue(startDateEdit->date());
    query.addBindValue(endDateEdit->date());
    
    if (query.exec()) {
        reportTable->setRowCount(0);
        while (query.next()) {
            int row = reportTable->rowCount();
            reportTable->insertRow(row);
            
            reportTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            reportTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            reportTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            reportTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            reportTable->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            reportTable->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        }
    }
}

void Reports::generateDocumentReport()
{
    reportTable->setColumnCount(5);
    reportTable->setHorizontalHeaderLabels({"ID", "Title", "Content", "Author", "Created Date"});
    
    QSqlQuery query;
    query.prepare("SELECT * FROM documents WHERE created_date BETWEEN ? AND ?");
    query.addBindValue(startDateEdit->date());
    query.addBindValue(endDateEdit->date());
    
    if (query.exec()) {
        reportTable->setRowCount(0);
        while (query.next()) {
            int row = reportTable->rowCount();
            reportTable->insertRow(row);
            
            reportTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            reportTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            reportTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            reportTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            reportTable->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        }
    }
}

void Reports::generateEventReport()
{
    reportTable->setColumnCount(4);
    reportTable->setHorizontalHeaderLabels({"ID", "Title", "Start Time", "End Time"});
    
    QSqlQuery query;
    query.prepare("SELECT * FROM events WHERE start_time BETWEEN ? AND ?");
    query.addBindValue(startDateEdit->date());
    query.addBindValue(endDateEdit->date());
    
    if (query.exec()) {
        reportTable->setRowCount(0);
        while (query.next()) {
            int row = reportTable->rowCount();
            reportTable->insertRow(row);
            
            reportTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            reportTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            reportTable->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            reportTable->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        }
    }
}

void Reports::exportToCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export Report",
        QDir::homePath() + "/report.csv", "CSV Files (*.csv)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            
            // Write headers
            for (int i = 0; i < reportTable->columnCount(); ++i) {
                out << reportTable->horizontalHeaderItem(i)->text();
                if (i < reportTable->columnCount() - 1)
                    out << ",";
            }
            out << "\n";
            
            // Write data
            for (int row = 0; row < reportTable->rowCount(); ++row) {
                for (int col = 0; col < reportTable->columnCount(); ++col) {
                    out << reportTable->item(row, col)->text();
                    if (col < reportTable->columnCount() - 1)
                        out << ",";
                }
                out << "\n";
            }
            
            file.close();
            QMessageBox::information(this, "Success", "Report exported successfully!");
        } else {
            QMessageBox::critical(this, "Error", "Failed to export report!");
        }
    }
}

void Reports::updateReportView()
{
    // Clear the current view
    reportTable->clear();
    reportTable->setRowCount(0);
    reportTable->setColumnCount(0);
    
    // Update based on the selected report type
    switch (reportTypeCombo->currentIndex()) {
        case 0: // Employee Report
            reportTable->setColumnCount(4);
            reportTable->setHorizontalHeaderLabels({"ID", "Name", "Position", "Department"});
            break;
        case 1: // Task Report
            reportTable->setColumnCount(6);
            reportTable->setHorizontalHeaderLabels({"ID", "Title", "Description", "Assignee", "Due Date", "Status"});
            break;
        case 2: // Document Report
            reportTable->setColumnCount(5);
            reportTable->setHorizontalHeaderLabels({"ID", "Title", "Content", "Author", "Created Date"});
            break;
        case 3: // Event Report
            reportTable->setColumnCount(4);
            reportTable->setHorizontalHeaderLabels({"ID", "Title", "Start Time", "End Time"});
            break;
    }
    
    // Adjust column widths
    for (int i = 0; i < reportTable->columnCount(); ++i) {
        reportTable->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
} 