#include "searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    connect(searchBtn, &QPushButton::clicked, this, &SearchWidget::onSearchClicked);
    connect(filterCombo, &QComboBox::currentTextChanged, this, &SearchWidget::onFilterChanged);
    connect(searchTable, &QTableWidget::cellDoubleClicked, this, &SearchWidget::onTableItemDoubleClicked);
    loadSearchData();
}

void SearchWidget::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchEdit = new QLineEdit(this);
    searchEdit->setPlaceholderText("جستجو...");
    filterCombo = new QComboBox(this);
    filterCombo->addItems({"همه", "نامه", "فرم", "یادداشت"});
    searchBtn = new QPushButton("جستجو", this);
    searchLayout->addWidget(new QLabel("جستجو:"));
    searchLayout->addWidget(searchEdit);
    searchLayout->addWidget(new QLabel("فیلتر:"));
    searchLayout->addWidget(filterCombo);
    searchLayout->addWidget(searchBtn);
    mainLayout->addLayout(searchLayout);

    searchTable = new QTableWidget(this);
    searchTable->setColumnCount(4);
    searchTable->setHorizontalHeaderLabels({"عنوان", "نوع", "تاریخ", "وضعیت"});
    mainLayout->addWidget(searchTable);
}

void SearchWidget::onSearchClicked() {}
void SearchWidget::onFilterChanged() {}
void SearchWidget::onTableItemDoubleClicked(int row, int column) {}
void SearchWidget::loadSearchData() {} 