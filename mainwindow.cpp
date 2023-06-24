#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::checkPalindrome);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isPalindrome(const QString& str) {
    QString lowerStr = str.toLower();
    QString reversed = lowerStr;
    std::reverse(reversed.begin(), reversed.end());
    return lowerStr == reversed;
}

void MainWindow::checkPalindrome() {
    QString str = ui->lineEdit->text();

    if (isPalindrome(str)) {
        ui->resultLabel->setText("Is palindrome.");
    } else {
        ui->resultLabel->setText("Is not palindrone.");
    }
}
