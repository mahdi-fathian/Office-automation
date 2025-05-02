#ifndef REPORTS_H
#define REPORTS_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QHeaderView>
#include "database.h"

class Reports : public QWidget
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = nullptr);
    ~Reports();

private slots:
    void onGenerateReportClicked();
    void onExportReportClicked();
    void onReportTypeChanged(int index);
    void updateReportView();

private:
    QTableWidget *reportTable;
    QComboBox *reportTypeCombo;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *generateButton;
    QPushButton *exportButton;
    Database *db;

    void setupUI();
    void generateEmployeeReport();
    void generateTaskReport();
    void generateDocumentReport();
    void generateEventReport();
    void exportToCSV();
};

#endif // REPORTS_H 