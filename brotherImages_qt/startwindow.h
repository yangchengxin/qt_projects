#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#endif // STARTWINDOW_H

// startwindow.h
#pragma once

#include <QWidget>

class QPushButton;

class StartWindow : public QWidget {
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);

signals:
    void openAlbum();

private:
    QPushButton *viewAlbumBtn;
    QPushButton *manageAlbumBtn;
};
