#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->showPhoto_label->setStyleSheet(
        "border: 2px solid black;"
        "border-radius: 5px;"
        "padding: 4px;"
        "background-color: lightgray;"
        );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loadbotton_clicked() {
    QString path = ui->photopath_lineEdit->text();
    QDir dir(path);
    if (!dir.exists()) {
        QMessageBox::warning(this, "错误", "路径不存在！");
        return;
    }

    QStringList filters = {"*.png", "*.jpg", "*.jpeg", "*.bmp", "*.gif"};
    imageFiles = dir.entryList(filters, QDir::Files);
    if (imageFiles.isEmpty()) {
        QMessageBox::information(this, "提示", "该目录下没有图片文件！");
        return;
    }

    currentIndex = 0;
    showImage(currentIndex);
}

void MainWindow::showImage(int index) {
    if (index < 0 || index >= imageFiles.size()) return;

    QString path = ui->photopath_lineEdit->text() + "/" + imageFiles.at(index);
    QPixmap pix(path);
    if (pix.isNull()) {
        QMessageBox::warning(this, "错误", "无法加载图片：" + path);
        return;
    }

    ui->showPhoto_label->setPixmap(pix.scaled(ui->showPhoto_label->size(), Qt::KeepAspectRatio));
}

void MainWindow::on_btn_prev_clicked() {
    if (imageFiles.isEmpty()) return;
    currentIndex = (currentIndex - 1 + imageFiles.size()) % imageFiles.size();
    showImage(currentIndex);
}

void MainWindow::on_btn_next_clicked() {
    if (imageFiles.isEmpty()) return;
    currentIndex = (currentIndex + 1) % imageFiles.size();
    showImage(currentIndex);
}
