#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_muyuButton_pressed();
    void on_muyuButton_released();
    void on_clearButton_clicked();
    void updateGongde();
    void hideTemporaryLabel();

private:
    Ui::MainWindow *ui;
    int gongde;
    QTimer *timer;
    QLabel *temporaryLabel;
    QTimer *temporaryLabelTimer;
};

#endif // MAINWINDOW_H
