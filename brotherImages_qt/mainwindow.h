#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadbotton_clicked();
    void on_btn_prev_clicked();
    void on_btn_next_clicked();

private:
    Ui::MainWindow *ui;
    QStringList imageFiles;
    int currentIndex = 0;

    void showImage(int index);
};
#endif // MAINWINDOW_H
