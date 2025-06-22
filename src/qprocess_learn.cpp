#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include "qprocess_learn.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}