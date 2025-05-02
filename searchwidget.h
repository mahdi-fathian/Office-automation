#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class SearchWidget : public QWidget {
    Q_OBJECT
public:
    explicit SearchWidget(QWidget *parent = nullptr);

private slots:
    void onSearchClicked();
    void onFilterChanged();
    void onTableItemDoubleClicked(int row, int column);
    void loadSearchData();

private:
    QLineEdit *searchEdit;
    QComboBox *filterCombo;
    QTableWidget *searchTable;
    QPushButton *searchBtn;
    void setupUI();
};

#endif // SEARCHWIDGET_H 