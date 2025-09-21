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

// void MainWindow::returnToStart()
// {
//     // mainwindow.cpp
//     auto *backButton = new QPushButton("返回首页", this);
//     ui->addWidget(backButton);
//     connect(backButton, &QPushButton::clicked, this, &MainWindow::returnToStart);
// }

void MainWindow::onAddPhotoClicked() {
    QString selectedYear = yearCombo->currentText();
    QString photoPath = QFileDialog::getOpenFileName(this, "选择照片", "", "Images (*.png *.jpg *.jpeg)");

    if (photoPath.isEmpty()) return;

    QDir targetDir(QDir::currentPath() + "/photos/" + selectedYear);
    if (!targetDir.exists()) {
        QDir().mkpath(targetDir.path());
    }

    QFileInfo fileInfo(photoPath);
    QString targetPath = targetDir.filePath(fileInfo.fileName());

    if (QFile::copy(photoPath, targetPath)) {
        QMessageBox::information(this, "成功", "照片已保存到 " + targetPath);
    } else {
        QMessageBox::warning(this, "失败", "无法保存照片");
    }
}

void MainWindow::on_returnbotton_clicked()
{
    connect(ui->returnbotton, &QPushButton::clicked, this, &MainWindow::returnToStart);
}

