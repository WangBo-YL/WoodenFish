#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gongde(0)
    , timer(new QTimer(this))
    , temporaryLabel(new QLabel(this))
    , temporaryLabelTimer(new QTimer(this))
{
    ui->setupUi(this);
    ui->gongdeLabel->setText("总功德值: 0");
    temporaryLabel->setStyleSheet("QLabel { color : red; }");
    temporaryLabel->setText("功德值+1");
    temporaryLabel->adjustSize();
    temporaryLabel->hide();
    connect(ui->muyuButton, &QPushButton::pressed, this, &MainWindow::on_muyuButton_pressed);
    connect(ui->muyuButton, &QPushButton::released, this, &MainWindow::on_muyuButton_released);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGongde);
    connect(temporaryLabelTimer, &QTimer::timeout, this, &MainWindow::hideTemporaryLabel);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_muyuButton_pressed() {
    // 立即增加一次功德值
    updateGongde();
    // 启动定时器，每100毫秒更新一次功德值
    timer->start(200);
    // 显示临时标签
    temporaryLabel->move(ui->muyuButton->x(), ui->muyuButton->y() - temporaryLabel->height());
    temporaryLabel->show();
    temporaryLabelTimer->start(500); // 显示500毫秒
}

void MainWindow::on_muyuButton_released() {
    // 停止定时器
    timer->stop();
}

void MainWindow::on_clearButton_clicked() {
    // 清零功德值
    gongde = 0;
    ui->gongdeLabel->setText("总功德值: 0");
}

void MainWindow::updateGongde() {
    // 每次触发时增加一次功德值
    gongde++;
    ui->gongdeLabel->setText(QString("总功德值: %1").arg(gongde));
}

void MainWindow::hideTemporaryLabel() {
    temporaryLabel->hide();
    temporaryLabelTimer->stop();
}
