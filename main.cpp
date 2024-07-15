#include "ChessBoard.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;
    ChessBoard chessBoard;
    chessBoard.add1x1Boat();
    chessBoard.show();
    return app.exec();
}
