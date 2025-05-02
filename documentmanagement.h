#ifndef DOCUMENTMANAGEMENT_H
#define DOCUMENTMANAGEMENT_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include "database.h"

class DocumentManagement : public QWidget
{
    Q_OBJECT

public:
    explicit DocumentManagement(QWidget *parent = nullptr);
    ~DocumentManagement();

private slots:
    void onAddDocumentClicked();
    void onEditDocumentClicked();
    void onDeleteDocumentClicked();
    void onSearchDocumentClicked();
    void onExportDocumentClicked();
    void onImportDocumentClicked();
    void refreshDocumentList();

private:
    QTableWidget *documentTable;
    QLineEdit *titleEdit;
    QTextEdit *contentEdit;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *searchButton;
    QPushButton *exportButton;
    QPushButton *importButton;
    QLineEdit *searchEdit;
    Database *db;

    void setupUI();
    void loadDocuments();
    void clearInputs();
};

#endif // DOCUMENTMANAGEMENT_H 