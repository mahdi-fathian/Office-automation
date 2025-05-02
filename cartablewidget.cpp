#include "cartablewidget.h"
#include <QAction>
#include <QFontComboBox>
#include <QComboBox>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QColorDialog>
#include <QTextListFormat>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QDateTime>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QSettings>
#include <QFile>

CartableWidget::CartableWidget(Database *db, QWidget *parent)
    : QWidget(parent), db(db)
{
    setStyleSheet("QWidget { background: white; }"
                  "QToolBar { background: #f3f4f6; border-radius: 6px; }"
                  "QPushButton { padding: 8px 20px; border-radius: 4px; background: #4a5568; color: white; }"
                  "QPushButton:hover { background: #2d3748; }");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(10, 10, 10, 10);

    // Toolbar (نوار ابزار بالا)
    toolbar = new QToolBar(this);
    sendBtn = new QPushButton("ارسال");
    draftBtn = new QPushButton("پیش‌نویس");
    deleteBtn = new QPushButton("حذف");
    newLetterBtn = new QPushButton("نامه جدید");
    toolbar->addWidget(sendBtn);
    toolbar->addWidget(draftBtn);
    toolbar->addWidget(deleteBtn);
    toolbar->addSeparator();
    toolbar->addWidget(newLetterBtn);
    mainLayout->addWidget(toolbar);

    // --- Inbox/Sent toggle ---
    QHBoxLayout *toggleLayout = new QHBoxLayout();
    QPushButton *inboxBtn = new QPushButton("ورودی");
    QPushButton *sentBtn = new QPushButton("خروجی");
    inboxBtn->setCheckable(true);
    sentBtn->setCheckable(true);
    inboxBtn->setChecked(true);
    toggleLayout->addWidget(inboxBtn);
    toggleLayout->addWidget(sentBtn);
    mainLayout->addLayout(toggleLayout);
    // Store toggle state
    bool *isInboxView = new bool(true); // will be captured in lambda

    // فرم اطلاعات نامه/یادداشت
    setupFormFields(mainLayout);

    // Recipient list with search
    QHBoxLayout *recipientLayout = new QHBoxLayout();
    recipientSearchEdit = new QLineEdit(this);
    recipientSearchEdit->setPlaceholderText("جستجوی گیرنده...");
    recipientList = new QListWidget(this);
    recipientList->setSelectionMode(QAbstractItemView::MultiSelection);
    populateRecipients();
    recipientLayout->addWidget(new QLabel("گیرندگان:"));
    recipientLayout->addWidget(recipientSearchEdit);
    recipientLayout->addWidget(recipientList);
    mainLayout->addLayout(recipientLayout);

    // Rich text editor with formatting toolbar
    formatToolbar = new QToolBar(this);
    QFontComboBox *fontCombo = new QFontComboBox(formatToolbar);
    QComboBox *sizeCombo = new QComboBox(formatToolbar);
    for (int i = 8; i <= 24; i += 2) sizeCombo->addItem(QString::number(i));
    QAction *boldAction = formatToolbar->addAction(QIcon(":/icons/bold.png"), "Bold");
    QAction *italicAction = formatToolbar->addAction(QIcon(":/icons/italic.png"), "Italic");
    QAction *underlineAction = formatToolbar->addAction(QIcon(":/icons/underline.png"), "Underline");
    QAction *colorAction = formatToolbar->addAction(QIcon(":/icons/color.png"), "Color");
    QAction *alignLeftAction = formatToolbar->addAction(QIcon(":/icons/align-left.png"), "Align Left");
    QAction *alignCenterAction = formatToolbar->addAction(QIcon(":/icons/align-center.png"), "Align Center");
    QAction *alignRightAction = formatToolbar->addAction(QIcon(":/icons/align-right.png"), "Align Right");
    QAction *bulletListAction = formatToolbar->addAction(QIcon(":/icons/bullet.png"), "Bullet List");
    QAction *numberedListAction = formatToolbar->addAction(QIcon(":/icons/numbered.png"), "Numbered List");
    QAction *insertTitleAction = formatToolbar->addAction("درج عنوان آماده");
    QAction *insertSignatureAction = formatToolbar->addAction("درج امضا");
    QAction *attachFileAction = formatToolbar->addAction(QIcon(":/icons/attach.png"), "پیوست فایل");
    formatToolbar->addWidget(fontCombo);
    formatToolbar->addWidget(sizeCombo);
    mainLayout->addWidget(formatToolbar);

    editor = new QTextEdit(this);
    editor->setPlaceholderText("متن نامه یا یادداشت...");
    mainLayout->addWidget(editor);

    // Table of letters/tasks
    cartableTable = new QTableWidget(this);
    cartableTable->setColumnCount(6);
    cartableTable->setHorizontalHeaderLabels({"شماره نامه", "فرستنده", "گیرنده", "تاریخ", "وضعیت", "پیوست"});
    mainLayout->addWidget(cartableTable);

    // اتصال ابزارها به QTextEdit
    connect(boldAction, &QAction::triggered, this, [this]() {
        QTextCharFormat fmt;
        fmt.setFontWeight(editor->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
        editor->mergeCurrentCharFormat(fmt);
    });
    connect(italicAction, &QAction::triggered, this, [this]() {
        QTextCharFormat fmt;
        fmt.setFontItalic(!editor->fontItalic());
        editor->mergeCurrentCharFormat(fmt);
    });
    connect(underlineAction, &QAction::triggered, this, [this]() {
        QTextCharFormat fmt;
        fmt.setFontUnderline(!editor->fontUnderline());
        editor->mergeCurrentCharFormat(fmt);
    });
    connect(colorAction, &QAction::triggered, this, [this]() {
        QColor color = QColorDialog::getColor(editor->textColor(), this, "انتخاب رنگ قلم");
        if (color.isValid()) {
            QTextCharFormat fmt;
            fmt.setForeground(color);
            editor->mergeCurrentCharFormat(fmt);
        }
    });
    connect(fontCombo, &QFontComboBox::currentFontChanged, this, [this](const QFont &font) {
        QTextCharFormat fmt;
        fmt.setFontFamily(font.family());
        editor->mergeCurrentCharFormat(fmt);
    });
    connect(sizeCombo, &QComboBox::currentTextChanged, this, [this](const QString &size) {
        QTextCharFormat fmt;
        fmt.setFontPointSize(size.toInt());
        editor->mergeCurrentCharFormat(fmt);
    });
    connect(alignLeftAction, &QAction::triggered, this, [this]() {
        editor->setAlignment(Qt::AlignLeft);
    });
    connect(alignCenterAction, &QAction::triggered, this, [this]() {
        editor->setAlignment(Qt::AlignCenter);
    });
    connect(alignRightAction, &QAction::triggered, this, [this]() {
        editor->setAlignment(Qt::AlignRight);
    });
    connect(bulletListAction, &QAction::triggered, this, [this]() {
        QTextCursor cursor = editor->textCursor();
        cursor.insertList(QTextListFormat::ListDisc);
    });
    connect(numberedListAction, &QAction::triggered, this, [this]() {
        QTextCursor cursor = editor->textCursor();
        cursor.insertList(QTextListFormat::ListDecimal);
    });
    connect(insertTitleAction, &QAction::triggered, this, [this]() {
        editor->insertPlainText("عنوان آماده نامه\n");
    });
    connect(insertSignatureAction, &QAction::triggered, this, [this]() {
        editor->append("\nبا احترام،\nامضا: کاربر سیستم");
    });
    connect(attachFileAction, &QAction::triggered, this, &CartableWidget::onAttachFileClicked);

    // اتصال دکمه‌ها به اسلات‌ها
    connect(sendBtn, &QPushButton::clicked, this, &CartableWidget::onSendClicked);
    connect(draftBtn, &QPushButton::clicked, this, &CartableWidget::onDraftClicked);
    connect(deleteBtn, &QPushButton::clicked, this, &CartableWidget::onDeleteClicked);
    connect(newLetterBtn, &QPushButton::clicked, this, &CartableWidget::onNewLetterClicked);
    connect(recipientSearchEdit, &QLineEdit::textChanged, this, &CartableWidget::onRecipientSearchChanged);
    connect(cartableTable, &QTableWidget::cellDoubleClicked, this, &CartableWidget::onTableItemDoubleClicked);

    // Toggle logic
    connect(inboxBtn, &QPushButton::clicked, this, [this, inboxBtn, sentBtn, isInboxView]() {
        *isInboxView = true;
        inboxBtn->setChecked(true);
        sentBtn->setChecked(false);
        loadCartableData(*isInboxView);
    });
    connect(sentBtn, &QPushButton::clicked, this, [this, inboxBtn, sentBtn, isInboxView]() {
        *isInboxView = false;
        inboxBtn->setChecked(false);
        sentBtn->setChecked(true);
        loadCartableData(*isInboxView);
    });

    loadCartableData(*isInboxView);
}

void CartableWidget::setupFormFields(QVBoxLayout *mainLayout) {
    QHBoxLayout *formLayout = new QHBoxLayout();
    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("عنوان نامه یا یادداشت");
    formLayout->addWidget(new QLabel("عنوان:"));
    formLayout->addWidget(titleEdit);

    typeCombo = new QComboBox(this);
    priorityCombo = new QComboBox(this);
    populateTypesAndPriorities();
    formLayout->addWidget(new QLabel("نوع:"));
    formLayout->addWidget(typeCombo);
    formLayout->addWidget(new QLabel("فوریت:"));
    formLayout->addWidget(priorityCombo);

    // CC recipients as QListWidget
    ccList = new QListWidget(this);
    ccList->setSelectionMode(QAbstractItemView::MultiSelection);
    // Populate ccList with users
    QSqlQuery query("SELECT id, full_name FROM users ORDER BY full_name");
    while (query.next()) {
        QListWidgetItem* item = new QListWidgetItem(query.value(1).toString());
        item->setData(Qt::UserRole, query.value(0).toInt());
        ccList->addItem(item);
    }
    QVBoxLayout *ccLayout = new QVBoxLayout();
    ccLayout->addWidget(new QLabel("گیرندگان رونوشت:"));
    ccLayout->addWidget(ccList);
    formLayout->addLayout(ccLayout);

    instructionEdit = new QLineEdit(this);
    instructionEdit->setPlaceholderText("دستور رونوشت");
    formLayout->addWidget(new QLabel("دستور رونوشت:"));
    formLayout->addWidget(instructionEdit);

    urgentCheck = new QCheckBox("فوری", this);
    formLayout->addWidget(urgentCheck);

    dueDateEdit = new QDateEdit(this);
    dueDateEdit->setCalendarPopup(true);
    dueDateEdit->setDisplayFormat("yyyy/MM/dd");
    dueDateEdit->setDate(QDate::currentDate());
    formLayout->addWidget(new QLabel("تاریخ مهلت:"));
    formLayout->addWidget(dueDateEdit);

    mainLayout->addLayout(formLayout);
}

void CartableWidget::populateRecipients() {
    recipientList->clear();
    QSqlQuery query("SELECT id, full_name FROM users ORDER BY full_name");
    while (query.next()) {
        QListWidgetItem* item = new QListWidgetItem(query.value(1).toString());
        item->setData(Qt::UserRole, query.value(0).toInt());
        recipientList->addItem(item);
    }
}

void CartableWidget::populateTypesAndPriorities() {
    typeCombo->clear();
    typeCombo->addItems({"نامه داخلی", "یادداشت اداری", "فرم اداری", "نامه صادره"});
    priorityCombo->clear();
    priorityCombo->addItems({"عادی", "فوری", "آنی"});
}

void CartableWidget::onAttachFileClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "انتخاب فایل پیوست");
    if (!fileName.isEmpty()) {
        attachedFilePath = fileName;
        QMessageBox::information(this, "پیوست", QString("فایل %1 پیوست شد.").arg(QFileInfo(fileName).fileName()));
    }
}

void CartableWidget::onSendClicked() {
    onSaveOrUpdateLetter(false);
}

void CartableWidget::onDraftClicked() {
    onSaveOrUpdateLetter(true);
}

void CartableWidget::onSaveOrUpdateLetter(bool isDraft) {
    QString title = titleEdit->text();
    QString type = typeCombo->currentText();
    QString content = editor->toHtml();
    QSettings settings("OfficeAutomation", "Dashboard");
    int authorId = settings.value("user/id", 1).toInt();
    if (title.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "خطا", "عنوان و متن نامه نمی‌تواند خالی باشد.");
        return;
    }
    QString saveTitle = isDraft ? (title + " [پیش‌نویس]") : title;
    bool ok = false;
    QString documentNumber;
    if (editingLetterId > 0) {
        // Update existing letter
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE documents SET title = ?, content = ?, modified_date = CURRENT_TIMESTAMP WHERE id = ?");
        updateQuery.addBindValue(saveTitle);
        updateQuery.addBindValue(content);
        updateQuery.addBindValue(editingLetterId);
        ok = updateQuery.exec();
        // Get document number for further operations
        QSqlQuery numQuery;
        numQuery.prepare("SELECT document_number FROM documents WHERE id = ?");
        numQuery.addBindValue(editingLetterId);
        if (numQuery.exec() && numQuery.next()) {
            documentNumber = numQuery.value(0).toString();
        }
    } else {
        // Insert new letter
        documentNumber = QString::number(QDateTime::currentSecsSinceEpoch());
        ok = db->addDocument(documentNumber, saveTitle, type, content, authorId);
        // Get last inserted document id
        QSqlQuery idQuery("SELECT id FROM documents WHERE document_number = '" + documentNumber + "'");
        if (idQuery.next()) {
            editingLetterId = idQuery.value(0).toInt();
        }
    }
    if (!ok) {
        QMessageBox::critical(this, "خطا", editingLetterId > 0 ? "به‌روزرسانی نامه با خطا مواجه شد." : "ذخیره نامه با خطا مواجه شد.");
        return;
    }
    int documentId = editingLetterId;
    if (documentId == -1) {
        QMessageBox::critical(this, "خطا", "شناسه نامه یافت نشد.");
        return;
    }
    // Save recipients (to)
    QList<QListWidgetItem*> selected = recipientList->selectedItems();
    for (QListWidgetItem* item : selected) {
        int userId = item->data(Qt::UserRole).toInt();
        if (userId == 0) userId = 1;
        db->addRecipient(documentId, userId, "to");
        db->addLetterStatus(documentId, userId, "unread");
    }
    // Save CC recipients
    QList<QListWidgetItem*> ccSelected = ccList->selectedItems();
    for (QListWidgetItem* item : ccSelected) {
        int userId = item->data(Qt::UserRole).toInt();
        if (userId == 0) userId = 1;
        db->addRecipient(documentId, userId, "cc");
        db->addLetterStatus(documentId, userId, "unread");
    }
    // Save attachment
    if (!attachedFilePath.isEmpty()) {
        QFileInfo fi(attachedFilePath);
        db->addLetterAttachment(documentId, fi.fileName(), attachedFilePath, fi.suffix(), fi.size(), authorId);
    }
    // Save history
    db->addLetterHistory(documentId, authorId, isDraft ? "draft" : "send", editingLetterId > 0 ? "ویرایش نامه" : "ایجاد نامه");
    QMessageBox::information(this, "موفقیت", editingLetterId > 0 ? "نامه با موفقیت ویرایش شد." : (isDraft ? "پیش‌نویس ذخیره شد." : "نامه ارسال شد."));
    clearForm();
    loadCartableData(*isInboxView);
}

void CartableWidget::onDeleteClicked() {
    int row = cartableTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "حذف نامه", "لطفاً یک نامه را برای حذف انتخاب کنید.");
        return;
    }
    QString docNumber = cartableTable->item(row, 0)->text();
    if (QMessageBox::question(this, "تایید حذف", "آیا از حذف این نامه اطمینان دارید؟") != QMessageBox::Yes)
        return;
    QSqlQuery query;
    query.prepare("DELETE FROM documents WHERE document_number = ?");
    query.addBindValue(docNumber);
    if (query.exec()) {
        QMessageBox::information(this, "حذف", "نامه با موفقیت حذف شد.");
        loadCartableData(*isInboxView);
    } else {
        QMessageBox::critical(this, "خطا", "حذف نامه با خطا مواجه شد.");
    }
}

void CartableWidget::onNewLetterClicked() {
    clearForm();
    // Reset editing state for new letter
    editingLetterId = -1;
}

void CartableWidget::onRecipientSearchChanged(const QString &text) {
    for (int i = 0; i < recipientList->count(); ++i) {
        QListWidgetItem *item = recipientList->item(i);
        bool match = item->text().contains(text, Qt::CaseInsensitive);
        item->setHidden(!match);
    }
}

void CartableWidget::onTableItemDoubleClicked(int row, int column) {
    if (row < 0) return;
    if (column == 5) { // Attachment column
        QString fileName = cartableTable->item(row, 5)->text();
        if (fileName.isEmpty()) {
            QMessageBox::information(this, "پیوست", "این نامه پیوست ندارد.");
            return;
        }
        // Find document id
        QString docNumber = cartableTable->item(row, 0)->text();
        QSqlQuery query;
        query.prepare("SELECT id FROM documents WHERE document_number = ?");
        query.addBindValue(docNumber);
        int docId = -1;
        if (query.exec() && query.next()) {
            docId = query.value(0).toInt();
        }
        if (docId == -1) {
            QMessageBox::warning(this, "خطا", "شناسه نامه یافت نشد.");
            return;
        }
        // Get attachment path
        QSqlQuery attQuery;
        attQuery.prepare("SELECT file_path FROM letter_attachments WHERE document_id = ? AND file_name = ?");
        attQuery.addBindValue(docId);
        attQuery.addBindValue(fileName);
        if (attQuery.exec() && attQuery.next()) {
            QString filePath = attQuery.value(0).toString();
            QString savePath = QFileDialog::getSaveFileName(this, "ذخیره پیوست", fileName);
            if (!savePath.isEmpty()) {
                if (QFile::copy(filePath, savePath)) {
                    QMessageBox::information(this, "پیوست", "فایل با موفقیت ذخیره شد.");
                } else {
                    QMessageBox::critical(this, "خطا", "ذخیره فایل با خطا مواجه شد.");
                }
            }
        } else {
            QMessageBox::warning(this, "خطا", "مسیر فایل پیوست یافت نشد.");
        }
        return;
    }
    // Default: load letter for editing
    QString docNumber = cartableTable->item(row, 0)->text();
    QSqlQuery query;
    query.prepare("SELECT id, title, content FROM documents WHERE document_number = ?");
    query.addBindValue(docNumber);
    if (query.exec() && query.next()) {
        editingLetterId = query.value(0).toInt();
        titleEdit->setText(query.value(1).toString());
        editor->setHtml(query.value(2).toString());
        // TODO: Load recipients, CCs, and other fields if needed
    }
}

void CartableWidget::loadCartableData(bool inbox) {
    cartableTable->setRowCount(0);
    QSettings settings("OfficeAutomation", "Dashboard");
    int currentUserId = settings.value("user/id", 1).toInt();
    QSqlQuery query;
    if (inbox) {
        // Inbox: letters where user is recipient (to or cc)
        query.prepare("SELECT d.id, d.document_number, d.title, u.full_name, d.created_date, d.status "
                      "FROM documents d "
                      "JOIN recipients r ON d.id = r.document_id "
                      "JOIN users u ON d.author_id = u.id "
                      "WHERE r.user_id = ? "
                      "ORDER BY d.created_date DESC");
        query.addBindValue(currentUserId);
    } else {
        // Sent: letters where user is author
        query.prepare("SELECT d.id, d.document_number, d.title, group_concat(u2.full_name, ', '), d.created_date, d.status "
                      "FROM documents d "
                      "LEFT JOIN recipients r ON d.id = r.document_id "
                      "LEFT JOIN users u2 ON r.user_id = u2.id "
                      "WHERE d.author_id = ? "
                      "GROUP BY d.id "
                      "ORDER BY d.created_date DESC");
        query.addBindValue(currentUserId);
    }
    int row = 0;
    if (query.exec()) {
        while (query.next()) {
            int docId = query.value(0).toInt();
            cartableTable->insertRow(row);
            for (int col = 0; col < 5; ++col) {
                cartableTable->setItem(row, col, new QTableWidgetItem(query.value(col + 1).toString()));
            }
            // Check for attachment
            QSqlQuery attQuery;
            attQuery.prepare("SELECT file_name FROM letter_attachments WHERE document_id = ? LIMIT 1");
            attQuery.addBindValue(docId);
            QString attName = "";
            if (attQuery.exec() && attQuery.next()) {
                attName = attQuery.value(0).toString();
            }
            cartableTable->setItem(row, 5, new QTableWidgetItem(attName));
            ++row;
        }
    }
}

void CartableWidget::clearForm() {
    titleEdit->clear();
    editor->clear();
    recipientList->clearSelection();
    ccList->clearSelection();
    instructionEdit->clear();
    urgentCheck->setChecked(false);
    dueDateEdit->setDate(QDate::currentDate());
    attachedFilePath.clear();
    editingLetterId = -1;
}

// TODO: پیاده‌سازی سایر اسلات‌ها و منطق ذخیره، ارسال، حذف، ویرایش و بارگذاری داده‌ها
// ... existing code ... 