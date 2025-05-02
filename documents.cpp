#include "documents.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>

Documents::Documents(QWidget *parent) : QWidget(parent)
{
    db = new Database(this);
    setupUI();
    connectSignals();
    loadDocuments();
    loadArchive();
}

Documents::~Documents()
{
}

void Documents::setupUI()
{
    // Find the tab widget
    tabWidget = findChild<QTabWidget*>("tabWidget");
    
    // Set up main documents tab
    documentTable = findChild<QTableWidget*>("documentTable");
    searchEdit = findChild<QLineEdit*>("searchEdit");
    viewButton = findChild<QPushButton*>("viewButton");
    exportButton = findChild<QPushButton*>("exportButton");
    importButton = findChild<QPushButton*>("importButton");
    addButton = findChild<QPushButton*>("addButton");
    editButton = findChild<QPushButton*>("editButton");
    deleteButton = findChild<QPushButton*>("deleteButton");
    
    // Set up create document tab
    titleEdit = findChild<QLineEdit*>("titleEdit");
    documentTypeCombo = findChild<QComboBox*>("documentTypeCombo");
    contentEdit = findChild<QTextEdit*>("contentEdit");
    referenceNumberEdit = findChild<QLineEdit*>("referenceNumberEdit");
    dateEdit = findChild<QDateEdit*>("dateEdit");
    attachmentEdit = findChild<QLineEdit*>("attachmentEdit");
    uploadButton = findChild<QPushButton*>("uploadButton");
    saveButton = findChild<QPushButton*>("saveButton");
    cancelButton = findChild<QPushButton*>("cancelButton");
    
    // Initialize date with current date
    dateEdit->setDate(QDate::currentDate());
    
    // Set up archive tab
    categoryFilterCombo = findChild<QComboBox*>("categoryFilterCombo");
    startDateEdit = findChild<QDateEdit*>("startDateEdit");
    endDateEdit = findChild<QDateEdit*>("endDateEdit");
    filterButton = findChild<QPushButton*>("filterButton");
    archiveTable = findChild<QTableWidget*>("archiveTable");
    viewArchiveButton = findChild<QPushButton*>("viewArchiveButton");
    restoreButton = findChild<QPushButton*>("restoreButton");
    exportArchiveButton = findChild<QPushButton*>("exportArchiveButton");
    printButton = findChild<QPushButton*>("printButton");
    
    // Initialize date range for archive
    QDate currentDate = QDate::currentDate();
    startDateEdit->setDate(currentDate.addMonths(-1));
    endDateEdit->setDate(currentDate);
}

void Documents::connectSignals()
{
    // Connect main tab buttons
    connect(viewButton, &QPushButton::clicked, this, &Documents::onViewDocumentClicked);
    connect(exportButton, &QPushButton::clicked, this, &Documents::onExportDocumentClicked);
    connect(importButton, &QPushButton::clicked, this, &Documents::onImportDocumentClicked);
    connect(addButton, &QPushButton::clicked, this, &Documents::onAddDocumentClicked);
    connect(editButton, &QPushButton::clicked, this, &Documents::onEditDocumentClicked);
    connect(deleteButton, &QPushButton::clicked, this, &Documents::onDeleteDocumentClicked);
    connect(searchEdit, &QLineEdit::returnPressed, this, &Documents::onSearchDocumentClicked);
    
    // Connect create document tab buttons
    connect(uploadButton, &QPushButton::clicked, [this]() {
        QString filePath = QFileDialog::getOpenFileName(this, "انتخاب فایل پیوست", QDir::homePath());
        if (!filePath.isEmpty()) {
            attachmentEdit->setText(filePath);
        }
    });
    
    connect(saveButton, &QPushButton::clicked, [this]() {
        if (validateInputs()) {
            // Get values from form
            QString title = titleEdit->text();
            QString documentType = documentTypeCombo->currentText();
            QString content = contentEdit->toPlainText();
            QString refNumber = referenceNumberEdit->text();
            QString date = dateEdit->date().toString("yyyy-MM-dd");
            QString attachment = attachmentEdit->text();
            
            // Create SQL query
            QSqlQuery query;
            query.prepare("INSERT INTO documents (title, document_type, content, reference_number, created_date, attachment_path, status) "
                          "VALUES (?, ?, ?, ?, ?, ?, 'فعال')");
            query.addBindValue(title);
            query.addBindValue(documentType);
            query.addBindValue(content);
            query.addBindValue(refNumber);
            query.addBindValue(date);
            query.addBindValue(attachment);
            
            if (query.exec()) {
                QMessageBox::information(this, "موفقیت", "سند با موفقیت ذخیره شد.");
                clearInputs();
                refreshDocumentList();
                tabWidget->setCurrentIndex(0); // Switch back to document list tab
            } else {
                QMessageBox::critical(this, "خطا", "خطا در ذخیره سند: " + query.lastError().text());
            }
        }
    });
    
    connect(cancelButton, &QPushButton::clicked, [this]() {
        clearInputs();
        tabWidget->setCurrentIndex(0); // Switch back to document list tab
    });
    
    // Connect archive tab buttons
    connect(filterButton, &QPushButton::clicked, this, &Documents::onFilterButtonClicked);
    connect(viewArchiveButton, &QPushButton::clicked, this, &Documents::onViewDocumentClicked);
    connect(restoreButton, &QPushButton::clicked, this, &Documents::onRestoreButtonClicked);
    connect(exportArchiveButton, &QPushButton::clicked, this, &Documents::onExportDocumentClicked);
    connect(printButton, &QPushButton::clicked, this, &Documents::onPrintButtonClicked);
    
    // Tab changed signal
    connect(tabWidget, &QTabWidget::currentChanged, this, &Documents::onTabChanged);
}

void Documents::loadDocuments()
{
    QSqlQuery query;
    query.exec("SELECT id, title, document_type, reference_number, created_date FROM documents WHERE status = 'فعال' ORDER BY created_date DESC");
    
    documentTable->setRowCount(0);
    
    int row = 0;
    while (query.next()) {
        documentTable->insertRow(row);
        
        for (int col = 0; col < 5; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            documentTable->setItem(row, col, item);
        }
        
        row++;
    }
}

void Documents::loadArchive()
{
    QDate startDate = startDateEdit->date();
    QDate endDate = endDateEdit->date();
    QString category = categoryFilterCombo->currentText();
    
    QSqlQuery query;
    
    if (category == "همه") {
        query.prepare("SELECT id, title, document_type, reference_number, created_date, status FROM documents "
                     "WHERE created_date BETWEEN ? AND ? ORDER BY created_date DESC");
        query.addBindValue(startDate.toString("yyyy-MM-dd"));
        query.addBindValue(endDate.toString("yyyy-MM-dd"));
    } else {
        query.prepare("SELECT id, title, document_type, reference_number, created_date, status FROM documents "
                     "WHERE document_type = ? AND created_date BETWEEN ? AND ? ORDER BY created_date DESC");
        query.addBindValue(category);
        query.addBindValue(startDate.toString("yyyy-MM-dd"));
        query.addBindValue(endDate.toString("yyyy-MM-dd"));
    }
    
    query.exec();
    
    archiveTable->setRowCount(0);
    
    int row = 0;
    while (query.next()) {
        archiveTable->insertRow(row);
        
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            archiveTable->setItem(row, col, item);
        }
        
        row++;
    }
}

void Documents::clearInputs()
{
    titleEdit->clear();
    contentEdit->clear();
    referenceNumberEdit->clear();
    dateEdit->setDate(QDate::currentDate());
    attachmentEdit->clear();
}

bool Documents::validateInputs()
{
    if (titleEdit->text().isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً عنوان سند را وارد کنید.");
        return false;
    }
    
    if (contentEdit->toPlainText().isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً محتوای سند را وارد کنید.");
        return false;
    }
    
    return true;
}

void Documents::onAddDocumentClicked()
{
    clearInputs();
    tabWidget->setCurrentIndex(1); // Switch to create document tab
}

void Documents::onEditDocumentClicked()
{
    QTableWidget *currentTable = (tabWidget->currentIndex() == 0) ? documentTable : archiveTable;
    QList<QTableWidgetItem*> selectedItems = currentTable->selectedItems();
    
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً یک سند را انتخاب کنید.");
        return;
    }
    
    int row = selectedItems.first()->row();
    QString id = currentTable->item(row, 0)->text();
    
    QSqlQuery query;
    query.prepare("SELECT title, document_type, content, reference_number, created_date, attachment_path FROM documents WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        // Fill form with document data
        titleEdit->setText(query.value(0).toString());
        
        // Find and set the document type in combo box
        QString docType = query.value(1).toString();
        for (int i = 0; i < documentTypeCombo->count(); ++i) {
            if (documentTypeCombo->itemText(i) == docType) {
                documentTypeCombo->setCurrentIndex(i);
                break;
            }
        }
        
        contentEdit->setText(query.value(2).toString());
        referenceNumberEdit->setText(query.value(3).toString());
        dateEdit->setDate(QDate::fromString(query.value(4).toString(), "yyyy-MM-dd"));
        attachmentEdit->setText(query.value(5).toString());
        
        // Switch to create document tab
        tabWidget->setCurrentIndex(1);
        
        // Change save button behavior for edit
        disconnect(saveButton, &QPushButton::clicked, nullptr, nullptr);
        connect(saveButton, &QPushButton::clicked, [this, id]() {
            if (validateInputs()) {
                // Get values from form
                QString title = titleEdit->text();
                QString documentType = documentTypeCombo->currentText();
                QString content = contentEdit->toPlainText();
                QString refNumber = referenceNumberEdit->text();
                QString date = dateEdit->date().toString("yyyy-MM-dd");
                QString attachment = attachmentEdit->text();
                
                // Create SQL query
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE documents SET title = ?, document_type = ?, content = ?, "
                                  "reference_number = ?, created_date = ?, attachment_path = ? WHERE id = ?");
                updateQuery.addBindValue(title);
                updateQuery.addBindValue(documentType);
                updateQuery.addBindValue(content);
                updateQuery.addBindValue(refNumber);
                updateQuery.addBindValue(date);
                updateQuery.addBindValue(attachment);
                updateQuery.addBindValue(id);
                
                if (updateQuery.exec()) {
                    QMessageBox::information(this, "موفقیت", "سند با موفقیت بروزرسانی شد.");
                    clearInputs();
                    refreshDocumentList();
                    refreshArchiveList();
                    tabWidget->setCurrentIndex(0); // Switch back to document list tab
                    
                    // Reconnect save button for add operation
                    disconnectSaveAndReconnect();
                } else {
                    QMessageBox::critical(this, "خطا", "خطا در بروزرسانی سند: " + updateQuery.lastError().text());
                }
            }
        });
    } else {
        QMessageBox::critical(this, "خطا", "خطا در بازیابی اطلاعات سند: " + query.lastError().text());
    }
}

void Documents::disconnectSaveAndReconnect()
{
    // Disconnect edit behavior
    disconnect(saveButton, &QPushButton::clicked, nullptr, nullptr);
    
    // Reconnect add behavior
    connect(saveButton, &QPushButton::clicked, [this]() {
        if (validateInputs()) {
            // Get values from form
            QString title = titleEdit->text();
            QString documentType = documentTypeCombo->currentText();
            QString content = contentEdit->toPlainText();
            QString refNumber = referenceNumberEdit->text();
            QString date = dateEdit->date().toString("yyyy-MM-dd");
            QString attachment = attachmentEdit->text();
            
            // Create SQL query
            QSqlQuery query;
            query.prepare("INSERT INTO documents (title, document_type, content, reference_number, created_date, attachment_path, status) "
                          "VALUES (?, ?, ?, ?, ?, ?, 'فعال')");
            query.addBindValue(title);
            query.addBindValue(documentType);
            query.addBindValue(content);
            query.addBindValue(refNumber);
            query.addBindValue(date);
            query.addBindValue(attachment);
            
            if (query.exec()) {
                QMessageBox::information(this, "موفقیت", "سند با موفقیت ذخیره شد.");
                clearInputs();
                refreshDocumentList();
                tabWidget->setCurrentIndex(0); // Switch back to document list tab
            } else {
                QMessageBox::critical(this, "خطا", "خطا در ذخیره سند: " + query.lastError().text());
            }
        }
    });
}

void Documents::onDeleteDocumentClicked()
{
    QTableWidget *currentTable = (tabWidget->currentIndex() == 0) ? documentTable : archiveTable;
    QList<QTableWidgetItem*> selectedItems = currentTable->selectedItems();
    
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً یک سند را انتخاب کنید.");
        return;
    }
    
    int row = selectedItems.first()->row();
    QString id = currentTable->item(row, 0)->text();
    QString title = currentTable->item(row, 1)->text();
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "تایید حذف",
        "آیا از حذف سند \"" + title + "\" اطمینان دارید؟",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("UPDATE documents SET status = 'آرشیو' WHERE id = ?");
        query.addBindValue(id);
        
        if (query.exec()) {
            QMessageBox::information(this, "موفقیت", "سند با موفقیت به آرشیو منتقل شد.");
            refreshDocumentList();
            refreshArchiveList();
        } else {
            QMessageBox::critical(this, "خطا", "خطا در انتقال سند به آرشیو: " + query.lastError().text());
        }
    }
}

void Documents::onSearchDocumentClicked()
{
    QString searchText = searchEdit->text().trimmed();
    
    if (searchText.isEmpty()) {
        loadDocuments();
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT id, title, document_type, reference_number, created_date FROM documents "
                 "WHERE (title LIKE ? OR document_type LIKE ? OR reference_number LIKE ?) AND status = 'فعال'");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");
    query.addBindValue("%" + searchText + "%");
    
    if (query.exec()) {
        documentTable->setRowCount(0);
        
        int row = 0;
        while (query.next()) {
            documentTable->insertRow(row);
            
            for (int col = 0; col < 5; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                documentTable->setItem(row, col, item);
            }
            
            row++;
        }
    } else {
        QMessageBox::critical(this, "خطا", "خطا در جستجوی سند: " + query.lastError().text());
    }
}

void Documents::onExportDocumentClicked()
{
    QTableWidget *currentTable = (tabWidget->currentIndex() == 0) ? documentTable : archiveTable;
    QList<QTableWidgetItem*> selectedItems = currentTable->selectedItems();
    
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً یک سند را انتخاب کنید.");
        return;
    }
    
    int row = selectedItems.first()->row();
    QString id = currentTable->item(row, 0)->text();
    QString title = currentTable->item(row, 1)->text();
    
    QSqlQuery query;
    query.prepare("SELECT title, document_type, content, reference_number, created_date FROM documents WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        QString title = query.value(0).toString();
        QString documentType = query.value(1).toString();
        QString content = query.value(2).toString();
        QString refNumber = query.value(3).toString();
        QString date = query.value(4).toString();
        
        QString fileName = QFileDialog::getSaveFileName(this, "صدور سند",
            QDir::homePath() + "/" + title + ".txt", "Text Files (*.txt);;Word Documents (*.docx);;All Files (*)");
        
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                
                out << "عنوان: " << title << "\n";
                out << "نوع سند: " << documentType << "\n";
                out << "شماره مرجع: " << refNumber << "\n";
                out << "تاریخ: " << date << "\n";
                out << "---------------------------------------\n\n";
                out << content;
                
                file.close();
                QMessageBox::information(this, "موفقیت", "سند با موفقیت صادر شد.");
            } else {
                QMessageBox::critical(this, "خطا", "خطا در باز کردن فایل برای نوشتن");
            }
        }
    } else {
        QMessageBox::critical(this, "خطا", "خطا در بازیابی اطلاعات سند: " + query.lastError().text());
    }
}

void Documents::onImportDocumentClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "وارد کردن سند",
        QDir::homePath(), "Text Files (*.txt);;Word Documents (*.docx);;All Files (*)");
    
    if (filePath.isEmpty()) {
        return;
    }
    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "خطا", "خطا در باز کردن فایل");
        return;
    }
    
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString content = in.readAll();
    file.close();
    
    QFileInfo fileInfo(filePath);
    titleEdit->setText(fileInfo.baseName());
    contentEdit->setText(content);
    dateEdit->setDate(QDate::currentDate());
    attachmentEdit->setText(filePath);
    
    tabWidget->setCurrentIndex(1); // Switch to create document tab
}

void Documents::onViewDocumentClicked()
{
    QTableWidget *currentTable = (tabWidget->currentIndex() == 0) ? documentTable : archiveTable;
    QList<QTableWidgetItem*> selectedItems = currentTable->selectedItems();
    
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً یک سند را انتخاب کنید.");
        return;
    }
    
    int row = selectedItems.first()->row();
    QString id = currentTable->item(row, 0)->text();
    
    QSqlQuery query;
    query.prepare("SELECT title, document_type, content, reference_number, created_date, attachment_path FROM documents WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        QString title = query.value(0).toString();
        QString documentType = query.value(1).toString();
        QString content = query.value(2).toString();
        QString refNumber = query.value(3).toString();
        QString date = query.value(4).toString();
        QString attachment = query.value(5).toString();
        
        // Create a formatted document view
        QString documentHtml = "<html><body style='direction: rtl; font-family: Arial; padding: 20px;'>"
                             "<h1 style='text-align: center;'>" + title + "</h1>"
                             "<div style='text-align: center; color: #666;'>"
                             "<p>نوع سند: " + documentType + "</p>"
                             "<p>شماره مرجع: " + refNumber + "</p>"
                             "<p>تاریخ: " + date + "</p>"
                             "</div>"
                             "<hr>"
                             "<div style='margin-top: 20px;'>" + 
                             content.replace("\n", "<br>") + 
                             "</div>";
        
        if (!attachment.isEmpty()) {
            documentHtml += "<p style='margin-top: 30px;'>پیوست: " + attachment + "</p>";
        }
        
        documentHtml += "</body></html>";
        
        QMessageBox viewDialog(this);
        viewDialog.setWindowTitle("مشاهده سند: " + title);
        viewDialog.setText(documentHtml);
        viewDialog.setTextFormat(Qt::RichText);
        viewDialog.setStandardButtons(QMessageBox::Close);
        viewDialog.exec();
    } else {
        QMessageBox::critical(this, "خطا", "خطا در بازیابی اطلاعات سند: " + query.lastError().text());
    }
}

void Documents::onFilterButtonClicked()
{
    loadArchive();
}

void Documents::onRestoreButtonClicked()
{
    QList<QTableWidgetItem*> selectedItems = archiveTable->selectedItems();
    
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً یک سند را انتخاب کنید.");
        return;
    }
    
    int row = selectedItems.first()->row();
    QString id = archiveTable->item(row, 0)->text();
    
    QSqlQuery query;
    query.prepare("UPDATE documents SET status = 'فعال' WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec()) {
        QMessageBox::information(this, "موفقیت", "سند با موفقیت از آرشیو بازیابی شد.");
        refreshDocumentList();
        refreshArchiveList();
    } else {
        QMessageBox::critical(this, "خطا", "خطا در بازیابی سند از آرشیو: " + query.lastError().text());
    }
}

void Documents::onPrintButtonClicked()
{
    QList<QTableWidgetItem*> selectedItems = archiveTable->selectedItems();
    
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً یک سند را انتخاب کنید.");
        return;
    }
    
    int row = selectedItems.first()->row();
    QString id = archiveTable->item(row, 0)->text();
    
    QSqlQuery query;
    query.prepare("SELECT title, document_type, content, reference_number, created_date FROM documents WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        QString title = query.value(0).toString();
        QString documentType = query.value(1).toString();
        QString content = query.value(2).toString();
        QString refNumber = query.value(3).toString();
        QString date = query.value(4).toString();
        
        // Create a document for printing
        QTextDocument document;
        document.setHtml("<html><body style='direction: rtl; font-family: Arial; padding: 20px;'>"
                       "<h1 style='text-align: center;'>" + title + "</h1>"
                       "<div style='text-align: center; color: #666;'>"
                       "<p>نوع سند: " + documentType + "</p>"
                       "<p>شماره مرجع: " + refNumber + "</p>"
                       "<p>تاریخ: " + date + "</p>"
                       "</div>"
                       "<hr>"
                       "<div style='margin-top: 20px;'>" + 
                       content.replace("\n", "<br>") + 
                       "</div></body></html>");
        
        QPrinter printer;
        QPrintDialog printDialog(&printer, this);
        
        if (printDialog.exec() == QDialog::Accepted) {
            document.print(&printer);
            QMessageBox::information(this, "موفقیت", "سند با موفقیت به چاپگر ارسال شد.");
        }
    } else {
        QMessageBox::critical(this, "خطا", "خطا در بازیابی اطلاعات سند: " + query.lastError().text());
    }
}

void Documents::refreshDocumentList()
{
    loadDocuments();
}

void Documents::refreshArchiveList()
{
    loadArchive();
}

void Documents::onTabChanged(int index)
{
    if (index == 0) {
        refreshDocumentList();
    } else if (index == 2) {
        refreshArchiveList();
    }
} 