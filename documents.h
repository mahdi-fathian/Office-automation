#ifndef DOCUMENTS_H
#define DOCUMENTS_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QTabWidget>
#include "database.h"

class Documents : public QWidget
{
    Q_OBJECT

public:
    explicit Documents(QWidget *parent = nullptr);
    ~Documents();

private slots:
    void onAddDocumentClicked();
    void onEditDocumentClicked();
    void onDeleteDocumentClicked();
    void onSearchDocumentClicked();
    void onExportDocumentClicked();
    void onImportDocumentClicked();
    void onViewDocumentClicked();
    void onFilterButtonClicked();
    void onRestoreButtonClicked();
    void onPrintButtonClicked();
    void refreshDocumentList();
    void refreshArchiveList();
    void onTabChanged(int index);

private:
    QTabWidget *tabWidget;
    
    // Main Documents Tab
    QTableWidget *documentTable;
    QLineEdit *searchEdit;
    QPushButton *viewButton;
    QPushButton *exportButton;
    QPushButton *importButton;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    
    // Create Document Tab
    QLineEdit *titleEdit;
    QComboBox *documentTypeCombo;
    QTextEdit *contentEdit;
    QLineEdit *referenceNumberEdit;
    QDateEdit *dateEdit;
    QLineEdit *attachmentEdit;
    QPushButton *uploadButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    
    // Archive Tab
    QComboBox *categoryFilterCombo;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *filterButton;
    QTableWidget *archiveTable;
    QPushButton *viewArchiveButton;
    QPushButton *restoreButton;
    QPushButton *exportArchiveButton;
    QPushButton *printButton;
    
    Database *db;

    void setupUI();
    void connectSignals();
    void loadDocuments();
    void loadArchive();
    void clearInputs();
    bool validateInputs();
    void disconnectSaveAndReconnect();
};

#endif // DOCUMENTS_H 