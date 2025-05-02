#include "emailwidget.h"

EmailWidget::EmailWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    connect(sendBtn, &QPushButton::clicked, this, &EmailWidget::onSendClicked);
    connect(receiveBtn, &QPushButton::clicked, this, &EmailWidget::onReceiveClicked);
    connect(deleteBtn, &QPushButton::clicked, this, &EmailWidget::onDeleteClicked);
    connect(attachBtn, &QPushButton::clicked, this, &EmailWidget::onAttachFileClicked);
    connect(recipientSearchEdit, &QLineEdit::textChanged, this, &EmailWidget::onRecipientSearchChanged);
    connect(emailTable, &QTableWidget::cellDoubleClicked, this, &EmailWidget::onTableItemDoubleClicked);
    loadEmailData();
}

void EmailWidget::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    toolbar = new QToolBar(this);
    sendBtn = new QPushButton("ارسال");
    receiveBtn = new QPushButton("دریافت");
    deleteBtn = new QPushButton("حذف");
    attachBtn = new QPushButton("پیوست فایل");
    toolbar->addWidget(sendBtn);
    toolbar->addWidget(receiveBtn);
    toolbar->addWidget(deleteBtn);
    toolbar->addWidget(attachBtn);
    mainLayout->addWidget(toolbar);

    QHBoxLayout *topLayout = new QHBoxLayout();
    recipientSearchEdit = new QLineEdit(this);
    recipientSearchEdit->setPlaceholderText("جستجوی گیرنده...");
    recipientList = new QListWidget(this);
    recipientList->setSelectionMode(QAbstractItemView::MultiSelection);
    populateRecipients();
    QVBoxLayout *recipientLayout = new QVBoxLayout();
    recipientLayout->addWidget(new QLabel("گیرندگان:"));
    recipientLayout->addWidget(recipientSearchEdit);
    recipientLayout->addWidget(recipientList);
    topLayout->addLayout(recipientLayout);

    QVBoxLayout *editorLayout = new QVBoxLayout();
    subjectEdit = new QLineEdit(this);
    subjectEdit->setPlaceholderText("موضوع ایمیل");
    editorLayout->addWidget(new QLabel("موضوع:"));
    editorLayout->addWidget(subjectEdit);
    editor = new QTextEdit(this);
    editor->setPlaceholderText("متن پیام...");
    editorLayout->addWidget(editor);
    topLayout->addLayout(editorLayout, 1);
    mainLayout->addLayout(topLayout);

    emailTable = new QTableWidget(this);
    emailTable->setColumnCount(5);
    emailTable->setHorizontalHeaderLabels({"فرستنده", "گیرنده", "موضوع", "تاریخ", "پیوست"});
    mainLayout->addWidget(emailTable);
}

void EmailWidget::populateRecipients() {
    recipientList->clear();
    QSqlQuery query("SELECT id, full_name FROM users ORDER BY full_name");
    while (query.next()) {
        QListWidgetItem* item = new QListWidgetItem(query.value(1).toString());
        item->setData(Qt::UserRole, query.value(0).toInt());
        recipientList->addItem(item);
    }
}

void EmailWidget::onSendClicked() {}
void EmailWidget::onReceiveClicked() {}
void EmailWidget::onDeleteClicked() {}
void EmailWidget::onAttachFileClicked() {}
void EmailWidget::onTableItemDoubleClicked(int row, int column) {}
void EmailWidget::onRecipientSearchChanged(const QString &text) {}
void EmailWidget::loadEmailData() {}
void EmailWidget::clearForm() {} 