#ifndef EMAILWIDGET_H
#define EMAILWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>
#include <QTableWidget>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>

class EmailWidget : public QWidget {
    Q_OBJECT
public:
    explicit EmailWidget(QWidget *parent = nullptr);

private slots:
    void onSendClicked();
    void onReceiveClicked();
    void onDeleteClicked();
    void onAttachFileClicked();
    void onTableItemDoubleClicked(int row, int column);
    void onRecipientSearchChanged(const QString &text);
    void loadEmailData();
    void clearForm();

private:
    QToolBar *toolbar;
    QPushButton *sendBtn;
    QPushButton *receiveBtn;
    QPushButton *deleteBtn;
    QPushButton *attachBtn;
    QLineEdit *recipientSearchEdit;
    QListWidget *recipientList;
    QTextEdit *editor;
    QLineEdit *subjectEdit;
    QTableWidget *emailTable;
    QString attachedFilePath;
    int editingEmailId = -1;
    void setupUI();
    void populateRecipients();
};

#endif // EMAILWIDGET_H 