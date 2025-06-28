#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QProcess>
#include <QString>

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("My Qt Application");
        setMinimumSize(400, 300);
        
        QPushButton *button = new QPushButton("Click Me", this);
        button->setGeometry(150, 120, 100, 30);
        
        connect(button, &QPushButton::clicked, this, &MainWindow::handleButton);
    }
    
private slots:
    void handleButton() {
        QProcess process;
        process.setProgram("/opt/ros/humble/bin/ros2");
        process.start();
        process.waitForFinished();
        QByteArray data = process.readAllStandardOutput();
        qDebug() << QString::fromUtf8(data.data(),data.size()).length();
    }
};
