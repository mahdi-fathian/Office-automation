#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Office Automation System");
    
    // Create and show login dialog
    login = new Login(this);
    login->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
