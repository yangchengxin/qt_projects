#include "mainwindow.h"
#include "startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow start_window;
    MainWindow show_window;

    QObject::connect(&start_window, &StartWindow::openAlbum, [&]() {
        start_window.hide();
        show_window.show();
    });

    QObject::connect(&show_window, &MainWindow::returnToStart, [&]() {
        show_window.hide();
        start_window.show();
    });

    start_window.resize(600, 400);
    start_window.show();

    return a.exec();
}
