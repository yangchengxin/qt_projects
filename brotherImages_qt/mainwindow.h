#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QPixmap>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    // 返回主菜单
    void returnToStart();


public slots:
    void on_returnbotton_clicked();

private slots:
    void on_loadbotton_clicked();
    void on_btn_prev_clicked();
    void on_btn_next_clicked();

    // 添加相片
    void onAddPhotoClicked();

private:
    Ui::MainWindow *ui;
    QStringList imageFiles;
    int currentIndex = 0;

    void showImage(int index);

    // 添加相片
    QComboBox *yearCombo;
    QPushButton *addPhotoButton;
};
#endif // MAINWINDOW_H
