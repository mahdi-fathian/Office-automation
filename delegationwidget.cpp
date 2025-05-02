#include "delegationwidget.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSettings>
#include <QTableWidget>
#include <QHeaderView>

DelegationWidget::DelegationWidget(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("QWidget { background: white; }"
                  "QGroupBox { font-weight: bold; }"
                  "QCheckBox { margin-right: 8px; }"
                  "QPushButton { padding: 8px 20px; border-radius: 4px; background: #4a5568; color: white; }"
                  "QPushButton:hover { background: #2d3748; }");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Title
    QLabel *titleLabel = new QLabel("کارشناس آموزش <b>تفویض...</b>");
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    mainLayout->addWidget(titleLabel, 0, Qt::AlignRight);

    // User selection
    QHBoxLayout *userLayout = new QHBoxLayout();
    userLayout->addWidget(new QLabel(":تفویض شود به"));
    userCombo = new QComboBox();
    // Populate userCombo from database
    QSqlQuery userQuery("SELECT id, full_name FROM users ORDER BY full_name");
    while (userQuery.next()) {
        userCombo->addItem(userQuery.value(1).toString(), userQuery.value(0).toInt());
    }
    userLayout->addWidget(userCombo);
    userLayout->addStretch();
    mainLayout->addLayout(userLayout);

    // Date and time
    QHBoxLayout *dateLayout = new QHBoxLayout();
    fromDateEdit = new QDateEdit(QDate::currentDate(), this);
    toDateEdit = new QDateEdit(QDate::currentDate(), this);
    fromTimeEdit = new QTimeEdit(QTime::fromString("08:30", "hh:mm"), this);
    toTimeEdit = new QTimeEdit(QTime::fromString("17:30", "hh:mm"), this);
    dateLayout->addWidget(new QLabel(":از تاریخ"));
    dateLayout->addWidget(fromDateEdit);
    dateLayout->addWidget(fromTimeEdit);
    dateLayout->addWidget(new QLabel(":تا تاریخ"));
    dateLayout->addWidget(toDateEdit);
    dateLayout->addWidget(toTimeEdit);
    dateLayout->addStretch();
    mainLayout->addLayout(dateLayout);

    // Details checkbox
    detailsCheck = new QCheckBox("مشخصات تفویض");
    detailsCheck->setChecked(true);
    mainLayout->addWidget(detailsCheck, 0, Qt::AlignRight);

    // Access items
    QLabel *accessLabel = new QLabel("لطفا آیتم های مورد نظر جهت دسترسی به شخص تفویض گیرنده را مشخص نمایید");
    mainLayout->addWidget(accessLabel, 0, Qt::AlignRight);

    QGridLayout *accessGrid = new QGridLayout();
    QStringList accessItems = {
        "تابلو اعلانات", "تقویم", "یادداشت", "دفتر تلفن", "گزارش های عمومی",
        "اتوماسیون اداری", "کارتابل", "نامه صادره", "نامه داخلی", "نامه وارده",
        "یادداشت اداری", "فرم اداری", "فرم‌های سازمانی", "بایگانی پست سازمانی",
        "بایگانی سازمانی", "پیش نویس", "جستجو", "پست الکترونیک", "تاریخچه", "بایگانی اسناد"
    };
    QList<int> checkedIndexes = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}; // پیش‌فرض تیک‌خورده‌ها
    int row = 0, col = 0;
    for (int i = 0; i < accessItems.size(); ++i) {
        QCheckBox *cb = new QCheckBox(accessItems[i]);
        if (checkedIndexes.contains(i)) cb->setChecked(true);
        accessChecks.append(cb);
        accessGrid->addWidget(cb, row, col);
        col++;
        if (col == 3) { col = 0; row++; }
    }
    mainLayout->addLayout(accessGrid);

    // Buttons
    QHBoxLayout *btnLayout = new QHBoxLayout();
    saveBtn = new QPushButton("ثبت", this);
    cancelBtn = new QPushButton("لغو", this);
    btnLayout->addStretch();
    btnLayout->addWidget(saveBtn);
    btnLayout->addWidget(cancelBtn);
    mainLayout->addLayout(btnLayout);

    // --- Delegations Table ---
    QTableWidget *delegationTable = new QTableWidget(this);
    delegationTable->setColumnCount(7);
    delegationTable->setHorizontalHeaderLabels({"به کاربر", "از تاریخ", "تا تاریخ", "از ساعت", "تا ساعت", "دسترسی‌ها", "عملیات"});
    delegationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(new QLabel("تفویض‌های قبلی شما:"));
    mainLayout->addWidget(delegationTable);

    auto loadDelegations = [this, delegationTable]() {
        QSettings settings("OfficeAutomation", "Dashboard");
        int fromUserId = settings.value("user/id", 1).toInt();
        delegationTable->setRowCount(0);
        QSqlQuery q;
        q.prepare("SELECT id, to_user_id, from_date, to_date, from_time, to_time, access_items FROM delegations WHERE from_user_id = ? ORDER BY id DESC");
        q.addBindValue(fromUserId);
        if (q.exec()) {
            while (q.next()) {
                int row = delegationTable->rowCount();
                delegationTable->insertRow(row);
                int delegationId = q.value(0).toInt();
                int toUserId = q.value(1).toInt();
                // Get to_user name
                QString toUserName = "";
                QSqlQuery uq;
                uq.prepare("SELECT full_name FROM users WHERE id = ?");
                uq.addBindValue(toUserId);
                if (uq.exec() && uq.next()) toUserName = uq.value(0).toString();
                delegationTable->setItem(row, 0, new QTableWidgetItem(toUserName));
                for (int col = 2; col <= 6; ++col) {
                    delegationTable->setItem(row, col-1, new QTableWidgetItem(q.value(col).toString()));
                }
                // Add delete button
                QPushButton *delBtn = new QPushButton("حذف");
                delegationTable->setCellWidget(row, 6, delBtn);
                // Connect delete
                QObject::connect(delBtn, &QPushButton::clicked, this, [delegationId, loadDelegations, this]() {
                    QSqlQuery dq;
                    dq.prepare("DELETE FROM delegations WHERE id = ?");
                    dq.addBindValue(delegationId);
                    if (dq.exec()) {
                        QMessageBox::information(this, "حذف", "تفویض حذف شد.");
                        loadDelegations();
                    } else {
                        QMessageBox::critical(this, "خطا", "حذف تفویض با خطا مواجه شد: " + dq.lastError().text());
                    }
                });
            }
        }
    };
    loadDelegations();
    // Reload after save
    connect(saveBtn, &QPushButton::clicked, this, loadDelegations);
} 