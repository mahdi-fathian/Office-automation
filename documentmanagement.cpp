#include "documentmanagement.h"

DocumentManagement::DocumentManagement(QWidget *parent) : QWidget(parent)
{
    db = new Database(this);
    setupUI();
    loadDocuments();
}

DocumentManagement::~DocumentManagement()
{
}

void DocumentManagement::setupUI()
{
    // Create main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // Create search section
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchEdit = new QLineEdit(this);
    searchEdit->setPlaceholderText("Search documents...");
    searchEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    searchButton = new QPushButton("Search", this);
    searchButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; padding: 8px; border-radius: 4px; }"
                              "QPushButton:hover { background-color: #2980b9; }");
    
    searchLayout->addWidget(searchEdit);
    searchLayout->addWidget(searchButton);
    mainLayout->addLayout(searchLayout);

    // Create document table
    documentTable = new QTableWidget(this);
    documentTable->setColumnCount(4);
    documentTable->setHorizontalHeaderLabels({"ID", "Title", "Author", "Created Date"});
    documentTable->setStyleSheet("QTableWidget { border: 1px solid #bdc3c7; border-radius: 4px; }"
                               "QHeaderView::section { background-color: #2c3e50; color: white; padding: 8px; }");
    documentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    documentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(documentTable);

    // Create input section
    QVBoxLayout *inputLayout = new QVBoxLayout();
    
    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("Document Title");
    titleEdit->setStyleSheet("QLineEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    contentEdit = new QTextEdit(this);
    contentEdit->setPlaceholderText("Document Content");
    contentEdit->setStyleSheet("QTextEdit { padding: 8px; border: 1px solid #bdc3c7; border-radius: 4px; }");
    
    inputLayout->addWidget(titleEdit);
    inputLayout->addWidget(contentEdit);
    mainLayout->addLayout(inputLayout);

    // Create button section
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    addButton = new QPushButton("Add Document", this);
    editButton = new QPushButton("Edit Document", this);
    deleteButton = new QPushButton("Delete Document", this);
    exportButton = new QPushButton("Export", this);
    importButton = new QPushButton("Import", this);
    
    QString buttonStyle = "QPushButton { padding: 8px; border-radius: 4px; }";
    addButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #2ecc71; color: white; }"
                           "QPushButton:hover { background-color: #27ae60; }");
    editButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #f1c40f; color: white; }"
                            "QPushButton:hover { background-color: #f39c12; }");
    deleteButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #e74c3c; color: white; }"
                              "QPushButton:hover { background-color: #c0392b; }");
    exportButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #3498db; color: white; }"
                              "QPushButton:hover { background-color: #2980b9; }");
    importButton->setStyleSheet(buttonStyle + "QPushButton { background-color: #9b59b6; color: white; }"
                              "QPushButton:hover { background-color: #8e44ad; }");
    
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);
    buttonLayout->addWidget(exportButton);
    buttonLayout->addWidget(importButton);
    mainLayout->addLayout(buttonLayout);

    // Connect signals
    connect(addButton, &QPushButton::clicked, this, &DocumentManagement::onAddDocumentClicked);
    connect(editButton, &QPushButton::clicked, this, &DocumentManagement::onEditDocumentClicked);
    connect(deleteButton, &QPushButton::clicked, this, &DocumentManagement::onDeleteDocumentClicked);
    connect(searchButton, &QPushButton::clicked, this, &DocumentManagement::onSearchDocumentClicked);
    connect(exportButton, &QPushButton::clicked, this, &DocumentManagement::onExportDocumentClicked);
    connect(importButton, &QPushButton::clicked, this, &DocumentManagement::onImportDocumentClicked);
}

void DocumentManagement::loadDocuments()
{
    QSqlQuery query;
    query.exec("SELECT * FROM documents");
    
    documentTable->setRowCount(0);
    while (query.next()) {
        int row = documentTable->rowCount();
        documentTable->insertRow(row);
        
        documentTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        documentTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        documentTable->setItem(row, 2, new QTableWidgetItem(query.value(3).toString()));
        documentTable->setItem(row, 3, new QTableWidgetItem(query.value(4).toString()));
    }
}

void DocumentManagement::onAddDocumentClicked()
{
    QString title = titleEdit->text();
    QString content = contentEdit->toPlainText();
    QString author = "Current User"; // In a real application, this would be the logged-in user

    if (title.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields!");
        return;
    }

    // Generate document number
    QString documentNumber = "DOC" + QString::number(QDateTime::currentDateTime().toSecsSinceEpoch());
    
    // Get author ID (assuming it's stored in a member variable)
    int authorId = 1; // TODO: Replace with actual current user ID

    if (db->addDocument(documentNumber, title, "General", content, authorId)) {
        QMessageBox::information(this, "Success", "Document added successfully!");
        clearInputs();
        loadDocuments();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add document!");
    }
}

void DocumentManagement::onEditDocumentClicked()
{
    QList<QTableWidgetItem*> selectedItems = documentTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a document to edit!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = documentTable->item(row, 0)->text();
    QString title = titleEdit->text();
    QString content = contentEdit->toPlainText();

    if (title.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields!");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE documents SET title = ?, content = ? WHERE id = ?");
    query.addBindValue(title);
    query.addBindValue(content);
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Document updated successfully!");
        clearInputs();
        loadDocuments();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update document!");
    }
}

void DocumentManagement::onDeleteDocumentClicked()
{
    QList<QTableWidgetItem*> selectedItems = documentTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a document to delete!");
        return;
    }

    int row = selectedItems.first()->row();
    QString id = documentTable->item(row, 0)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
        "Are you sure you want to delete this document?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM documents WHERE id = ?");
        query.addBindValue(id);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Document deleted successfully!");
            loadDocuments();
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete document!");
        }
    }
}

void DocumentManagement::onSearchDocumentClicked()
{
    QString searchText = searchEdit->text();
    if (searchText.isEmpty()) {
        loadDocuments();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM documents WHERE title LIKE ? OR content LIKE ? OR author LIKE ?");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");

    if (query.exec()) {
        documentTable->setRowCount(0);
        while (query.next()) {
            int row = documentTable->rowCount();
            documentTable->insertRow(row);
            
            documentTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            documentTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            documentTable->setItem(row, 2, new QTableWidgetItem(query.value(3).toString()));
            documentTable->setItem(row, 3, new QTableWidgetItem(query.value(4).toString()));
        }
    }
}

void DocumentManagement::onExportDocumentClicked()
{
    QList<QTableWidgetItem*> selectedItems = documentTable->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a document to export!");
        return;
    }

    int row = selectedItems.first()->row();
    QString title = documentTable->item(row, 1)->text();
    QString content = contentEdit->toPlainText();

    QString fileName = QFileDialog::getSaveFileName(this, "Export Document",
        QDir::homePath() + "/" + title + ".txt", "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Title: " << title << "\n\n";
            out << content;
            file.close();
            QMessageBox::information(this, "Success", "Document exported successfully!");
        } else {
            QMessageBox::critical(this, "Error", "Failed to export document!");
        }
    }
}

void DocumentManagement::onImportDocumentClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Import Document",
        QDir::homePath(), "Text Files (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString content = in.readAll();
            file.close();

            titleEdit->setText(QFileInfo(fileName).baseName());
            contentEdit->setText(content);
            QMessageBox::information(this, "Success", "Document imported successfully!");
        } else {
            QMessageBox::critical(this, "Error", "Failed to import document!");
        }
    }
}

void DocumentManagement::clearInputs()
{
    titleEdit->clear();
    contentEdit->clear();
}

void DocumentManagement::refreshDocumentList()
{
    documentTable->setRowCount(0);
    loadDocuments();
} 