#ifndef CARTABLEWIDGET_H
#define CARTABLEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QTextEdit>
#include <QTableWidget>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDateEdit>
#include <QCheckBox>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QMap>
#include <QVariant>
#include "database.h"

class CartableWidget : public QWidget {
    Q_OBJECT
public:
    explicit CartableWidget(Database *db, QWidget *parent = nullptr);

private slots:
    void onSendClicked();
    void onDraftClicked();
    void onDeleteClicked();
    void onNewLetterClicked();
    void onAttachFileClicked();
    void onTableItemDoubleClicked(int row, int column);
    void onRecipientSearchChanged(const QString &text);
    void onSaveOrUpdateLetter(bool isDraft);
    void loadCartableData();
    void refreshCartableTable();
    void clearForm();

private:
    Database *db;
    QToolBar *toolbar;
    QToolBar *formatToolbar;
    QPushButton *sendBtn;
    QPushButton *draftBtn;
    QPushButton *deleteBtn;
    QPushButton *newLetterBtn;
    QLineEdit *recipientSearchEdit;
    QListWidget *recipientList;
    QTextEdit *editor;
    QTableWidget *cartableTable;
    QLineEdit *titleEdit;
    QComboBox *priorityCombo;
    QComboBox *typeCombo;
    QListWidget *ccList;
    QLineEdit *instructionEdit;
    QCheckBox *urgentCheck;
    QDateEdit *dueDateEdit;
    QString attachedFilePath;
    int editingLetterId = -1;
    void setupFormFields(QVBoxLayout *mainLayout);
    void populateRecipients();
    void populateTypesAndPriorities();
};

#endif // CARTABLEWIDGET_H 