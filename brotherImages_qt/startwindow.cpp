// startwindow.cpp
#include "startwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    auto *title = new QLabel("📷 照片管理软件", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold;");

    viewAlbumBtn = new QPushButton("查看相册", this);
    manageAlbumBtn = new QPushButton("管理相册", this);

    layout->addWidget(title);
    layout->addSpacing(20);
    layout->addWidget(viewAlbumBtn);
    layout->addWidget(manageAlbumBtn);

    connect(viewAlbumBtn, &QPushButton::clicked, this, &StartWindow::openAlbum);
}
