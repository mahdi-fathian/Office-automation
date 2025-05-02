#ifndef ARCHIVEWIDGET_H
#define ARCHIVEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class ArchiveWidget : public QWidget {
    Q_OBJECT
public:
    explicit ArchiveWidget(QWidget *parent = nullptr);

private slots:
    void onViewClicked();
    void onDownloadClicked();
    void onDeleteClicked();
    void onFilterChanged();
    void onTableItemDoubleClicked(int row, int column);
    void loadArchiveData();

private:
    QComboBox *typeCombo;
    QDateEdit *dateEdit;
    QComboBox *statusCombo;
    QTableWidget *archiveTable;
    QToolBar *toolbar;
    QPushButton *viewBtn;
    QPushButton *downloadBtn;
    QPushButton *deleteBtn;
    void setupUI();
};

#endif // ARCHIVEWIDGET_H 