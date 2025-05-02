#include "archivewidget.h"

ArchiveWidget::ArchiveWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    connect(viewBtn, &QPushButton::clicked, this, &ArchiveWidget::onViewClicked);
    connect(downloadBtn, &QPushButton::clicked, this, &ArchiveWidget::onDownloadClicked);
    connect(deleteBtn, &QPushButton::clicked, this, &ArchiveWidget::onDeleteClicked);
    connect(typeCombo, &QComboBox::currentTextChanged, this, &ArchiveWidget::onFilterChanged);
    connect(dateEdit, &QDateEdit::dateChanged, this, &ArchiveWidget::onFilterChanged);
    connect(statusCombo, &QComboBox::currentTextChanged, this, &ArchiveWidget::onFilterChanged);
    connect(archiveTable, &QTableWidget::cellDoubleClicked, this, &ArchiveWidget::onTableItemDoubleClicked);
    loadArchiveData();
}

void ArchiveWidget::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *filterLayout = new QHBoxLayout();
    filterLayout->addWidget(new QLabel("نوع:"));
    typeCombo = new QComboBox(this);
    typeCombo->addItems({"همه", "نامه", "فرم", "یادداشت"});
    filterLayout->addWidget(typeCombo);
    filterLayout->addWidget(new QLabel("تاریخ:"));
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setCalendarPopup(true);
    filterLayout->addWidget(dateEdit);
    filterLayout->addWidget(new QLabel("وضعیت:"));
    statusCombo = new QComboBox(this);
    statusCombo->addItems({"همه", "فعال", "آرشیو شده"});
    filterLayout->addWidget(statusCombo);
    mainLayout->addLayout(filterLayout);

    archiveTable = new QTableWidget(this);
    archiveTable->setColumnCount(5);
    archiveTable->setHorizontalHeaderLabels({"شماره سند", "عنوان", "نوع", "تاریخ", "وضعیت"});
    mainLayout->addWidget(archiveTable);

    toolbar = new QToolBar(this);
    viewBtn = new QPushButton("مشاهده");
    downloadBtn = new QPushButton("دانلود");
    deleteBtn = new QPushButton("حذف");
    toolbar->addWidget(viewBtn);
    toolbar->addWidget(downloadBtn);
    toolbar->addWidget(deleteBtn);
    mainLayout->addWidget(toolbar);
}

void ArchiveWidget::onViewClicked() {}
void ArchiveWidget::onDownloadClicked() {}
void ArchiveWidget::onDeleteClicked() {}
void ArchiveWidget::onFilterChanged() {}
void ArchiveWidget::onTableItemDoubleClicked(int row, int column) {}
void ArchiveWidget::loadArchiveData() {} 