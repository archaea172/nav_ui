# pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>

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
        qDebug() << "Button clicked!";
    }
};
