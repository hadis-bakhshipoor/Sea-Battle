#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QCursor>
#include <QLabel>

namespace Ui {
    class ChessBoard;
}

class ChessBoard : public QMainWindow {
    Q_OBJECT

    public:
        ChessBoard(QWidget* parent = nullptr);
        void addboat();
        void add1x1Boat();
        void add1x2Boat();
        void add1x3Boat();
        void add1x4Boat();

    protected:
        void paintEvent(QPaintEvent*) override;

    private:
        Ui::ChessBoard *ui;
        QCursor cursor;
        QGraphicsScene* m_scene;
        QGraphicsView* m_view;
        QLabel* m_posLabel;

    private slots:
        void onMousePress(QMouseEvent* event) {
            QPoint cursorPos = m_view->mapToGlobal(event->pos());
            QString posText = QString("Cursor Position: (%1, %2)").arg(cursorPos.x()).arg(cursorPos.y());
            m_posLabel->setText(posText);
            qDebug() << posText;
        }

};

#endif // CHESSBOARD_H

