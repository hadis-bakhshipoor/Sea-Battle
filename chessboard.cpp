#include <QApplication>
#include "ChessBoard.h"
#include <QPainter>
#include <QWidget>
#include <QBrush>
#include <QColor>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QRect>
#include <QDebug>
#include <QLabel>

// Global Variable
int width_  = 600;
int height_ = 500;
int cellSize = 50;



ChessBoard::ChessBoard(QWidget* parent) : QMainWindow(parent){
    setFixedSize(width_, height_);

    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    addboat();
}

void ChessBoard::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    painter.fillRect(rect(), QBrush(QColor(173, 216, 230)));        // Blue Color
    int num_Of_cells_x = width_  / cellSize;
    int num_of_cells_y = height_ / cellSize;

    for (int i = 2; i < num_Of_cells_x; i++) {
        for (int j = 0; j < num_of_cells_y; j++) {
            if ((i + j) % 2 == 0) {
                painter.fillRect(i * cellSize, j * cellSize, cellSize, cellSize, QBrush(QColor(173, 205, 230)));    // i=x, j=y
            }
        }
    }

    painter.fillRect(0, 0, 100, height_, QBrush(QColor(0, 0, 0)));
}

void ChessBoard::addboat() {
    QMenu* fileMenu = menuBar()->addMenu("add boat");

    QAction* one = fileMenu->addAction("boat 1*1");
    // QAction* two = fileMenu->addAction("boat 1*2");
    // QAction* three = fileMenu->addAction("boat 1*3");
    // QAction* four = fileMenu->addAction("boat 1*4");

    // connect(one, &QAction::triggered, this, &ChessBoard::onButtonClicked);
    // connect(two, &QAction::triggered, this, &ChessBoard::add1x2Boat);
    // connect(three, &QAction::triggered, this, &ChessBoard::add1x3Boat);
    // connect(four, &QAction::triggered, this, &ChessBoard::add1x4Boat);
}

void ChessBoard::add1x1Boat() {
    
}


// void ChessBoard::add1x2Boat() {
//     boats.emplace_back(0, 0, 1, 2);
//     update();
// }


